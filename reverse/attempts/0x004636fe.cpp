// ??1Rva004636FE@@QAE@XZ
// partial score=0.9 date=2026-10-02
// cl: /O1 /EHsc /MD /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_CRTIMP= /D_BFME_RETAIL_TREE_INSERT_LAYOUT
// stlport
// ??1Rva004636FE@@QAE@XZ 0x004636FE 56B
// Destructor of an honest-address class holding a Rva00462D35Tree map at +0
// (same typedef as stlport_tree_erase_00462D35.cpp which names this address
// as the dtor calling clear 0x004633FC). Body clears the tree then frees the
// header block at [this] via the game free at 0x00030830 with a null check.
// EH prolog plus state guards the clear call. The explicit specialization
// below declares clear without a body so the compiler calls the rowed
// out-of-line copy instead of inlining the header version.
#include <map>

struct Rva00462D35Mapped
{
	unsigned int m_bits;
};

typedef _STL::pair<const int, Rva00462D35Mapped> Rva004636FEPair;
typedef _STL::_Rb_tree<int, Rva004636FEPair, _STL::_Select1st<Rva004636FEPair>, _STL::less<int>, _STL::allocator<Rva004636FEPair> > Rva004636FETree;

namespace _STL {
template<> void _Rb_tree<int, Rva004636FEPair, _Select1st<Rva004636FEPair>, less<int>, allocator<Rva004636FEPair> >::clear();
}

extern "C" void __cdecl free(void *);

class Rva004636FE
{
public:
	~Rva004636FE();
private:
	Rva004636FETree m_tree;
};

// ??1Rva004636FE@@QAE@XZ present-unmatched
Rva004636FE::~Rva004636FE()
{
	m_tree.clear();
	void *p = *(void * *)&m_tree;
	if (p)
		free(p);
}
