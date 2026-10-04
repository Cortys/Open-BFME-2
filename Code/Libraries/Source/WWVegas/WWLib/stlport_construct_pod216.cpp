// cl: /Ireference/shims/bfme2_ascii /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ??$_Construct@UBfmePod216@@U1@@_STL@@YAXPAUBfmePod216@@ABU1@@Z @0x0021EF66 45B: placement copy of 216B element via rowed Rva0021E85A copy ctor 0x0021E85A. Callers in stlport_pod_vector_bodies.cpp (__uninitialized_copy/fill_n/push_back).
#include <new>
#include <vector>
struct BfmePod216 { int a[54]; };
class Rva0021E85A
{
public:
	Rva0021E85A(const Rva0021E85A &o);
};
namespace _STL {
template <> inline void _Construct<BfmePod216, BfmePod216>(BfmePod216 *__p, const BfmePod216 &__val)
{
	new ((void *)__p) Rva0021E85A((const Rva0021E85A &)__val);
}
}

#pragma inline_depth(0)
// ?bfmeEmitPod216Construct@@YAXPAUBfmePod216@@ABU1@@Z present-unmatched
void bfmeEmitPod216Construct(BfmePod216 *p, const BfmePod216 &q)
{
	_STL::_Construct<BfmePod216, BfmePod216>(p, q);
}
#pragma inline_depth()
