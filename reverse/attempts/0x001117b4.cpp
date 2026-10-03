// ?Rva001117B4IsPow2@@YGEH@Z
// partial score=0.93 date=2026-10-03
// cl: /O1 /MD
//
// 0x001117B4 47B power-of-two test for 1..64; retail checks 0x40 then
// 0x20/0x10/8/4/2/1. Evidence: frameless stdcall shape with ret 4, callees
// none, callers are the unclaimed 0x000AC88E/0x000AEDFA bodies.
// ?Rva001117B4IsPow2@@YGEH@Z present-unmatched
unsigned char __stdcall Rva001117B4IsPow2( int v )
{
	if( v == 0x40 )
		return 1;
	else if( v == 0x20 || v == 0x10 || v == 8 || v == 4 || v == 2 )
		return 1;
	else
		return v == 1;
}
