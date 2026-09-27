// ?changeObjectPanelFlagForSingleObject@ScriptActions@@QAEXPAVObject@@ABVAsciiString@@_N@Z
// partial score=0.85 date=2026-09-27
// cl: /O1 /DNDEBUG /MD /EHsc /D_STLP_USE_STATIC_LIB
// stlport
//
// ?changeObjectPanelFlagForSingleObject@ScriptActions@@QAEXPAVObject@@ABVAsciiString@@_N@Z,
// retail 0x003C4C07, 341 bytes. Dedicated TU.
//
// Donor: Zero Hour ScriptActions.cpp changeObjectPanelFlagForSingleObject,
// keyed by the TheObjectFlagsNames table (Scripts.cpp; retail array at
// 0x00DC10FC, "Player Targetable" anchor). Arm order, script-status bits
// (1, 2, 4, 0x10) and negations match the donor. BFME2 facts:
// - flag compare is StringBase<char>::compare (0x000069B1) == 0.
// - Indestructible also recurses into every contained object: contain
//   module at Object +0x250 (slot 31 count, slot 70 list view returned by
//   hidden pointer), body module inline at +0x254 (slot 33).
// - AI Recruitable writes the AIUpdate byte +0x3BE inline (AI at +0x258).
// Virtual slot indices are target facts; the unused slots are placeholders.
#include <list>

typedef bool Bool;

class AsciiString
{
public:
	int compare(const char *s) const;
private:
	void *m_data;
};

extern const char *TheObjectFlagsNames[];

enum ObjectScriptStatusBit
{
	OBJECT_STATUS_SCRIPT_DISABLED = 0x01,
	OBJECT_STATUS_SCRIPT_UNPOWERED = 0x02,
	OBJECT_STATUS_SCRIPT_UNSELLABLE = 0x04,
	OBJECT_STATUS_SCRIPT_TARGETABLE = 0x10
};

class Object;
typedef _STL::list<Object *> ContainedItemsList;

// Returned by hidden pointer from the contain module; only the list
// pointer at +0x04 is read.
struct ContainedItemsView
{
	ContainedItemsView() {}
	int m_unused;
	ContainedItemsList *m_list;
};

class BodyModuleInterface
{
public:
	virtual void unused0();
	virtual void unused1();
	virtual void unused2();
	virtual void unused3();
	virtual void unused4();
	virtual void unused5();
	virtual void unused6();
	virtual void unused7();
	virtual void unused8();
	virtual void unused9();
	virtual void unused10();
	virtual void unused11();
	virtual void unused12();
	virtual void unused13();
	virtual void unused14();
	virtual void unused15();
	virtual void unused16();
	virtual void unused17();
	virtual void unused18();
	virtual void unused19();
	virtual void unused20();
	virtual void unused21();
	virtual void unused22();
	virtual void unused23();
	virtual void unused24();
	virtual void unused25();
	virtual void unused26();
	virtual void unused27();
	virtual void unused28();
	virtual void unused29();
	virtual void unused30();
	virtual void unused31();
	virtual void unused32();
	virtual void setIndestructible(bool indestructible);
};

