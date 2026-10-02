// ?rva0031912E@Rva0031912E@@QAEHXZ
// partial score=0.93 date=2026-10-02
// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD /EHsc
// ?rva0031912E@Rva0031912E@@QAEHXZ, retail 0x0031912E, 43 bytes.
// Unlock lane predicate: AsciiString at +0x18 empty check via rowed
// StringBase<char>::isEmpty 0x00001E2F, then diff of dwords at +0x40/+0x44
// of ptr at +0x78 masked with ~7. Callers 0x002B4CAF 0x00319621 0x003FDD30.
#include "ascii_string.h"

struct Rva0031912EInner
{
	char m_pad[0x40];
	int m_40;
	int m_44;
};

class Rva0031912E
{
public:
	int rva0031912E();
private:
	char m_pad[0x18];
	AsciiString m_str;
	char m_pad2[0x78 - 0x1C];
	Rva0031912EInner *m_78;
};

// ?rva0031912E@Rva0031912E@@QAEHXZ present-unmatched
int Rva0031912E::rva0031912E()
{
	if (((const StringBase<char> *)&m_str)->isEmpty() != 0) {
		Rva0031912EInner *inner = m_78;
		int v = inner->m_44;
		int *p = &inner->m_40;
		if (((v - *p) & 0xFFFFFFF8) == 0)
			return 1;
	}
	return 0;
}
