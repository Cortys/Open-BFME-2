// cl: /O1 /G7 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
//
// ?_M_insert_overflow@?$vector@UCoord3D@@V?$allocator@UCoord3D@@@_STL@@@_STL@@IAEXPAUCoord3D@@ABU3@ABU__false_type@2@I_N@Z @0x002CDF8A 189B:
// Vector<Coord3D> fill overflow via rowed allocate 0x395928 plus Coord3D workers copy 0x346C2D fill 0x2CA849 plus Construct pin 0x2CA82C plus free 0x30830.
// Evidence: same 5-arg ret-0x14 shape as PrereqUnitRec overflow 0x2A1C02; callers 0x8280D 0xCA2E2 0xCE809; unblocks 0x2CE7DC 0xCA1EE 0x82719.
#include <vector>
struct Coord3D {
  float x, y, z;
  Coord3D(const Coord3D &that) throw();
};
namespace _STL {
template <> void _Construct<Coord3D, Coord3D>(Coord3D *, const Coord3D &);
}
template void _STL::vector<Coord3D>::_M_insert_overflow(Coord3D *, const Coord3D &, const _STL::__false_type &, unsigned int, bool);
