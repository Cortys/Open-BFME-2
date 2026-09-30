// cl: /Ireference/shims/bfme2_ascii /O1 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// ?rva000B435F@Rva000B435F@@QAEAAU0@ABU0@@Z @0x000B435F 37B.
// Copy-assignment for 12-byte struct {int +0, AsciiString +4, int +8}.
// Evidence: copies [edi] to [esi], calls ?set@?$StringBase@D@@QAEXABV1@@Z
// for +4, copies [edi+8] to [esi+8], returns this; caller at 0x000B684C
// strides 0xC over the same 12-byte elements.
#include "ascii_string.h"

struct Rva000B435F
{
	int m_a;
	AsciiString m_s;
	int m_b;
	Rva000B435F &operator=(const Rva000B435F &o);
};

Rva000B435F &Rva000B435F::operator=(const Rva000B435F &o)
{
	m_a = o.m_a;
	m_s.set(o.m_s);
	m_b = o.m_b;
	return *this;
}
