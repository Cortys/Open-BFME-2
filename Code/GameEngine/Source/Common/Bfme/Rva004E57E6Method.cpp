// cl: /DNDEBUG /MD /O1 /arch:SSE
// ?rva004E57E6@Rva004E57E6@@QAEXPAURva004E57E6Pair@@M@Z @0x004E57E6 (29B)
// __thiscall setter: copies pair->m_0 to +0x28, pair->m_4 to +0x2c, float to +0x30.
// Evidence: unlock lane, callee-free, caller 0x0029B187 passes pair ptr plus float
// with this = [ecx+0x7f4]; unblocks 0x0029B187. movss idiom -> /arch:SSE.
struct Rva004E57E6Pair {
	int m_0;
	int m_4;
};

class Rva004E57E6 {
	char m_pad[0x28];
	int m_28;
	int m_2c;
	float m_30;
public:
	void rva004E57E6(Rva004E57E6Pair *p, float f);
};

void Rva004E57E6::rva004E57E6(Rva004E57E6Pair *p, float f)
{
	m_28 = p->m_0;
	m_2c = p->m_4;
	m_30 = f;
}
