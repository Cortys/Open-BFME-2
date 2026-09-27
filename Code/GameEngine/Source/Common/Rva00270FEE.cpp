// cl: /O1 /MD
// ?rva00270FEE@Rva00270FEE@@QAEPADXZ @0x00270FEE 26B
// If ptr at +0xFC is set returns its dword at +0x104 else returns ptr at +0x04 plus 0xA0.
// Evidence: caller at 0x0027100C uses return plus 0x14 as float; no donor; honest Rva name.
struct Rva00270FEEInner
{
	unsigned char m_pad[0x104];
	char *m_104;
};

class Rva00270FEE
{
public:
	char *rva00270FEE();
private:
	unsigned char m_pad0[4];
	char *m_04;
	unsigned char m_pad8[0xfc - 8];
	Rva00270FEEInner *m_fc;
};

char *Rva00270FEE::rva00270FEE()
{
	if (m_fc)
		return m_fc->m_104;
	return m_04 + 0xa0;
}
