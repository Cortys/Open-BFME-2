// ?Rva00452496Check@@YA_NPAVObject@@@Z
// partial score=0.94 date=2026-09-29
// ?Rva00452496Check@@YA_NPAVObject@@@Z
// partial score=0.94 date=2026-09-29
// cl: /O1 /MD
// Static AutoHeal helper at 0x00452496 (79B): returns true if obj's AI (Object+0x258)
// has a current victim, else checks obj->m_containedBy (Object+0x274): if the
// container's template kind byte at +0x115 has 0x20 and the container's AI has a
// victim, returns true; else false. Layout proven by Object_isAbleToAttack.cpp
// (m_template+0x4/m_kindByte115, m_ai+0x258, m_containedBy+0x274) and rowed
// ?getCurrentVictim@AIUpdateInterface@@QBEPAVObject@@XZ 0x00268D71.
// VC7.1 gives this static helper a private convention (arg in ESI, no push/pop):
// it only matches with a caller in the same TU (static __declspec(noinline)).
// Both retail callers (checkForAutoHeal 0x004524E5 and update 0x0045280B) hold the
// healer Object* in ESI with no mov ecx setup. Dummy caller below forces ESI;
// replace it with the real checkForAutoHeal/update body when landing.
// Remaining wall (74/79B, 0 mem diffs): tail merges to setne al where retail has
// test+je+xor eax+inc eax then xor eax (5B). Early mov al/1 and all offsets exact.
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
// ?Rva00452496Check@@YA_NPAVObject@@@Z present-unmatched
static __declspec(noinline) Bool Rva00452496Check(Object *obj)
{
	if (!obj)
		return false;
	AIUpdateInterface *ai = obj->m_ai;
	if (ai) {
		if (ai->getCurrentVictim() != 0)
			return true;
	}
	Object *container = obj->m_containedBy;
	if (!container)
		return false;
	if ((container->m_template->m_kindByte115 & 0x20) == 0)
		return false;
	AIUpdateInterface *cai = container->m_ai;
	if (!cai)
		return false;
	Object *victim = cai->getCurrentVictim();
	if (victim != 0)
		return true;
	return false;
}
// ?Rva00452496Caller@@YAHPAVObject@@@Z present-unmatched
int Rva00452496Caller(Object *obj)
{
	return (int)Rva00452496Check(obj) + (int)Rva00452496Check(obj);
}
