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
