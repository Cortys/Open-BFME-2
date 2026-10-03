// ??0?$vector@URva00511E48@@V?$allocator@URva00511E48@@@_STL@@@_STL@@QAE@I@Z
// partial score=0.93 date=2026-10-04
// ??0?$vector@URva00511E48@@V?$allocator@URva00511E48@@@_STL@@@_STL@@QAE@I@Z
// partial score=0.93 date=2026-10-02
// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD /EHsc /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ??0?$vector@URva00511E48@@V?$allocator@URva00511E48@@@_STL@@@_STL@@QAE@I@Z @0x00512000 105B: vector<Rva00511E48> single-arg ctor (n) via base + fill with default (empty,0); evidence callers 0x005121B7 with 2 and callees Vector_base 0x000B6378 StringBase copy 0x000365F0 fill 0x00511F58 releaseBuffer 0x00036410 and TheEmptyString.
// Called from 0x0051215B AptMessenger Init with count 2 at +0x28c.
#include "ascii_string.h"
#pragma auto_inline(off)
#include <vector>
#pragma auto_inline(on)

struct Rva00511E48
{
	AsciiString m_str;
	char m_c;
	char m_pad[3];
	Rva00511E48() : m_str(AsciiString::TheEmptyString), m_c(0) {}
	Rva00511E48(const Rva00511E48 &o) : m_str(o.m_str), m_c(o.m_c) {}
};

template class _STL::vector<Rva00511E48, _STL::allocator<Rva00511E48> >;
