// ?rva0047B628@Rva0047B628@@QAEXHPAX@Z
// partial score=0.93 date=2026-10-03
// ?rva0047B628@Rva0047B628@@QAEXHPAX@Z
// partial score=0.93 date=2026-10-02
// cl: /O1 /DNDEBUG /MD /EHs /arch:SSE /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// ??1AODHordeContain@@UAE@XZ, retail 0x0047B563, 197 bytes.
// Slot evidence: ??_G at 0x0047B674 (ContainModuleDeletingDtors) calls here.
// Restores 11 vptrs (+0x00 +0x0C +0x10 +0x20 +0x24 +0x28 +0x2C +0x30 +0x34
// +0xFC +0x11C) then destroys vector at +0x30C (free via 0x00030830, state 0)
// plus 60 x 0x10 array at +0x338 and 20 x 0x18 array at +0x6FC through ehvec
// 0x00629110 (states 1-2, empty element dtors DIR32-masked to retail 0x4B3FD0)
// then calls pinned ??1HordeContain@@UAE@XZ at 0x0046F901. Layout from the
// rowed ctor 0x0047B3DB in AODHordeContainCtor.cpp (vector plus two-array
// concept from BFME1 AODHordeContainDestructors.cpp; BFME2 offsets +0x30C /
// +0x338 / +0x6FC, factory news 0x8E0). Identity is the ModuleFactory
// AODHordeContain registration plus the audited deleting-dtor caller.
#include <vector>

class Thing;
class ModuleData;

struct Iface00 { virtual void f00(); unsigned char m_pad[8]; };
struct Iface0C { virtual void f0C(); };
struct Iface10 { virtual void f10(); unsigned char m_pad[12]; };
struct Iface20 { virtual void f20(); };
struct Iface24 { virtual void f24(); };
struct Iface28 { virtual void f28(); };
struct Iface2C { virtual void f2C(); };
struct Iface30 { virtual void f30(); };
struct Iface34 { virtual void f34(); unsigned char m_pad[0xFC - 0x38]; };
struct IfaceFC { virtual void fFC(); unsigned char m_pad[0x11C - 0x100]; };
struct Iface11C { virtual void f11C(); unsigned char m_pad[0x30C - 0x11C - 4]; };

class HordeContain
	: public Iface00
	, public Iface0C
	, public Iface10
	, public Iface20
	, public Iface24
	, public Iface28
	, public Iface2C
	, public Iface30
	, public Iface34
	, public IfaceFC
	, public Iface11C
{
public:
	virtual ~HordeContain();
};

struct BfmeE16
{
	float x;
	float y;
	float z;
	float w;
};

struct AODDtorElem16
{
	~AODDtorElem16();
	float m_f[4];
};

// ??1AODDtorElem16@@QAE@XZ present-unmatched
AODDtorElem16::~AODDtorElem16()
{
}

struct AODDtorElem24
{
	~AODDtorElem24();
	float m_f[5];
	unsigned char m_b;
	unsigned char m_pad[3];
};

// ??1AODDtorElem24@@QAE@XZ present-unmatched
AODDtorElem24::~AODDtorElem24()
{
}

class GameLogic
{
public:
	unsigned char m_pad[0x40];
	int m_40;
};

extern GameLogic *TheGameLogic;

class Rva0047B628
{
public:
	void rva0047B628(int a, void *b);

private:
	unsigned char m_pad[0x1FC];
	int m_1FC;
	int m_200;
};

class AODHordeContain : public HordeContain
{
public:
	virtual ~AODHordeContain();
	void refreshTrackedLargeUnit();

private:
	_STL::vector<BfmeE16> m_vector;
	int m_318;
	int m_31C;
	float m_320[3];
	float m_32C;
	float m_330;
	float m_334;
	AODDtorElem16 m_arrayA[0x3C];
	int m_6F8;
	AODDtorElem24 m_arrayB[0x14];
	int m_8DC;
};

// ??1AODHordeContain@@UAE@XZ
AODHordeContain::~AODHordeContain()
{
}

// ?rva0047B628@Rva0047B628@@QAEXHPAX@Z, retail 0x0047B628, 76 bytes.
// Gap between ??1 (0x0047B563) and ??_G (0x0047B674) in this TU; same flags.
// Large-unit tracker update: validates the second arg (null, +0x438 flag,
// +0x4 -> +0x5F5 == 2), stores +0x74 to +0x1FC (full +0x318) unless equal,
// refreshes via full-0x11C, then +0x200 (full +0x31C) from TheGameLogic+0x40.
// Callers: none rowed. Callees rowed: refreshTrackedLargeUnit 0x0047B2AA,
// TheGameLogic ?TheGameLogic@@3PAVGameLogic@@A.
// ?rva0047B628@Rva0047B628@@QAEXHPAX@Z present-unmatched
void Rva0047B628::rva0047B628(int a, void *b)
{
	if (b == 0)
		return;
	if (*((unsigned char *)b + 0x438) & 1)
		return;
	void *p = *(void **)((char *)b + 4);
	if (*((unsigned char *)p + 0x5F5) != 2)
		return;
	int v = *(int *)((char *)b + 0x74);
	if (v == m_1FC)
		return;
	m_1FC = v;
	((AODHordeContain *)((char *)this - 0x11C))->refreshTrackedLargeUnit();
	m_200 = TheGameLogic->m_40;
}
