// cl: /O1 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
// ?_M_insert_overflow@?$vector@U?$pair@$$CBVAsciiString@@D@_STL@@V?$allocator@U?$pair@$$CBVAsciiString@@D@_STL@@@2@@_STL@@IAEXPAU?$pair@$$CBVAsciiString@@D@2@ABU32@ABU__false_type@2@I_N@Z @0x0021E356 178B: vector<pair<const AsciiString,char>> growth path, same 178B sar-3/lea-8 shape as BfmeStringRecord00426A5B overflow 0x00426DE2 in same flags; calls rowed allocate 0x523D6C via ICF pin plus rowed copy 0x21AA7A plus rowed Construct 0x21A9B7 plus rowed fill_n 0x21AAA0 plus shared clear 0x4C3D8B; caller push_back 0x21E70A.
class AsciiString { public: AsciiString(const AsciiString &); __forceinline ~AsciiString() { releaseBuffer(); } protected: void releaseBuffer(); private: void *m_data; };
#include <memory>
namespace _STL {
template <> void _Construct<struct pair<const AsciiString, char>, struct pair<const AsciiString, char> >(struct pair<const AsciiString, char> *, const struct pair<const AsciiString, char> &);
}
#include <vector>
template void _STL::vector<struct _STL::pair<const AsciiString, char> >::_M_insert_overflow(
	struct _STL::pair<const AsciiString, char> *,
	const struct _STL::pair<const AsciiString, char> &,
	const _STL::__false_type &,
	unsigned int,
	bool);
