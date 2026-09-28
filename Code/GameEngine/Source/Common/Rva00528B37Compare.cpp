// cl: /O1 /arch:SSE /MD
// ?Rva00528B37Equal@@YAHPBURva00528B37Key@@0@Z retail 0x00528B37 59B
// Evidence: ints +0 +4 equal plus fabs(float +8 diff) < 0.1f at 0x7C2424 via fabs 0x629210; caller 0x00529C1D tests al
extern float g_Va00BC2424;
extern "C" double __cdecl fabs(double v);

struct Rva00528B37Key
{
	int m_a;
	int m_b;
	float m_f;
};

int Rva00528B37Equal(const Rva00528B37Key *a, const Rva00528B37Key *b)
{
	if (a->m_a != b->m_a)
		return false;
	if (a->m_b != b->m_b)
		return false;
	if (fabs(a->m_f - b->m_f) < g_Va00BC2424)
		return true;
	return false;
}
