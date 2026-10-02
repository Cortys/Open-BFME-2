// ?rva004E9600@Rva004E9600@@QAE_NPAX@Z
// partial score=0.9 date=2026-10-02
// cl: /O1 /EHsc /D_STLP_NO_EXCEPTIONS /MD /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_CRTIMP= /D_BFME_RETAIL_TREE_INSERT_LAYOUT
// stlport
// ?rva004E9600@Rva004E9600@@QAE_NPAX@Z @0x004E9600 42B map<int,int> contains via rowed _M_find 0x00388F63 key at arg+0x54 caller 0x002A8B24
#include <map>

class Rva004E9600
{
public:
    _STL::map<int, int, _STL::less<int>, _STL::allocator<_STL::pair<const int, int> > > m_map;
    bool rva004E9600(void *p);
};

// ?rva004E9600@Rva004E9600@@QAE_NPAX@Z present-unmatched
bool Rva004E9600::rva004E9600(void *p)
{
    if (p) {
        int key = *(int *)((char *)p + 0x54);
        return m_map.find(key) != m_map.end();
    }
    return false;
}
