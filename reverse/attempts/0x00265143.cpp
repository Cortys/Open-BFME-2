// ?rva00265143@AIUpdateInterface@@QAEHXZ
// partial score=0.95 date=2026-09-28
// ?rva00265143@AIUpdateInterface@@QAEHXZ
// partial score=0.95 date=2026-09-28
// cl: /O1 /DNDEBUG /MD
//
// ?rva00265143@AIUpdateInterface@@QAEHXZ, retail 0x00265143 (48 bytes). AI state-gated 12-byte vector size.
// Ours 46B vs retail 48B: missing add ecx,0x3c; ours folds to sub eax,[ecx+0x3c] (3B) vs retail add+sub (5B).
// Tried /O1, /O1+G7, /Os, ptr-arith, &begin, char*+add spellings; all fold. Only addressing choice left.

class AIStateMachineInner
{
public:
	char m_pad00[0x3C];
	int m_begin3C;
	int m_end40;
};

class AIUpdateInterface
{
public:
	int getCurrentStateID() const;
	int rva00265143();

private:
	char m_pad00[0x30];
	AIStateMachineInner *m_machine;
};

int AIUpdateInterface::rva00265143()
{
	if (getCurrentStateID() == 6 || getCurrentStateID() == 0x43)
		return (m_machine->m_end40 - m_machine->m_begin3C) / 12;
	return 0;
}
