// ?getRelationship@Team@@QBE?AW4Relationship@@PBV1@@Z
// partial score=0.95 date=2026-09-28
// ?getRelationship@Team@@QBE?AW4Relationship@@PBV1@@Z
// partial score=0.95 date=2026-09-28
// cl: /MD /O1 /GX /DNDEBUG /DWIN32 /D_WINDOWS /D_STLP_USE_STATIC_LIB /D_CRTIMP= /D_STLP_USE_MALLOC /D_STLP_NO_EXCEPTIONS
// stlport
// ?getRelationship@Team@@QBE?AW4Relationship@@PBV1@@Z, retail 0x003A0FD2 (137 bytes).
// Team::getRelationship(const Team*) const -- BFME2 retail Team+0x34 is the
// team key (Player 0x002AD0C6 inlines the same +0x34 read), Team+0x118 is the
// team-override map and Team+0x11C the player-override map (BFME1 donor keeps
// them at +0xec/+0xf0), Player+0x54 is m_playerIndex. Donor: BFME1
// Team::getRelationship in open-bfme-1/Code/GameEngine/Source/Common/RTS/Team.cpp:2128
// for the empty-then-find team map, empty-then-controllingPlayer-then-find
// player map, fallback to getControllingPlayer()->getRelationship shape.
// Evidence: 9 callers including 0x002760E1 0x0028D243 0x0037431F 0x0041B84C;
// callees rowed/pinned 0x002888D4 (_M_find ICF twin H) 0x0039D7CF 0x002AD0C6.
#include <hash_map>

enum Relationship
{
	ENEMIES = 0,
	NEUTRAL = 1,
	ALLIES = 2
};

typedef std::hash_map<int, Relationship, std::hash<int>, std::equal_to<int> > PlayerRelationMapType;

struct RetailPlayerRelationMap
{
	void *m_vtbl;
	PlayerRelationMapType m_map;
};

class Team;
class Object;
class Player
{
public:
	int getPlayerIndex() const { return m_playerIndex; }
	Relationship getRelationship(const Player *that) const;
	Relationship getRelationship(const Team *that) const;
	Relationship getRelationship(const Object *that) const;

private:
	char m_pad00[0x54];
	int m_playerIndex; // +0x54
	char m_pad58[0x330 - 0x58];
	RetailPlayerRelationMap *m_playerRelations; // +0x330
	RetailPlayerRelationMap *m_teamRelations; // +0x334
};

class Team
{
public:
	Player *getControllingPlayer() const;
	int getTeamKey() const { return m_key34; }
	Relationship getRelationship(const Team *that) const;

private:
	char m_pad00[0x30];
	void *m_proto; // +0x30 read by Team::getControllingPlayer in its TU
	int m_key34; // +0x34
	char m_pad38[0x118 - 0x38];
	RetailPlayerRelationMap *m_teamRelations; // +0x118
	RetailPlayerRelationMap *m_playerRelations; // +0x11C
};

class Object
{
public:
	Player *getControllingPlayer() const;
};

Relationship Team::getRelationship(const Team *that) const
{
	RetailPlayerRelationMap *teamMap = m_teamRelations;
	if (!teamMap->m_map.empty() && that != NULL)
	{
		PlayerRelationMapType::const_iterator it = teamMap->m_map.find(that->getTeamKey());
		if (it != teamMap->m_map.end())
		{
			return (*it).second;
		}
	}

	RetailPlayerRelationMap *playerMap = m_playerRelations;
	if (!playerMap->m_map.empty() && that != NULL)
	{
		Player *thatPlayer = that->getControllingPlayer();
		if (thatPlayer != NULL)
		{
			PlayerRelationMapType::const_iterator it = playerMap->m_map.find(thatPlayer->getPlayerIndex());
			if (it != playerMap->m_map.end())
			{
				return (*it).second;
			}
		}
	}

	return getControllingPlayer()->getRelationship(that);
}
