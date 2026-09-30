// ?rva00463235@Rva00463235@@QAEPAV?$StringBase@D@@PAV2@PAVThing@@@Z
// partial score=0.9 date=2026-09-30
// ?rva00463235@Rva00463235@@QAEPAV?$StringBase@D@@PAV2@PAVThing@@@Z
// partial score=0.90 date=2026-09-30
// cl: /O1 /DNDEBUG /MD
//
// ?rva00463235@Rva00463235@@QAEPAV?$StringBase@D@@PAV2@PAVThing@@@Z, retail 0x00463235, 92 bytes.
// Search list at +4 for node passing isKindOfMulti or default ARROW_ string.
// Evidence: retail list walk via +0x48 plus isKindOfMulti row 0x0030AD7D,
// StringBase ctors row 0x00037BA0 plus pin 0x000365F0, ARROW_ literal,
// defaultStorage g_defaultStorage009FEFA4, callers 6 unclaimed.
#include <new>
template <int N>
class BitFlags
{
public:
	char m_data[(N + 7) / 8];
};

class Thing
{
public:
	bool isKindOfMulti(const BitFlags<116> &a, const BitFlags<116> &b) const;
};

template <typename T>
class StringBase
{
private:
	StringBase(const StringBase &o) throw();
	StringBase(const char *s) throw();
	friend class Rva00463235;
	T *m_data;
};

typedef StringBase<char> AsciiString;

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
	AsciiString *rva00463235(AsciiString *out, Thing *filter);
	char m_pad00[4];
	Rva00463235List *m_list;
};

AsciiString *Rva00463235::rva00463235(AsciiString *out, Thing *filter)
{
	__assume(out);
	Rva00463235Node *head = m_list->m_head;
	Rva00463235Node *cur = head->m_next;
	if (cur == head)
		return new (out) AsciiString("ARROW_");
	if (!filter)
		return new (out) AsciiString(cur->m_str24);
	for (; cur != head; cur = cur->m_next) {
		if (filter->isKindOfMulti(*(const BitFlags<116> *)&cur->m_flags08,
				*(const BitFlags<116> *)&g_defaultStorage009FEFA4))
			return new (out) AsciiString(cur->m_str24);
	}
	return new (out) AsciiString("ARROW_");
}
