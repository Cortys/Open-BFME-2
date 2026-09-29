// cl: /O1 /DNDEBUG /MD /EHs-c-
// ?Rva00503D26Evaluate@@YAMMMMM@Z @0x00503D26 40B
// Quadratic Bezier scalar evaluate(a b c t) = (1-t)^2*a + 2*(1-t)*t*b + t^2*c.
// Pure x87, EBP frame. Unlocks 0x00503DEB 0x00503E17.
// Evidence: fld1 fsub t then a*u 2*b*t sum*u c*t*t pattern, callers 0x00503E0E 0x00503E46.
float __cdecl Rva00503D26Evaluate(float a, float b, float c, float t);
float __cdecl Rva00503D26Evaluate(float a, float b, float c, float t)
{
	float u = 1 - t;
	float s = a * u + 2 * b * t;
	s = s * u + c * t * t;
	return s;
}
