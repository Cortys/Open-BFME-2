// ?rva000B6586@Rva000B6586@@QBEHXZ
// partial score=0.88 date=2026-10-01
// cl: /O1 /DNDEBUG /MD
// ?rva000B6586@Rva000B6586@@QBEHXZ @0x000B6586 72B: SWAR popcount summed over the 19 dwords at +0
// (callers 0x000BB75D 0x004B661E). Textbook fold; retail applies the 0x33333333
// mask to the copied register and shifts the original in place, cl here
// does the opposite from every source and flag form tried (see
// reverse/re_attempts.log). Honest address name; owner unproven.
class Rva000B6586
{
public:
	int rva000B6586() const;

private:
	unsigned m_words[19];
};

int Rva000B6586::rva000B6586() const
{
	int sum = 0;
	for (unsigned i = 0; i < 19; i++)
	{
		unsigned v = m_words[i];
		v = v - ((v >> 1) & 0x55555555);
		v = (v & 0x33333333) + ((v >> 2) & 0x33333333);
		v = (v + (v >> 4)) & 0x0F0F0F0F;
		sum += (v * 0x01010101) >> 24;
	}
	return sum;
}
