// cl: /O1 /DNDEBUG /MD /GX
// ??1Rva007401F6@@UAE@XZ, retail 0x007401F6, 48 bytes.
// ModuleData-style dtor: destroys AsciiString at +8 via rowed releaseBuffer then restores base vtable 0x0083962C.
// Evidence: callers 0x00740229 deleting dtor plus 0x007402AE base call from 0x00740242 vtable 0x008F1600; callee rowed releaseBuffer 0x00036410.
class Xfer;
class Snapshot
{
public:
	virtual ~Snapshot();
	virtual void crc(Xfer *xfer);
	virtual void loadPostProcess();
	virtual void xfer(Xfer *xfer);
};
inline Snapshot::~Snapshot()
{
	*(const void **)this = reinterpret_cast<const void *>(0x00C3962C);
}
template <typename T>
class StringBase
{
public:
	~StringBase() { releaseBuffer(); }
private:
	void releaseBuffer();
	void *m_data;
};
typedef StringBase<char> AsciiString;
class __declspec(novtable) Rva007401F6 : public Snapshot
{
public:
	virtual ~Rva007401F6();
private:
	int m_unused04;
	AsciiString m_str08;
};
Rva007401F6::~Rva007401F6()
{
}
