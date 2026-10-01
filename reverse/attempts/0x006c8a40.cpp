// ?Rva006C8A40Get@@YA?AV?$basic_string@DV?$char_traits@D@_STL@@V?$allocator@D@2@@_STL@@PBD@Z
// partial score=0.93 date=2026-10-01
// ?Rva006C8A40Get@@YA?AV?$basic_string@DV?$char_traits@D@_STL@@V?$allocator@D@2@@_STL@@PBD@Z
// partial score=0.93 date=2026-10-01
// cl: /O2 /DNDEBUG /MD
// stlport
//
// ?Rva006C8A40Get@@YA?AV?$basic_string@DV?$char_traits@D@_STL@@V?$allocator@D@2@@_STL@@PBD@Z @0x006C8A40 145B
// STL narrow registry-path builder: roots subPath under GetRegistryGameRegPath,
// inserting '\\' unless subPath is empty or already backslashed. Evidence: calls
// rowed GetRegistryGameRegPath 0x0002FA00, sprintf via IAT, constructs rowed
// _STL::basic_string ctor 0x00009100 from 512B stack buffer, returns result ptr.

const char *__cdecl GetRegistryGameRegPath();
extern "C" __declspec(dllimport) int __cdecl sprintf(char *buf, const char *fmt, ...);

namespace _STL
{
template <class T>
class allocator
{
public:
	allocator() {}
	allocator(const allocator &) {}
	~allocator() {}
};

template <class T>
class char_traits
{
};

template <class CharT, class Traits, class Alloc>
class basic_string
{
public:
	typedef Alloc allocator_type;
	basic_string(const CharT *s, const allocator_type &a = allocator_type());
};
}

// ?Rva006C8A40Get@@YA?AV?$basic_string@DV?$char_traits@D@_STL@@V?$allocator@D@2@@_STL@@PBD@Z present-unmatched
_STL::basic_string<char, _STL::char_traits<char>, _STL::allocator<char> > __cdecl Rva006C8A40Get(const char *subPath)
{
	char buf[512];
	if (subPath && *subPath && *subPath != '\\')
		sprintf(buf, "%s\\%s", GetRegistryGameRegPath(), subPath);
	else if (subPath)
		sprintf(buf, "%s%s", GetRegistryGameRegPath(), subPath);
	else
	{
		const char *src = GetRegistryGameRegPath();
		char *dst = buf;
		char c;
		do
		{
			c = *src++;
			*dst++ = c;
		} while (c != 0);
	}
	return _STL::basic_string<char, _STL::char_traits<char>, _STL::allocator<char> >(buf);
}
