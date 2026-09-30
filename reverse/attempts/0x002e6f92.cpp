// ?rva002E6F92@Rva002E6F92@@QAEHHPAUIn002E6F92@@HH@Z
// partial score=0.9 date=2026-09-30
// ?rva002E6F92@Rva002E6F92@@QAEHHPAUIn002E6F92@@HH@Z
// partial score=0.90 date=2026-09-30
// cl: /O1 /G7 /arch:SSE
// ?rva002E6F92@Rva002E6F92@@QAEHHPAUIn002E6F92@@HH@Z, retail 0x002E6F92, 77 bytes.
// Float select on low nibble at input +0x0C: 7/1 scales two ints by 10 to
// +0x00/+0x04 with zero at +0x08 else byte 1 at +0x0C; first int arg unused
// per ret 0x10. Caller at 0x002E840D.
struct In002E6F92
{
	char m_pad[0x0C];
	int m_bits;
};

class Rva002E6F92
{
public:
	int rva002E6F92(int unused, In002E6F92 *in, int a, int b);

private:
	float m_00;
	float m_04;
	float m_08;
	unsigned char m_0C;
};

// ?rva002E6F92@Rva002E6F92@@QAEHHPAUIn002E6F92@@HH@Z present-unmatched
int Rva002E6F92::rva002E6F92(int unused, In002E6F92 *in, int a, int b)
{
	(void)unused;
	int bits = in->m_bits & 0xF;
	if (bits == 7 || bits == 1) {
		int ia = a * 10;
		int ib = b * 10;
		m_00 = (float)ia;
		m_04 = (float)ib;
		m_08 = 0.0f;
		return 0;
	}
	if (bits == 0)
		m_0C = 1;
	return 1;
}
