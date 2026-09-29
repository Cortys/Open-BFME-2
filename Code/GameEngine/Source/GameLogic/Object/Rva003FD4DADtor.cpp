// cl: /O1 /DNDEBUG /MD /GX
// ??1Rva003FD4DA@@UAE@XZ @0x003FD4DA 72B
// ModuleData dtor: vtable 0x007FE1B0, two releaseBuffer calls on the string at
// +0x0C (body clear plus implicit member destruction), then Snapshot base
// vtable 0x00BBB554. Same recipe as Rva003FD789Dtor (TU-local Snapshot with
// extern BBB554); StringBase<char>::releaseBuffer is the row at 0x00036410.
// Unblocks ??_G at 0x002B5972.
class Xfer;

class Snapshot
{
public:
	virtual ~Snapshot();
	virtual void crc(Xfer *xfer);
	virtual void loadPostProcess();
	virtual void xfer(Xfer *xfer);
};

extern const void *const g_00BBB554[];

inline Snapshot::~Snapshot()
{
	*(const void **)this = g_00BBB554;
}

template <typename T> class StringBase
{
public:
	~StringBase() { releaseBuffer(); }
	void clear() { releaseBuffer(); }
private:
	void releaseBuffer(); // declared only: ?releaseBuffer@?$StringBase@D@@AAEXXZ is rowed
	T *m_data;
};

class Rva003FD4DA : public Snapshot
{
public:
	virtual ~Rva003FD4DA();
private:
	char m_pad04[8];
	StringBase<char> m_0c;
};

Rva003FD4DA::~Rva003FD4DA()
{
	m_0c.clear();
}
