// cl: /O1 /EHsc
// ?rva0050F0AB@Rva0050F0AB@@QAEXXZ, retail 0x0050F0AB, 96 bytes.
// If m_7c null return; else format m_6c via UnicodeString::format L"%d" into
// local buf and GadgetTextEntrySetText(m_7c buf by value). Evidence: EH prolog
// 0x00629188; format 0x006CB5D0; StringBase-G copy 0x00037050; SetText
// 0x002C17EB; releaseBuffer 0x00036E70; callers 0x0050F297 0x0050F2EB
// 0x0050F416 0x0050F446 0x0050F4A0; neighbours RegistryAsciiPath /O1 /EHsc.
typedef unsigned short wchar_t;

template <typename T>
class StringBase
{
	friend class AsciiString;
	friend class UnicodeString;
private:
	StringBase() : m_data(0) {}
	StringBase(const StringBase<T> &that);
	void releaseBuffer();
	struct Header
	{
		int ref_count;
		unsigned short length;
		unsigned short capacity;
		T data[1];
	};
	Header *m_data;
};

class UnicodeString
{
public:
	UnicodeString() {}
	UnicodeString(const UnicodeString &that) : m_data(that.m_data) {}
	~UnicodeString() { m_data.releaseBuffer(); }
	void __cdecl format(const wchar_t *format, ...);
private:
	StringBase<wchar_t> m_data;
};

class GameWindow;

void GadgetTextEntrySetText(GameWindow *g, UnicodeString text);

class Rva0050F0AB
{
public:
	void rva0050F0AB();
	void rva0050F420(unsigned int val);
	void rva0050F290();
private:
	char m_pad00[0x68];
	unsigned int m_68;
	unsigned int m_6c;
	char m_pad70[0x78 - 0x70];
	GameWindow *m_78;
	GameWindow *m_7c;
};

void Rva0050F0AB::rva0050F0AB()
{
	if (m_7c == 0)
		return;
	UnicodeString buf;
	buf.format(L"%u", m_6c);
	GadgetTextEntrySetText(m_7c, buf);
}

int __cdecl Rva0050E776Send(GameWindow *window, int data);

void Rva0050F0AB::rva0050F420(unsigned int val)
{
	if (val == m_6c)
		return;
	if (val > m_68)
	{
		val = m_68;
		Rva0050E776Send(m_78, val);
	}
	m_6c = val;
	rva0050F0AB();
}

void Rva0050F0AB::rva0050F290()
{
	m_6c = 0;
	rva0050F0AB();
	GameWindow *win = m_78;
	if (win)
		Rva0050E776Send(win, 0);
}

class GameWindowManager {
public:
#define V(n) virtual void pad##n() = 0;
	V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7)
	V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15)
	V(16) V(17) V(18) V(19) V(20) V(21) V(22) V(23)
	V(24) V(25) V(26) V(27) V(28) V(29) V(30) V(31)
	V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
	V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47)
	virtual void *winGetFocus();
#undef V
	virtual int winSetFocus(GameWindow *window);
#define W(n) virtual void pad##n() = 0;
	W(50) W(51) W(52) W(53) W(54) W(55) W(56) W(57)
#undef W
	virtual int winSendSystemMsg(GameWindow *window, unsigned int msg, unsigned int mData1, unsigned int mData2);
};

extern GameWindowManager *TheWindowManager;

class Rva0050F5A6
{
public:
	void rva0050F5A6(int unused);
private:
	char m_pad00[0x20];
	int m_20;
	char m_pad24[0x28 - 0x24];
	Rva0050F0AB *m_array28[1];
};

void Rva0050F5A6::rva0050F5A6(int unused)
{
	(void)unused;
	TheWindowManager->winSetFocus(0);
	for (int i = 0; i < m_20; ++i)
	{
		Rva0050F0AB *entry = *(Rva0050F0AB **)((char *)m_array28 + i * 8);
		if (entry)
			entry->rva0050F290();
	}
}
