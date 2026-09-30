// ?rva00547223@Rva00547223@@QAEXPAH0@Z
// partial score=0.94 date=2026-09-30
// ?rva00547223@Rva00547223@@QAEXPAH0@Z
// partial score=0.94 date=2026-09-30
// cl: /O1 /MD
// ?rva00547223@Rva00547223@@QAEXPAH0@Z, retail 0x00547223, 34 bytes.
// Unlock: copies 1 dword from *a and 3 dwords from b[0..2] to +0/+4/+8/+0xC.
// Evidence: unlock lane, callers 0x005472A3 0x00547511, neighbours share /O1.

class Rva00547223
{
public:
	void rva00547223(int *a, int *b);
	int m_00;
	int m_04;
	int m_08;
	int m_0C;
};

// ?rva00547223@Rva00547223@@QAEXPAH0@Z present-unmatched
void Rva00547223::rva00547223(int *a, int *b)
{
	int *dst = (int *)this;
	dst[0] = *a;
	dst[1] = b[0];
	dst[2] = b[1];
	dst[3] = b[2];
}
