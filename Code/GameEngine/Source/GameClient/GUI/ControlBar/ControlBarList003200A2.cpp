// cl: /O1 /Ireference/shims/ini_bfme2 /DNDEBUG /MD /EHsc /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/open-bfme-1/Code/GameEngine/Source/Common/System /Ireference/open-bfme-1/Code/GameEngine/Include /Ireference/open-bfme-1/Code/GameEngine/Include/Precompiled /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib
// stlport
// ?rva003200A2@Rva003200A2@@QAEXH@Z @0x003200A2 26B.
// Adds non-zero int to list at +0x170. Caller 0x003201A9 passes INI-parsed
// object. push_back 0x0005548F rowed.
#include <list>

class Rva003200A2
{
public:
	void rva003200A2(int value);
private:
	char m_pad[0x170];
	std::list<int> m_list;
};

void Rva003200A2::rva003200A2(int value)
{
	if (value == 0)
		return;
	m_list.push_back(value);
}
