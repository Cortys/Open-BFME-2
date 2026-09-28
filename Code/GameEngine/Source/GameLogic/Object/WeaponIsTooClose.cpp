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

class GameLogic
{
public:
	char m_pad00[0x40];
	unsigned int m_frame; // +0x40
};

#define TheGameLogic (*(GameLogic **)0x00DFE78C)

class Weapon
{
public:
	bool isTooClose(const Object *source, const Coord3D *pos) const;
	float rva002C957E() const;
	bool rva002C95F0() const;

private:
	char m_pad00[4];
	const WeaponTemplate *m_template; // +4
	char m_pad08[0x50 - 8]; // +8..0x50
	volatile unsigned int m_50; // +0x50 volatile forces m_50-first load order (retail 17B vs 16B A1 size opt)
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

// ?rva002C95F0@Weapon@@QBE_NXZ @0x002C95F0 17B
// Weapon frame check: m_50 (+0x50 leech/active frame per WeaponCtor) vs GameLogic frame+0x40 via TheGameLogic.
// Evidence: callers 0x00343EAD 0x00343EC0 in 0x00343DD8; unblocks 0x00343DD8; prev/next Weapon owners; pooled TheGameLogic.
bool Weapon::rva002C95F0() const
{
	return m_50 > TheGameLogic->m_frame;
}
