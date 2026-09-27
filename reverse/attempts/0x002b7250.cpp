// ?rva002B7250@Rva002B7250@@QAEXPAVCreateAHeroData@@@Z
// partial score=0.95 date=2026-09-27
// ?rva002B7250@Rva002B7250@@QAEXPAVCreateAHeroData@@@Z
// partial score=0.95 date=2026-09-27
// cl: /O1 /DNDEBUG /DWIN32 /MD /EHsc /D_STLP_USE_STATIC_LIB /D_CRTIMP= /Ireference/shims/bfmealloc
// stlport
#include <vector>
#include <algorithm>

class CreateAHeroData;
struct BfmeE12 { float x, y, z; };
struct BfmeE16 { float x, y, z, w; };

// ?rva002B7250@Rva002B7250@@QAEXPAVCreateAHeroData@@@Z present-unmatched
class Rva002B7250 {
public:
    void rva002B7250(CreateAHeroData *v);
private:
    _STL::vector<void *> m_vec;
    unsigned int m_selected;
};

void Rva002B7250::rva002B7250(CreateAHeroData *v)
{
    CreateAHeroData **b = (CreateAHeroData **)m_vec.begin();
    CreateAHeroData **e = (CreateAHeroData **)m_vec.end();
    CreateAHeroData **it = _STL::find(b, e, v);
    if (it != e) {
        if (m_selected != (unsigned int)-1) {
            unsigned int idx = (unsigned int)(it - b);
            if (idx < m_selected)
                --m_selected;
        }
        m_vec.erase((void **)it);
        if (m_vec.empty()) {
            _STL::vector<BfmeE16> tmp((_STL::allocator<BfmeE16>()));
            (( _STL::vector<BfmeE12> &)*( _STL::vector<BfmeE12> *)&tmp).swap(( _STL::vector<BfmeE12> &)m_vec);
        }
    }
}
