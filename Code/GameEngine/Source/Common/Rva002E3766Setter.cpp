// cl: /O1 /MD
// ?set@Rva002E3766Holder@@QAEXHH@Z, retail 0x002E3766, 17 bytes.
// Leaf thiscall setter storing two ints at +0x54/+0x58. Callers 0x0039867C
// 0x004B0BC3 0x004EBD7D pass owner and code target; owning class unproven
// so honest Rva holder. Shape matches Rva002716 2-arg precedent.
class Rva002E3766Holder
{
public:
	void set(int a, int b);

private:
	unsigned char m_pad[0x54];
	int m_54;
	int m_58;
};

void Rva002E3766Holder::set(int a, int b)
{
	m_54 = a;
	m_58 = b;
}
