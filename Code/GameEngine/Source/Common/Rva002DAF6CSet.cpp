// cl: /Ireference/shims/bfme2_ascii /O1 /MD /EHsc /G7
// ?rva002DAF6C@Rva002DAF6C@@QAEXHHVAsciiString@@@Z retail 0x002DAF6C 64 bytes.
// AsciiString by-value setter into array at +0x0 via (a+0x13)*3+b imul-3,
// via rowed set 0x000366F0 plus releaseBuffer 0x00036410 plus EH prolog.
// Twin of Rva002DAF2BSet.cpp (65B at +0xA4) with bias 0x13 and no pad.
// Evidence: add eax,0x13 plus imul-3 plus lea ecx,0x0 plus ret 0xC
// plus callers 0x002DB09B 0x002DB81E plus same EH data VA 0x00B77C6F.
class AsciiString;
#include "ascii_string.h"
class Rva002DAF6C
{
public:
	void rva002DAF6C(int a, int b, AsciiString c);
private:
	AsciiString m_arr[64];
};
void Rva002DAF6C::rva002DAF6C(int a, int b, AsciiString c)
{
	AsciiString &slot = m_arr[(a + 0x13) * 3 + b];
	slot = c;
}
