// ?rva001DC01C@Rva001DC01C@@QAEPAXV?$StringBase@D@@@Z
// partial score=0.95 date=2026-09-30
// ?rva001DC01C@Rva001DC01C@@QAEPAXV?$StringBase@D@@@Z
// partial score=0.95 date=2026-09-30
// cl: /Ireference/shims/bfmelist /O1 /EHs /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// ?rva001DC01C@Rva001DC01C@@QAEPAXV?$StringBase@D@@@Z @0x001DC01C 98B. Find entry by name.
// Evidence: by-value AsciiString param with EH_prolog plus releaseBuffer row 0x00036410,
// isEmpty early-out null plus length check, list-pointer at +0x20 iterated raw,
// compareNoCase row 0x00006A00 against Entry string at +0xC, returns found pointer or null.
// Callers 0x001DC1FD 0x001DC252 0x001DC42C 0x001DC4D2. Honest address name.
#include <list>

template <typename T> class StringBase
{
public:
	int compareNoCase(const StringBase<T> &other) const throw();
	bool isEmpty() const { return m_data == 0 || m_data->length == 0; }
	~StringBase() { releaseBuffer(); }
private:
	void releaseBuffer();
	struct Header
	{
		int ref_count;
		unsigned short length;
		unsigned short capacity;
		T data[1];
	};
	Header *m_data;
};

struct Rva001DC01CEntry
{
	char m_pad[12];
	StringBase<char> m_name;
};

struct Rva001DC01CNode
{
	Rva001DC01CNode *m_next;
	Rva001DC01CNode *m_prev;
	Rva001DC01CEntry *m_value;
};

class Rva001DC01C
{
public:
	void *rva001DC01C(StringBase<char> name);
private:
	char m_pad[32];
	Rva001DC01CNode *m_head;
};

// ?rva001DC01C@Rva001DC01C@@QAEPAXV?$StringBase@D@@@Z present-unmatched
void *Rva001DC01C::rva001DC01C(StringBase<char> name)
{
	if (name.isEmpty())
		return 0;
	Rva001DC01CNode *cur = m_head->m_next;
	while (cur != m_head) {
		Rva001DC01CEntry *e = cur->m_value;
		if (name.compareNoCase(e->m_name) == 0)
			return e;
		cur = cur->m_next;
	}
	return 0;
}
