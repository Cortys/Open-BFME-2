// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// ?rva00423A68@Rva00423A68@@QAEXPBVModuleData@@@Z retail 0x00423A68 13B
// Thin push_back forwarder over a vector<ModuleData*> at +0: lea the stack
// arg and tail-call the rowed push_back at 0x004DFCB0. Evidence: 3 callers
// plus STLport neighbours with same bfmealloc flags.
#include <vector>

class ModuleData;

class Rva00423A68
{
public:
	void rva00423A68(const ModuleData *p);
private:
	_STL::vector<const ModuleData *> m_vec;
};

void Rva00423A68::rva00423A68(const ModuleData *p)
{
	m_vec.push_back(p);
}
