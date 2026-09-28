// ?getMinMaxAndCenter@AIGroup@@QAE_NPAUCoord2D@@0PAUCoord3D@@@Z
// partial score=0.93 date=2026-09-28
// ?getMinMaxAndCenter@AIGroup@@QAE_NPAUCoord2D@@0PAUCoord3D@@@Z
// partial score=0.93 date=2026-09-28
// cl: /O1 /Oy- /DNDEBUG /MD /arch:SSE2
//
// ?getMinMaxAndCenter@AIGroup@@QAE_NPAUCoord2D@@0PAUCoord3D@@@Z, retail 0x0036D14F, 374B.
// BFME1 AIGroup_getMinMaxAndCenter donor (0x151F70) via ZH AIGroup.
// Evidence: same 3-out-param bbox loop as donor; Object+0x38 position plus
// +0x1C8 mask 8 DISABLED_HELD plus +0x258 AI plus +0x410 formation (BFME1
// +0x1A4/+0x204/+0x31C); divide-once multiply-thrice plus count>=2 formation
// rule; callers at 0x36D3FA 0x36F782 0x372596; movss needs /arch:SSE and ebp
// frame needs /Oy-; MSVC list at +0x04 as in AIGroupAttackTeam.

#include <list>

typedef int Int;
typedef float Real;
typedef bool Bool;
typedef unsigned int FormationID;

enum { NO_FORMATION_ID = 0 };
enum { DISABLED_HELD = 0x08 };

struct Coord2D
{
	Real x;
	Real y;
};

struct Coord3D
{
	Real x;
	Real y;
	Real z;
};

class AIUpdateInterface;

class Object
{
public:
	Int getDisabledMask() const { return m_disabledMaskWord; }
	AIUpdateInterface *getAIUpdateInterface() { return m_ai; }
	const Coord3D *getPosition() const { return &m_position; }
	FormationID getFormationID() const { return m_formationID; }

private:
	char m_pad00[0x38];
	Coord3D m_position;
	char m_pad44[0x1C8 - 0x44];
	Int m_disabledMaskWord;
	char m_pad1CC[0x258 - 0x1CC];
	AIUpdateInterface *m_ai;
	char m_pad25C[0x410 - 0x25C];
	FormationID m_formationID;
};

class AIGroup
{
public:
	Bool getMinMaxAndCenter(Coord2D *min, Coord2D *max, Coord3D *center);

private:
	std::list<Object *> m_memberList;
};

// ?getMinMaxAndCenter@AIGroup@@QAE_NPAUCoord2D@@0PAUCoord3D@@@Z present-unmatched
Bool AIGroup::getMinMaxAndCenter(Coord2D *min, Coord2D *max, Coord3D *center)
{
	Int count = 0;
	min->x = 1e10f;
	max->x = -1e10f;
	min->y = 1e10f;
	max->y = -1e10f;
	center->x = 0.0f;
	center->y = 0.0f;
	center->z = 0.0f;

	std::list<Object *>::iterator i;
	FormationID id = NO_FORMATION_ID;
	for (i = m_memberList.begin(); i != m_memberList.end(); ++i) {
		if ((*i)->getDisabledMask() & DISABLED_HELD) {
			continue;
		}
		AIUpdateInterface *ai = (*i)->getAIUpdateInterface();
		if (ai) {
			const Coord3D *objPos = (*i)->getPosition();
			center->x = objPos->x + center->x;
			center->y = objPos->y + center->y;
			center->z = objPos->z + center->z;

			min->x = min->x > objPos->x ? objPos->x : min->x;
			max->x = max->x < objPos->x ? objPos->x : max->x;
			min->y = min->y > objPos->y ? objPos->y : min->y;
			max->y = max->y < objPos->y ? objPos->y : max->y;
			FormationID curID = (*i)->getFormationID();
			if (count == 0) {
				id = curID;
			} else {
				if (id == NO_FORMATION_ID) {
					id = NO_FORMATION_ID;
				}
			}

			count++;
		}
	}

	Real oneOverCount = 1.0f / count;
	center->x = oneOverCount * center->x;
	center->y = oneOverCount * center->y;
	center->z = oneOverCount * center->z;
	Bool isFormation = (id != NO_FORMATION_ID);
	if (count < 2)
		isFormation = false;
	return isFormation;
}
