// ?rva0040C9A4@Rva0040C985@@QAEMXZ
// partial score=0.96 date=2026-10-03
// cl: /O1
class Rva00DFE78C { public: char m_pad[0x40]; int m_40; };
class GameLogic;
extern GameLogic *TheGameLogic;
class Rva0040C985 { public: void rva0040C985(int x); float rva0040C9A4();
private: char m_pad[0x24]; int m_24; int m_28; int m_2C; int m_30; int m_34; int m_38; };
float Rva0040C985::rva0040C9A4()
{
int denom = m_34 - m_38;
	if (denom <= 0)
		denom = 1;
	unsigned num = (unsigned)(((Rva00DFE78C *)TheGameLogic)->m_40 - m_38);
	float fd = (float)denom;
	float fn = (float)num;
	float f = fn / fd;
	if (f > 1.0f)
		f = 1.0f;
	return f;
}
