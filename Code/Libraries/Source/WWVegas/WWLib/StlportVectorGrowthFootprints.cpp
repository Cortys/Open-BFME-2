// cl: /G7 /O1 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
//
// STLport 4.5.3 vector growth paths and their fill/copy helpers for BFME2
// element types whose other STL helpers are already matched, dedicated TU.
// Each element is reduced to its footprint (size read from the owning TU's
// definition) with an out-of-line copy ctor and dtor: these bodies only
// move elements through _Construct, which is declared as an explicit
// specialization so the copies call the element's matched _Construct row.
//
// Target evidence per body: it is the unowned retail caller of that element's
// matched _Construct / __uninitialized_fill_n rows, byte-identical with
// relocations masked; the remaining callees are rows or pins to matched
// bodies they reproduce. /G7 emits retail's imul element scaling (the
// AnimSet sibling's IMUL recipe), bfmealloc keeps allocate a two-argument
// call and _STLP_NO_EXCEPTIONS drops the EH frame retail does not have.
#define _STLP_NO_EXCEPTIONS 1
#include <vector>

// 32-byte element; layout owner stlport_bfmeassignrecord32_destroy.cpp.
struct BfmeAssignRecord32 { char m_pad[32]; public: BfmeAssignRecord32(const BfmeAssignRecord32 &); ~BfmeAssignRecord32(); };
// 8-byte element; layout owner StlportVectorDtorChains.cpp.
class Rva002390CB { char m_pad[8]; public: Rva002390CB(const Rva002390CB &); ~Rva002390CB(); };
// 20-byte element; layout owner Rva003371B1Copy.cpp.
class Rva003371B1 { char m_pad[20]; public: Rva003371B1(const Rva003371B1 &); ~Rva003371B1(); };
// 20-byte element; layout owner stlport_vector_stringrecord_5ed5f3_allocate_copy.cpp.
struct BfmeStringRecord005ED5F3 { char m_pad[20]; public: BfmeStringRecord005ED5F3(const BfmeStringRecord005ED5F3 &); ~BfmeStringRecord005ED5F3(); };
// 36-byte element; layout owner stlport_vector_rva0007bb16_destroy.cpp.
struct Rva0007BB16Record { char m_pad[36]; public: Rva0007BB16Record(const Rva0007BB16Record &); ~Rva0007BB16Record(); };
// 36-byte element; layout owner StringContainerRecordCopyBFME2.cpp.
struct BfmeRecord001ECAF9 { char m_pad[36]; public: BfmeRecord001ECAF9(const BfmeRecord001ECAF9 &); ~BfmeRecord001ECAF9(); };
// 36-byte element; layout owner StringVectorRecordCopyBFME2.cpp.
struct BfmeVectorRecord002AF478 { char m_pad[36]; public: BfmeVectorRecord002AF478(const BfmeVectorRecord002AF478 &); ~BfmeVectorRecord002AF478(); };
// 16-byte element; layout owner StringRecordCopyBFME2.cpp.
struct BfmeStringRecord0040360E { char m_pad[16]; public: BfmeStringRecord0040360E(const BfmeStringRecord0040360E &); ~BfmeStringRecord0040360E(); };
// 24-byte element; layout owner StringRecordCopyBFME2.cpp.
struct BfmeStringRecord00404BF3 { char m_pad[24]; public: BfmeStringRecord00404BF3(const BfmeStringRecord00404BF3 &); ~BfmeStringRecord00404BF3(); };

namespace _STL
{
template <> void _Construct<BfmeAssignRecord32, BfmeAssignRecord32>(BfmeAssignRecord32 *, const BfmeAssignRecord32 &);
template <> void _Construct<Rva002390CB, Rva002390CB>(Rva002390CB *, const Rva002390CB &);
template <> void _Construct<Rva003371B1, Rva003371B1>(Rva003371B1 *, const Rva003371B1 &);
template <> void _Construct<BfmeStringRecord005ED5F3, BfmeStringRecord005ED5F3>(BfmeStringRecord005ED5F3 *, const BfmeStringRecord005ED5F3 &);
template <> void _Construct<Rva0007BB16Record, Rva0007BB16Record>(Rva0007BB16Record *, const Rva0007BB16Record &);
template <> void _Construct<BfmeRecord001ECAF9, BfmeRecord001ECAF9>(BfmeRecord001ECAF9 *, const BfmeRecord001ECAF9 &);
template <> void _Construct<BfmeVectorRecord002AF478, BfmeVectorRecord002AF478>(BfmeVectorRecord002AF478 *, const BfmeVectorRecord002AF478 &);
template <> void _Construct<BfmeStringRecord0040360E, BfmeStringRecord0040360E>(BfmeStringRecord0040360E *, const BfmeStringRecord0040360E &);
template <> void _Construct<BfmeStringRecord00404BF3, BfmeStringRecord00404BF3>(BfmeStringRecord00404BF3 *, const BfmeStringRecord00404BF3 &);
}

