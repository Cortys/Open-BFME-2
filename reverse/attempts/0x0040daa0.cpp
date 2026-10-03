// ?rva0040DAA0@Rva0040DAA0@@QBEPAXABV?$StringBase@D@@PAH@Z
// partial score=0.93 date=2026-10-03
// ?rva0040DAA0@Rva0040DAA0@@QBEPAXABV?$StringBase@D@@PAH@Z
// partial score=0.93 date=2026-10-01
// cl: /O1 /Ireference/shims/bfme2_ascii
// ?rva0040DAA0@Rva0040DAA0@@QBEPAXABV?$StringBase@D@@PAH@Z @0x0040DAA0 80B linear find by string over 8-byte entries at +0x40/+0x44; returns entry target and optional index via compare row 0x000069D6
#include "ascii_string.h"

struct Rva0040DAA0Target
{
	char m_pad00[4];
	StringBase<char> m_name;
};

struct Rva0040DAA0Entry
{
	int m_first;
	Rva0040DAA0Target *m_second;
};

class Rva0040DAA0
{
public:
	void *rva0040DAA0(const StringBase<char> &name, int *indexOut) const;
private:
	char m_pad[0x40];
	Rva0040DAA0Entry *m_begin;
	Rva0040DAA0Entry *m_end;
};

// ?rva0040DAA0@Rva0040DAA0@@QBEPAXABV?$StringBase@D@@PAH@Z present-unmatched
void *Rva0040DAA0::rva0040DAA0(const StringBase<char> &name, int *indexOut) const
{
	for (unsigned int i = 0; i < (unsigned int)(m_end - m_begin); ++i) {
		Rva0040DAA0Target *t = m_begin[i].m_second;
		if (t->m_name.compare(name) == 0) {
			if (indexOut)
				*indexOut = (int)i;
			return m_begin[i].m_second;
		}
	}
	return 0;
}
