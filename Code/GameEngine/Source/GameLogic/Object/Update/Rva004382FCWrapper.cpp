// cl: /O1 /arch:SSE /DNDEBUG /MD /GX-
// ??0Rva004382FC@@QAE@XZ, retail 0x004382FC, 32 bytes.
// Wrapper ctor with Rva002542F3Member at +0 (rowed 0x002542F3, size 0xB8)
// then int 0 at +0xB8/+0xBC and byte 0 at +0xC0. Caller 0x0043A004.
// Member layout and size per Rva002542F3MemberCtor.cpp (InvisibilityNugget
// at +0x08/0x7C, wrapper at +0). No donor: honest address name.
class Rva002542F3Member
{
public:
	Rva002542F3Member();
	Rva002542F3Member(const Rva002542F3Member &other);
private:
	char m_pad[0xB8];
};

class GameLogic
{
public:
	unsigned char m_pad00[0x40];
	unsigned int m_frame;
};

#define TheGameLogic (*(GameLogic **)0x00DFE78C)

class Rva004382FC
{
public:
	Rva004382FC();
	Rva004382FC(const Rva002542F3Member &a1, int a2);
private:
	Rva002542F3Member m_00;
	int m_B8;
	int m_BC;
	unsigned char m_C0;
};

Rva004382FC::Rva004382FC()
{
	m_B8 = 0;
	m_BC = 0;
	m_C0 = 0;
}

Rva004382FC::Rva004382FC(const Rva002542F3Member &a1, int a2)
	: m_00(a1)
	, m_B8((int)TheGameLogic->m_frame)
	, m_BC(a2)
	, m_C0(0)
{
}
