// cl: /O1 /G7 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
// BFME2's 20-byte BfmeStringRecord00568CE0 vector _M_insert_overflow at RVA 0x0056A12D.
// /G7 emits the retail register allocation and imul; explicit member (not whole-class)
// instantiation keeps the other members owned by the /O1 sibling TU. _Construct is
// declared only so the copies call the rowed body at 0x00568F92.
class AsciiString { public: AsciiString(const AsciiString &); __forceinline ~AsciiString() { releaseBuffer(); } protected: void releaseBuffer(); private: void *m_data; };
struct BfmeStringRecord00568CE0 {
    AsciiString text0, text1;
    unsigned int word0, word1;
    unsigned char flag;
    BfmeStringRecord00568CE0();
    BfmeStringRecord00568CE0(const BfmeStringRecord00568CE0 &o) : text0(o.text0), text1(o.text1), word0(o.word0), word1(o.word1), flag(o.flag) {}
};
#include <vector>
namespace _STL {
template <> void _Construct<BfmeStringRecord00568CE0, BfmeStringRecord00568CE0>(
	BfmeStringRecord00568CE0 *, const BfmeStringRecord00568CE0 &);
}
template void _STL::vector<BfmeStringRecord00568CE0>::_M_insert_overflow(
	BfmeStringRecord00568CE0 *,
	const BfmeStringRecord00568CE0 &,
	const _STL::__false_type &,
	unsigned int,
	bool);
