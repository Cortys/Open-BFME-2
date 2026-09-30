// ?rva002C986B@Object@@QBEXPAUCoord3D@@PBU2@@Z
// partial score=0.93 date=2026-09-30
// ?rva002C986B@Object@@QBEXPAUCoord3D@@PBU2@@Z
// partial score=0.93 date=2026-09-30
// cl: /O1 /arch:SSE /DNDEBUG /MD /EHs-c-
// ?rva002C986B@Object@@QBEXPAUCoord3D@@PBU2@@Z @0x002C986B 119B
// Object planar scaled-repulsion: delta via rowed 0x0026382B, len via rowed Coord3D::length,
// radius at +0xB8 (Object geometry per ObjectRva002C97E8 sibling); zero when len <= radius
// else out = delta * (len - radius) / len. Evidence: callers 0x002CAEE2; prev/next TUs share
// +0x38 position and +0xB8 majorRadius layout and /O1 /arch:SSE flags.
struct Coord3D
{
	float x;
	float y;
	float z;
	float length() const;
};

class Object
{
public:
	void rva002C986B(Coord3D *out, const Coord3D *pos) const;
	void rva0026382B(Coord3D *out, const Coord3D *pos) const;

private:
	char m_pad00[0x38];
	Coord3D m_position; // +0x38
	char m_pad44[0xB8 - 0x38 - 12];
	float m_majorRadius; // +0xB8
};

// ?rva002C986B@Object@@QBEXPAUCoord3D@@PBU2@@Z present-unmatched
void Object::rva002C986B(Coord3D *out, const Coord3D *pos) const
{
	Coord3D delta;
	rva0026382B(&delta, pos);
	float len = delta.length();
	float rad = m_majorRadius;
	float f;
	float ox;
	float oy;
	float oz;
	if (rad >= len) {
		ox = 0.0f;
		oy = 0.0f;
		oz = 0.0f;
	} else {
		f = (len - rad) / len;
		oz = delta.z * f;
		oy = delta.y * f;
		ox = f * delta.x;
	}
	out->x = ox;
	out->y = oy;
	out->z = oz;
}
