// cl: /O1 /MD
//
// ?Rva00452496Check@@YA_NPAVObject@@@Z, retail 0x00452496, 79 bytes.
// Static AutoHeal helper: true if obj's AI (Object+0x258) has a current victim,
// else true when obj's container (Object+0x274) is kind-marked 0x20 (template
// +0x115) and the container's AI has a current victim. Layout proven by
// Object_isAbleToAttack.cpp and the rowed
// ?getCurrentVictim@AIUpdateInterface@@QBEPAVObject@@XZ 0x00268D71.
//
// VC7.1 emits this file-static helper with a private convention (arg in ESI, no
// prolog/epilog); retail's callers (0x4524E5, 0x45280B) already hold the Object*
// in ESI. The scaffold caller below is present-unmatched: it exists only so the
// static body is emitted with that convention, and is replaced when the real
// callers are reconstructed.

class Object;
class AIUpdateInterface
{
public:
	Object *getCurrentVictim() const;
};
struct ThingTemplate
{
	unsigned char m_pad[0x115];
	unsigned char m_kindByte115;
};
class Object
{
public:
	void *m_vtable;
	ThingTemplate *m_template;
	char m_pad8[0x258 - 0x8];
	AIUpdateInterface *m_ai;
	char m_pad25C[0x274 - 0x25C];
	Object *m_containedBy;
};
typedef bool Bool;

static __declspec(noinline) Bool Rva00452496Check(Object *obj)
{
	if (!obj)
		return false;
	AIUpdateInterface *ai = obj->m_ai;
	if (ai && ai->getCurrentVictim() != 0)
		return true;
	Object *container = obj->m_containedBy;
	return container
		&& (container->m_template->m_kindByte115 & 0x20) != 0
		&& container->m_ai != 0
		&& container->m_ai->getCurrentVictim() != 0;
}

// ?Rva00452496Caller@@YAHPAVObject@@@Z present-unmatched
int Rva00452496Caller(Object *obj)
{
	return (int)Rva00452496Check(obj) + (int)Rva00452496Check(obj);
}
