// cl: /O1 /MD
//
// ??1Rva001E3E43@@UAE@XZ, retail 0x001E3E43, 19 bytes.
// Scalar dtor: stores derived vtable 0x00BDE888, dec global 0x00DFDC64,
// restores Snapshot base vtable 0x00BBB554. Called by deleting dtor
// at 0x001E4625 (push esi / call 0x1E3E43 / test [esp+8],1 / delete).
// Owner identity unproven, honest Rva name.

extern "C" const void *const vtbl_00BBB554[];  // folded, 23 classes; via ??_7BfmeBaseVUQ@@6B@
#pragma comment(linker, "/alternatename:_vtbl_00BBB554=??_7BfmeBaseVUQ@@6B@")

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
	*(const void **)this = reinterpret_cast<const void *>(((unsigned int)vtbl_00BBB554));
}

class Rva001E3E43 : public Snapshot
{
public:
	virtual ~Rva001E3E43();
};

extern int g_Va00DFDC64;
// g_Va00DFDC64: matched references place it at VA 0xdfdc64 (zero-filled .bss).
int g_Va00DFDC64;

Rva001E3E43::~Rva001E3E43()
{
	--g_Va00DFDC64;
}
