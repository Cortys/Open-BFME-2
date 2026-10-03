// ?Rva005EF46BCopyBackward@@YAPAVRva005EEFD2@@PAV1@00@Z
// partial score=0.99 date=2026-10-03
// cl: /O1 /MD
// ?Rva005EF46BCopyBackward@@YAPAVRva005EEFD2@@PAV1@00@Z retail 0x005EF46B 29B
// Evidence: 3-arg wrapper forwarding to 5-arg __copy_backward at 0x005EF000 with tag and null Distance*; pushes 0 and tag temp; caller 0x005EFCA6; callee row 0x005EF000.
class Rva005EEFD2
{
public:
	Rva005EEFD2 &operator=(const Rva005EEFD2 &other);
};

namespace _STL
{
	struct random_access_iterator_tag {};
	Rva005EEFD2 *__cdecl CopyBackward5(Rva005EEFD2 *first, Rva005EEFD2 *last, Rva005EEFD2 *result, const random_access_iterator_tag &tag, int *dist);
}

// ?Rva005EF46BCopyBackward@@YAPAVRva005EEFD2@@PAV1@00@Z present-unmatched
Rva005EEFD2 *__cdecl Rva005EF46BCopyBackward(Rva005EEFD2 *first, Rva005EEFD2 *last, Rva005EEFD2 *result)
{
	_STL::random_access_iterator_tag tag;
	return _STL::CopyBackward5(first, last, result, tag, (int *)0);
}
