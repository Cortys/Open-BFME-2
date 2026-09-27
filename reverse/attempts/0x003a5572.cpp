// ?Rva003A5572@Rva003AED3E@@UAEXXZ
// partial score=0.97 date=2026-09-27
// ?Rva003A5572@Rva003AED3E@@UAEXXZ
// partial score=0.97 date=2026-09-27
// cl: /DNDEBUG /MD /GX- /O1 /Ob2 /arch:SSE
// ?Rva003A5572@Rva003AED3E@@UAEXXZ @0x003A5572 485B vslot1 of 0x0081C60C (Rva003AED3E) via BFME1 fxpswindmodule.cpp donor
#include <math.h>

extern float GetGameClientRandomValueReal(float lo, float hi, char *file, int line);

class Rva003AED3E
{
public:
	virtual ~Rva003AED3E();
	virtual void Rva003A5572();
	virtual void slot2();
	virtual void slot3();
private:
	char m_pad04[28];
	int m_at20;
	char m_at24[12];
	float m_at30;
	float m_at34;
	float m_at38;
	float m_at3C;
	float m_at40;
	float m_at44;
	float m_at48;
	float m_at4C;
	float m_at50;
	float m_at54;
	bool m_at58;
};

// ?Rva003A5572@Rva003AED3E@@UAEXXZ present-unmatched
void Rva003AED3E::Rva003A5572()
{
	const char *file = "C:\\projects\\bfme2patch103\\bfme2\\Code\\GameEngine\\Source\\GameClient\\System\\FXParticleSystem\\fxpswindmodule.cpp";
	switch (m_at20) {
	case 3:
		if (m_at34 == 0.0f)
			m_at34 = GetGameClientRandomValueReal(m_at38, m_at3C, (char *)file, 0x154);
		m_at30 += m_at34;
		if (m_at30 > 6.2831855f)
			m_at30 -= 6.2831855f;
		else if (m_at30 < 0.0f)
			m_at30 += 6.2831855f;
		break;
	case 2:
		{
			float lower = m_at40;
			float upper = m_at4C;
			float halfRange = (upper - lower) * 0.5f;
			float fabsInput = halfRange - m_at30 + lower;
			float fabsResult = (float)fabs(fabsInput);
			float speed = (1.0f - fabsResult / halfRange) * m_at34;
			if (speed < 0.005f)
				speed = 0.005f;
			if (m_at58) {
				m_at30 += speed;
				if (m_at30 >= upper) {
					m_at58 = false;
					m_at34 = GetGameClientRandomValueReal(m_at38, m_at3C, (char *)file, 0x120);
					m_at40 = GetGameClientRandomValueReal(m_at44, m_at48, (char *)file, 0x125);
					m_at4C = GetGameClientRandomValueReal(m_at50, m_at54, (char *)file, 0x128);
				}
			} else {
				m_at30 -= speed;
				if (m_at30 <= lower) {
					m_at58 = true;
					m_at34 = GetGameClientRandomValueReal(m_at38, m_at3C, (char *)file, 0x13C);
					m_at40 = GetGameClientRandomValueReal(m_at44, m_at48, (char *)file, 0x141);
					m_at4C = GetGameClientRandomValueReal(m_at50, m_at54, (char *)file, 0x144);
				}
			}
		}
		break;
	}
}
