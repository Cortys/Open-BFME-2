// ?rva00468E98@Rva00468E98@@QAEXPAMMM@Z
// partial score=0.95 date=2026-10-04
// cl: /O1 /DNDEBUG /MD /EHsc /arch:SSE
// ?rva00468E98@Rva00468E98@@QAEXPAMMM@Z retail 0x00468E98 119B
// 2D vector rotation: angle from this+8 +0x44; the sin/fcos pair plus fsincos
// keep the pair in one aggregate so their stack homes match retail's
// [ebp-8]/[ebp-0xc]; the four products are the remaining diff.
// Callers 0x46A5D9 0x472696 0x47AE8A 0x47B8D3.
extern "C" double __cdecl sin(double angle);
extern "C" double __cdecl cos(double angle);

struct Rva00468E98Outer
{
	char m_pad[0x44];
	float m_44;
};

class Rva00468E98
{
public:
	void rva00468E98(float *out, float a, float b);
	char m_pad0[8];
	Rva00468E98Outer *m_8;
};

void Rva00468E98::rva00468E98(float *out, float a, float b)
{
	float angle = m_8->m_44;
	struct Trig { volatile float cosine; volatile float sine; } trig;
	trig.sine = (float)sin(angle);
	trig.cosine = (float)cos(angle);
	__asm { fld angle
		fsincos
		fstp trig.cosine
		fstp trig.sine }
	float rotated = a * trig.cosine - b * trig.sine;
	out[1] = a * trig.sine + b * trig.cosine;
	out[0] = rotated;
}
