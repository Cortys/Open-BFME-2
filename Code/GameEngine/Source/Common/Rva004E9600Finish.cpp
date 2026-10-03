// cl: /O1 /EHsc /D_STLP_NO_EXCEPTIONS /MD /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_CRTIMP= /D_BFME_RETAIL_TREE_INSERT_LAYOUT
// stlport
//
// ?rva004E9600@Rva004E9600@@QAE_NPAX@Z @0x004E9600 42B
// Map<int int> contains-check keyed by the int at arg+0x54 via the rowed
// _M_find 0x00388F63; null arg or a miss returns false. The map sits at +0,
// the layout the matched Rva004E962ACtor.cpp fixes. Caller 0x002A8B24.
#include <map>

class Rva004E9600
{
public:
    _STL::map<int, int, _STL::less<int>, _STL::allocator<_STL::pair<const int, int> > > m_map;
    bool rva004E9600(void *p);
};

bool Rva004E9600::rva004E9600(void *p)
{
    bool result;
    if (p) {
        int key = *(int *)((char *)p + 0x54);
        result = m_map.find(key) != m_map.end();
    } else {
        result = false;
    }
    return result;
}
