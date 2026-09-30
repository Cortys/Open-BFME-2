// ?_M_insert_overflow@?$vector@U?$pair@$$CBVAsciiString@@UNoCaseTreeValue4@@@_STL@@V?$allocator@U?$pair@$$CBVAsciiString@@UNoCaseTreeValue4@@@_STL@@@2@@_STL@@IAEXPAU?$pair@$$CBVAsciiString@@UNoCaseTreeValue4@@@2@ABU32@ABU__false_type@2@I_N@Z
// partial score=0.98 date=2026-09-30
// ?_M_insert_overflow@?$vector@U?$pair@$$CBVAsciiString@@UNoCaseTreeValue4@@@_STL@@V?$allocator@U?$pair@$$CBVAsciiString@@UNoCaseTreeValue4@@@_STL@@@2@@_STL@@IAEXPAU?$pair@$$CBVAsciiString@@UNoCaseTreeValue4@@@2@ABU32@ABU__false_type@2@I_N@Z
// partial score=0.98 date=2026-09-30
// cl: /Ireference/shims/bfme2_ascii /O1 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
// ?_M_insert_overflow@?$vector@U?$pair@$$CBVAsciiString@@UNoCaseTreeValue4@@@_STL@@V?$allocator@U?$pair@$$CBVAsciiString@@UNoCaseTreeValue4@@@_STL@@@2@@_STL@@IAEXPAU?$pair@$$CBVAsciiString@@UNoCaseTreeValue4@@@2@ABU32@ABU__false_type@2@I_N@Z @0x001DA68C 178B: vector<pair<const AsciiString,NoCaseTreeValue4>> growth path, same 178B sar-3 shape as pair<char> overflow 0x0021E356 and Rva0048130E overflow 0x0048160B; calls allocate 0x00523D6C via pair pin plus copy 0x001D9B3C plus Construct 0x001D9B0F plus fill_n 0x001D9B62 plus clear 0x004C3D8B via pair pin; caller push_back 0x001DAAF2.
#include <memory>

#include "ascii_string.h"

struct NoCaseTreeValue4
{
	char m_body[4];
};

namespace _STL {
template <> void _Construct<struct pair<const AsciiString, NoCaseTreeValue4>, struct pair<const AsciiString, NoCaseTreeValue4> >(struct pair<const AsciiString, NoCaseTreeValue4> *, const struct pair<const AsciiString, NoCaseTreeValue4> &);
}

#include <vector>
template void _STL::vector<struct _STL::pair<const AsciiString, NoCaseTreeValue4> >::_M_insert_overflow(
	struct _STL::pair<const AsciiString, NoCaseTreeValue4> *,
	const struct _STL::pair<const AsciiString, NoCaseTreeValue4> &,
	const _STL::__false_type &,
	unsigned int,
	bool);
