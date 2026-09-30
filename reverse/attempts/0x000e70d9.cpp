// ?rva000E70D9@Rva000E70D9@@QAEXH@Z
// partial score=0.91 date=2026-09-30
// ?rva000E70D9@Rva000E70D9@@QAEXH@Z
// partial score=0.91 date=2026-09-30
// cl: /O1 /MD /arch:SSE
//
// ?rva000E70D9@Rva000E70D9@@QAEXH@Z, retail 0x000E70D9, 103 bytes.
// Loop over 0xA0-stride array clearing entries whose id matches the arg:
// zero three floats, set field to -2, zero three floats, set last to 1.0f,
// set dirty at +0x4FB5C; count at +0x4FB58.
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

void Rva000E70D9::rva000E70D9(int id)
{
	for (int i = 0; i < m_count; ++i) {
		if (m_elems[i].m_id58 == id) {
			float one = g_Va00BBB8D8;
			m_elems[i].f00 = 0.0f;
			m_elems[i].f04 = 0.0f;
			m_elems[i].f08 = 0.0f;
			m_elems[i].m_field40 = -2;
			m_elems[i].m_f48 = 0.0f;
			m_elems[i].m_f4C = 0.0f;
			m_elems[i].m_f50 = 0.0f;
			m_elems[i].m_f54 = one;
			m_dirty = 1;
		}
	}
}
