// ?rva00504682@Rva00504682@@QAEXH@Z
// partial score=0.93 date=2026-10-03
// cl: /O1 /arch:SSE /MD
// ?rva00504682@Rva00504682@@QAEXH@Z @ 0x00504682 (46B):
// Leaf thiscall initializer. Stores the int arg at +0, 1 at +4, four
// zero floats at +8..+14 and zero bytes at +18/+19. Evidence: reads ecx;
// caller at 0x005051E7; SSE zero idiom needs /arch:SSE.
class Rva00504682
{
public:
	void rva00504682(int v);
private:
	int m_00;
	unsigned char m_04;
	char m_pad05[3];
	float m_08;
	float m_0C;
	float m_10;
	float m_14;
	unsigned char m_18;
	unsigned char m_19;
};

// ?rva00504682@Rva00504682@@QAEXH@Z present-unmatched
void Rva00504682::rva00504682(int v)
{
	m_00 = v;
	m_04 = 1;
	m_08 = 0.0f;
	m_0C = 0.0f;
	m_10 = 0.0f;
	m_14 = 0.0f;
	m_18 = 0;
	m_19 = 0;
}
