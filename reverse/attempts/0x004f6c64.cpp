// ?Rva004F6C64Push@@YAXPAURva004F64FC@@HHU1@@Z
// partial score=0.95 date=2026-09-29
// ?Rva004F6C64Push@@YAXPAURva004F64FC@@HHU1@@Z
// partial score=0.95 date=2026-09-29
// cl: /O1 /EHsc
// ?Rva004F6C64Push@@YAXPAURva004F64FC@@HHU1@@Z, retail 0x004F6C64, 121 bytes.
// Heap push for 12-byte Rva004F64FC array stride 0xC keyed at +8 via rowed assign 0x004F64FC plus Release 0x7DEEF with EH for by-value.
// Evidence: chain from 0x004F64FC; callers 0x004F6E04 0x004F7188; prev vector copy 0x004F6C05 /O1.

struct TargetRef00217D4C
{
	void *m_vtbl;
	int references;
};

struct TreeHintRef00217D4C
{
	TargetRef00217D4C *m_ptr;
	TreeHintRef00217D4C &operator=(const TreeHintRef00217D4C &other);
};

void __fastcall ReleaseTreeHintRef00217D4C(TargetRef00217D4C *p);

struct Rva004F64FC
{
	TreeHintRef00217D4C m_00;
	int m_04;
	int m_key;
	Rva004F64FC &operator=(const Rva004F64FC &other);
	~Rva004F64FC()
	{
		if (m_00.m_ptr)
			ReleaseTreeHintRef00217D4C(m_00.m_ptr);
	}
};

void __cdecl Rva004F6C64Push(Rva004F64FC *base, int hole, int top, Rva004F64FC value)
{
	int parent = (hole - 1) / 2;
	while (hole > top) {
		Rva004F64FC *parentElem = base + parent;
		if (parentElem->m_key <= value.m_key)
			break;
		base[hole] = *parentElem;
		hole = parent;
		parent = (hole - 1) / 2;
	}
	base[hole] = value;
}
