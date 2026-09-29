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

// ?Rva0052BF4DDestroyTagged@@YAXPAURva0052BF4DElem@@0ABU__false_type@_STL@@@Z
// @0x0052BF4D 26B. Unlock lane: same tagged virtual loop as 0x0052BF33 above
// but stride 0x28; caller at 0x0052C274; unblocks 0x0052C266.
struct Rva0052BF4DElem
{
	virtual ~Rva0052BF4DElem();
	char m_pad[36];
};

void Rva0052BF4DDestroyTagged(Rva0052BF4DElem *first, Rva0052BF4DElem *last, const _STL::__false_type &tag)
{
	for (; first != last; ++first)
		first->~Rva0052BF4DElem();
}

// ?Rva0052BF67DestroyTagged@@YAXPAURva0052BF67Elem@@0ABU__false_type@_STL@@@Z
// @0x0052BF67 26B. Unlock lane: same tagged virtual loop as above but stride
// 0x20; caller at 0x0052C3CD; unblocks 0x0052C3BF.
struct Rva0052BF67Elem
{
	virtual ~Rva0052BF67Elem();
	char m_pad[28];
};

void Rva0052BF67DestroyTagged(Rva0052BF67Elem *first, Rva0052BF67Elem *last, const _STL::__false_type &tag)
{
	for (; first != last; ++first)
		first->~Rva0052BF67Elem();
}
