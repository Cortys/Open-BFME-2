// ?rva00468E98@Rva00468E98@@QAEXPAMMM@Z
// partial score=0.92 date=2026-09-29
// ?rva00468E98@Rva00468E98@@QAEXPAMMM@Z
// partial score=0.92 date=2026-09-29
// cl: /O1 /DNDEBUG /MD /EHsc /arch:SSE
//
// ?rva00468E98@Rva00468E98@@QAEXPAMMM@Z, retail 0x00468E98 119B.
// Thiscall rotation: angle from this+8 +0x44 via sin cos then fsincos,
// out[0]=a*cos-b*sin out[1]=a*sin+b*cos via SSE.
// Callers 0x46A5D9 0x472696 0x47AE8A 0x47B8D3, prev 0x468E26 next 0x468F0F.

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

// ?rva00468E98@Rva00468E98@@QAEXPAMMM@Z present-unmatched
void Rva00468E98::rva00468E98(float *out, float a, float b)
{
	float angle = m_8->m_44;
	volatile float s = (float)sin(angle);
	volatile float c = (float)cos(angle);
	float s2;
	float c2;
	__asm {
		fld angle
		fsincos
		fstp c2
		fstp s2
	}
	out[0] = a * c2 - b * s2;
	out[1] = a * s2 + b * c2;
}
