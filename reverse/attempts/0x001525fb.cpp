// ??0Rva001525FB@@QAE@XZ
// partial score=0.95 date=2026-10-01
// ??0Rva001525FB@@QAE@XZ
// partial score=0.95 date=2026-10-01
// cl: /O1 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
// ??0Rva001525FB@@QAE@XZ, retail 0x001525FB, 66 bytes.
// Ctor: vtable at +0, NumRefs=1 at +4 via inline base, ObjectCreationList
// at +0xc, ints at +8/+0x18/+0x1c(=4)/+0x20/+0x24, vector<BfmeE16> at +0x28.
// Evidence: unlock lane, callees rowed ObjectCreationList 0x001F81BF and
// Vector_base e16 0x00211E58, callers 0x00152C47 0x0018AF70, base-before-vptr
// order proves +4 from base (refcount 1) with derived vptr second.
#include <vector>

struct BfmeE16 { float x, y, z, w; };

class ObjectCreationList
{
public:
	ObjectCreationList();
private:
	char m_pad[12];
};

class Rva001525FBBase
{
public:
// ??0Rva001525FBBase@@QAE@XZ present-unmatched
	Rva001525FBBase() : m_00(1) {}
private:
	int m_00;
};

class Rva001525FB : public Rva001525FBBase
{
public:
	Rva001525FB();
	virtual void Delete_This();
private:
	int m_08;
	ObjectCreationList m_list;
	int m_18;
	int m_1c;
	int m_20;
	int m_24;
	_STL::vector<BfmeE16> m_vec;
};

// ??0Rva001525FB@@QAE@XZ present-unmatched
Rva001525FB::Rva001525FB() : Rva001525FBBase(), m_08(0), m_18(0), m_1c(4), m_20(0), m_24(0)
{
}
