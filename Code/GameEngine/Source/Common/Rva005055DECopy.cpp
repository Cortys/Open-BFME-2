// cl: /O1 /MD /D_STLP_USE_STATIC_LIB /D_CRTIMP= /Ireference/shims/bfmealloc
// stlport
// ?rva005055DE@Rva005055DE@@QAEXXZ, retail 0x005055DE, 40 bytes.
// Evidence: copies ModuleData ptr range from global g_00E0311C vec at +0xc via rowed push_back 0x004DFCB0 into vec at +0x14; caller jmp 0x0050590C.
#include <vector>

class ModuleData;

struct Rva005055DESrc
{
	char m_00[0xc];
	_STL::vector<const ModuleData *> m_0C;
};

extern Rva005055DESrc *g_00E0311C;

class Rva005055DE
{
	char m_00[0x14];
	_STL::vector<const ModuleData *> m_14;
public:
	void rva005055DE();
};

void Rva005055DE::rva005055DE()
{
	_STL::vector<const ModuleData *> &src = g_00E0311C->m_0C;
	for (_STL::vector<const ModuleData *>::iterator it = src.begin(); it != src.end(); ++it)
		m_14.push_back(*it);
}
