// cl: /O1
// ??1Rva0025EF18@@UAE@XZ at 0x0025EF18 (11B).
// Snapshot-derived scalar dtor: zeroes +4 then restores Snapshot base vtable
// 0x00BBB554. Evidence: vtable 0xBBB554, caller 0x0025EFF1 deleting dtor shape,
// and [ecx+4],0 /O1 idiom for m_04 = 0.

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
	*(const void **)this = reinterpret_cast<const void *>(0x00BBB554);
}

class __declspec(novtable) Rva0025EF18 : public Snapshot
{
public:
	virtual ~Rva0025EF18();
private:
	int m_04;
};

Rva0025EF18::~Rva0025EF18()
{
	m_04 = 0;
}
