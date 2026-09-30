// ??0?$vector@URva0007BB16Record@@V?$allocator@URva0007BB16Record@@@_STL@@@_STL@@QAE@ABV01@@Z
// partial score=0.97 date=2026-09-30
// ??0?$vector@URva0007BB16Record@@V?$allocator@URva0007BB16Record@@@_STL@@@_STL@@QAE@ABV01@@Z
// partial score=0.97 date=2026-09-30
// cl: /G7 /O1 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
// ??0?$vector@URva0007BB16Record@@V?$allocator@URva0007BB16Record@@@_STL@@@_STL@@QAE@ABV01@@Z @0x0010E604 (96B):
// vector<Rva0007BB16Record> copy ctor sibling of the _M_insert_overflow and
// push_back rows in StlportVectorGrowthFootprints.cpp. Evidence: element
// stride 0x24 matches the 36-byte Rva0007BB16Record footprint; callees are
// the rowed AsciiString get_allocator @0x0021983A, the 36B GeometryShape
// count-taking _Vector_base @0x0010E5A2 and the Rva0007BB16Record
// __uninitialized_copy @0x0010E5DE.
#define _STLP_NO_EXCEPTIONS 1
#include <vector>

// 36-byte element; layout owner stlport_vector_rva0007bb16_destroy.cpp.
struct Rva0007BB16Record { char m_pad[36]; public: Rva0007BB16Record(const Rva0007BB16Record &); ~Rva0007BB16Record(); };

namespace _STL
{
template <> void _Construct<Rva0007BB16Record, Rva0007BB16Record>(Rva0007BB16Record *, const Rva0007BB16Record &);
}

// ??0?$vector@URva0007BB16Record@@V?$allocator@URva0007BB16Record@@@_STL@@@_STL@@QAE@ABV01@@Z present-unmatched
template _STL::vector<Rva0007BB16Record>::vector(const _STL::vector<Rva0007BB16Record> &);
