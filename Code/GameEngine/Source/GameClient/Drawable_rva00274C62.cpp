// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD /EHsc
//
// ?rva00274C62@Drawable@@QAE_NPAVAsciiString@@@Z, retail 0x00274C62, 38 bytes.
// Drawable AsciiString slot at this+0x348 via rowed isEmpty plus rowed set.
// Evidence: caller 0x002765ED plus 0x0029EE52 plus 0x004E7591 plus sibling
// Rva0029B4C4 ascii pattern plus prev Drawable 0x00274445 in same page.
//
#include "ascii_string.h"

class Drawable
{
public:
	bool rva00274C62(AsciiString *dst);
	bool rva00274CB2(AsciiString *dst);
private:
	unsigned char m_pad[0x348];
	AsciiString m_s348;
	AsciiString m_s34C;
};

bool Drawable::rva00274C62(AsciiString *dst)
{
	if (!m_s348.isEmpty()) {
		dst->set(m_s348);
		return true;
	}
	return false;
}

bool Drawable::rva00274CB2(AsciiString *dst)
{
	if (!m_s34C.isEmpty()) {
		dst->set(m_s34C);
		return true;
	}
	return false;
}
