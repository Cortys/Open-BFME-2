// ?rva00240167@Rva00240167@@QAEPAVAsciiString@@V2@@Z
// partial score=0.93 date=2026-10-01
// ?rva00240167@Rva00240167@@QAEPAVAsciiString@@V2@@Z
// partial score=0.93 date=2026-10-01
// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD /EHsc
// ?rva00240167@Rva00240167@@QAEPAVAsciiString@@VAsciiString@@@Z @0x00240167 89B list at +0x1c0 find by AsciiString
#include "ascii_string.h"

struct Rva00240167Node
{
	Rva00240167Node *m_next;
	char m_pad4[4];
	AsciiString m_name;
};

class Rva00240167
{
public:
	AsciiString *rva00240167(AsciiString key);

	char m_pad[0x1C0];
	Rva00240167Node *m_1c0;
};

// ?rva00240167@Rva00240167@@QAEPAVAsciiString@@V2@@Z present-unmatched
AsciiString *Rva00240167::rva00240167(AsciiString key)
{
	Rva00240167Node *cur = m_1c0->m_next;
	if (cur == m_1c0)
		return 0;
	do {
		if (((const StringBase<char> *)&cur->m_name)->compare(*(const StringBase<char> *)&key) == 0)
			return &cur->m_name;
		cur = cur->m_next;
	} while (cur != m_1c0);
	return 0;
}
