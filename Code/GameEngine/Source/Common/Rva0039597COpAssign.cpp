// cl: /O1 /MD /Ireference/shims/bfme2_ascii
//
// ?rva0039597C@Rva0039597C@@QAEAAV1@ABV1@@Z, retail 0x0039597C, 39 bytes.
// Copy-assignment over two AsciiStrings plus int at +8, returning *this.
// Calls rowed StringBase<char>::set at 0x000366F0 twice (inlined through
// shared AsciiString::operator=), then int copy, then return *this via mov
// eax,esi. Prev allocator/StringRecordCopyBFME2 and next CastleMemberBehavior
// share the 00395xxx page; AsciiString via shared header (str/set inline
// through StringBase, literals link).
#include "ascii_string.h"

class Rva0039597C
{
public:
	Rva0039597C &rva0039597C(const Rva0039597C &other);
private:
	AsciiString m_00;
	AsciiString m_04;
	int m_08;
};
Rva0039597C &Rva0039597C::rva0039597C(const Rva0039597C &other)
{
	m_00 = other.m_00;
	m_04 = other.m_04;
	m_08 = other.m_08;
	return *this;
}
