// ?Rva004E5D4DRange@@YAEPAPAX0E@Z
// partial score=0.99 date=2026-09-30
// ?Rva004E5D4DRange@@YAEPAPAX0E@Z
// partial score=0.99 date=2026-09-30
// cl: /O1 /MD /Oy-
// ?Rva004E5D4DRange@@YAEPAPAX0E@Z @0x004E5D4D (33B)
// __cdecl range deleter: for each slot in [first, last) calls deleter on the
// slot value with this=&flag to reproduce retail lea ecx, then returns flag.
// Evidence: chain lane calls 0x004E5CB0; caller 0x004E5D6E pushes 3 args.
// Byte-exact (33B 0 regions) when deleter is thiscall ignoring this, but the
// rowed deleter is stdcall ?Rva004E5CB0Delete@@YGXPAX@Z so the gate cannot
// resolve the thiscall name. Retail caller proves callee is thiscall (lea ecx
// [ebp+0x10] before call); fix is to repoint 0x004E5CB0 to honest thiscall
// ?rva004E5CB0@Rva004E5CB0@@QAEXPAX@Z (same bytes, ignores this) then land.
class Rva004E5CB0This
{
public:
	void deleter(void *p);
};

unsigned char __cdecl Rva004E5D4DRange(void **first, void **last, unsigned char flag)
{
	for (void **p = first; p != last; ++p)
		((Rva004E5CB0This *)&flag)->deleter(*p);
	return flag;
}
