// cl: /O1 /MD /EHsc
// ?Rva003FF02EPowerCap@@YAXH@Z @0x003FF02E 134B
// Static AsciiString key APT:PlayerPowerCap via rowed StringBase ctor 0x00037BA0 plus atexit,
// Unicode value via format 0x006CB5D0 on extern format string 0x007C9260,
// then bfmeSetText pin 0x00225301 on global 0x009FE4CC with false, release 0x00036E70.
// Evidence: literal 0x0083814C, static guard 0x00A02EE0, caller 0x002D69A4;
// precedent Rva00517048Chat.cpp local key plus bfmeSetText false, Rva005FDF1CApt.cpp flags.
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
	StringBase(const T *text);
	void releaseBuffer();
public:
	StringBase() : m_data(0) {}
	~StringBase() { releaseBuffer(); }
private:
	BfmeStringData<T> *m_data;
};

class AsciiString : private StringBase<char>
{
public:
	AsciiString() {}
	AsciiString(const char *text) : StringBase<char>(text) {}
	~AsciiString() {}
};

class UnicodeString : private StringBase<unsigned short>
{
public:
	UnicodeString() {}
	~UnicodeString() {}
	void __cdecl format(const unsigned short *format, ...);
};

class BfmeAptWindowManager
{
public:
	void bfmeSetText(const AsciiString &, const UnicodeString &, bool);
};

extern BfmeAptWindowManager *g_Va009FE4CC;
extern const unsigned short g_Va007C9260[];

void __cdecl Rva003FF02EPowerCap(int cap)
{
	static AsciiString s_key("APT:PlayerPowerCap");
	UnicodeString value;
	value.format(g_Va007C9260, cap);
	g_Va009FE4CC->bfmeSetText(s_key, value, false);
}
