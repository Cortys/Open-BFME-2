// cl: /O1 /DNDEBUG /MD /EHsc /arch:SSE
// ??1BfmeStrVM0@@UAE@XZ, retail 0x0025D686, 111 bytes.
// Destructor of BfmeStrVM0: stores vtable 0x7F5DA0 then runs the field-reset
// helper rva0025D19E and the list-clear rva0025C0FF on the same this, then
// destroys AsciiString at +0xF0/+0xD0 and Unicode string at +0xB0 in reverse
// order, then the GameEngineDeletingBase base dtor.
// Evidence: same-this calls at 0x0025D6A4/0x0025D6AB; vtable shared with ctor
// 0x0025D489 which inits the same D0/E0/E4/C8/CC/F0 fields; base call
// 0x001B4E74; deleting-dtor caller 0x0025DA57.
template <typename T> class StringBase
{
public:
	~StringBase() { releaseBuffer(); }
	void set(const StringBase &o);
private:
	void releaseBuffer();
	T *m_data;
};

class Rva0025C0FF
{
public:
	void rva0025C0FF();
};

class GameEngineDeletingBase
{
public:
	virtual ~GameEngineDeletingBase();
private:
	char m_pad[8];
};

class BfmeStrVM0 : public GameEngineDeletingBase
{
public:
	virtual ~BfmeStrVM0();
	void rva0025D19E();
	void rva0025D358(StringBase<unsigned short> s, float fC0, float fC4, int iB4, int iB8, int iBC);
private:
	char m_pad0C[0xA4];
	StringBase<unsigned short> m_sB0;
	int m_iB4;
	int m_iB8;
	int m_iBC;
	float m_fC0;
	float m_fC4;
	char m_padC8[0x08];
	StringBase<char> m_sD0;
	char m_padD4[0x1C];
	StringBase<char> m_sF0;
	char m_padF4[0x1C];
};

BfmeStrVM0::~BfmeStrVM0()
{
	rva0025D19E();
	((Rva0025C0FF *)this)->rva0025C0FF();
}

// ?rva0025D358@BfmeStrVM0@@QAEXV?$StringBase@G@@MMHHH@Z, retail 0x0025D358, 112 bytes.
// Sets the +0xB0 display block: Unicode string via set plus ints at +0xB4/+0xB8/+0xBC
// and floats at +0xC0/+0xC4; by-value string temp released at the end.
// Evidence: same +0xB0/+0xD0/+0xF0 layout as the dtor in this TU and ctor 0x0025D489;
// callees rowed/pinned set 0x00037150 plus releaseBuffer 0x00036E70; caller 0x00356AC1.
void BfmeStrVM0::rva0025D358(StringBase<unsigned short> s, float fC0, float fC4, int iB4, int iB8, int iBC)
{
	StringBase<unsigned short> &dst = m_sB0;
	dst.set(s);
	m_iB4 = iB4;
	m_iB8 = iB8;
	m_iBC = iBC;
	m_fC0 = fC0;
	m_fC4 = fC4;
}
