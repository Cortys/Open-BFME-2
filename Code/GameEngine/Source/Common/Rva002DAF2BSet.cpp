// cl: /O1 /MD /EHsc /G7
// ?rva002DAF2B@Rva002DAF2B@@QAEXHHVAsciiString@@@Z @0x002DAF2B 65B: indexed AsciiString setter via imul-3.
// Evidence: op= pin 0x366F0, releaseBuffer row 0x36410, ret 0xC with this plus imul-3 lea 0xA4, callers 0x002DB0DB 0x002DB64E, neighbour Rva002DB311Dtor /O1 /MD /EHsc.

class AsciiString
{
public:
	AsciiString(const AsciiString &other);
	AsciiString &operator=(const AsciiString &other);
	~AsciiString() { releaseBuffer(); }
private:
	void releaseBuffer();
	void *m_data;
};

class Rva002DAF2B
{
public:
	void rva002DAF2B(int a, int b, AsciiString c);
private:
	char m_pad[0xA4];
	AsciiString m_arr[64];
};

void Rva002DAF2B::rva002DAF2B(int a, int b, AsciiString c)
{
	AsciiString &slot = m_arr[a * 3 + b];
	slot = c;
}
