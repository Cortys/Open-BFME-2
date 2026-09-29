// ?rva000B6586@Rva000B6586@@QBEHXZ
// partial score=0.88 date=2026-09-29
// ?rva000B6586@Rva000B6586@@QBEHXZ
// partial score=0.88 date=2026-09-29
// cl: /O1
// ?rva000B6586@Rva000B6586@@QBEHXZ, retail 0x000B6586, 72 bytes.
// __thiscall const method returning the total popcount of 19 dwords at +0:
// classic shift-and-add Hamming weight with 0x33333333 hoisted. Callers
// 0x000BB75D 0x004B661E. Honest address name; owner unproven.
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
		unsigned s1 = v;
		s1 >>= 1;
		s1 &= 0x55555555;
		v -= s1;
		unsigned s2 = v;
		s2 &= 0x33333333;
		v >>= 2;
		v &= 0x33333333;
		v += s2;
		unsigned s3 = v;
		s3 >>= 4;
		s3 += v;
		s3 &= 0x0F0F0F0F;
		s3 *= 0x01010101;
		s3 >>= 24;
		sum += s3;
	}
	return sum;
}
