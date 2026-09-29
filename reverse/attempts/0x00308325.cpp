// ?rva00308325@Rva00308325@@QAEXPAMMH@Z
// partial score=0.9 date=2026-09-29
?rva00308325@Rva00308325@@QAEXPAMMH@Z
// partial score=0.90 date=2026-09-29
// cl: /O1 /MD /arch:SSE /Oy-
//
// ?rva00308325@Rva00308325@@QAEXPAMMH@Z @0x00308325 (242B).
// Float-track sampler: empty table zeroes the output vec4, else position
// t scaled by +0xA4 selects wrapped 16B elements from track +0xAC indexed
// by the third arg and lerps all four floats by the fractional remainder
// against 1.0f. Eight callers waiting. Same /arch:SSE flags as the
// Rva0037E421Accessor neighbour.
struct Rva00308325Elem
{
	float v[4];
};

class Rva00308325
{
public:
	void rva00308325(float *out, float t, int index);
private:
	char m_pad[0xA0];
	unsigned int m_count;
	float m_scale;
	char m_gap[0xAC - 0xA8];
	Rva00308325Elem *m_tracks[1];
};

// ?rva00308325@Rva00308325@@QAEXPAMMH@Z present-unmatched
void Rva00308325::rva00308325(float *out, float t, int index)
{
	if (m_count == 0) {
		out[0] = 0.0f;
		out[1] = 0.0f;
		out[2] = 0.0f;
		out[3] = 0.0f;
		return;
	}
	float ts = t * m_scale;
	int i = (int)ts;
	float f = ts - (float)i;
	unsigned int r = (unsigned int)i % m_count;
	unsigned int r2 = (r + 1) % m_count;
	Rva00308325Elem *track = m_tracks[index];
	Rva00308325Elem *a = &track[r];
	Rva00308325Elem *b = &track[r2];
	float g = 1.0f - f;
	out[0] = a->v[0] * g + b->v[0] * f;
	out[1] = a->v[1] * g + b->v[1] * f;
	out[2] = a->v[2] * g + b->v[2] * f;
	out[3] = a->v[3] * g + b->v[3] * f;
}
