// ?rva00363BC7@Rva00363BC7@@QAEPAXPAUCoord2D@@PAM@Z
// partial score=0.98 date=2026-10-03
// cl: /O1 /DNDEBUG /MD /arch:SSE
// ?rva00363BC7@Rva00363BC7@@QAEPAXPAUCoord2D@@PAM@Z, retail 0x00363BC7, 170 bytes.
// Unlock: if +0x08 null zeroes out vec and sets *len to g_00BCF628 returning
// null; else builds dx dy from template +0xC/+0x10 minus this +0xC/+0x10,
// length via rowed Coord2D::length, clamps *len to g_00BCF628, normalizes out
// vec via 1.0f g_00BBB8D8. Evidence: unlock lane, callers 0x001E3572 0x00365F4B;
// externs g_Va00BCF628 g_Va00BBB8D8 as annotated; len kept in ST0 via local.
//
// Improvement over the previous bank (0.97): the clamp condition reads
// `g_Va00BCF628 > len`, which emits retail's `fld st(0); fld [g]; fcomip
// st,st(1)` order and the matching `g <= len` skip. The prior `len > g`
// spelling compiled to the transposed `fld [g]; fld st(1)` and clamped on the
// opposite edge. Remaining diff: the normalize's `movss xmm1,[out]` is
// scheduled after the 1.0f load instead of before it (xmm1/xmm0 swap, +0x83).

extern float g_Va00BCF628;
extern float g_Va00BBB8D8;

struct Coord2D
{
	float x;
	float y;
	float length() const;
};

struct LocomotorTemplate
{
	char m_pad[0xC];
	float m_x0C;
	float m_y10;
};

class Rva00363BC7
{
public:
	void *rva00363BC7(Coord2D *out, float *outLen);
	char m_pad00[8];
	LocomotorTemplate *m_08;
	float m_0C;
	float m_10;
};

void *Rva00363BC7::rva00363BC7(Coord2D *out, float *outLen)
{
	if (m_08 == 0) {
		out->y = 0.0f;
		out->x = 0.0f;
		*outLen = g_Va00BCF628;
		return 0;
	}
	out->x = m_08->m_x0C - m_0C;
	out->y = m_08->m_y10 - m_10;
	float len = out->length();
	*outLen = len;
	if (g_Va00BCF628 > len) {
		*outLen = g_Va00BCF628;
	}
	float inv = g_Va00BBB8D8 / *outLen;
	out->x *= inv;
	out->y *= inv;
	return m_08;
}
