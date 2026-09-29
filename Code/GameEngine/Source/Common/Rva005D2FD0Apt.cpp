// cl: /O1 /MD /EHsc
// ?Rva005D2FD0Set@@YAXHPAURva005D2FD0Outer@@PBDABVUnicodeString@@@Z retail 0x005D2FD0 106B
// Evidence: format APT:_level%u.%s_%s via 0x00038150; bfmeSetText via pin 0x00225301; releaseBuffer 0x00036410; globals 0x009FE4CC 0x007BAC1C 0x008758A8; callers 0x005D3128 0x005D318D 0x005D31F2
template <typename T> struct BfmeStringData
{
	int refCount;
	unsigned short length;
	unsigned short capacity;
	T text[1];
};

template <typename T> class StringBase
{
	friend class AsciiString;
	friend class UnicodeString;
public:
	StringBase() : m_data(0) {}
	void format_va(const T *format, char *args);
private:
	~StringBase() { releaseBuffer(); }
	void releaseBuffer();
	BfmeStringData<T> *m_data;
};

class AsciiString : private StringBase<char>
{
public:
	AsciiString() {}
	~AsciiString() {}
	void __cdecl format(const char *format, ...);
};

class UnicodeString : private StringBase<unsigned short>
{
public:
	UnicodeString() {}
	~UnicodeString() {}
};

struct Rva005D2FD0Inner
{
	char m_pad8[8];
	char m_name[1];
};

struct Rva005D2FD0Outer
{
	Rva005D2FD0Inner *m_ptr;
};

class BfmeAptWindowManager
{
public:
	void bfmeSetText(const AsciiString &, const UnicodeString &, bool);
};

extern BfmeAptWindowManager *g_Va009FE4CC;
extern char g_Va007BAC1C;

void __cdecl Rva005D2FD0Set(int level, Rva005D2FD0Outer *outer, const char *suffix, const UnicodeString &text)
{
	AsciiString key;
	const char *mid = outer->m_ptr ? outer->m_ptr->m_name : &g_Va007BAC1C;
	key.format("APT:_level%u.%s_%s", level, mid, suffix);
	g_Va009FE4CC->bfmeSetText(key, text, true);
}

void __cdecl Rva005D366ASet(int level, Rva005D2FD0Outer *outer, const UnicodeString &text)
{
	AsciiString key;
	const char *mid = outer->m_ptr ? outer->m_ptr->m_name : &g_Va007BAC1C;
	key.format("APT:_level%u.%s_RegionName", level, mid);
	g_Va009FE4CC->bfmeSetText(key, text, false);
}
