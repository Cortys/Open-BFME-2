// cl: /O1 /DNDEBUG /MD /arch:SSE
// ?rva003605AF@Rva003605AF@@QAEXXZ, retail 0x003605AF, 38 bytes.
// Zeroes a 30x4 table of 16-byte elements (float + 3 ints) at +0x00.
// Evidence: unlock lane, neighbours ?clear@DFX@DamageFX (0x0036059C) and
// ?rva003605E3@DamageFX (0x003605E3); 0x1e=30 matches the 30 damage types;
// /O1 push/pop constants, and [m],0 zero idiom and movss float store.

struct Rva003605AFELEM
{
	float m_f;
	int m_a;
	int m_b;
	int m_c;
};

class Rva003605AF
{
public:
	void rva003605AF();

private:
	Rva003605AFELEM m_table[30][4];
};

void Rva003605AF::rva003605AF()
{
	for (int i = 0; i < 30; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			m_table[i][j].m_f = 0.0f;
			m_table[i][j].m_a = 0;
			m_table[i][j].m_b = 0;
			m_table[i][j].m_c = 0;
		}
	}
}
