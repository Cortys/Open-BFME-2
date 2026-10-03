// ??1Rva0059A85C@@UAE@XZ
// partial score=0.99 date=2026-10-03
// ??1Rva0059A85C@@UAE@XZ
// partial score=0.99 date=2026-10-03
// ??1Rva0059A85C@@UAE@XZ
// cl: /O1 /EHs /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfme2_ascii /Ireference/shims/bfmealloc
// stlport
// dtor of Rva0059A85C (vtable 0x00870DE4); callees rowed erase set-dtor free setter
// Target evidence: vtable store 0x00870DE4; callers 0x004EC640 0x0059A480; unblocks 0x0059A47D; neighbours 0x0059A281 0x0059A71C
#include <vector>
#include <set>
class Rva00506B1B
{
public:
	Rva00506B1B();
	virtual ~Rva00506B1B();
	virtual void v0();
	virtual void v1();
	bool m_04;
};

// Retail's derived destructor tail-calls the base destructor at +0x4F:
//   mov ecx,edi ; call 0x00506B28
// and 0x00506B28 is the 7-byte body `mov DWORD PTR [ecx],0x00C63F9C; ret`
// -- the base vtable store, byte-identical to the body the ledger already
// verifies for ?apply@Rva00506B28DwordImmSetter@@QAEXXZ. The store is reached
// through a volatile function pointer so MSVC cannot inline it into the
// derived destructor -- retail calls the base destructor, it does not store
// the base vtable inline. The call target is pinned to 0x00506B28 in
// reverse/symbols.csv.
typedef void (*BaseDtorFn)(Rva00506B1B *);

extern BaseDtorFn volatile g_00506B28BaseDtor;

Rva00506B1B::~Rva00506B1B()
{
	((BaseDtorFn)g_00506B28BaseDtor)(this);
}
struct BfmeE16 { float x, y, z, w; };
#include "ascii_string.h"
class Rva002EE9B7
{
public:
	~Rva002EE9B7() throw();
};
extern const void *const g_00C70DE4[];
class Rva0059A85C : public Rva00506B1B
{
public:
	Rva0059A85C(void *outer);
	virtual ~Rva0059A85C();
private:
	_STL::vector<void *> m_vec;
	void *m_outer;
	Rva002EE9B7 m_tree;
};

Rva0059A85C::~Rva0059A85C()
{
	m_vec.clear();
}
