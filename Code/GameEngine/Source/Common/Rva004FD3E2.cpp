// cl: /O1 /GX /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// ?rva004FD3E2@Rva004FD3E2@@QAEXPBVModuleData@@@Z @0x004FD3E2 102B.
// Multimap<int int> insert per int plus vector<ModuleData*> push_back.
// Evidence: unlock lane unblocks 0x004FD77C TeamDefeatCondition ParseINI;
// caller 0x004FD7B5 passes new Rva004FCD49 0x14 with vector<int> at +4 in push
// and holder in ecx; map at this+0x5c via rowed insert_equal 0x004FF876;
// vector at this+0x80 via rowed push_back 0x004DFCB0; same 0x24 spacing as
// siblings 0x004FD37F 0x50/0x74 and 0x004FD448 0x68/0x8c; neighbours carry
// /O1 /GX /MD.
#include <vector>
#include <map>

class ModuleData;

struct Rva004FCD49Vec {
    void *vtbl;
    _STL::vector<int> m_vec;
    int m_10;
};

class Rva004FD3E2 {
public:
    void rva004FD3E2(const ModuleData *p);
private:
    char m_pad00[0x5c];
    _STL::multimap<int, int> m_map;
    char m_pad1[0x80 - 0x5c - sizeof(_STL::multimap<int, int>)];
    _STL::vector<const ModuleData *> m_vec;
};

void Rva004FD3E2::rva004FD3E2(const ModuleData *p)
{
    if (!p)
        return;
    const _STL::vector<int> &vec = ((const Rva004FCD49Vec *)p)->m_vec;
    for (unsigned int i = 0; i < vec.size(); ++i) {
        int v = vec[i];
        m_map.insert(_STL::multimap<int, int>::value_type(v, (int)p));
    }
    m_vec.push_back(p);
}
