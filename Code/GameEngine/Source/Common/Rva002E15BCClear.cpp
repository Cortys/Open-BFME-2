// cl: /O1
//
// ?rva002E15BC@Rva002E15BC@@QAEXPAX@Z @0x002E15BC 42B.
// Bit-clear method: if arg+4 nonzero return, else clear bit arg+0x38 in
// this+0x1D8 array via ~(1u << (bit & 31)). Evidence: caller 0x0020EDB5
// passing element plus this; prev/next share /O1.
struct Rva002E15BCArg
{
	int m_00;
	int m_04;
	char m_pad[0x38 - 8];
	int m_38;
};

struct Rva002E15BC
{
	char m_pad[0x1D8];
	unsigned int m_bits[1];
	void rva002E15BC(void *arg);
};

void Rva002E15BC::rva002E15BC(void *argp)
{
	Rva002E15BCArg *arg = (Rva002E15BCArg *)argp;
	if (arg->m_04 != 0)
		return;
	unsigned int bit = (unsigned int)arg->m_38;
	m_bits[bit >> 5] &= ~(1u << (bit & 31));
}
