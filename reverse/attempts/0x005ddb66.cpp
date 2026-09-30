// ?rva005DDB66@Rva005DDB66@@QAEXIABUBfmeStringRecord005DDD40@@_N@Z
// partial score=0.95 date=2026-09-30
// ?rva005DDB66@Rva005DDB66@@QAEXIABUBfmeStringRecord005DDD40@@_N@Z
// partial score=0.95 date=2026-09-30
// cl: /O1 /Ob2 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /arch:SSE
//
// ?rva005DDB66@Rva005DDB66@@QAEXIABUBfmeStringRecord005DDD40@@_N@Z,
// retail 0x005DDB66, 69 bytes. Unlock lane: bounded index assign over
// 8-byte elements (stride 8, sar 3). Copies src record via rowed operator=
// 0x005DD6B6 into begin[index] when index < count, sets +0x14 to 1, and when
// the bool arg is set updates float at +0x10 from src+4 when greater
// (movss/comiss/jbe). Layout: +0x4 begin +0x8 end +0x10 float +0x14 flag.
// Flags copy neighbour Rva005DD772Ctor for SSE idioms.

struct BfmeStringRecord005DDD40
{
	int m_00;
	float m_04;
	BfmeStringRecord005DDD40 &operator=(const BfmeStringRecord005DDD40 &other);
};

class Rva005DDB66
{
public:
	void rva005DDB66(unsigned int index, const BfmeStringRecord005DDD40 &src, bool update);

private:
	char m_pad00[0x4];
	BfmeStringRecord005DDD40 *m_begin;
	BfmeStringRecord005DDD40 *m_end;
	char m_pad0C[0x4];
	float m_10;
	bool m_14;
};

// ?rva005DDB66@Rva005DDB66@@QAEXIABUBfmeStringRecord005DDD40@@_N@Z present-unmatched
void Rva005DDB66::rva005DDB66(unsigned int index, const BfmeStringRecord005DDD40 &src, bool update)
{
	const float *tp = &src.m_04;
	if (index >= (unsigned int)(m_end - m_begin))
		return;
	m_begin[index] = src;
	m_14 = true;
	if (!update)
		return;
	float v = tp[0];
	if (v > m_10)
		m_10 = v;
}
