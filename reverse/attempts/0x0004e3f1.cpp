// ?rva0004E3F1@Rva0004E3F1@@QAEXXZ
// partial score=0.96 date=2026-10-03
// ?rva0004E3F1@Rva0004E3F1@@QAEXXZ
// partial score=0.96 date=2026-10-03
// ?rva0004E3F1@Rva0004E3F1@@QAEXXZ
// partial score=0.95 date=2026-10-01
// cl: /O1 /DNDEBUG /MD /arch:SSE
//
// ?rva0004E3F1@Rva0004E3F1@@QAEXXZ @0x0004E3F1 159B: Image setup via setStatus
// 2 plus texture select by +0x14d5 plus 16B {0 1 1 0} copy plus field copies.
// Evidence: setStatus 0x002D8E63; bfmeSetTexture 0x002D905E; g_Va00BBB8D8
// 0x007BB8D8; callers 0x0004E8F1 0x0004FBE9.
class BfmeMapPictureTexture
{
	void *m_ptr;
};

struct Float4
{
	float f[4];
};

class Image
{
public:
	virtual ~Image();
	unsigned int setStatus(unsigned int bit);
	void bfmeSetTexture(const BfmeMapPictureTexture &tex);
public:
	char m_pad04[0x0C - 0x04];
	int m_0C;
	int m_10;
	Float4 m_14;
	int m_24;
	int m_28;
};

class Rva0004E3F1
{
public:
	void rva0004E3F1();
private:
	char m_pad00[0x146C];
	Image *m_146C;
	BfmeMapPictureTexture m_1470;
	BfmeMapPictureTexture m_1474;
	char m_pad1478[0x149C - 0x1478];
	int m_149C;
	int m_14A0;
	char m_pad14A4[0x14D5 - 0x14A4];
	unsigned char m_14D5;
};

// ?rva0004E3F1@Rva0004E3F1@@QAEXXZ present-unmatched
void Rva0004E3F1::rva0004E3F1()
{
	Float4 tmp;
	tmp.f[0] = 0.0f;
	tmp.f[1] = 1.0f;
	tmp.f[2] = 1.0f;
	tmp.f[3] = 0.0f;
	const BfmeMapPictureTexture *tex = &m_1474;
	if (m_14D5 == 0)
		tex = &m_1470;
	m_146C->setStatus(2);
	m_146C->bfmeSetTexture(*tex);
	m_146C->m_14 = tmp;
	const int *v1 = &m_149C;
	const int *v2 = &m_14A0;
	Image *img0 = m_146C;
	img0->m_0C = *v1;
	img0->m_10 = *v2;
	img0->m_24 = *v1;
	img0->m_28 = *v2;
}
