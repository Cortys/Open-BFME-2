// ?Rva004F7801Partition@@YAPAURva004F6352@@PAU1@0PAHHUTreeHintRef00217D4C@@@Z
// partial score=0.93 date=2026-09-30
// ?Rva004F7801Partition@@YAPAURva004F6352@@PAU1@0PAHHUTreeHintRef00217D4C@@@Z
// partial score=0.93 date=2026-09-30
// cl: /O1 /EHsc /MD
// ?Rva004F7801Partition@@YAPAURva004F6352@@PAU1@0PAHHUTreeHintRef00217D4C@@@Z, retail 0x004F7801, 107 bytes.
// Partition loop stride 0xC over Rva004F6352 via rowed _STL::swap 0x004F6E62,
// keys are m_00[2] vs pivot[2] (double-deref +8 pattern like median 0x004F60EC).
// 5th param hint released at end via rowed __fastcall Release 0x0007DEEF.
// Evidence: callers 0x004F95F4 in introsort 0x004F95A8; callees rowed.

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

// ?ReleaseTreeHintRef00217D4C@@YIXPAUTargetRef00217D4C@@@Z present-unmatched
inline TreeHintRef00217D4C::~TreeHintRef00217D4C()
{
	if (m_ptr)
		ReleaseTreeHintRef00217D4C(m_ptr);
}

struct Rva004F6352
{
	int *m_00;
	int m_04;
	TreeHintRef00217D4C m_08;
	Rva004F6352(const Rva004F6352 &other);
	Rva004F6352 &operator=(const Rva004F6352 &other);
	~Rva004F6352();
};

namespace _STL
{
template <class T> void swap(T &a, T &b);
}

// ?Rva004F7801Partition@@YAPAURva004F6352@@PAU1@0PAHHUTreeHintRef00217D4C@@@Z present-unmatched
Rva004F6352 *__cdecl Rva004F7801Partition(Rva004F6352 *first, Rva004F6352 *last, int *pivot, int dummy, TreeHintRef00217D4C hint)
{
	(void)dummy;
	for (;;) {
		while (first->m_00[2] > pivot[2])
			++first;
		--last;
		while (pivot[2] > last->m_00[2])
			--last;
		if (!(first < last))
			return first;
		_STL::swap(*first, *last);
		++first;
	}
}
