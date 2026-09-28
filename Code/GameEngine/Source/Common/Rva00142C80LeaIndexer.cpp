// cl: /O1 /MD
//
// ?rva00142C80@Rva00142C80@@QAEPAXXZ, RVA 0x00142C80, 14B.
// Indexed lea from array at +0xB8 by index at +0x138.
// Evidence: mov eax [ecx+0x138] lea eax [ecx+eax*4+0xB8]; callers at 0x0014BED9
// 0x0014BF26 0x0014BFA0 use result as element address; ctor 0x00142EE0 zeroes
// +0xB8 and +0x138; honest address name.

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
