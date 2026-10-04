// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ??$__copy_ptrs@PAUBfmeObject476@@PAU1@@_STL@@YAPAUBfmeObject476@@PAU1@00ABU__false_type@0@@Z @0x001FEF62 29B: STLport __copy_ptrs wrapper for BfmeObject476*. Forwards first/last/result to the rowed 5-arg __copy 0x001FEB55 with a fresh random_access tag and (int*)0. Evidence: retail 29B push-0 plus lea-tag plus 3-push shape calling rowed __copy; caller 0x001FEFB9 erase passes 4 args including false_type tag.
struct BfmeObject476
{
    virtual ~BfmeObject476();
    unsigned char opaque[472];
    BfmeObject476();
    BfmeObject476(const BfmeObject476 &);
};
namespace _STL
{
struct __false_type
{
};
struct random_access_iterator_tag
{
};
template <class InputIter, class OutputIter, class Distance>
OutputIter __copy(InputIter first, InputIter last, OutputIter result, const random_access_iterator_tag &tag, Distance *extra);
template <class InputIter, class OutputIter>
OutputIter __copy_ptrs(InputIter first, InputIter last, OutputIter result, const __false_type &tag);
}
template <>
__declspec(noinline) BfmeObject476 *_STL::__copy_ptrs<BfmeObject476 *, BfmeObject476 *>(BfmeObject476 *first, BfmeObject476 *last, BfmeObject476 *result, const _STL::__false_type &tag)
{
    __false_type local;
    return _STL::__copy(first, last, result, reinterpret_cast<const random_access_iterator_tag &>(local), (int *)0);
}
