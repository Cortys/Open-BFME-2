// cl: /Ireference/shims/bfme2_ascii /O1 /MD /EHsc /G7
// ?rva002DACF4@Rva002DACF4@@QAE?AVAsciiString@@HH@Z @0x002DACF4 37B: indexed AsciiString getter via imul-3.
// Evidence: copy ctor row 0x000365F0 ret 0xC with this plus imul-3 lea 0x74 callers 0x002DB64E 0x00456AC5 neighbour Rva002DAF2BSet /O1 /G7.
#include "ascii_string.h"

class Rva002DACF4
{
public:
	AsciiString rva002DACF4(int a, int b);
	void rva002DAEED(int a, int b, AsciiString s);
private:
	char m_pad[0x74];
	AsciiString m_arr[64];
};
AsciiString Rva002DACF4::rva002DACF4(int a, int b)
{
	return m_arr[a * 3 + b];
}
void Rva002DACF4::rva002DAEED(int a, int b, AsciiString s)
{
	AsciiString &slot = m_arr[a * 3 + b];
	slot = s;
}
