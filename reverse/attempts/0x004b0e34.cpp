// ?Rva004B0E34Get@@YG_NI@Z
// partial score=0.94 date=2026-10-03
// cl: /O2 /EHsc /arch:SSE /DNDEBUG /MD
// ?Rva004B0E34Get@@YG_NI@Z, retail 0x004B0E34, 32 bytes.
// Evidence: caller 0x004B0FA0 pushes int and returns bool; range 0..0xb; 2-outcome switch.
// ?Rva004B0E34Get@@YG_NI@Z present-unmatched
bool __stdcall Rva004B0E34Get(unsigned int x)
{
	switch (x) {
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
	case 6:
	case 7:
	case 8:
	case 9:
	case 10:
	case 11:
		return true;
	default:
		return false;
	}
}
