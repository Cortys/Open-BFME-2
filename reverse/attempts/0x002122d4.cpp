// ?rva002122D4@Rva002122D4@@QAEHH@Z
// partial score=0.93 date=2026-09-29
// ?rva002122D4@Rva002122D4@@QAEHH@Z
// partial score=0.93 date=2026-09-29
// cl: /O1 /Ob2 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB
// stlport

// ?rva002122D4@Rva002122D4@@QAEHH@Z, RVA 0x002122D4, 41B. Unlock lane:
// Map<int int> lookup at this+0x2B4 via rowed _M_find 0x00388F63 with
// key-zero guard returning 0; found returns second at node+0x14 else 0.
// Callers at 0x00212313/0x002137CD. Same pattern as Rva0046ACF6MapFind
// (34B) plus the zero-key early-out. Owner unknown so honest names.
#include <map>
class Rva002122D4
{
public:
	int rva002122D4(int key);
private:
	char m_pad[0x2B4];
	_STL::map<int, int> m_map;
};

// ?rva002122D4@Rva002122D4@@QAEHH@Z present-unmatched
int Rva002122D4::rva002122D4(int key)
{
	if (key == 0)
		return 0;
	_STL::map<int, int>::iterator it = m_map.find(key);
	if (it != m_map.end())
		return (*it).second;
	return 0;
}
