// cl: /O1 /arch:SSE /MD
// ?rva005B02B5@Rva005B02B5@@QAEXXZ @0x005B02B5 72B
// ?rva005B02FD@Rva005B02B5@@QAEXXZ @0x005B02FD 77B sibling increment plus max-cap
// Evidence: callers 0x00513929/0x0051393E and 0x005B2044/0x005B2062; callee ?rva00232683@AIPlayer@@QAE_NXZ rowed;
// globals g_009FE720 INV g_00BC7838 from packet; float at +0x16c decremented then clamped to 0.
extern class Rva0025CEEFHost *g_009FE720;
extern "C" float INV;
extern float g_00BC7838;
extern float g_Va00BBB8D8;

class AIPlayer
{
public:
	bool rva00232683();
};

class Rva005B02B5
{
public:
	void rva005B02B5();
	void rva005B02FD();
private:
	char m_pad[0x16c];
	float m_val;
};

void Rva005B02B5::rva005B02B5()
{
	bool active = ((AIPlayer *)g_009FE720)->rva00232683();
	float dec = active ? INV : g_00BC7838;
	float v = m_val - dec;
	m_val = v;
	if (v < 0.0f)
		m_val = 0.0f;
}

void Rva005B02B5::rva005B02FD()
{
	bool active = ((AIPlayer *)g_009FE720)->rva00232683();
	float dec = active ? INV : g_00BC7838;
	float v = m_val + dec;
	float cap = g_Va00BBB8D8;
	m_val = v;
	if (v > cap)
		m_val = cap;
}
