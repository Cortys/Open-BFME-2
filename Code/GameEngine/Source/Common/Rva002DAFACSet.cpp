// cl: /Ireference/shims/bfme2_ascii /O1 /MD /EHsc /G7
// ?rva002DAFAC@Rva002DAFAC@@QAEXHHVAsciiString@@@Z retail 0x002DAFAC 64 bytes.
// AsciiString by-value setter into array at +0x0 via (a+0x17)*3+b imul-3,
// via rowed set 0x000366F0 plus releaseBuffer 0x00036410 plus EH prolog.
// Twin of Rva002DAF6CSet.cpp (64B at +0x0 with bias 0x13) with bias 0x17.
// Evidence: add eax,0x17 plus imul-3 plus lea ecx,0x0 plus ret 0xC
// plus callers 0x002DB18A 0x002DB83B plus same EH data VA 0x00B77C6F.
#include "ascii_string.h"
class Rva002DAFAC
{
public:
	void rva002DAFAC(int a, int b, AsciiString c);
private:
	AsciiString m_arr[64];
};
void Rva002DAFAC::rva002DAFAC(int a, int b, AsciiString c)
{
	AsciiString &slot = m_arr[(a + 0x17) * 3 + b];
	slot = c;
}
