// cl: /O2 /DNDEBUG /MD /EHsc
//
// ??1Rva006ED150@@UAE@XZ, retail 0x006ED150, 139 bytes.
// Derived destructor over base vtable 0x00CEC9CC (the rowed Rva006F8460 dtor)
// with derived vtable 0x00CECB90: frees the +0x0C pointer through the pool when
// +0x2C == 1, destroys the +0x24 sub-object (0x006F84F0), then switches to the
// base vtable and inlines the base dtor -- release the +0x10 member through
// 0x0070A840 and free it with size 0x14. Evidence: derived ctor 0x006ED060
// installs the same 0x00CECB90 vtable; callers 0x006E6045 / 0x006EFB73 and the
// scalar deleting dtor tail-jumps at 0x007A91AB / 0x007A91D3; the pool global
// g_pChainBlockAllocator is defined at FamilyDeletingDtors_Rva006D6D20.cpp.
// The base class name is not recovered, so it stays address-derived.

class Rva0070A840
{
public:
	~Rva0070A840();
};

class Rva006DB270
{
public:
	void freeBlock(void *p, int size);
};

extern Rva006DB270 *g_pChainBlockAllocator;

class Rva006ED150Base
{
public:
	virtual ~Rva006ED150Base();
protected:
	char m_pad04[8];
	void *m_0C;
	Rva0070A840 *m_10;
};

// ??1Rva006ED150Base@@UAE@XZ present-unmatched
inline Rva006ED150Base::~Rva006ED150Base()
{
	Rva0070A840 *p = m_10;
	if (p) {
		p->~Rva0070A840();
		g_pChainBlockAllocator->freeBlock(p, 0x14);
	}
}

class Rva006F84F0
{
public:
	~Rva006F84F0();
private:
	int m_x;
};

class Rva006ED150 : public Rva006ED150Base
{
public:
	virtual ~Rva006ED150();
private:
	char m_pad14[0x10];
	Rva006F84F0 m_24;
	int m_28;
	int m_2C;
};

Rva006ED150::~Rva006ED150()
{
	if (m_2C == 1) {
		g_pChainBlockAllocator->freeBlock(m_0C, 0x40);
	}
}
