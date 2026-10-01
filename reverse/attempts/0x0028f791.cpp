// ?rva0028F791@Rva0028F791@@QBEHXZ
// partial score=0.88 date=2026-10-01
// cl: /O1 /DNDEBUG /MD
// ?rva0028F791@Rva0028F791@@QBEHXZ @0x0028F791 72B: SWAR popcount summed over the 5 dwords at +0
// (callers 0x002926D9). Textbook fold; retail applies the 0x33333333
// mask to the copied register and shifts the original in place, cl here
// does the opposite from every source and flag form tried (see
// reverse/re_attempts.log). Honest address name; owner unproven.
class Rva0028F791
{
public:
	int rva0028F791() const;

private:
	unsigned m_words[5];
};

int Rva0028F791::rva0028F791() const
{
	int sum = 0;
	for (unsigned i = 0; i < 5; i++)
	{
		unsigned v = m_words[i];
		v = v - ((v >> 1) & 0x55555555);
		v = (v & 0x33333333) + ((v >> 2) & 0x33333333);
		v = (v + (v >> 4)) & 0x0F0F0F0F;
		sum += (v * 0x01010101) >> 24;
	}
	return sum;
}
