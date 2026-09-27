// cl: /O1 /EHsc /DNDEBUG /MD
//
// ?init@FontLibrary@@UAEXXZ, retail 0x00217561, 89 bytes.
// FontLibrary subsystem init: virtual slot 1 (offset 0x4) of vtable 0x007E5AD0.
// Stack INI (0x87C) plus one loadFile("data\\ini\\fontsubstitution.ini",
// INI_LOAD_OVERWRITE, 0) via rowed StringBase<char> ctor 0x00037BA0 and pinned
// INI ctor 0x0002CDB0 / loadFile 0x0002DC75 / dtor 0x0002CE5B. ZH donor
// GameFont.h declares virtual void init; ZH/BFME1 bodies are empty, BFME2 adds
// the font-substitution load. Retail ignores this.

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
private:
	StringBase(const T *text);
	StringBase(const StringBase<T> &other);
	~StringBase() { releaseBuffer(); }
	void releaseBuffer();
	BfmeStringData<T> *m_data;
public:
	const T *str() const { return m_data ? &m_data->text[0] : (const T *)""; }
};

class AsciiString : private StringBase<char>
{
public:
	AsciiString(const char *text) : StringBase<char>(text) {}
	AsciiString(const AsciiString &other);
	~AsciiString() {}
};

class Xfer;

enum INILoadType
{
	INI_LOAD_INVALID = 0,
	INI_LOAD_OVERWRITE = 1,
	INI_LOAD_CREATE_OVERRIDES = 2
};

class INI
{
public:
	INI();
	~INI();
	void loadFile(AsciiString filename, INILoadType loadType, Xfer *xfer);
private:
	char m_storage[0x87C];
};

class SubsystemInterface
{
public:
	SubsystemInterface();
	~SubsystemInterface();
	virtual void init();
	void setName(AsciiString name);

private:
	unsigned char m_bfmeBasePad[8];
};

class FontLibrary : public SubsystemInterface
{
public:
	FontLibrary();
	~FontLibrary();
	virtual void init();

private:
	void *m_fontList;
	int m_count;
	unsigned char m_tables[0x18];
};

void FontLibrary::init()
{
	INI ini;
	ini.loadFile("data\\ini\\fontsubstitution.ini", INI_LOAD_OVERWRITE, 0);
}
