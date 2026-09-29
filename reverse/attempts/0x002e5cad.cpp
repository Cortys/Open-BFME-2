// ??$__unguarded_linear_insert@PAUStringLookUp@@U1@UStringLookUpLess@@@_STL@@YAXPAUStringLookUp@@U1@UStringLookUpLess@@@Z
// partial score=0.95 date=2026-09-29
// ??$__unguarded_linear_insert@PAUStringLookUp@@U1@UStringLookUpLess@@@_STL@@YAXPAUStringLookUp@@U1@UStringLookUpLess@@@Z
// partial score=0.95 date=2026-09-29
// cl: /O1 /DNDEBUG /DWIN32 /MD /D_STLP_USE_STATIC_LIB
// stlport
// ??$__unguarded_linear_insert@PAUStringLookUp@@U1@UStringLookUpLess@@@_STL@@YAXPAUStringLookUp@@U1@UStringLookUpLess@@@Z 0x002E5CAD 60B
// Evidence: unlock calls rowed compareStringLookUpLess 0x002E5678; 8B StringLookUp; callers 0x002E60C2 0x002E6232.
bool __stdcall compareStringLookUpLess(const void *left, const void *right);

struct StringLookUp
{
	void *label;
	void *info;
};

struct StringLookUpLess
{
	bool operator()(const StringLookUp &a, const StringLookUp &b) const
	{
		return compareStringLookUpLess(&a, &b);
	}
};

namespace _STL
{

template <class _RandomAccessIter, class _Tp, class _Compare>
void __unguarded_linear_insert(_RandomAccessIter __last, _Tp __val, _Compare __comp)
{
	_RandomAccessIter __next = __last;
	--__next;
	while (__comp(__val, *__next))
	{
		*__last = *__next;
		__last = __next;
		--__next;
	}
	*__last = __val;
}

template void __unguarded_linear_insert<StringLookUp *, StringLookUp,
	StringLookUpLess>(StringLookUp *, StringLookUp, StringLookUpLess);

}
