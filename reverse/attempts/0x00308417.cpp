// ?rva00308417@Rva00308417@@QAEXPAMMH@Z
// partial score=0.91 date=2026-09-29
// ?rva00308417@Rva00308417@@QAEXPAMMH@Z
// partial score=0.91 date=2026-09-29
// cl: /O1 /MD /arch:SSE /Oy-
// ?rva00308417@Rva00308417@@QAEXPAMMH@Z, retail 0x00308417, 242 bytes.
// Float-track sampler: empty table zeroes the output vec4, else position
// t scaled by +0xA4 selects wrapped 16B elements from track +0xB8 indexed
// by the third arg and lerps all four floats by the fractional remainder
// against 1.0f. Same 242B shape as stashed 0x00308325 (tracks at +0xAC
// there, +0xB8 here). Callers 0x00080988 etc (8 sites).
struct Rva00308417Elem
{
	float v[4];
};

class Rva00308417
{
public:
	void rva00308417(float *out, float t, int index);
private:
	char m_pad[0xA0];
	unsigned int m_count;
	float m_scale;
	char m_gap[0xB8 - 0xA8];
	Rva00308417Elem *m_tracks[1];
};

// ?rva00308417@Rva00308417@@QAEXPAMMH@Z present-unmatched
void Rva00308417::rva00308417(float *out, float t, int index)
{
	float v0;
	if (m_count > 0) {
		float ts = t * m_scale;
		int i = (int)ts;
		float f = ts - (float)i;
		unsigned int r = (unsigned int)i % m_count;
		unsigned int r2 = (r + 1) % m_count;
		Rva00308417Elem *track = m_tracks[index];
		Rva00308417Elem *a = &track[r];
		Rva00308417Elem *b = &track[r2];
		float g = 1.0f - f;
		float b0f = b->v[0] * f;
		float b1f = b->v[1] * f;
		float b2f = b->v[2] * f;
		float b3f = b->v[3] * f;
		float a0g = a->v[0] * g;
		float a1g = a->v[1] * g;
		float a2g = a->v[2] * g;
		float a3g = a->v[3] * g;
		out[1] = a1g + b1f;
		out[2] = a2g + b2f;
		out[3] = a3g + b3f;
		v0 = a0g + b0f;
	} else {
		out[1] = 0.0f;
		out[2] = 0.0f;
		out[3] = 0.0f;
		v0 = 0.0f;
	}
	out[0] = v0;
}