// Retail 0x0015239D.
template void _STL::vector<Rva0007BB16Record>::reserve(unsigned int);
// Retail 0x00173FE9.
template void _STL::vector<BfmeAssignRecord32>::_M_insert_overflow(
    BfmeAssignRecord32 *, const BfmeAssignRecord32 &, const _STL::__false_type &, unsigned int, bool);
// Retail 0x001ECD5F.
template BfmeRecord001ECAF9 *_STL::__uninitialized_fill_n<BfmeRecord001ECAF9 *, unsigned int, BfmeRecord001ECAF9>(
    BfmeRecord001ECAF9 *, unsigned int, const BfmeRecord001ECAF9 &, const _STL::__false_type &);
// Retail 0x001ECD84.
template BfmeRecord001ECAF9 *_STL::__uninitialized_copy<BfmeRecord001ECAF9 *, BfmeRecord001ECAF9 *>(
    BfmeRecord001ECAF9 *, BfmeRecord001ECAF9 *, BfmeRecord001ECAF9 *, const _STL::__false_type &);
// Retail 0x001ED13A.
template void _STL::vector<BfmeRecord001ECAF9>::_M_insert_overflow(
    BfmeRecord001ECAF9 *, const BfmeRecord001ECAF9 &, const _STL::__false_type &, unsigned int, bool);
// Retail 0x002AF67A.
template BfmeVectorRecord002AF478 *_STL::__uninitialized_copy<BfmeVectorRecord002AF478 *, BfmeVectorRecord002AF478 *>(
    BfmeVectorRecord002AF478 *, BfmeVectorRecord002AF478 *, BfmeVectorRecord002AF478 *, const _STL::__false_type &);
// Retail 0x002AF6A0.
template BfmeVectorRecord002AF478 *_STL::__uninitialized_fill_n<BfmeVectorRecord002AF478 *, unsigned int, BfmeVectorRecord002AF478>(
    BfmeVectorRecord002AF478 *, unsigned int, const BfmeVectorRecord002AF478 &, const _STL::__false_type &);
// Retail 0x002B1418.
template void _STL::vector<BfmeVectorRecord002AF478>::_M_insert_overflow(
    BfmeVectorRecord002AF478 *, const BfmeVectorRecord002AF478 &, const _STL::__false_type &, unsigned int, bool);
// Retail 0x00337B57.
template void _STL::vector<Rva003371B1>::_M_insert_overflow(
    Rva003371B1 *, const Rva003371B1 &, const _STL::__false_type &, unsigned int, bool);
// Retail 0x00339EB3.
template void _STL::vector<Rva002390CB>::_M_insert_overflow(
    Rva002390CB *, const Rva002390CB &, const _STL::__false_type &, unsigned int, bool);
// Retail 0x00403666.
template BfmeStringRecord0040360E *_STL::__uninitialized_copy<BfmeStringRecord0040360E *, BfmeStringRecord0040360E *>(
    BfmeStringRecord0040360E *, BfmeStringRecord0040360E *, BfmeStringRecord0040360E *, const _STL::__false_type &);
// Retail 0x0040368C.
template BfmeStringRecord0040360E *_STL::__uninitialized_fill_n<BfmeStringRecord0040360E *, unsigned int, BfmeStringRecord0040360E>(
    BfmeStringRecord0040360E *, unsigned int, const BfmeStringRecord0040360E &, const _STL::__false_type &);
// Retail 0x00404C8D.
template BfmeStringRecord00404BF3 *_STL::__uninitialized_copy<BfmeStringRecord00404BF3 *, BfmeStringRecord00404BF3 *>(
    BfmeStringRecord00404BF3 *, BfmeStringRecord00404BF3 *, BfmeStringRecord00404BF3 *, const _STL::__false_type &);
// Retail 0x00404CB3.
template BfmeStringRecord00404BF3 *_STL::__uninitialized_fill_n<BfmeStringRecord00404BF3 *, unsigned int, BfmeStringRecord00404BF3>(
    BfmeStringRecord00404BF3 *, unsigned int, const BfmeStringRecord00404BF3 &, const _STL::__false_type &);
// Retail 0x005EDABD.
template void _STL::vector<BfmeStringRecord005ED5F3>::_M_insert_overflow(
    BfmeStringRecord005ED5F3 *, const BfmeStringRecord005ED5F3 &, const _STL::__false_type &, unsigned int, bool);
