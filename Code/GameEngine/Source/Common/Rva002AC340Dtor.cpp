// cl: /O1 /Ob2 /EHs /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ??1Rva002AC340@@MAE@XZ @0x002AC366 (60B): Rva002AC340 dtor.
// Stores own vtable 0x007FDD6C, frees the BfmeE16 vector buffer at +8 via
// rowed _free 0x00030830, then restores Snapshot base vtable 0x00BBB554
// through the TU-local inline Snapshot base. Same class as rowed ctor 0x002AC340 (vtable
// 0x007FDD6C int at +4 vector at +8). Callers at 0x002AC3A5 0x002B1323 plus
// unwinds at 0x00775DE0 0x00775F6C. Follows PillageModuleDataDtor pattern.
#include <vector>

struct BfmeE16 { float x, y, z, w; };

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

class Rva002AC340 : public Snapshot
{
public:
	Rva002AC340();
protected:
	virtual ~Rva002AC340();
private:
	int m_int;
	_STL::vector<BfmeE16> m_vec;
};

Rva002AC340::~Rva002AC340()
{
}
