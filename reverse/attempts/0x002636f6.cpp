// ?rva002636F6@Object@@QBEMPBUCoord3D@@PBX0@Z
// partial score=1.0 date=2026-09-29
// ?rva002636F6@Object@@QBEMPBUCoord3D@@PBX0@Z
// partial score=1.0 date=2026-09-29
// cl: /O1 /arch:SSE /DNDEBUG /MD /EHs-c-
// ?rva002636F6@Object@@QBEMPBUCoord3D@@PBX0@Z,
// retail 0x002636F6 (109 bytes). Two-radius twin of rowed 0x002C97E8.
// Planar shrunken-distance-squared with two radii:
// sqr(max(0, sqrt(dx*dx+dy*dy) - this->m_majorRadius - otherRadius))
// where otherRadius is the +0xB8 float of the middle object.
// Evidence: same x87+qword+sqrt-import shape as ObjectRva002C97E8.cpp;
// this+0xB8 and arg2+0xB8 both fsubbed; ret 0xC with
// (Coord3D*, void*, Coord3D*); middle typed void to avoid inventing
// its class; callers 0x002C9863/0x002CB2EA/0x002CB4D1.
#include <math.h>

struct Coord3D
{
	float x;
	float y;
	float z;
};

class Object
{
public:
	float rva002636F6(const Coord3D *a, const void *other, const Coord3D *b) const;

private:
	char m_pad00[0x38];
	Coord3D m_position; // +0x38
	char m_pad44[0xB8 - 0x38 - 12];
	float m_majorRadius; // +0xB8
};

float Object::rva002636F6(const Coord3D *a, const void *other, const Coord3D *b) const
{
	float dx = a->x - b->x;
	float dy = a->y - b->y;
	float rad = m_majorRadius;
	float rad2 = *(float const *)((char const *)other + 0xB8);
	double dist = sqrt((double)(dx * dx + dy * dy));
	float d = (float)dist - rad - rad2;
	float result;
	if (d < 0.0f)
		result = 0.0f;
	else
		result = d * d;
	return result;
}
