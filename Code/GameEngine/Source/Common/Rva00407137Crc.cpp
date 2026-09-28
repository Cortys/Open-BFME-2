// cl: /O1 /EHsc /MD
//
// ?rva00407137@Rva00407137@@QAEXABVUnicodeString@@@Z retail 0x00407137 88B
// Evidence: unlock lane; AsciiString from UnicodeString 0x00038250 plus CRC::String 0x00619B00 plus releaseBuffer 0x00036410; caller 0x004071AA; prev StringRecordCopy same /O1 /EHsc.
class UnicodeString;
class CRC
{
public:
	static unsigned long String(const char *string, unsigned long crc);
};

template <typename T>
struct BfmeStringData
{
	int refCount;
	unsigned short length;
	unsigned short capacity;
	T text[1];
};

template <typename T>
class StringBase
{
	friend class AsciiString;
public:
	const T *str() const { return m_data ? &m_data->text[0] : (const T *)""; }
private:
	void releaseBuffer();
	BfmeStringData<T> *m_data;
};

class AsciiString : private StringBase<char>
{
public:
	AsciiString(const UnicodeString &u);
	~AsciiString() { releaseBuffer(); }
	using StringBase<char>::str;
};

class Rva00407137
{
public:
	void rva00407137(const UnicodeString &u);
private:
	unsigned long m_crc;
	bool m_flag;
};

void Rva00407137::rva00407137(const UnicodeString &u)
{
	m_flag = true;
	AsciiString s(u);
	const char *str = s.str();
	m_crc = CRC::String(str, m_crc);
}
