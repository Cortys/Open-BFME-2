// ?rva002864E6@Rva00285DC5@@QAEXPAMMHHHH_N@Z
// partial score=0.91 date=2026-09-30
// ?rva002864E6@Rva00285DC5@@QAEXPAMMHHHH_N@Z
// partial score=0.91 date=2026-09-30
// cl: /O1 /DNDEBUG /MD /arch:SSE
// ?rva002864E6@Rva00285DC5@@QAEXPAMMHHHH_N@Z @ 0x002864E6 310B
// Circle/disc paint delegating to Rva00285DC5 row-range paint: converts world pos
// via INV/g_00BC26F8 floor/ceil through IAT floor/ceil, then midpoint loop calling
// 0x00285DC5 twice per row range. Evidence: same Rva00285DC5 this, same
// INV 0x007C2424/g_00BC26F8 0x007C26F8 immediates, callers at 0x00395DEC/0x0050BE94.
// x87 fistp via inline asm (retail uses fld/fistp, SSE cvttss2si differs); SSE for comiss.
extern "C" __declspec(dllimport) double __cdecl floor(double);
extern "C" __declspec(dllimport) double __cdecl ceil(double);
extern "C" float INV;
extern double g_00BC26F8;

__forceinline long FloatToLong(float f)
{
	long i;
	__asm {
		fld [f]
		fistp [i]
	}
	return i;
}

class Rva00285DC5
{
public:
	void rva00285DC5(int r0, int r1, int col, int add, int f12, int f10, int f8, bool flag);
	void rva002864E6(float *p, float w, int add, int f12, int f10, int f8, bool flag);
};

// ?rva002864E6@Rva00285DC5@@QAEXPAMMHHHH_N@Z present-unmatched
void Rva00285DC5::rva002864E6(float *p, float w, int add, int f12, int f10, int f8, bool flag)
{
	if (w <= 0.0f)
		return;
	if (add == 0)
		return;
	float fx = (float)floor(p[0] * INV + g_00BC26F8);
	int cx = FloatToLong(fx);
	float fy = (float)floor(p[1] * INV + g_00BC26F8);
	int cy = FloatToLong(fy);
	float fr = (float)ceil(w * INV);
	int rad = FloatToLong(fr);
	int y = rad;
	int d = 0;
	int err = 2 - 2 * rad;
	int bot = cx;
	int top = cx;
	while (true) {
		if (err + y > 0) {
			if (y == 0) {
				if (rad == 1) {
					d++;
					bot++;
					top--;
				}
			}
			rva00285DC5(top, bot, cy + y, add, f12, f10, f8, flag);
			if (y == 0)
				break;
			rva00285DC5(top, bot, cy - y, add, f12, f10, f8, flag);
			y--;
			err += 1 - 2 * y;
		}
		if (d <= err)
			continue;
		d++;
		bot++;
		top--;
		err += 2 * d + 1;
	}
}
