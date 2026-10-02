// ?rva00072988@Rva00072988@@QAEEHH@Z
// partial score=0.96 date=2026-10-02
// cl: /O1 /G7 /MD
// ?rva00072988@Rva00072988@@QAEEHH@Z, retail 0x00072988 68B.
// Unlock body calling 0x00073CC0. Grid lookup with width at +0 height at +4
// data at +0x18 as 2-byte cells. Bounds-checks both args returning 0.
// Loads cell byte and masks low nibble then scales by float at 0x00BC653C
// via fild/fmul/__ftol2. Callers at 0x00073FFB. Evidence: ret-8 thiscall
// with two int args and byte return plus layout from neighbours.
extern float g_00BC653C;

struct Rva00072988Cell
{
	unsigned char m_lo;
	unsigned char m_hi;
};

class Rva00072988
{
public:
	unsigned char rva00072988(int x, int y);
private:
	int m_width;
	int m_height;
	char m_pad[16];
	unsigned char *m_data;
};

// ?rva00072988@Rva00072988@@QAEEHH@Z present-unmatched
unsigned char Rva00072988::rva00072988(int x, int y)
{
	if (!m_data)
		return 0;
	if (x >= m_width || y >= m_height)
		return 0;
	int v = y * m_width + x;
	v = m_data[v * 2] & 15;
	float f = (float)v;
	f *= g_00BC653C;
	return (unsigned char)(int)f;
}
