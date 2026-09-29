// cl: /O1 /MD
//
// ?rva00142C80@Rva00142C80@@QAEPAXXZ, RVA 0x00142C80, 14B.
// Indexed lea from array at +0xB8 by index at +0x138.
// Evidence: mov eax [ecx+0x138] lea eax [ecx+eax*4+0xB8]; callers at 0x0014BED9
// 0x0014BF26 0x0014BFA0 use result as element address; ctor 0x00142EE0 zeroes
// +0xB8 and +0x138; honest address name.
//
// ?rva0030812E@Rva0030812E@@QAEPAXH@Z, retail 0x0030812E, 11 bytes.
// Stack-indexed lea: mov eax [esp+4] lea eax [ecx+eax*4+0x78] ret 4.
// Spelled as byte arithmetic (no array size claimed); unlocks 0x7EDBC/
// 0x81E36/0x81CDF. Honest address name.

class Rva00142C80
{
	char m_pad[0xb8];
	void *m_items[32];
	int m_index;

public:
	void *rva00142C80();
};

void *Rva00142C80::rva00142C80()
{
	return &m_items[m_index];
}

class Rva0030812E
{
public:
	void *rva0030812E(int i);
};

void *Rva0030812E::rva0030812E(int i)
{
	return (char *)this + 0x78 + i * 4;
}
