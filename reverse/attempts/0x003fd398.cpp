// ?rva003FD398@Rva003FD398@@QAEXXZ
// partial score=0.92 date=2026-09-30
// ?rva003FD398@Rva003FD398@@QAEXXZ
// partial score=0.92 date=2026-09-30
// cl: /O1 /DNDEBUG /MD /GX /arch:SSE
// ?rva003FD398@Rva003FD398@@QAEXXZ @0x003FD398 47B
// Zeroes floats at +0x00/+0x04/+0x08/+0x0C via xorps/movss, int at +0x18
// via and [m],0, then sets +0x10/+0x14 from shared float g_Va007C26F0.
// Callers at 0x004E1E62 0x00503FE6 0x00504071 0x0050464E. Unblocks
// 0x0050406E 0x00503FD1 0x004E1E35.
extern float g_Va007C26F0;

class Rva003FD398
{
public:
	void rva003FD398();
private:
	float m_00;
	float m_04;
	float m_08;
	float m_0c;
	float m_10;
	float m_14;
	int m_18;
};

void Rva003FD398::rva003FD398()
{
	m_18 = 0;
	m_00 = 0.0f;
	m_04 = 0.0f;
	m_08 = 0.0f;
	m_0c = 0.0f;
	m_10 = g_Va007C26F0;
	m_14 = m_10;
}
