// ?rva00498716@Rva00498716@@QAEHXZ @0x00498716 15B
// Leaf getter with global compare. Evidence: sibling 0x00498707 same shape
// with m_44; this uses m_48; same global g_00DCB4CC; caller 0x004996D2.
extern int g_00DCB4CC;

class Rva00498716
{
	char m_pad0[0xC];
	int m_0C;
	char m_pad1[0x38];
	int m_48;
public:
	int rva00498716();
};

int Rva00498716::rva00498716()
{
	int v = m_48;
	if (v == g_00DCB4CC)
		v = m_0C;
	return v;
}
