// ?rva00046827@Rva00046827@@QAEHXZ
// partial score=0.93 date=2026-09-29
// ?rva00046827@Rva00046827@@QAEHXZ
// partial score=0.93 date=2026-09-29
// cl: /O1 /MD
//
// ?rva00046827@Rva00046827@@QAEHXZ, retail 0x00046827, 72 bytes.
// Popcount over 32 dwords at +0 via 0x55555555 0x33333333 0x0F0F0F0F
// 0x01010101 idiom summed into eax. Evidence: leaf with no callees;
// 7 callers including 0x004B8095 triple-site; unblocks 4.
class Rva00046827
{
public:
	int rva00046827();
private:
	unsigned m_bits[32];
};

int Rva00046827::rva00046827()
{
	int total = 0;
	for (unsigned i = 0; i < 32; ++i) {
		unsigned x = m_bits[i];
		x = x - ((x >> 1) & 0x55555555);
		unsigned b = (x >> 2) & 0x33333333;
		unsigned a = x & 0x33333333;
		x = b + a;
		x = (x + (x >> 4)) & 0x0F0F0F0F;
		x = (x * 0x01010101) >> 24;
		total += (int)x;
	}
	return total;
}
