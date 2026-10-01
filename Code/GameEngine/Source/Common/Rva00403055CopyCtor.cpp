// cl: /O1 /MD /EHsc /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc /Ireference/shims/bfme2_ascii
// stlport
//
// ??0Rva00403055@@QAE@ABV0@@Z retail 0x00403055 97B.
// Evidence: copies the string at +0 through the rowed StringBase copy ctor
// 0x000365F0, builds an empty pointer vector at +4 through the shared
// _Vector_base ctor 0x00211E58, copies the two handles at +0x10 and +0x14
// through the rowed nothrow Rva0036CA00Str copy ctor 0x000A8C7C, then calls
// 0x00402FD8 with the source. That 125-byte routine clears the vector,
// reserves the source's count and push_backs a new 0x5C-byte copy of each
// element, so the vector holds owned pointers. Unwind states 0 and 3 bracket
// the nothrow member copies. The snapped-boundary queue named it
// GrantStealthBehaviorModuleData's ctor; names here are generated.
#include <vector>

#include "string_base.h"

#include "ascii_string.h"

class Rva0036CA00Str
{
	void *m_item;
public:
	__declspec(nothrow) Rva0036CA00Str(const Rva0036CA00Str &other);
	~Rva0036CA00Str();
};

class Rva00402F28Item
{
public:
	Rva00402F28Item(const Rva00402F28Item &other);
private:
	char m_bytes[0x5C];
};

class Rva00403055
{
public:
	Rva00403055(const Rva00403055 &other);
	void clearItems();
	void copyItems(const Rva00403055 &other);

private:
	AsciiString m_name;
	_STL::vector<Rva00402F28Item *> m_items;
	Rva0036CA00Str m_at10;
	Rva0036CA00Str m_at14;
};

Rva00403055::Rva00403055(const Rva00403055 &other)
	: m_name(other.m_name), m_items(), m_at10(other.m_at10), m_at14(other.m_at14)
{
	copyItems(other);
}

void Rva00403055::copyItems(const Rva00403055 &other)
{
	clearItems();
	m_items.reserve(other.m_items.size());
	_STL::vector<Rva00402F28Item *>::const_iterator it = other.m_items.begin();
	_STL::vector<Rva00402F28Item *>::const_iterator end = other.m_items.end();
	for (; it != end; ++it)
		m_items.push_back(new Rva00402F28Item(**it));
}
