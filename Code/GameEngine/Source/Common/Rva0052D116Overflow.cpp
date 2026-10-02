// cl: /G7 /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
// ?_M_insert_overflow@?$vector@VRva002E0A0A@@V?$allocator@VRva002E0A0A@@@_STL@@@_STL@@IAEXPAVRva002E0A0A@@ABV3@ABU__false_type@2@I_N@Z 0x0052D116 183B evidence: chain via 0x0052C203 now ready; idiv-0x28 stride 40 via Rva002E0A0A class to match rowed Construct V; callees allocate Pod40 0x000B4039 copy 0x0052C203 Construct 0x0052C1D6 fill 0x0052C229 tidy 0x005659E8; caller 0x0052D34B; precedent Rva0056644EOverflow same recipe; v3 add /G7 for imul-0x28 like Pod40 allocate.
#include <vector>
class Rva002E0A0A {
    char opaque[40];
public:
    Rva002E0A0A(const Rva002E0A0A &);
    Rva002E0A0A &operator=(const Rva002E0A0A &);
    ~Rva002E0A0A();
};
namespace _STL {
template <> void _Construct<Rva002E0A0A, Rva002E0A0A>(
    Rva002E0A0A *, const Rva002E0A0A &);
}
template void _STL::vector<Rva002E0A0A>::_M_insert_overflow(
    Rva002E0A0A *, const Rva002E0A0A &,
    const _STL::__false_type &, unsigned int, bool);
