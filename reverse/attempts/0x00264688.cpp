// ?rva00264688@AIUpdateInterface@@QBE_NXZ
// partial score=0.94 date=2026-09-28
// ?rva00264688@AIUpdateInterface@@QBE_NXZ
// partial score=0.94 date=2026-09-28
// cl: /O1 /DNDEBUG /MD
//
// ?rva00264688@AIUpdateInterface@@QBE_NXZ, retail 0x00264688 97B.
// AIUpdateInterface containment climb plus locomotor tail. Evidence:
// m_object at +0x08 (wakeUpNow 0x262871), m_flag3B7 at +0x3B7 (rva00262ACE),
// m_goalType at +0x1FC (setLocomotorGoalPositionExplicit 0x262C35), AI at
// Object+0x258 and containedBy at +0x274 (Object_isAbleToAttack), template
// bytes +0x108&4 and +0x115&0x20 (same area isAbleToAttack models),
// callers 0x2686EF (AI this) and 0x2948D3 (Object+0x258 AI this), virtual
// slot 110 at +0x1B8 returning Bool (tail isIdle-then-locomotor like BFME1
// AIUpdate::isMoving). Tail (flag cmp, virtual jne to shared false, cmp
// dword 0x1FC imm plus pop plus setne) already byte-exact. Remaining wall:
// loop rotation hoists next obj load via ecx (mov eax,[ecx+8]) before mov
// esi,ecx, needing entry jmp; retail keeps mov esi,ecx plus jmp top with
// shared top loads, 3B smaller. Tried for/goto/do/while plus /Os /G7 /G6.
typedef bool Bool;
struct ThingTemplate
{
	unsigned char m_pad[0x108];
	unsigned char m_byte108;
	unsigned char m_pad109[0x115 - 0x109];
	unsigned char m_byte115;
};
class AIUpdateInterface;
class ObjectFull
{
public:
	char m_pad00[4];
	ThingTemplate *m_template;
	unsigned char m_pad08[0x258 - 0x08];
	AIUpdateInterface *m_ai;
	unsigned char m_pad25C[0x274 - 0x25C];
	ObjectFull *m_containedBy;
};
template <int N>
class BfmeVirtualSlots : public BfmeVirtualSlots<N - 1>
{
public:
	virtual void unused(char (*)[N]) = 0;
};
template <>
class BfmeVirtualSlots<0>
{
};
class AIUpdateInterface : public BfmeVirtualSlots<110>
{
public:
	virtual Bool slot110() const;
	char m_pad04[0x08 - 0x04];
	ObjectFull *m_object;
	char m_pad0C[0x1FC - 0x0C];
	int m_goalType;
	char m_pad200[0x3B7 - 0x200];
	Bool m_flag3B7;
public:
	Bool rva00264688() const;
};
// ?rva00264688@AIUpdateInterface@@QBE_NXZ present-unmatched
Bool AIUpdateInterface::rva00264688() const
{
	const AIUpdateInterface *cur = this;
	for (;;)
	{
		ObjectFull *obj = cur->m_object;
		ThingTemplate *tmpl = obj->m_template;
		if ((tmpl->m_byte108 & 4) != 0)
			return false;
		ObjectFull *container = obj->m_containedBy;
		if (container == 0)
			break;
		AIUpdateInterface *containerAI = container->m_ai;
		if (containerAI == 0)
			break;
		ThingTemplate *ctmpl = container->m_template;
		if ((ctmpl->m_byte115 & 0x20) != 0)
			break;
		cur = containerAI;
	}
	if (cur->m_flag3B7)
		return true;
	if (cur->slot110())
		return false;
	if (cur->m_goalType == 0)
		return false;
	return true;
}
