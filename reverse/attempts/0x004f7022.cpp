// ?Rva004F7022PushHeap@@YAXPAURva004F6352@@HHU1@@Z
// partial score=0.96 date=2026-09-30
// ?Rva004F7022PushHeap@@YAXPAURva004F6352@@HHU1@@Z
// partial score=0.96 date=2026-09-30
// cl: /O1 /EHsc /MD
// ?Rva004F7022PushHeap@@YAXPAURva004F6352@@HHU1@@Z @0x004F7022 131B
// __push_heap sift-up for 12-byte Rva004F6352 records with value by value.
// Evidence: callees assign 0x004F6352 row Rva004F6352Assign.cpp Release 0x0007DEEF row TreeHintRefReleaseBFME2.cpp; prev swap 0x004F6E62 same flags same assign Release; caller 0x004F767A; same STLport spelling as rowed 0x00428233 with parent hole-top indices and imul 0xC stride and inlined key compare at [m_00+8].
struct TargetRef00217D4C
{
	void *m_vtbl;
	int references;
};
void __fastcall ReleaseTreeHintRef00217D4C(TargetRef00217D4C *p);
struct TreeHintRef00217D4C
{
	TargetRef00217D4C *m_ptr;
	TreeHintRef00217D4C(const TreeHintRef00217D4C &other);
	TreeHintRef00217D4C &operator=(const TreeHintRef00217D4C &other);
	~TreeHintRef00217D4C();
};
struct Rva004F6352
{
	int m_00;
	int m_04;
	TreeHintRef00217D4C m_08;
	Rva004F6352(const Rva004F6352 &other);
	Rva004F6352 &operator=(const Rva004F6352 &other);
	~Rva004F6352();
};
// ??1TreeHintRef00217D4C@@QAE@XZ present-unmatched
inline TreeHintRef00217D4C::~TreeHintRef00217D4C()
{
	if (m_ptr)
		ReleaseTreeHintRef00217D4C(m_ptr);
}
// ??1Rva004F6352@@QAE@XZ present-unmatched
inline Rva004F6352::~Rva004F6352()
{
}
// ?Rva004F7022PushHeap@@YAXPAURva004F6352@@HHU1@@Z present-unmatched
void __cdecl Rva004F7022PushHeap(Rva004F6352 *first, int holeIndex, int topIndex, Rva004F6352 val)
{
	int parent = (holeIndex - 1) / 2;
	while (holeIndex > topIndex)
	{
		Rva004F6352 *parentRec = first + parent;
		int parentKey = *(int *)(parentRec->m_00 + 8);
		int valKey = *(int *)(val.m_00 + 8);
		if (parentKey <= valKey)
			break;
		*(Rva004F6352 *)(first + holeIndex) = *parentRec;
		holeIndex = parent;
		parent = (holeIndex - 1) / 2;
	}
	*(Rva004F6352 *)(first + holeIndex) = val;
}
