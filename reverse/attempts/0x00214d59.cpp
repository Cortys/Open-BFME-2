// ?rva00214D59@Rva00214D59@@QAEHXZ
// partial score=0.98 date=2026-10-01
// ?rva00214D59@Rva00214D59@@QAEHXZ
// partial score=0.98 date=2026-10-01
// cl: /O1 /DNDEBUG /MD /arch:SSE
// ?rva00214D59@Rva00214D59@@QAEHXZ retail 0x00214D59 169B
// Packed 0xFFRRGGBB from +0x64/+0x68/+0x6c scaled by +0x70 plus double-based
// base; upper clamp via cmov and lower via branch; final add/shl pack.
// Evidence: same +0x64 +0x68 +0x6c +0x70 layout in all four lanes; double
// helpers g_00BBCC70 g_00BBB8E8 via x87 ftol row 0x00629228; float scale
// g_00BC2900; caller at 0x0009569A.
// ?rva00214D59@Rva00214D59@@QAEHXZ present-unmatched
extern const double g_00BBCC70;
extern const double g_00BBB8E8;
extern float g_00BC2900;
class Rva00214D59
{
public:
	int rva00214D59();
private:
	char _pad[0x64];
	float m_64;
	float m_68;
	float m_6C;
	float m_70;
};
int Rva00214D59::rva00214D59()
{
	int base = (int)((g_00BBCC70 - m_70) * g_00BBB8E8);
	if (base > 255)
		base = 255;
	if (base < 0)
		base = 0;
	float fbase = (float)base;
	float tr = m_64 * m_70;
	int r = (int)(tr * g_00BC2900 + fbase);
	if (r > 255)
		r = 255;
	if (r < 0)
		r = 0;
	float tg = m_68 * m_70;
	int g = (int)(tg * g_00BC2900 + fbase);
	if (g > 255)
		g = 255;
	if (g < 0)
		g = 0;
	float tb = m_6C * m_70;
	int b = (int)(tb * g_00BC2900 + fbase);
	if (b > 255)
		b = 255;
	if (b < 0)
		b = 0;
	int packed = 0xFF00 + r;
	packed <<= 8;
	packed += g;
	packed <<= 8;
	packed += b;
	return packed;
}
