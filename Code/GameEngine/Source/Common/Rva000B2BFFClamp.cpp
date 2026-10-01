// cl: /O1 /DNDEBUG /MD /arch:SSE
// ?Rva000B2BFFClamp@@YAXPAMM@Z @0x000B2BFF 190B, callers 0x000B4DFF and
// 0x000B7227. Steps the angle at p toward v by the INV global (the long way
// round when the gap exceeds pi), snaps when within one step, then wraps the
// result into [-pi, pi].
// Target evidence: pooled float constants pi at 0x00BC7468 and 2pi at
// 0x00BC746C/0x00BC7470 are compiler literals here (the banked attempt read
// them through float globals); INV is the shared extern used by the matched
// Rva005B02B5.cpp and GeometryInfoCtor.cpp.
// ?Rva000B2BFFClamp@@YAXPAMM@Z 0x000B2BFF 190B evidence: free cdecl float-ptr float SSE wrap via INV vs 3.1415927410125732f then clamp via 6.2831854820251465f -3.1415927410125732f; callers 0x000B4CE2/0x000B710D
extern "C" float INV;

void __cdecl Rva000B2BFFClamp(float *p, float v)
{
	if (*p > v)
	{
		float diff = *p - v;
		if (diff > 3.1415927410125732f)
		{
			*p += INV;
		}
		else if (diff > INV)
		{
			*p -= INV;
		}
		else
		{
			*p = v;
		}
	}
	else if (v > *p)
	{
		float diff = v - *p;
		if (diff > 3.1415927410125732f)
		{
			*p -= INV;
		}
		else if (diff > INV)
		{
			*p += INV;
		}
		else
		{
			*p = v;
		}
	}
	if (*p > 3.1415927410125732f)
	{
		*p -= 6.2831854820251465f;
	}
	if (-3.1415927410125732f > *p)
	{
		*p += 6.2831854820251465f;
	}
}
