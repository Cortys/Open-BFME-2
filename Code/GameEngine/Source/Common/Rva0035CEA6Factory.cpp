// cl: /O1 /DNDEBUG /MD /EHsc
// ?Rva0035CEA6Create@@YGPAVRva0035CC36@@PAVRva0035CE52@@@Z, retail 0x0035CEA6 (106B).
// Factory: news 0x44 bytes, constructs Rva0035CC36 via rowed ctor, copies
// via rowed Rva0035CE52 operator= under g_00E01EA8 guard, stamps +0x8 1,
// links [template+4] to new, returns new. Evidence: rowed new 0x0002FDA0,
// ctor 0x0035CC36, assign 0x0035CE52, EH_prolog frame, ret 4 stdcall.

class Rva0035CC36
{
public:
	Rva0035CC36();
	char m_pad[0x44];
};

class Rva0035CE52
{
public:
	Rva0035CE52 &operator=(const Rva0035CE52 &that);
};

#include <new>

extern void *__cdecl operator new(unsigned int size);
extern unsigned char g_00E01EA8;

Rva0035CC36 *__stdcall Rva0035CEA6Create(Rva0035CE52 *templ)
{
	if (templ == 0)
		return 0;
	Rva0035CC36 *res = new Rva0035CC36();
	g_00E01EA8 = 1;
	((Rva0035CE52 *)res)->operator=(*templ);
	g_00E01EA8 = 0;
	*((unsigned char *)res + 8) = 1;
	*(Rva0035CC36 **)((char *)templ + 4) = res;
	return res;
}
