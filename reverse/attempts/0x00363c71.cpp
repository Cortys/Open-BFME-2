// ?Rva00363C71Approx@@YANPBUCoord3D@@0@Z
// partial score=0.9 date=2026-09-30
// ?Rva00363C71Approx@@YANPBUCoord3D@@0@Z
// partial score=0.90 date=2026-09-30
// cl: /O1 /G7 /DNDEBUG /MD /Oi-
#include <math.h>
//
// ?Rva00363C71Approx@@YANPBUCoord3D@@0@Z
// RVA 0x00363C71 size 130. Fast 2D hypotenuse approximation max+K*min over
// fabs components with K at 0x007BB8D4; fabs stays a call via /Oi- (pin
// _fabs at 0x00629210). Evidence: callers at 0x00363D3C/52 pass two point
// pointers and accumulate the double result; sibling PathDistance proves the
// Coord3D arg shape and push-ecx double-temp idiom; no EH frame.

struct Coord3D
{
	float x;
	float y;
	float z;
};

extern float g_007BB8D4;

// ?Rva00363C71Approx@@YANPBUCoord3D@@0@Z present-unmatched
double __cdecl Rva00363C71Approx(const Coord3D *a, const Coord3D *b)
{
	if (fabs(a->x - b->x) > fabs(a->y - b->y))
		return fabs(a->x - b->x) + fabs(a->y - b->y) * g_007BB8D4;
	return fabs(a->y - b->y) + fabs(a->x - b->x) * g_007BB8D4;
}
