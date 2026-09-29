// ?rva004DFA43@Rva004DFA43@@QAE_NPAX0@Z
// partial score=0.93 date=2026-09-29
// ?rva004DFA43@Rva004DFA43@@QAE_NPAX0@Z
// partial score=0.93 date=2026-09-29
// cl: /O1 /MD /arch:SSE
// ?rva004DFA43@Rva004DFA43@@QAE_NPAX0@Z, RVA 0x004DFA43, 112 bytes.
// __thiscall sphere test: radius m_04-m_14 vs distance from center
// m_08/m_0C/m_10 to the point returned by the __cdecl getter in the second
// arg called with the first arg. Evidence: EBP frame plus push [ebp+8] call
// [ebp+C] plus movss/subss/mulss/addss/comiss plus ret8 plus callers at
// 0x002829FE and 0x004DFD27. Neighbours are /O1 /MD; SSE for movss.
struct Vec3
{
	float x;
	float y;
	float z;
};

class Rva004DFA43
{
public:
	bool rva004DFA43(void *ctx, void *fn);

private:
	float m_00;
	float m_04;
	float m_08;
	float m_0C;
	float m_10;
	float m_14;
};

// ?rva004DFA43@Rva004DFA43@@QAE_NPAX0@Z present-unmatched
bool Rva004DFA43::rva004DFA43(void *ctx, void *fn)
{
	float r = m_04 - m_14;
	Vec3 *p = ((Vec3 *(__cdecl *)(void *))fn)(ctx);
	float dx = p->x - m_08;
	float dy = p->y - m_0C;
	float dz = p->z - m_10;
	float d2 = dz * dz + dy * dy + dx * dx;
	float r2 = r * r;
	if (r2 < d2)
		return false;
	return true;
}
