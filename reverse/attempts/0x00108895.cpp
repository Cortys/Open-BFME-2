// ?rva00108895@Rva00108895@@QAEXXZ
// partial score=0.9 date=2026-09-30
// ?rva00108895@Rva00108895@@QAEXXZ
// partial score=0.90 date=2026-09-30
// cl: /O1 /MD /arch:SSE
//
// ?rva00108895@Rva00108895@@QAEXXZ @0x00108895 97B (ours 98B). Zeroing reset
// with SSE stores; const g_00BCF9B0 at +0x88..+0x90; 16x2 loop +0x94/+0xD4.
// 0 reg diffs; left: retail lea edi+stosd pair vs 2 movs, lea eax for float
// stores vs direct, push 0x10 late vs early. memset+/Oi gives stosd but
// regresses float CSE to 101-117B. Callers 0x0010BA3C/0x0010BA6C.
extern float g_00BCF9B0;

class Rva00108895
{
public:
	void rva00108895();
private:
	char m_pad00[0x68];
	int m_68;
	int m_6C;
	int m_70;
	unsigned char m_74;
	char m_pad75[3];
	float m_78;
	float m_7C;
	int m_80;
	unsigned char m_84;
	unsigned char m_85;
	char m_pad86[2];
	float m_88;
	float m_8C;
	float m_90;
	int m_94[16];
	int m_D4[16];
};

// ?rva00108895@Rva00108895@@QAEXXZ present-unmatched
void Rva00108895::rva00108895()
{
	m_68 = 0;
	m_6C = 0;
	m_78 = 0.0f;
	m_7C = 0.0f;
	float c = g_00BCF9B0;
	m_70 = 0;
	m_74 = 0;
	m_80 = 0;
	m_84 = 0;
	m_85 = 0;
	m_88 = c;
	m_8C = c;
	m_90 = c;
	for (int i = 0; i < 16; i++) {
		m_94[i] = 0;
		m_D4[i] = 0;
	}
}
