// cl: /O1 /EHsc /MD /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_CRTIMP= /D_BFME_RETAIL_TREE_INSERT_LAYOUT
// stlport
//
// ?rva00289218@Rva00289218@@QAEXPBVModuleData@@@Z, retail 0x00289218, 16 bytes.
//
// Forwards a ModuleData pointer to the vector<const ModuleData*> at +0x14
// through the rowed ModuleFactory push_back at 0x004DFCB0. Same 16-byte
// lea-push-add-call shape as the rowed list/vector push_back twins. Identity:
// unlock lane, thiscall (reads ecx), callers at 0x002892CF and 0x0052D0F8;
// owner class unproven so honest Rva address name.
#include <vector>
class ModuleData;
typedef _STL::vector<const ModuleData *, _STL::allocator<const ModuleData *> > ModuleDataVec;
class Rva00289218 {
    char m_pad[20];
    ModuleDataVec m_vec;
public:
    void rva00289218(const ModuleData *p);
};
void Rva00289218::rva00289218(const ModuleData *p)
{
    m_vec.push_back(p);
}
