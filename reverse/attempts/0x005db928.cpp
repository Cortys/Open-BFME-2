// ?rva005DB928@Elem005DB98E@@QAEMXZ
// partial score=0.93 date=2026-09-29
// ?rva005DB928@Elem005DB98E@@QAEMXZ
// partial score=0.93 date=2026-09-29
// cl: /O1 /MD /arch:SSE
// ?rva005DB928@Elem005DB98E@@QAEMXZ 0x005DB928 51B
// Falloff: if m_08 <= 1.0 return 0.0 else max(m_08-m_0C-1.0,0)/m_08.
// Evidence: caller 0x5DB96B (same this as 0x5DB95B); globals 1.0 at 0xBBB8D8 0.0 at 0xBBAEAC.
extern float g_Va00BBB8D8;
extern float g_Va00BBAEAC;

struct Elem005DB98E
{
	int m_00;
	float m_04;
	float m_08;
	float m_0C;
	unsigned long m_10;
	char m_14[4];
public:
	float rva005DB928();
};

float Elem005DB98E::rva005DB928()
{
	if (m_08 <= g_Va00BBB8D8)
		return g_Va00BBAEAC;
	double t = (double)m_08 - (double)m_0C - (double)g_Va00BBB8D8;
	if (t < 0.0)
		t = 0.0;
	t /= m_08;
	return (float)t;
}
