// cl: /Ireference/shims/bfme2_ascii /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport

#include "ascii_string.h"

namespace rts
{
	template <class T> struct hash
	{
	};
	template <> struct hash<AsciiString>
	{
		unsigned int operator()(const AsciiString &key) const;
	};
}

#include <hash_map>
#include <set>

class INIMacroTable
{
public:
	INIMacroTable();

private:
	std::hash_map<AsciiString, AsciiString, rts::hash<AsciiString>, std::equal_to<AsciiString> > m_macros;
	std::set<AsciiString> m_expanded;
	void *m_unkn20;
	void *m_unkn24;
};

INIMacroTable::INIMacroTable()
	: m_macros()
	, m_expanded()
	, m_unkn20(0)
	, m_unkn24(0)
{
}
