// ?rva0030822F@Rva0030822F@@QAEXPAUInterpElem@@M@Z
// partial score=0.92 date=2026-10-01
// ?rva0030822F@Rva0030822F@@QAEXPAUInterpElem@@M@Z
// partial score=0.92 date=2026-10-01
// cl: /O1 /MD /arch:SSE /Oy- /G7
// ??0 placeholder header: ?rva0030822F@Rva0030822F@@QAEXPAUInterpElem@@M@Z RVA 0x0030822F size 246 evidence SSE lerp with g_Va00BBB8D8 1.0 callers 0x00080858 0x00080F95
extern float g_Va00BBB8D8;

struct InterpElem
{
	float x, y, z, w;
};

class Rva0030822F
{
public:
	void rva0030822F(InterpElem *out, float t);
private:
	char m_pad00[0xa0];
	unsigned int m_count;
	float m_scale;
	InterpElem *m_base;
};

// ?rva0030822F@Rva0030822F@@QAEXPAUInterpElem@@M@Z present-unmatched
void Rva0030822F::rva0030822F(InterpElem *out, float t)
{
	if (m_count <= 0)
	{
		out->y = 0.0f;
		out->z = g_Va00BBB8D8;
		out->w = 0.0f;
		out->x = 0.0f;
		return;
	}
	float ft = m_scale * t;
	int it = (int)ft;
	float f_it = (float)it;
	float fract = ft - f_it;
	float inv = g_Va00BBB8D8 - fract;
	unsigned int idx1 = (unsigned int)it % m_count;
	unsigned int idx2 = (idx1 + 1) % m_count;
	InterpElem *a = &m_base[idx1];
	InterpElem *b = &m_base[idx2];
	out->x = a->x * inv + b->x * fract;
	out->y = a->y * inv + b->y * fract;
	out->z = a->z * inv + b->z * fract;
	out->w = a->w * inv + b->w * fract;
}
