// cl: /O1 /arch:SSE /MD
// ?rva005B02B5@Rva005B02B5@@QAEXXZ @0x005B02B5 72B
// Evidence: callers 0x00513929 and 0x005B2044; callee ?rva00232683@AIPlayer@@QAE_NXZ rowed;
// globals g_009FE720 INV g_00BC7838 from packet; float at +0x16c decremented then clamped to 0.
extern class Rva0025CEEFHost *g_009FE720;
extern "C" float INV;
extern float g_00BC7838;

class AIPlayer
{
public:
	bool rva00232683();
};

class Rva005B02B5
{
public:
	void rva005B02B5();
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
