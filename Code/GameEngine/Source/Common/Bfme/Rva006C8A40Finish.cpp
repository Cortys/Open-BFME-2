// ?Rva006C8A40Get@@YA?AV?$basic_string@DV?$char_traits@D@_STL@@V?$allocator@D@2@@_STL@@PBD@Z
// cl: /O2 /DNDEBUG /MD
// stlport
//
// The 516-byte slot is laid out as a 4-byte header at +0 followed by the
// 512-byte sprintf target at +4. Retail opens with
// `sub esp,0x208 / mov ecx,[esp+0x210] / mov [esp+4],0`, so the zeroing
// store lands on that header word and every sprintf/copy target is +4 past
// the frame. A bare `char buf[516]` folds to one 0x204 frame with no store;
// zeroing four bytes individually is 0x212 with four stores. Splitting the
// header from the buffer reproduces both the frame size and the single
// 4-byte store.
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

_STL::basic_string<char, _STL::char_traits<char>, _STL::allocator<char> > __cdecl Rva006C8A40Get(const char *subPath)
{
	char all[516];
	char *buf = all + 4;
	*(int *)all = 0;
	if (subPath && *subPath && *subPath != 0x5c)
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