class ContainModuleInterface
{
public:
	virtual void unused0();
	virtual void unused1();
	virtual void unused2();
	virtual void unused3();
	virtual void unused4();
	virtual void unused5();
	virtual void unused6();
	virtual void unused7();
	virtual void unused8();
	virtual void unused9();
	virtual void unused10();
	virtual void unused11();
	virtual void unused12();
	virtual void unused13();
	virtual void unused14();
	virtual void unused15();
	virtual void unused16();
	virtual void unused17();
	virtual void unused18();
	virtual void unused19();
	virtual void unused20();
	virtual void unused21();
	virtual void unused22();
	virtual void unused23();
	virtual void unused24();
	virtual void unused25();
	virtual void unused26();
	virtual void unused27();
	virtual void unused28();
	virtual void unused29();
	virtual void unused30();
	virtual int getContainCount();
	virtual void unused32();
	virtual void unused33();
	virtual void unused34();
	virtual void unused35();
	virtual void unused36();
	virtual void unused37();
	virtual void unused38();
	virtual void unused39();
	virtual void unused40();
	virtual void unused41();
	virtual void unused42();
	virtual void unused43();
	virtual void unused44();
	virtual void unused45();
	virtual void unused46();
	virtual void unused47();
	virtual void unused48();
	virtual void unused49();
	virtual void unused50();
	virtual void unused51();
	virtual void unused52();
	virtual void unused53();
	virtual void unused54();
	virtual void unused55();
	virtual void unused56();
	virtual void unused57();
	virtual void unused58();
	virtual void unused59();
	virtual void unused60();
	virtual void unused61();
	virtual void unused62();
	virtual void unused63();
	virtual void unused64();
	virtual void unused65();
	virtual void unused66();
	virtual void unused67();
	virtual void unused68();
	virtual void unused69();
	virtual ContainedItemsView getContainedItemsList();
};

class AIUpdateInterface
{
public:
	void setIsRecruitable(Bool isRecruitable) { m_isRecruitable = isRecruitable; }
private:
	unsigned char m_pad[0x3BE];
	Bool m_isRecruitable;	// +0x3BE
};

class Object
{
public:
	void setScriptStatus(ObjectScriptStatusBit bit, Bool set);
	Bool isSelectable() const;
	void setSelectable(Bool selectable);
	ContainModuleInterface *const &getContain() const { return m_contain; }
	BodyModuleInterface *getBodyModule() const { return m_body; }
	AIUpdateInterface *getAIUpdateInterface() const { return m_ai; }
private:
	unsigned char m_pad[0x250];
	ContainModuleInterface *m_contain;	// +0x250
	BodyModuleInterface *m_body;		// +0x254
	AIUpdateInterface *m_ai;		// +0x258
};

class ScriptActions
{
public:
	void changeObjectPanelFlagForSingleObject(Object *obj, const AsciiString &flagToChange, Bool newVal);
};

void ScriptActions::changeObjectPanelFlagForSingleObject(Object *obj, const AsciiString &flagToChange, Bool newVal)
{
	if (flagToChange.compare(TheObjectFlagsNames[0]) == 0)
	{
		obj->setScriptStatus(OBJECT_STATUS_SCRIPT_DISABLED, !newVal);
		return;
	}
	if (flagToChange.compare(TheObjectFlagsNames[1]) == 0)
	{
		obj->setScriptStatus(OBJECT_STATUS_SCRIPT_UNPOWERED, !newVal);
		return;
	}
	if (flagToChange.compare(TheObjectFlagsNames[2]) == 0)
	{
		BodyModuleInterface *body = obj->getBodyModule();
		if (body)
			body->setIndestructible(newVal);
		ContainModuleInterface *const &contain = obj->getContain();
		if (contain && contain->getContainCount())
		{
			ContainedItemsView view = contain->getContainedItemsList();
			for (ContainedItemsList::iterator it = view.m_list->begin(); it != view.m_list->end(); ++it)
			{
				if (*it)
					changeObjectPanelFlagForSingleObject(*it, flagToChange, newVal);
			}
		}
		return;
	}
	if (flagToChange.compare(TheObjectFlagsNames[3]) == 0)
	{
		obj->setScriptStatus(OBJECT_STATUS_SCRIPT_UNSELLABLE, newVal);
		return;
	}
	if (flagToChange.compare(TheObjectFlagsNames[4]) == 0)
	{
		if (obj->isSelectable() != newVal)
			obj->setSelectable(newVal);
		return;
	}
	if (flagToChange.compare(TheObjectFlagsNames[5]) == 0)
	{
		if (obj->getAIUpdateInterface())
			obj->getAIUpdateInterface()->setIsRecruitable(newVal);
		return;
	}
	if (flagToChange.compare(TheObjectFlagsNames[6]) == 0)
	{
		obj->setScriptStatus(OBJECT_STATUS_SCRIPT_TARGETABLE, newVal);
		return;
	}
}
