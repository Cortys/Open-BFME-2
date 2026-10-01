// ?method@Rva00409850SubObject@@QAEXE@Z
// partial score=0.92 date=2026-10-01
// cl: /O1 /MD
//
// ?method@Rva00409850SubObject@@QAEXE@Z retail 0x00362609 62 bytes. Subobject
// active/flag/target state machine proven by caller 0x003626AD dispatchSlot
// (index*0x44 lea +8) and callee 0x00419BA5 direct call plus target+8 state 2.
// Evidence: rowed callee Rva00419BA5 rva00419BA5, sibling Rva00409930SlotArray
// method shape, shared tail m04=0.

class Rva00419BA5
{
public:
	void rva00419BA5();
};

struct Rva00362609SubTarget
{
	char m_pad[8];
	int m_state;
};

class Rva00409850SubObject
{
public:
	void method(unsigned char arg);

private:
	char m_00[4];
	unsigned char m_04;
	char m_05[7];
	int m_0C;
	char m_10[8];
	void *m_18;
	char m_1C[0x20];
};

// ?method@Rva00409850SubObject@@QAEXE@Z present-unmatched
void Rva00409850SubObject::method(unsigned char arg)
{
	if (arg)
	{
		if (m_18)
		{
			((Rva00419BA5 *)m_18)->rva00419BA5();
			m_18 = 0;
		}
	}
	else
	{
		if (!m_04)
			return;
		if (m_0C - 1 != 0)
			return;
		if (m_18)
			((Rva00362609SubTarget *)m_18)->m_state = 2;
	}
	m_04 = 0;
}
