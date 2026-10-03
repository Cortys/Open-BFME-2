// cl: /O1 /DNDEBUG /MD
// ?Rva00202678Get@@YGPBDH@Z @0x00202678 40B. Indexed string getter: 0<=i<2
// returns table g_00DB96B0[i], -1 returns "Unknown", else g_00BBE8E8.
// Evidence: caller 0x002E53FA passes int and uses result for StringBase::set,
// string literal 0x007D0FA4 "Unknown", table at 0x00DB96B0, default at 0x00BBE8E8.
extern const char *g_00DB96B0[];
extern const char g_00BBE8E8[];

const char *__stdcall Rva00202678Get(int i)
{
	if (i >= 0 && i < 2)
		return g_00DB96B0[i];
	if (i == -1)
		return "Unknown";
	return g_00BBE8E8;
}
