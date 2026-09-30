// cl: /O1 /MD
//
// ?Rva00547070@Rva00546F61@@UAEPAUCoord3D@@H@Z, retail 0x00547070 41B.
// Virtual slot 8 (offset 0x20) of vtable 0x0086A420 (class of
// ??1Rva00546F61@@UAE@XZ in Rva00548948Derived.cpp). No donor (opaque Rva).
// Evidence: push [ebx+0x18] ObjectID plus TheGameLogic findObjectByID row
// 0x00049DC5 plus copy of found Object position +0x38 into this Coord3D +0x20
// via lea plus 3x movsd plus lea eax return. No callers. Ignores int dummy
// param (ret 4) and uses this only.
enum ObjectID
{
	INVALID_OBJECT_ID = 0
};
struct Coord3D
{
	float x;
	float y;
	float z;
};
class Object
{
public:
	char m_pad0[0x38];
	Coord3D m_position; // +0x38
	char m_pad44[0x438 - 0x44];
	unsigned char m_flags438; // +0x438 bit0
	bool isUsingAirborneLocomotor() const;
};
class GameLogic
{
public:
	Object* findObjectByID(ObjectID id);
};
extern GameLogic* TheGameLogic;
class BuildListInfo
{
public:
	int getDesiredGatherers();
};
class Rva00546F61
{
public:
	virtual ~Rva00546F61();
	virtual void slot01();
	virtual void slot02();
	virtual void slot03();
	virtual void slot04();
	virtual bool Rva0054703E(int dummy);
	virtual void slot06();
	virtual void slot07();
	virtual Coord3D* Rva00547070(int dummy);
	virtual void slot09();
	virtual void slot10();
	virtual bool rva00547099(int *outID, void *out);
private:
	char m_pad04[0x18 - 4];
	ObjectID m_targetID; // +0x18
	bool m_b1C; // +0x1C
	char m_pad1D[3];
	Coord3D m_pos; // +0x20
};
Coord3D* Rva00546F61::Rva00547070(int dummy)
{
	Object* found = TheGameLogic->findObjectByID(m_targetID);
	if (found != 0) {
		Coord3D* dst = &m_pos;
		const Coord3D* src = &found->m_position;
		*dst = *src;
	}
	return &m_pos;
}

// ?Rva0054703E@Rva00546F61@@UAE_NH@Z @0x0054703E 50B.
// Virtual slot 5 (offset 0x14) of vtable 0x0086A420 (same class/vtable/flags
// as slot8 above). Evidence: m_b1C check plus m_targetID plus TheGameLogic
// findObjectByID row 0x00049DC5 plus Object+0x438 bit0 test. No callers.
// Ignores int dummy param (ret 4) and uses this only.
bool Rva00546F61::Rva0054703E(int dummy)
{
	if (m_b1C) {
		return true;
	}
	Object* found = TheGameLogic->findObjectByID(m_targetID);
	if (found == 0) {
		m_b1C = true;
		return true;
	}
	if ((found->m_flags438 & 1) == 0) {
		return false;
	}
	m_b1C = true;
	return true;
}

// ?rva00547099@Rva00546F61@@UAE_NPAHPAX@Z, retail 0x00547099 95B.
// Virtual slot 11 (offset 0x2C) of vtable 0x0086A420 (same class/vtable/flags
// as slots 5/8 above). Sets *outID to 0x425, finds Object via m_targetID,
// copies found position+0x38 or own m_pos to out+0x14 via 3x movsd, gatherers
// to out+4, airborne to out+0. Returns true. Evidence: vslot, donor layout,
// callers none.
bool Rva00546F61::rva00547099(int *outID, void *out)
{
	*outID = 0x425;
	Object *found = TheGameLogic->findObjectByID(m_targetID);
	if (found) {
		int gatherers = ((BuildListInfo *)found)->getDesiredGatherers();
		*(int *)((char *)out + 4) = gatherers;
		*(Coord3D *)((char *)out + 0x14) = found->m_position;
		*(bool *)out = found->isUsingAirborneLocomotor();
	} else {
		*(Coord3D *)((char *)out + 0x14) = m_pos;
	}
	return true;
}
