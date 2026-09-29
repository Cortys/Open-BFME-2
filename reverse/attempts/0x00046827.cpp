// ?rva00046827@Rva00046827@@QAEHXZ
// partial score=0.88 date=2026-09-29
// ?rva00046827@Rva00046827@@QAEHXZ
// partial score=0.88 date=2026-09-29
// cl: /O1 /G7
// ?rva00046827@Rva00046827@@QAEHXZ @0x00046827 72B. Unlock lane: popcount sum
// over 32 dwords at [this]; 7 callers including 0x004B8196 and 0x002E1568;
// unblocks 4 (0x002E14E9 0x004B8095 0x0040F87E 0x002AEA9F). Prev 0x00045984,
// next 0x0004686F Disp8 getters.
class Rva00046827
{
public:
	int rva00046827();
private:
	unsigned int m_bits[32];
};
// ?rva00046827@Rva00046827@@QAEHXZ present-unmatched
int Rva00046827::rva00046827()
{
	int total = 0;
	for (unsigned int i = 0; i < 32; ++i) {
		unsigned int v = m_bits[i];
		v = v - ((v >> 1) & 0x55555555);
		unsigned int low = v & 0x33333333;
		unsigned int high = (v >> 2) & 0x33333333;
		v = high + low;
		total += (int)(((v + (v >> 4)) & 0x0F0F0F0F) * 0x01010101 >> 24);
	}
	return total;
}
