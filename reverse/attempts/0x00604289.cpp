// ?Rva00604289Construct@@YAXPAVRva0060426C@@ABV1@@Z
// partial score=0.93 date=2026-10-04
// cl: /O1 /EHs /MD /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_CRTIMP= /D_BFME_RETAIL_TREE_INSERT_LAYOUT
// stlport
// ??0Rva0060426C@@QAE@ABV0@@Z @0x0060426C 29B: copy ctor copies dword +0 then map<unsigned void*> at +4 via rowed Rb_tree copy 0x00603EEB. Evidence: callers 0x00604289 0x006045A2; callee rowed.
#include <map>

class Rva0060426C
{
public:
	unsigned int m_first;
	_STL::map<unsigned int, void *> m_map;
	Rva0060426C(const Rva0060426C &other);
};

Rva0060426C::Rva0060426C(const Rva0060426C &other) : m_first(other.m_first), m_map(other.m_map)
{
}

// ?Rva00604289Construct@@YAXPAVRva0060426C@@ABV1@@Z present-unmatched
void Rva00604289Construct(Rva0060426C *dest, const Rva0060426C &src)
{
	if (dest != 0)
		new(dest) Rva0060426C(src);
}
