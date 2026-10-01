// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD /EHsc
//
// ?Rva005FF207Format@@YA?AVUnicodeString@@H@Z @ 0x005FF207 (96B).
// Conditional Unicode format into temp then return by value (hidden pointer).
// Evidence: format row 0x006CB5D0; StringBase wide copy 0x00037050;
// releaseBuffer 0x00036E70; format string 0x007C9260 (g_Va007C9260);
// caller 0x005FF4F8 pushes (val,out) hidden-pointer style and passes
// return to 0x005FF450.
#include "ascii_string.h"

class UnicodeString : private StringBase<unsigned short>
{
public:
	UnicodeString() {}
	UnicodeString(const UnicodeString &o)
		: StringBase<unsigned short>((const StringBase<unsigned short> &)o) {}
	~UnicodeString() {}
	void __cdecl format(const unsigned short *format, ...);
};

extern const unsigned short g_Va007C9260[];

UnicodeString __cdecl Rva005FF207Format(int val)
{
	UnicodeString tmp;
	if (val >= 0)
		tmp.format(g_Va007C9260, val);
	return tmp;
}
