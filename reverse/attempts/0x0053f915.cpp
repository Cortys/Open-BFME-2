// ?rva0053F915@Rva0053FB33@@UAE_NPAVDataChunkInput@@PAX@Z
// partial score=0.96 date=2026-09-30
// ?rva0053F915@Rva0053FB33@@UAE_NPAVDataChunkInput@@PAX@Z
// partial score=0.96 date=2026-09-30
// cl: /O1 /EHs /MD
// ?rva0053F915@Rva0053FB33@@UAE_NPAVDataChunkInput@@PAX@Z, retail 0x0053F915, 106 bytes.
// Vslot 4 of 0x008694DC (Rva0053FB33): reads AsciiString via rowed
// DataChunkInput::rva0030750A into +0x18 via pinned AsciiString::op=, reads
// int to +0x1C via rowed readInt, reads +0x20 if version word at second arg
// +8 >= 3 else zeroes. Returns true. Evidence: vslot, donor dtor layout,
// callers 0x00540BEF 0x005423C8.

template <typename T> struct StringInlineData
{
	int m_refCount;
	int m_length;
	T m_text[1];
};

template <typename T> class StringBase
{
public:
	~StringBase() { releaseBuffer(); }
private:
	void releaseBuffer();
	StringInlineData<T> *m_data;
};

class AsciiString : public StringBase<char>
{
public:
	AsciiString &operator=(const AsciiString &other);
};

class DataChunkInput
{
public:
	AsciiString rva0030750A();
	int readInt();
};

struct Rva0053FB33Holder
{
	~Rva0053FB33Holder();
	void *m_ptr;
};

class Rva0053FB33
{
public:
	virtual bool rva0053F915(DataChunkInput *input, void *ver);
private:
	Rva0053FB33Holder m_holder04;
	char m_pad08[0x18 - 0x08];
	AsciiString m_str18;
	int m_1C;
	int m_20;
};

// ?rva0053F915@Rva0053FB33@@UAE_NPAVDataChunkInput@@PAX@Z present-unmatched
bool Rva0053FB33::rva0053F915(DataChunkInput *input, void *ver)
{
	m_str18 = input->rva0030750A();
	m_1C = input->readInt();
	if (*(unsigned short *)((char *)ver + 8) >= 3)
		m_20 = input->readInt();
	else
		m_20 = 0;
	return true;
}
