// ?rva00308509@Rva00308509@@QAEXPAUVec4@@MH@Z
// partial score=0.91 date=2026-09-29
// ?rva00308509@Rva00308509@@QAEXPAUVec4@@MH@Z
// partial score=0.91 date=2026-09-29
// cl: /O1 /MD /arch:SSE /Oy-
// ?rva00308509@Rva00308509@@QAEXPAUVec4@@MH@Z, retail 0x00308509 242B.
// Keyframe blend with wrap and lerp. Evidence: callers 0x80A8D 0x80C4C,
// float 0xBBB8D8, prev 0x3081FB next 0x308663.

struct Vec4
{
	float x;
	float y;
	float z;
	float w;
};

struct Key
{
	float x;
	float y;
	float z;
	float w;
};

class Rva00308509
{
public:
	void rva00308509(Vec4 *out, float weight, int index);
private:
	char m_00[0xa0];
	unsigned int m_a0;
	float m_a4;
	char m_a8[0x1c];
	Key *m_c4[1];
};

// ?rva00308509@Rva00308509@@QAEXPAUVec4@@MH@Z present-unmatched
void Rva00308509::rva00308509(Vec4 *out, float weight, int index)
{
	if (*(volatile unsigned int *)&m_a0 == 0) {
		out->y = 0.0f;
		out->z = 0.0f;
		out->w = 0.0f;
		out->x = 0.0f;
		return;
	}
	float w = m_a4 * weight;
	int i = (int)w;
	float f = (float)i;
	unsigned int n = m_a0;
	unsigned int r1 = (unsigned int)i % n;
	unsigned int r2 = (r1 + 1) % n;
	float fract = w - f;
	float inv = 1.0f - fract;
	Key *base = m_c4[index];
	Key *k1 = &base[r1];
	Key *k2 = &base[r2];
	out->x = k1->x * inv + k2->x * fract;
	out->y = k1->y * inv + k2->y * fract;
	out->z = k1->z * inv + k2->z * fract;
	out->w = k1->w * inv + k2->w * fract;
}
