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
private:
	char m_pad0C[0xA4];
	StringBase<unsigned short> m_sB0;
	char m_padB4[0x1C];
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
