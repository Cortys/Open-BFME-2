// ?Rva004C20D5IsWithin@@YG_NMPBUCoord3D@@0@Z
// partial score=0.93 date=2026-09-30
// ?Rva004C20D5IsWithin@@YG_NMPBUCoord3D@@0@Z
// partial score=0.93 date=2026-09-30
// cl: /O1 /DNDEBUG /MD /arch:SSE2
//
// ?Rva004C20D5IsWithin@@YG_NMPBUCoord3D@@0@Z @0x004C20D5 82B. XY distance check.
// Evidence: free __stdcall ret 0xC with float plus two 12B pointers, 3x movss
// subss plus stores to 12B local, Coord2D GetLength row 0x0000599F on XY part,
// fld plus fcompi plus jb returning AL 1 when dist >= length. Callers 0x004C21A9
// plus self-neighbour. Honest address name.
struct Coord3DBase
{
	float x;
	float y;
	float z;
};

struct Coord2D
{
	float GetLength() const;
	float x;
	float y;
};

struct Coord3D : public Coord3DBase
{
	Coord3D &Sub(const Coord3DBase &left, const Coord3DBase &right)
	{
		x = left.x - right.x;
		y = left.y - right.y;
		z = left.z - right.z;
		return *this;
	}
};

// ?Rva004C20D5IsWithin@@YG_NMPBUCoord3D@@0@Z present-unmatched
bool __stdcall Rva004C20D5IsWithin(float dist, const Coord3D *a, const Coord3D *b)
{
	Coord3D diff;
	diff.Sub(*b, *a);
	float len = ((const Coord2D *)&diff)->GetLength();
	if (dist >= len)
		return true;
	return false;
}
