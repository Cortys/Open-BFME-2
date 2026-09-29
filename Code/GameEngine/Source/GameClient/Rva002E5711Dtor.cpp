// cl: /O1 /DNDEBUG /DWIN32 /MD /D_STLP_USE_STATIC_LIB
// ??1Rva002E5711@@QAE@XZ 0x002E5711 8B
// Evidence: add ecx 4 plus jmp to rowed releaseBuffer 0x00036E70;
// callers 0x002E5D46 0x002E6551; non-virtual dtor over Unicode member at +4.
template <typename T> class StringBase
{
public:
	~StringBase() { releaseBuffer(); }

private:
	void releaseBuffer();
	T *m_data;
};

class UnicodeString
{
public:
	~UnicodeString();

private:
	StringBase<unsigned short> m_text;
};

inline UnicodeString::~UnicodeString()
{
}

class Rva002E5711
{
public:
	~Rva002E5711();

private:
	char m_pad[4];
	UnicodeString m_text;
};

Rva002E5711::~Rva002E5711()
{
}
