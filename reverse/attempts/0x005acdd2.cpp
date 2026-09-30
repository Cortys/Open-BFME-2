// ?Rva005ACDD2Distance@@YGMPBVCoord3D@@0@Z
// partial score=0.92 date=2026-09-30
// ?Rva005ACDD2Distance@@YGMPBVCoord3D@@0@Z
// partial score=0.92 date=2026-09-30
// cl: /O1 /MD /arch:SSE
// ?Rva005ACDD2Distance@@YAMPBVCoord3D@@0@Z @0x005ACDD2 67B: distance between
// two Coord3D via diff temp plus rowed Coord3D::length. Unblocks 179B caller.

class Coord3D
{
public:
	float length() const;

	float m_x;
	float m_y;
	float m_z;
};

// ?Rva005ACDD2Distance@@YGMPBVCoord3D@@0@Z present-unmatched
float __stdcall Rva005ACDD2Distance(const Coord3D *a, const Coord3D *b)
{
	float ax = a->m_x;
	float ay = a->m_y;
	float az = a->m_z;
	float bx = b->m_x;
	float by = b->m_y;
	float bz = b->m_z;
	Coord3D diff;
	diff.m_x = ax - bx;
	diff.m_y = ay - by;
	diff.m_z = az - bz;
	return diff.length();
}
