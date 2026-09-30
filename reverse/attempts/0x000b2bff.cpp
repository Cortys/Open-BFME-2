// ?Rva000B2BFFClamp@@YAXPAMM@Z
// partial score=0.93 date=2026-09-30
// ?Rva000B2BFFClamp@@YAXPAMM@Z
// partial score=0.93 date=2026-09-30
// cl: /O1 /DNDEBUG /MD /arch:SSE
// ?Rva000B2BFFClamp@@YAXPAMM@Z 0x000B2BFF 190B evidence: free cdecl float-ptr float SSE wrap via INV vs g_00BC7468 then clamp via g_00BC746C g_00BC7470; callers 0x000B4CE2/0x000B710D
extern "C" float INV;
extern float g_00BC7468;
extern float g_00BC746C;
extern float g_00BC7470;

void __cdecl Rva000B2BFFClamp(float *p, float v);

// ?Rva000B2BFFClamp@@YAXPAMM@Z present-unmatched
void __cdecl Rva000B2BFFClamp(float *p, float v)
{
	if (*p > v)
	{
		float diff = *p - v;
		if (diff > g_00BC7468)
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
		if (diff > g_00BC7468)
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
	if (*p > g_00BC7468)
	{
		*p -= g_00BC746C;
	}
	if (g_00BC7470 > *p)
	{
		*p += g_00BC746C;
	}
}
