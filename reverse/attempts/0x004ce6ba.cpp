// ?rva004CE6BA@Rva004CE6BA@@QAEXXZ
// partial score=0.88 date=2026-09-29
// ?rva004CE6BA@Rva004CE6BA@@QAEXXZ
// partial score=0.88 date=2026-09-29
// cl: /O1 /MD /arch:SSE
//
// ?rva004CE6BA@Rva004CE6BA@@QAEXXZ, retail 0x004CE6BA 42B.
// Leaf: init 16B via global int doubled plus global float.
// Caller 0x253E50, prev 0x4CE56D xfer next 0x4CE6E4 xfer.

extern int g_009BA4E4;
extern float g_007BB9AC;

class Rva004CE6BA
{
public:
	void rva004CE6BA();
	int m_0;
	int m_4;
	float m_8;
	float m_C;
};

// ?rva004CE6BA@Rva004CE6BA@@QAEXXZ present-unmatched
void Rva004CE6BA::rva004CE6BA()
{
	float f = g_007BB9AC;
	int t1 = g_009BA4E4;
	t1 += t1;
	m_0 = t1;
	int t2 = g_009BA4E4;
	t2 += t2;
	m_4 = t2;
	m_8 = f;
	m_C = f;
}
