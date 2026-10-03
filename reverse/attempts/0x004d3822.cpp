// ?rva004D3822@Rva004D3822@@QAEXXZ
// partial score=0.93 date=2026-10-03
// cl: /O1 /MD
// ?rva004D3822@Rva004D3822@@QAEXXZ @0x004D3822 (163B).
// Init of Rva004D3822: set +4=0 +8=-1 +c=1 +10=-1, clear 8x8 Item8 at +0x30,
// per-row dword at +0x230 byte at +0x250 word at +0x272 byte at +0x282,
// zero +0x258/+0x25c/+0x260/+0x264/+0x268/+0x26c/+0x270.
// Evidence: callees none, caller 0x004D25DC, prev/next rows, or-idiom /O1.
struct Rva004D3822Item
{
	char c;
	char pad[3];
	int v;
};

class Rva004D3822
{
public:
	void rva004D3822();
private:
	char m_pad00[4];
	int m_04;
	int m_08;
	int m_0c;
	int m_10;
	char m_pad14[0x30 - 0x14];
	Rva004D3822Item m_items[8][8];
	int m_230[8];
	char m_250[8];
	int m_258;
	int m_25c;
	int m_260;
	int m_264;
	int m_268;
	int m_26c;
	char m_270;
	char m_pad271;
	unsigned short m_272[8];
	char m_282[8];
};

// ?rva004D3822@Rva004D3822@@QAEXXZ present-unmatched
void Rva004D3822::rva004D3822()
{
	m_08 = -1;
	m_10 = -1;
	m_04 = 0;
	m_258 = 0;
	m_0c = 1;
	m_25c = 0;
	m_268 = 0;
	Rva004D3822Item *p = &m_items[0][0];
	char *q282 = &m_282[0];
	unsigned short *q272 = &m_272[0];
	int *q230 = &m_230[0];
	char *q250 = &m_250[0];
	for (int outer = 8; outer != 0; --outer) {
		for (int inner = 8; inner != 0; --inner) {
			p->c = 0;
			p->v = 0;
			++p;
		}
		*q230++ = 0;
		*q250++ = 0;
		*q272++ = 0;
		*q282++ = 0;
	}
	m_26c = 0;
	m_260 = 0;
	m_264 = 0;
	m_270 = 0;
}
