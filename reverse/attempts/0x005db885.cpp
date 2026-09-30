// ?rva005DB885@Elem005DB98E@@QAEXH@Z
// partial score=0.9 date=2026-09-30
// ?rva005DB885@Elem005DB98E@@QAEXH@Z
// partial score=0.9 date=2026-09-30
// cl: /O1 /arch:SSE /MD /DNDEBUG /Oy-
// ?rva005DB885@Elem005DB98E@@QAEXH@Z @0x005DB885 95B
// Elem time smoothing: delta from timeGetTime, 0<delta<10000 gates float update of m_04/m_0C then m_10 stamp.
// Evidence: caller 0x005DBF09 passes eax from rva005DB98E as this with dword arg; same Elem005DB98E layout and IAT timeGetTime as next 0x005DB8F7.
extern "C" __declspec(dllimport) unsigned long __stdcall timeGetTime(void);
extern float g_00BBB8D8;
extern double g_00BC26F8;

struct Elem005DB98E
{
	int m_00;
	float m_04;
	float m_08;
	float m_0C;
	unsigned long m_10;
	char m_14[4];
public:
	void rva005DB885(int a);
};

void Elem005DB98E::rva005DB885(int a)
{
	unsigned long now = timeGetTime();
	a = (int)(now - (unsigned long)a);
	if (a >= 10000)
		return;
	if (a <= 0)
		return;
	m_04 = (float)((double)(m_0C * m_04) + (double)a * g_00BC26F8);
	m_0C += g_00BBB8D8;
	m_04 /= m_0C;
	m_10 = timeGetTime();
}
