// ?rva003A0D62@Rva003A0D62@@QAEXABVRva0039D769@@@Z
// partial score=0.97 date=2026-10-03
// ?rva003A0D62@Rva003A0D62@@QAEXABVRva0039D769@@@Z
// partial score=0.95 date=2026-10-02
// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD
//
// ?rva003A0D62@Rva003A0D62@@QAEXABVRva0039D769@@@Z @0x003A0D62 166B.
// Evidence: unlock lane; 0x18 stride AsciiString m10+int m14 search via StringBase compare row;
// sum via 0x0039D5A9 assign via 0x0039D769; total at +0x2D4 count at +0x1D8 max 7.

#include "ascii_string.h"

class Rva0039D5A9
{
public:
	int rva0039D5A9();
	int m_00;
	int m_04;
	char m_pad08[0xAC - 0x08];
	int m_countAC;
};

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

class Rva003A0D62
{
public:
	void rva003A0D62(const Rva0039D769 &src);
	char m_pad[0x12c];
	Rva0039D5A9 m_sum;
	char m_pad2[0xf8];
	int m_total;
};

// ?rva003A0D62@Rva003A0D62@@QAEXABVRva0039D769@@@Z present-unmatched
void Rva003A0D62::rva003A0D62(const Rva0039D769 &src)
{
	Rva0039D769 *items = (Rva0039D769 *)((char *)this + 0x130);
	int i = 0;
	if (m_sum.m_countAC > 0)
	{
		Rva0039D769 *p = items;
		do {
			if (((const StringBase<char> &)p->m10).compare((const StringBase<char> &)src.m10) == 0 && p->m14 == src.m14)
				goto found;
			++i;
			p = (Rva0039D769 *)((char *)p + 0x18);
		} while (i < m_sum.m_countAC);
	}
	i = m_sum.m_countAC;
	if (i >= 7)
		return;
	{
		int sum = m_sum.rva0039D5A9();
		if (sum == 0)
			m_total = src.m00;
		else
			m_total += src.m00;
	}
	*(Rva0039D769 *)((char *)items + i * 0x18) = src;
	m_sum.m_countAC++;
	return;
found:
	{
		Rva0039D769 *f = (Rva0039D769 *)((char *)items + i * 0x18);
		f->m00 += src.m00;
		f->m04 += src.m04;
		m_total += src.m00;
	}
}
