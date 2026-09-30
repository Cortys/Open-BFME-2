// ??0Rva004E16D9Record@@QAE@XZ
// partial score=0.95 date=2026-09-30
// ??0Rva004E16D9Record@@QAE@XZ
// partial score=0.95 date=2026-09-30
// AsciiString::TheEmptyString via pinned StringBase copy 0x000365F0; m_08/m_0C
// default empty plus releaseBuffer 0x00036410; floats at +0x10/+0x14/+0x20/+0x24
// zeroed via xorps/movss; bytes at +0x1C/+0x1D zeroed. Pin names the ctor;
// dtor row 0x004E1682; caller ParseForceBattle 0x004E16D9.
template <typename T> class StringBase
{
	friend class AsciiString;
private:
	StringBase() { m_data = 0; }
	StringBase(const StringBase<T> &other);
	void releaseBuffer();
	void *m_data;
};
class AsciiString : private StringBase<char>
{
public:
	AsciiString() {}
	AsciiString(const AsciiString &other) : StringBase<char>(other) {}
	~AsciiString();
	AsciiString &operator=(const AsciiString &other);
	void clear() { releaseBuffer(); }
	static AsciiString TheEmptyString;
};
struct FloatPair0027 {
	float x;
	float y;
	FloatPair0027() : x(0.0f), y(0.0f) {}
};
class Rva004E16D9Record {
public:
	virtual void anchor();
	Rva004E16D9Record();
	virtual ~Rva004E16D9Record();
private:
	AsciiString m_04;
	AsciiString m_08;
	AsciiString m_0C;
	FloatPair0027 m_10;
	AsciiString m_18;
	unsigned char m_1C;
	unsigned char m_1D;
	char m_pad1E[2];
	float m_20;
	float m_24;
};
// ??0Rva004E16D9Record@@QAE@XZ present-unmatched
Rva004E16D9Record::Rva004E16D9Record() : m_04(AsciiString::TheEmptyString), m_10(), m_18(AsciiString::TheEmptyString)
{
	m_1C = 0;
	m_1D = 0;
	m_20 = 0.0f;
	m_24 = 0.0f;
	m_08.clear();
	m_0C.clear();
}
