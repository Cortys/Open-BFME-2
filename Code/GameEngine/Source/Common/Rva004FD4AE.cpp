// cl: /O1 /GX /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// ?rva004FD4AE@Rva004FD4AE@@QAEXPBVModuleData@@@Z @0x004FD4AE 19B.
// Vector<ModuleData*> push_back at this+0x98.
// Evidence: unlock lane unblocks 0x0059E6D3; abuts 0x004FD448; rowed push_back
// 0x004DFCB0; neighbours carry /O1 /GX /MD.
#include <vector>

class ModuleData;

class Rva004FD4AE {
public:
    void rva004FD4AE(const ModuleData *p);
private:
    char m_pad00[0x98];
    _STL::vector<const ModuleData *> m_vec;
};

void Rva004FD4AE::rva004FD4AE(const ModuleData *p)
{
    m_vec.push_back(p);
}
