// cl: /O1 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
//
// ??$__uninitialized_fill_n@PAUBfmeAssignRecord32@@IU1@@_STL@@YAPAUBfmeAssignRecord32@@PAU1@IABU1@ABU__false_type@0@@Z
// @ 0x0017381C (37B): count loop constructing via the rowed _Construct at
// 0x001737EF striding 0x20. Callers at 0x001739C3 and 0x00174054.
// ??$__uninitialized_copy@PBUBfmeAssignRecord32@@PAU1@@_STL@@YAPAUBfmeAssignRecord32@@PBU1@0PAU1@ABU__false_type@0@@Z
// @ 0x0017398C (38B): range loop constructing via the same rowed _Construct
// striding 0x20. Callers at 0x00174027 0x00174072 0x00174293 0x001742E4.
// Minimal 32-byte struct with the struct-ness of the rowed copy ctor at
// 0x00173731; no member is touched. Same flags as the sibling
// stlport_vector_stringrecord_111acf_allocate_copy.cpp.
#include <vector>
struct BfmeAssignRecord32 {
	BfmeAssignRecord32();
	BfmeAssignRecord32(const BfmeAssignRecord32 &other);
	char m_body[0x20];
};
namespace _STL {
template <> void _Construct<BfmeAssignRecord32, BfmeAssignRecord32>(BfmeAssignRecord32 *, const BfmeAssignRecord32 &);
}
template class _STL::vector<BfmeAssignRecord32, _STL::allocator<BfmeAssignRecord32> >;
