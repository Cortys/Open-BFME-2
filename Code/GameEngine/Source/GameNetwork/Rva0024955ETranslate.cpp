// cl: /O1 /DNDEBUG /MD /EHsc
// Retail 0x0024955E, 55 bytes.
// ?rva0024955E@Rva0024955E@@QAEXVAsciiString@@@Z
// Honest address name: __thiscall (ret 4: one by-value AsciiString,
// destroyed in the EH epilogue via rowed narrow releaseBuffer). Translates
// the argument into the UnicodeString member at +0x1B0 via rowed
// UnicodeString::translate. Owner class unproven (four callers in unclaimed
// bodies), so the class carries the address. String models follow
// LANAPIRequestSetName, with releaseBuffer declared private to match the
// rowed AAE spellings. Unlock lane.
typedef unsigned short WideChar;
typedef bool Bool;

template<typename T> class StringBase
{
public:
	StringBase() : m_data(0) {}
	~StringBase() { releaseBuffer(); }
private:
	void releaseBuffer();
	void *m_data;
};

class AsciiString : public StringBase<char>
{
};

class UnicodeString : public StringBase<WideChar>
{
public:
	void translate(const AsciiString &other);
};

class Rva0024955E
{
public:
	void rva0024955E(AsciiString name);
private:
	char m_pad[0x1B0];
	UnicodeString m_name;
};

void Rva0024955E::rva0024955E(AsciiString name)
{
	m_name.translate(name);
}
