// cl: /O1 /arch:SSE /DNDEBUG /MD /EHs-c-
// ?isTooClose@Weapon@@QBE_NPBVObject@@PBUCoord3D@@@Z @0x002C9B3D (67B).
// Weapon::isTooClose(source, pos): minRange==0 -> false; else shrunkenDistSqr
// (Object::rva002C97E8 of source position vs pos) < sqr(minRange).
// Evidence: [ecx+4] is WeaponTemplate (getMinimumAttackRange rowed 0x002C92FA);
// caller passes source+0x38 and pos to rowed rva002C97E8; ZH donor Weapon.cpp
// isTooClose(const Object*, const Coord3D*) with PartitionManager replaced by
// the BFME2 Object shrunken-distance body.
typedef float Real;

struct Coord3D
{
	float x;
	float y;
	float z;
};

class Object
{
public:
	float rva002C97E8(const Coord3D *a, const Coord3D *b) const;

private:
	char m_pad00[0x38];
public:
	Coord3D m_position; // +0x38
};

class WeaponTemplate
{
public:
	float getMinimumAttackRange() const;
};

class Weapon
{
public:
	bool isTooClose(const Object *source, const Coord3D *pos) const;
	float rva002C957E() const;

private:
	char m_pad00[4];
	const WeaponTemplate *m_template; // +4
};

bool Weapon::isTooClose(const Object *source, const Coord3D *pos) const
{
	float minRange = m_template->getMinimumAttackRange();
	if (minRange == 0.0f)
		return false;
	float distSqr = source->rva002C97E8(&source->m_position, pos);
	if (distSqr < minRange * minRange)
		return true;
	return false;
}

float Weapon::rva002C957E() const
{
	return m_template->getMinimumAttackRange();
}
