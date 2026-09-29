// cl: /O1 /DNDEBUG /MD /GX-
// ?Rva0052BF33DestroyTagged@@YAXPAURva0052BF33Elem@@0ABU__false_type@_STL@@@Z
// @0x0052BF33 26B. Unlock lane: destroys range through each 8-byte element's
// virtual dtor (scalar-deleting slot with zero flag); caller 0x005A6EDA is the
// tag-dispatch DestroyRange. Same shape as Rva0052BF81_DestroyTagged in
// LivingWorldRegionConnectionHelpers.cpp but stride 8. Next is that TU.
namespace _STL
{
struct __false_type
{
};
}

struct Rva0052BF33Elem
{
	virtual ~Rva0052BF33Elem();
	char m_pad[4];
};

void Rva0052BF33DestroyTagged(Rva0052BF33Elem *first, Rva0052BF33Elem *last, const _STL::__false_type &tag)
{
	for (; first != last; ++first)
		first->~Rva0052BF33Elem();
}
