// ?Rva002D7ACBCheck@@YG_NH@Z
// partial score=0.95 date=2026-09-28
// cl: /O1 /G7 /DNDEBUG /MD
//
// ?Rva002D7ACBCheck@@YG_NH@Z @0x002D7ACB (21B).
// Returns true when arg is outside 0..1 (signed less-than-zero or greater-than-one).
// Retail uses xor-inc plus jl-jg plus xor-al shape. Evidence: 1 caller at
// 0x002D8012; honest Rva free function, no donor.

// ?Rva002D7ACBCheck@@YG_NH@Z present-unmatched
bool __stdcall Rva002D7ACBCheck(int x)
{
	return x < 0 || x > 1;
}
