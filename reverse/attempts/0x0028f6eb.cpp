// ?rva0028F6EB@Rva0028F6EB@@QAEHXZ
// partial score=0.88 date=2026-10-01
// cl: /O1 /DNDEBUG /MD
// ?rva0028F6EB@Rva0028F6EB@@QAEHXZ @0x0028F6EB 72B: SWAR popcount summed over the 4 dwords at +0
// (callers 0x002914FC 0x0029259D 0x00494CA4). Textbook fold; retail applies the 0x33333333
// mask to the copied register and shifts the original in place, cl here
// does the opposite from every source and flag form tried (see
// reverse/re_attempts.log). Honest address name; owner unproven.
class Rva0028F6EB
{
public:
	int rva0028F6EB();

private:
	unsigned m_words[4];
};

int Rva0028F6EB::rva0028F6EB()
{
	int sum = 0;
	for (unsigned i = 0; i < 4; i++)
	{
		unsigned v = m_words[i];
		v = v - ((v >> 1) & 0x55555555);
		v = (v & 0x33333333) + ((v >> 2) & 0x33333333);
		v = (v + (v >> 4)) & 0x0F0F0F0F;
		sum += (v * 0x01010101) >> 24;
	}
	return sum;
}
