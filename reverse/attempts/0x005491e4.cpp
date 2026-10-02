// ??0Rva005491E4@@QAE@XZ
// partial score=0.95 date=2026-10-02
// cl: /O1 /G7 /DNDEBUG /MD
// ??0Rva005491E4@@QAE@XZ @0x005491E4 83B ctor with global AI double-deref plus array ??_H plus rep stosd. Evidence: packet disasm with rowed ??_H 0x00001423 and extern g_Va009FF0F8 plus prev/next in this dir plus caller 0x0054953C.
class AIInner
{
public:
	char m_pad[0xB4];
	int m_00B4;
};

class AI
{
public:
	char m_pad[0x18];
	AIInner *m_0018;
};
extern AI *g_Va009FF0F8;
#pragma comment(linker, "/alternatename:?g_Va009FF0F8@@3PAVAI@@A=?TheAI@@3PAVAI@@A")

struct Elem005491E4
{
	char m_pad[0x0A];
	Elem005491E4();
};

// ??0Elem005491E4@@QAE@XZ present-unmatched
inline Elem005491E4::Elem005491E4()
{
}

class Rva005491E4
{
public:
	Rva005491E4();
private:
	int m_00;
	int m_04;
	Elem005491E4 m_elems08[0x1C];
	int m_0120;
	int m_0124[0x24];
	int m_01B4;
	unsigned char m_01B8;
};

// ??0Rva005491E4@@QAE@XZ present-unmatched
Rva005491E4::Rva005491E4() : m_00(0), m_04(g_Va009FF0F8->m_0018->m_00B4 + g_Va009FF0F8->m_0018->m_00B4), m_0120(0), m_01B4(0), m_01B8(0)
{
	for (int i = 0; i < 0x24; i++)
		m_0124[i] = 0;
}
