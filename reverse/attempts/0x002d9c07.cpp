// ?rva002D9C07@Rva002D9C07@@QAEEXZ
// partial score=0.93 date=2026-09-28
// ?rva002D9C07@Rva002D9C07@@QAEEXZ
// partial score=0.93 date=2026-09-28
// cl: /O1 /DNDEBUG /MD
//
// ?rva002D9C07@Rva002D9C07@@QAEEXZ @0x002D9C07, 40B.
// Predicate reading outer byte at +0x4C and inner pointer at +0x8;
// inner int at +0xB0 and byte at +0x4C bit0. Callers at 0x002DA0A8
// (same-this forward) and 0x00059DCF (member +0x1C) prove the
// thiscall uchar shape. Honest address name; class identity unproven.
class Inner002D9C07
{
public:
	char m_pad4C[0x4C];
	unsigned char m_b4C; // +0x4C
	char m_padB0[0xB0 - 0x4D];
	int m_vB0; // +0xB0
};

class Rva002D9C07
{
public:
	unsigned char rva002D9C07();
private:
	char m_pad8[8];
	Inner002D9C07 *m_p8; // +0x08
	char m_pad4C[0x4C - 0x0C];
	unsigned char m_b4C; // +0x4C
};

unsigned char Rva002D9C07::rva002D9C07()
{
	Inner002D9C07 *p;
	return m_b4C == 0 && ((p = m_p8) == 0 || p->m_vB0 == 0 || p->m_vB0 == 3 || (p->m_b4C & 1) != 0);
}
