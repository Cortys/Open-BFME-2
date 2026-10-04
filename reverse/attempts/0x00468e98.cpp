// ?rva00468E98@Rva00468E98@@QAEXPAMMM@Z
// partial score=0.96 date=2026-10-04
// cl: /O1 /DNDEBUG /MD /EHsc /arch:SSE
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
	float aa = a;
	float cc = trig.cosine;
	float sc = trig.sine;
	out[0] = aa * cc - b * sc;
	out[1] = aa * sc + b * cc;
}
