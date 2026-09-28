// ?Rva002ADD75Equal@@YA_NPBUAsciiRange002ADD75@@0@Z
// partial score=0.93 date=2026-09-28
// ?Rva002ADD75Equal@@YA_NPBUAsciiRange002ADD75@@0@Z
// partial score=0.93 date=2026-09-28
// cl: /O1 /DNDEBUG /MD
// ?Rva002ADD75Equal@@YA_NPBUAsciiRange002ADD75@@0@Z @0x002ADD75 (61B): AsciiString range pair equal.
// Checks the two 8-byte ranges (begin/end) have equal size via sub-xor-test
// 0xFFFFFFFC then delegates to rowed Rva002ACFFBEqual at 0x002ACFFB for
// element-wise StringBase compare, returning its result. Callers at
// 0x002B0EA4 0x002B2179 0x00360F2C 0x00360F3F 0x004E2E36. Prev grantScience
// next ObjectLookupMapFindSlot.
template <typename T>
class StringBase
{
public:
	int compare(const StringBase<T> &str) const;
};

struct AsciiRange002ADD75
{
	StringBase<char> *m_begin;
	StringBase<char> *m_end;
};

bool __cdecl Rva002ACFFBEqual(StringBase<char> *first1, StringBase<char> *last1, StringBase<char> *first2);

// ?Rva002ADD75Equal@@YA_NPBUAsciiRange002ADD75@@0@Z present-unmatched
bool __cdecl Rva002ADD75Equal(const AsciiRange002ADD75 *a, const AsciiRange002ADD75 *b)
{
	unsigned int sizeA = (unsigned int)((char *)a->m_end - (char *)a->m_begin);
	unsigned int sizeB = (unsigned int)((char *)b->m_end - (char *)b->m_begin);
	if (((sizeA ^ sizeB) & 0xFFFFFFFC) == 0) {
		bool res = Rva002ACFFBEqual(a->m_begin, a->m_end, b->m_begin);
		if (res)
			return true;
		return false;
	}
	return false;
}
