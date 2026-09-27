// cl: /O1 /DNDEBUG /MD
//
// ?setLocomotorGoalPositionExplicit@AIUpdateInterface@@UAEXABUCoord3D@@@Z, retail 0x00262C35, 30 bytes. ZH donor AIUpdate.cpp verbatim: m_type at
// +0x1FC becomes POSITION_EXPLICIT (2) then the Coord3D arg copies to +0x200.
// Offsets shift the ZH +0x1D8/+0x1DC pair by +0x24 with the BFME2 tail that
// the landed wakeUpNow (+0x3C2) and 0x3B6-cluster siblings bound. Leaf.

struct Coord3D
{
	float x;
	float y;
	float z;
};

class AIUpdateInterface
{
	char m_pad04[0x1F8];
	int m_locomotorGoalType;
	Coord3D m_locomotorGoalData;
public:
	virtual void setLocomotorGoalPositionExplicit(const Coord3D &newPos);
};

void AIUpdateInterface::setLocomotorGoalPositionExplicit(const Coord3D &newPos)
{
	m_locomotorGoalType = 2;
	m_locomotorGoalData = newPos;
}
