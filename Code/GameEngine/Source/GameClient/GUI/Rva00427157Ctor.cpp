// cl: /O1 /DNDEBUG /MD /EHsc /D_STLP_USE_STATIC_LIB /Ireference/shims/bfme2_ascii /Ireference/shims/bfme_windowvideo /Ireference/open-bfme-1/Code/GameEngine/Source/Common/System /Ireference/open-bfme-1/Code/GameEngine/Source/GameClient /Ireference/open-bfme-1/Code/GameEngine/Include/Precompiled /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib
// ??0Rva00427157@@QAE@ABVAsciiString@@PBV0@@Z @0x00427157 62B ctor copies AsciiString at +0 via rowed StringBase copy 0x000365F0 fills 8 floats at +4 with 1.0f if src null else copies 8 floats from src+4 caller 0x004273FF
#include "ascii_string.h"

class Rva00427157
{
public:
	Rva00427157(const AsciiString &name, const Rva00427157 *src);
private:
	AsciiString m_name;
	float m_vals[8];
};

Rva00427157::Rva00427157(const AsciiString &name, const Rva00427157 *src) : m_name(name)
{
	if (!src) {
		for (int i = 0; i < 8; ++i)
			m_vals[i] = 1.0f;
	} else {
		for (int i = 0; i < 8; ++i)
			m_vals[i] = src->m_vals[i];
	}
}
