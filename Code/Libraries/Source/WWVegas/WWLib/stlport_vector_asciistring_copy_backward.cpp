// cl: /Ireference/shims/bfme2_ascii /O1 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
//
// _STL::__copy_backward worker for AsciiString at 0x000B4460, 47 bytes.
// Backward twin of the rowed forward __copy at 0x000B4431 (dup_000b4431):
// count = (last-first)>>2, then decrement last/result and copy via
// ?set@?$StringBase@D@@QAEXABV1@@Z. Caller wrapper at 0x000B6631.
#include <vector>

#include "ascii_string.h"

template class _STL::vector<AsciiString, _STL::allocator<AsciiString> >;
