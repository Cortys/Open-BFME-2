// cl: /O1 /MD
//
// ?rva000B980E@Rva000B980E@@QAEXPADHH@Z retail 0x000B980E 44B
// String-data memcpy: copy size bytes from the held AsciiString data
// plus offset (or the empty literal when null) to dst via msvcrt memcpy.
// Evidence: 2 callers plus empty-literal pin 0x00BBAC1C plus m_data
// plus 8 str idiom plus rowed memcpy import 0x006291A8.
extern "C" void *memcpy(void *dst, const void *src, unsigned int n);

class AsciiString
{
	struct Header
	{
		int m_refCount;
		unsigned short m_length;
		unsigned short m_capacity;
		char m_data[1];
	};

	Header *m_data;

public:
	const char *str() const { return m_data ? (const char *)m_data + 8 : ""; }
};

class Rva000B980E
{
public:
	void rva000B980E(char *dst, int off, int size);
private:
	AsciiString *m_str;
};

void Rva000B980E::rva000B980E(char *dst, int off, int size)
{
	const char *base = m_str->str();
	memcpy(dst, base + off, size);
}
