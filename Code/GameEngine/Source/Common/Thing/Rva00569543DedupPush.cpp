// cl: /O1 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
// RVA 0x00569543 dedup push into vector<ModuleData*> at +0x58 via rowed push_back @0x004DFCB0.
class ModuleData;
#include <vector>
class Rva00569543 {
	char m_pad[0x58];
	_STL::vector<const ModuleData *> m_mods;
public:
	void rva00569543(const ModuleData *m);
};
void Rva00569543::rva00569543(const ModuleData *m)
{
	for (_STL::vector<const ModuleData *>::iterator it = m_mods.begin(); it != m_mods.end(); ++it) {
		if (*it == m)
			return;
	}
	m_mods.push_back(m);
}
