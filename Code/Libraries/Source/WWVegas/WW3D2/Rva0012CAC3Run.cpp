// cl: /O1 /DNDEBUG /MD /GX-
//
// ?Rva0012CAC3Run@@YA_NXZ, retail 0x0012CAC3, 82 bytes.
// OR the wide Run helper at 0x0012C907 called with NULL and with the
// configured directory converted to Unicode. Evidence: E8 calls to rowed
// 0x0012C907 twice, g_00DEE93C AsciiString length check, rowed
// UnicodeString ctor 0x006CB6D0, inline str() via TheNullChr 0x00BBB5C4,
// rowed releaseBuffer 0x00036E70; caller at 0x0012CFDB in 0x0012CFA0.

typedef unsigned short WideChar;

template <typename T>
class StringBase
{
	friend class AsciiString;
	friend class UnicodeString;
	void releaseBuffer();
protected:
	struct Header
	{
		int ref_count;
		unsigned short length;
		unsigned short capacity;
		T data[1];
	};
	Header *m_data;
};

class AsciiString
{
public:
	struct AsciiHeader
	{
		int ref_count;
		unsigned short length;
		unsigned short capacity;
		char data[1];
	};
	AsciiHeader *m_data;
};

class UnicodeString : public StringBase<WideChar>
{
public:
	UnicodeString(const AsciiString &ascii);
	~UnicodeString() { releaseBuffer(); }
	const WideChar *str() const
	{
		static const WideChar TheNullChr = 0;
		return m_data ? &m_data->data[0] : &TheNullChr;
	}
};

extern AsciiString g_00DEE93C;
bool __cdecl Rva0012C907Run(const unsigned short *currentDirectory);

bool __cdecl Rva0012CAC3Run()
{
	bool ok = Rva0012C907Run(0);
	if (g_00DEE93C.m_data && g_00DEE93C.m_data->length != 0) {
		ok |= Rva0012C907Run(UnicodeString(g_00DEE93C).str());
	}
	return ok;
}
