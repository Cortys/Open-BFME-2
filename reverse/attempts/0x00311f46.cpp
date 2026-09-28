// ?rva00311F46@Rva00311F46@@QAE_NPBUCoord3D@@M@Z
// partial score=0.91 date=2026-09-28
// ?rva00311F46@Rva00311F46@@QAE_NPBUCoord3D@@M@Z
// partial score=0.91 date=2026-09-28
// cl: /O1 /arch:SSE /MD
// ?rva00311F46@Rva00311F46@@QAE_NPBUCoord3D@@M@Z, retail 0x00311F46, 156 bytes.
// Evidence: caller 0x003767BB in aerial-path 0x0037609C; shares +0x2c/+0x30
// 184B vector with 0x311974/0x311B70 siblings; rowed Coord3D::length 0x3571;
// XY-only distance vs thresh, overwrites element+0xa4 on hit.
struct Coord3D
{
	float x;
	float y;
	float z;
	float length() const;
};

struct Rva00311F46
{
	char m_pad00[0x2c];
	char *m_begin;
	char *m_end;
	bool rva00311F46(const Coord3D *pt, float thresh);
};

// ?rva00311F46@Rva00311F46@@QAE_NPBUCoord3D@@M@Z present-unmatched
bool Rva00311F46::rva00311F46(const Coord3D *pt, float thresh)
{
	char *p = m_begin + 0x170;
	if (p == m_end)
		return false;
	do
	{
		int count = (m_end - m_begin) / 0xb8;
		char *last = m_begin + count * 0xb8 - 0x170;
		if (p == last)
			return false;
		float dx = *(float *)(p + 0xa4) - pt->x;
		float dy = *(float *)(p + 0xa8) - pt->y;
		Coord3D d;
		d.x = dx;
		d.y = dy;
		d.z = 0.0f;
		float len = d.length();
		if (thresh > len)
		{
			*(Coord3D *)(p + 0xa4) = *pt;
			return true;
		}
		p += 0xb8;
	} while (p != m_end);
	return false;
}
