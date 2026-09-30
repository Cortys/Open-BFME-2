// cl: /O1 /DNDEBUG /MD /GX
//
// ??1Rva004E179A@@UAE@XZ 81B @0x004E179A: ModuleData dtor with three
// StringBase<char> members at +0x4/+0x8/+0xC (inlined releaseBuffer calls
// via rowed 0x00036410) plus Snapshot vtable restore to 0x007BB554.
// Derived vtable 0x00861B78 stored at entry. Unlock lane: landing unblocks
// 0x004E1CFA/28. Evidence: EH prolog 0x00791A74 plus states 2/1/0 plus
// three releaseBuffer plus second vtable 0x007BB554 plus ret, callers at
// 0x004E183A 0x004E1CFD. Recipe follows landed PillageModuleDataDtor
// (TU-local Snapshot with inline BBB554-restoring dtor) with link-clean
// extern vtable (commit hook refuses literal) and inline StringBase dtor.

class Xfer;

class Snapshot
{
public:
	virtual ~Snapshot();
	virtual void crc(Xfer *xfer);
	virtual void loadPostProcess();
	virtual void xfer(Xfer *xfer);
};

extern const void *const g_007BB554[];

inline Snapshot::~Snapshot()
{
	*(const void **)this = g_007BB554;
}

template <typename T> class StringBase
{
public:
	~StringBase() { releaseBuffer(); }
private:
	void releaseBuffer();
	T *m_data;
};

class Rva004E179A : public Snapshot
{
public:
	virtual ~Rva004E179A();
private:
	StringBase<char> m_str04; // +0x04
	StringBase<char> m_str08; // +0x08
	StringBase<char> m_str0C; // +0x0C
};

// ??1Rva004E179A@@UAE@XZ
Rva004E179A::~Rva004E179A()
{
}

// ?Rva004E179ADelete@@YAXPAVRva004E179A@@@Z absent-from-retail
void Rva004E179ADelete(Rva004E179A *p)
{
	delete p;
}
