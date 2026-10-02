// ?rva003A0E08@Rva003A0E08@@QAEXABVRva0039D769@@@Z
// partial score=0.97 date=2026-10-02
// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD
//
// ?rva003A0E08@Rva003A0E08@@QAEXABVRva0039D769@@@Z @0x003A0E08 102B.
// Evidence: unlock lane; same 0x18 stride AsciiString m10+int m14 search as 0x003A0D62 via StringBase compare row;
// subtracts m00/m04 and total at +0x2D4 on match, count at +0x1D8, no add-new path.

#include "ascii_string.h"

class Rva0039D769
{
public:
	Rva0039D769 &operator=(const Rva0039D769 &rhs);
	int m00;
	int m04;
	int m08;
	AsciiString m0C;
	AsciiString m10;
	int m14;
};

class Rva003A0E08
{
public:
	void rva003A0E08(const Rva0039D769 &src);
	char m_pad[0x12c];
	int m_12C;
	int m_130_first;
	char m_pad134[0x1D8 - 0x134];
	int m_count1D8;
	char m_pad1DC[0x2D4 - 0x1DC];
	int m_total2D4;
};

// ?rva003A0E08@Rva003A0E08@@QAEXABVRva0039D769@@@Z present-unmatched
void Rva003A0E08::rva003A0E08(const Rva0039D769 &src)
{
	Rva0039D769 *items = (Rva0039D769 *)((char *)this + 0x130);
	int i = 0;
	if (m_count1D8 <= 0)
		return;
	{
		Rva0039D769 *p = items;
		do {
			if (((const StringBase<char> &)p->m10).compare((const StringBase<char> &)src.m10) == 0 && p->m14 == src.m14)
				goto found;
			++i;
			p = (Rva0039D769 *)((char *)p + 0x18);
		} while (i < m_count1D8);
		return;
	}
found:
	i *= 0x18;
	{
		char *base = (char *)(i + (char *)this);
		*(int *)(base + 0x130) -= src.m00;
		*(int *)(base + 0x134) -= src.m04;
		m_total2D4 -= src.m00;
	}
}
