// ??1Rva00337AA8@@UAE@XZ
// partial score=0.96 date=2026-10-03
// cl: /O1 /DNDEBUG /MD /GX
// ??1Rva00337AA8@@UAE@XZ @0x00337AA8 164B outer dtor.
// Evidence: retail 164B EH FuncInfo 0x00B7C388; stores vtable 0x00C0E390; lua_close rowed 0x0074DF60 at +0xC/+0x10 with null; free rowed 0x00030830 at +0xC8/+0xBC/+0xA0; member dtor just-landed 0x003378D0 at +0xB0; base rowed GameEngineDeletingBase 0x001B4E74; member order follows retail.
extern "C" void __cdecl lua_close(void *L);
void __cdecl free(void *block);
struct Rva003378D0
{
	~Rva003378D0();
	char m_pad[12];
};
class AsciiStringMember
{
public:
	~AsciiStringMember();
};
class GameEngineDeletingBase
{
public:
	virtual ~GameEngineDeletingBase();
private:
	char m_pad04[4];
	AsciiStringMember m_member08;
};
template <class T> struct Rva00337AA8Buf
{
	void *m_ptr;
	~Rva00337AA8Buf()
	{
		if (m_ptr != 0)
			free(m_ptr);
	}
};
extern const void *const g_00C0E390[];
class Rva00337AA8 : public GameEngineDeletingBase
{
public:
	virtual ~Rva00337AA8();
private:
	void *m_lua0C;
	void *m_lua10;
	char m_pad14[0xA0 - 0x14];
	Rva00337AA8Buf<void> m_bufA0;
	char m_padA4[0xB0 - 0xA4];
	Rva003378D0 m_vecB0;
	Rva00337AA8Buf<void> m_bufBC;
	char m_padC0[0xC8 - 0xC0];
	Rva00337AA8Buf<void> m_bufC8;
};
// ??1Rva00337AA8@@UAE@XZ present-unmatched
Rva00337AA8::~Rva00337AA8()
{
	if (m_lua0C != 0)
	{
		lua_close(m_lua0C);
		m_lua0C = 0;
	}
	if (m_lua10 != 0)
	{
		lua_close(m_lua10);
		m_lua10 = 0;
	}
}
