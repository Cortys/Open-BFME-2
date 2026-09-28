// cl: /O1 /MD

// ?Rva000422A0Atan2@@YANMM@Z @0x000422A0 27B
// Unlock: float to double adapter for atan2 import thunk 0x0062992E.
// Caller 0x000422CD is pinned _atan2f. Prev/next are disp trivials.

extern "C" double __cdecl atan2(double y, double x);

double __cdecl Rva000422A0Atan2(float y, float x)
{
	return atan2(y, x);
}

extern "C" float __cdecl atan2f(float y, float x)
{
	return Rva000422A0Atan2(y, x);
}
