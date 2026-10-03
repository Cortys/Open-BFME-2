// cl: /O1 /DNDEBUG /MD /GX /Ireference/shims/moduledata
//
// ??1Rva004E179A@@UAE@XZ 81B @0x004E179A: ModuleData dtor with three
// StringBase<char> members at +0x4/+0x8/+0xC (inlined releaseBuffer calls
// via rowed 0x00036410) plus Snapshot vtable restore to 0x007BB554.
// Derived vtable 0x00861B78 stored at entry. Unlock lane: landing unblocks
// 0x004E1CFA/28. Evidence: EH prolog 0x00791A74 plus states 2/1/0 plus
// three releaseBuffer plus second vtable 0x007BB554 plus ret, callers at
// 0x004E183A 0x004E1CFD. The canonical Snapshot header supplies the base dtor;
// StringBase remains inline to match this unit.

#include "Common/Snapshot.h"

template <typename T> class StringBase
{
public:
	~StringBase() { releaseBuffer(); }
private:
	void releaseBuffer();
	T *m_data;
};

// Existing public narrow teardown spelling resolves to the verified
// 133-byte releaseBuffer worker at RVA 0x36410. Wide teardown is unchanged.
template <> StringBase<char>::~StringBase();
#pragma comment(linker, "/alternatename:??1?$StringBase@D@@QAE@XZ=?releaseBuffer@?$StringBase@D@@AAEXXZ")


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
