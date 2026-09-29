// cl: /O1
//
// ?Rva002E1EB7Insert@@YAXPAPAX0PAX1@Z @0x002E1EB7 58B.
// Guarded linear insert over void* elements keyed at +0xC. If new key exceeds
// first key shifts via rowed __copy_trivial_backward at 0x620840 and stores
// at first, else delegates to rowed Rva002E08A2Insert at 0x002E08A2.
// Evidence: caller 0x002E2167; prev/next share /O1; mirrors Rva005B639FGuarded.
namespace _STL
{
void *__copy_trivial_backward(const void *first, const void *last, void *result);
}

void Rva002E08A2Insert(void **pos, void *val, void *extra);

void Rva002E1EB7Insert(void **first, void **last, void *val, void *extra)
{
	if (((int *)val)[3] > ((int *)(*first))[3]) {
		_STL::__copy_trivial_backward(first, last, last + 1);
		*first = val;
	}
	else {
		Rva002E08A2Insert(last, val, extra);
	}
}

// ?Rva002E214ESort@@YAXPAPAX0PAX@Z @0x002E214E 45B.
// Insertion sort via guarded insert: for each slot from begin+1 to end call
// Rva002E1EB7Insert with (begin slot value extra). Evidence: callers
// 0x002E2307 0x002E2325; callee rowed 0x002E1EB7.
void Rva002E214ESort(void **begin, void **end, void *extra)
{
	if (begin == end)
		return;
	for (void **p = begin + 1; p != end; ++p)
		Rva002E1EB7Insert(begin, p, *p, extra);
}
