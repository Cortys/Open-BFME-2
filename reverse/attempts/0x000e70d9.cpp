// ?rva000E70D9@Rva000E70D9@@QAEXH@Z
// partial score=0.98 date=2026-10-03
// cl: /O1 /MD /G7 /arch:SSE
// ?rva000E70D9@Rva000E70D9@@QAEXH@Z 0x000E70D9 103B
// Loop over 0xA0-stride array clearing entries whose id matches the arg:
// zero three floats, set field to -2, zero three floats, set last to 1.0f,
// set dirty at +0x4FB5C; count at +0x4FB58. Cursor is &elem.f08 (base
// 0x1960) so retail lea matches; id at +0x50, stores via -8/-4/0.
// Evidence: retail lea/add stride plus caller at 0x000E76A0 passing id at
// +0x19B0 and touching +0x1998; sibling Rva000E76B8 layout; float 1.0 via
// g_Va00BBB8D8.
extern float g_Va00BBB8D8;

struct Rva000E70D9Elem
{
	float f00;
	float f04;
	float f08;
	unsigned char m_pad0C[0x34];
	int m_field40;
	unsigned char m_flag44;
	unsigned char m_pad45[3];
	float m_f48;
	float m_f4C;
	float m_f50;
	float m_f54;
	int m_id58;
	unsigned char m_tail5C[0x44];
};

class Rva000E70D9
{
public:
	void rva000E70D9(int id);
	char m_pad[0x1958];
	Rva000E70D9Elem m_elems[1999];
	char m_gap[0xA0];
	int m_count;
	unsigned char m_dirty;
};

// ?rva000E70D9@Rva000E70D9@@QAEXH@Z present-unmatched
void Rva000E70D9::rva000E70D9(int id)
{
	char *base = (char *)this;
	float z = 0.0f;
	float *f = (float *)(base + 0x1960);
	for (int i = 0; i < m_count; ++i, f += 0x28) {
		if (((int *)f)[20] != id)
			continue;
		float one = g_Va00BBB8D8;
		f[-2] = z;
		f[-1] = z;
		f[0] = z;
		((int *)f)[14] = -2;
		f[16] = z;
		f[17] = z;
		f[18] = z;
		f[19] = one;
		m_dirty = 1;
	}
}
