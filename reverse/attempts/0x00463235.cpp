// ?rva00463235@Rva00463235@@QAEPAV?$StringBase@D@@PAV2@PAVThing@@@Z
// partial score=0.94 date=2026-10-02
// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD
// ?rva00463235@Rva00463235@@QAEPAV?$StringBase@D@@PAV2@PAVThing@@@Z, retail 0x00463235, 92 bytes.
// Search list at +4 for node passing isKindOfMulti or default ARROW_ string.
// Evidence: retail list walk via +0x48 plus isKindOfMulti row 0x0030AD7D,
// StringBase ctors row 0x00037BA0 plus pin 0x000365F0, ARROW_ literal,
// defaultStorage g_defaultStorage009FEFA4, callers 6 unclaimed.
#include "ascii_string.h"

template <int N>
class BitFlags
{
public:
	unsigned int m_bits[(N + 31) / 32];
};

class Thing
{
public:
	bool isKindOfMulti(const BitFlags<116> &mustBeSet, const BitFlags<116> &mustBeClear) const;
};

class BfmeFixedStorage0004543D
{
public:
	char m_data[28];
};
extern const BfmeFixedStorage0004543D g_defaultStorage009FEFA4;

struct Rva00463235Node
{
	Rva00463235Node *m_next;
	char m_pad04[4];
	BitFlags<116> m_flags08;
	char m_pad18[12];
	AsciiString m_str24;
};

struct Rva00463235List
{
	char m_pad00[0x48];
	Rva00463235Node *m_head;
};

class Rva00463235
{
public:
	StringBase<char> *rva00463235(StringBase<char> *out, Thing *filter);
	char m_pad00[4];
	Rva00463235List *m_list;
};

// ?rva00463235@Rva00463235@@QAEPAV?$StringBase@D@@PAV2@PAVThing@@@Z present-unmatched
StringBase<char> *Rva00463235::rva00463235(StringBase<char> *out, Thing *filter)
{
	Rva00463235List *list = m_list;
	Rva00463235Node *cur = list->m_head->m_next;
	if (cur == list->m_head) {
		((AsciiString *)out)->AsciiString::AsciiString("ARROW_");
		return out;
	}
	for (; cur != list->m_head; cur = cur->m_next) {
		if (filter == 0) {
			((AsciiString *)out)->AsciiString::AsciiString((const AsciiString &)cur->m_str24);
			return out;
		}
		if (filter->isKindOfMulti(cur->m_flags08, (const BitFlags<116> &)g_defaultStorage009FEFA4)) {
			((AsciiString *)out)->AsciiString::AsciiString((const AsciiString &)cur->m_str24);
			return out;
		}
	}
	((AsciiString *)out)->AsciiString::AsciiString("ARROW_");
	return out;
}
