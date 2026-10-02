// ??1Rva0059A85C@@UAE@XZ
// partial score=0.98 date=2026-10-02
// cl: /O1 /EHs /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfme2_ascii /Ireference/shims/bfmealloc
// stlport
// ??1Rva0059A85C@@UAE@XZ @0x0059A40D 98B
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
// ??1Rva0059A85C@@UAE@XZ present-unmatched
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
