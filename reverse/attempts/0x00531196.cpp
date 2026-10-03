// ?rva00531196@Rva00531196@@QAEXPAI@Z
// partial score=0.97 date=2026-10-03
// cl: /O1 /MD
// ?rva00531196@Rva00531196@@QAEXPAI@Z @ 0x00531196 (159B): __thiscall memset(this,0,4) then bit-pack dword from p[3]; caller 0x005329C8.
extern "C" void __cdecl memset(void *, int, unsigned int);
class Rva00531196
{
public:
	void rva00531196(unsigned int *p);
	unsigned int m_val;
};
// ?rva00531196@Rva00531196@@QAEXPAI@Z present-unmatched
void Rva00531196::rva00531196(unsigned int *p)
{
	memset((void *)this, 0, 4);
	m_val ^= (p[3] ^ m_val) & 7u;
	m_val ^= ((p[3] >> 1) ^ m_val) & 0x1f8u;
	m_val ^= ((p[3] >> 1) ^ m_val) & 0x7e00u;
	unsigned char c1 = (unsigned char)(p[3] >> 17);
	m_val ^= ((c1 << 15) ^ m_val) & 0x8000u;
	unsigned char c2 = (unsigned char)(p[3] >> 18);
	m_val ^= ((c2 << 16) ^ m_val) & 0x10000u;
	m_val ^= ((p[3] >> 2) ^ m_val) & 0x60000u;
	unsigned char c3 = (unsigned char)(p[3] >> 22);
	m_val ^= ((c3 << 19) ^ m_val) & 0x80000u;
}
