// ?rva00265514@Object@@QBEPAUCoord3D@@PAU2@PBV1@@Z
// partial score=0.94 date=2026-10-03
// ?rva00265514@Object@@QBEPAUCoord3D@@PAU2@PBV1@@Z
// partial score=0.94 date=2026-09-29
// ?rva00265514@Object@@QBEPAUCoord3D@@PAU2@PBV1@@Z
// partial score=0.94 date=2026-09-29
// cl: /O1 /DNDEBUG /MD /EHsc /arch:SSE
// ?rva00265514@Object@@QBEPAUCoord3D@@PAU2@PBV1@@Z retail 0x00265514 130B.
// Unlock lane: planar dir plus radii sum vs length plus scaled out.
// Evidence: callers at 0x0026E48B 0x002CAEC0 plus rowed getPlanarDirectionTo.

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
	Coord3D *getPlanarDirectionTo(Coord3D *out, const Object *other) const;
	Coord3D *rva00265514(Coord3D *out, const Object *other) const;
private:
	char m_pad00[0x38];
	Coord3D m_position;
	char m_pad44[0xB8 - 0x38 - 12];
	float m_majorRadius;
};

// ?rva00265514@Object@@QBEPAUCoord3D@@PAU2@PBV1@@Z present-unmatched
Coord3D *Object::rva00265514(Coord3D *out, const Object *other) const
{
	Coord3D dir;
	getPlanarDirectionTo(&dir, other);
	float len = dir.length();
	float sum = other->m_majorRadius + m_majorRadius;
	Coord3D tmp;
	if (sum >= len) {
		tmp.x = 0.0f;
		tmp.y = 0.0f;
		tmp.z = 0.0f;
	} else {
		float f = (len - sum) / len;
		tmp.x = dir.x * f;
		tmp.y = dir.y * f;
		tmp.z = dir.z * f;
	}
	out->x = tmp.x;
	out->y = tmp.y;
	out->z = tmp.z;
	return out;
}
