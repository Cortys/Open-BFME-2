// ?rva0028F791@Rva0028F791@@QBEHXZ
// partial score=0.9 date=2026-10-01
// ?rva0028F791@Rva0028F791@@QBEHXZ
// partial score=0.90 date=2026-10-01
// cl: /O1 /DNDEBUG /MD
//
// ?rva0028F791@Rva0028F791@@QBEHXZ @0x0028F791 72B:
// Five-word popcount: parallel bitcount over m_words[5] summed into eax.
// No callees; caller at 0x002926D9; landing unblocks 0x0029268C.
// ?rva0028F791@Rva0028F791@@QBEHXZ present-unmatched
class Rva0028F791
{
public:
	int rva0028F791() const;
private:
	unsigned int m_words[5];
};

int Rva0028F791::rva0028F791() const
{
	int sum = 0;
	for (unsigned int i = 0; i < 5; i++) {
		unsigned int x = m_words[i];
		x = x - ((x >> 1) & 0x55555555);
		x = ((x >> 2) & 0x33333333) + (x & 0x33333333);
		x = (x + (x >> 4)) & 0x0F0F0F0F;
		sum += (x * 0x01010101) >> 24;
	}
	return sum;
}
