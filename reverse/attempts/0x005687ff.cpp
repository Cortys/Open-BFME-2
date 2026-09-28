// ??$__unguarded_linear_insert@PAPAXPAXURva00568721Cmp@@@_STL@@YAXPAPAXPAXURva00568721Cmp@@@Z
// partial score=0.93 date=2026-09-28
// ??$__unguarded_linear_insert@PAPAXPAXURva00568721Cmp@@@_STL@@YAXPAPAXPAXURva00568721Cmp@@@Z
// partial score=0.93 date=2026-09-28
// cl: /O1 /G7 /DNDEBUG /MD /EHsc /Oy-
// stlport
struct Rva00568721Cmp
{
    bool operator()(const void *a, const void *b) const;
};
namespace _STL
{
template <class _RandomAccessIter, class _Tp, class _Compare>
inline void __unguarded_linear_insert(_RandomAccessIter __last, _Tp __val, _Compare __comp)
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
template void __unguarded_linear_insert<void **, void *, Rva00568721Cmp>(void **, void *, Rva00568721Cmp);
}
