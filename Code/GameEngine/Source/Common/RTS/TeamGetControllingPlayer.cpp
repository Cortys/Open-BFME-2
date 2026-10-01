// cl: /MD /O1 /GX /DNDEBUG /DWIN32 /D_WINDOWS /D_STLP_USE_STATIC_LIB /D_CRTIMP= /D_STLP_USE_MALLOC /D_STLP_NO_EXCEPTIONS
// stlport

// ?getControllingPlayer@Team@@QBEPAVPlayer@@XZ, retail 0x0039D7CF (12 bytes).
// Team::getControllingPlayer is `return m_proto ? m_proto->m_owningPlayer :
// NULL`. Retail-measured BFME2 layout: Team::m_proto is at +0x30 here and the
// prototype owner holds m_owningPlayer at +0x08. Dedicated TU so the pin
// (Object::getControllingPlayer tail target) resolves to a row.
//
// ?getRelationship@Team@@QBE?AW4Relationship@@PBV1@@Z, retail 0x003A0FD2
// (137 bytes). BFME1 donor Team::getRelationship (Team.cpp:2128): the
// team-override map, then the player-override map keyed by the other team's
// controlling player index, then the controlling player's own relationship.
// BFME2 retail layout: Team+0x34 is the team key (Player 0x002AD0C6 inlines
// the same +0x34 read), Team+0x118 the team-override map and Team+0x11C the
// player-override map (the BFME1 donor keeps them at +0xEC/+0xF0),
// Player+0x54 is m_playerIndex. Callees: the rowed hashtable _M_find
// 0x002888D4 and Player::getRelationship(const Team *) 0x002AD0C6; 9 callers
// such as 0x002760E1 and 0x0028D243. Retail keeps state across the
// getControllingPlayer call in a volatile register, which cl only does when
// that callee was compiled earlier in the same TU, so it joins this file; the
// TU takes the STLport flags its hash_map needs (the two earlier bodies are
// unchanged by them).
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

	char m_pad00[0x54];
	int m_playerIndex; // +0x54
	char m_pad58[0x5c - 0x58];
	int m_playerType; // +0x5C
	char m_pad60[0x330 - 0x60];
	RetailPlayerRelationMap *m_playerRelations; // +0x330
	RetailPlayerRelationMap *m_teamRelations; // +0x334
};

struct TeamPrototypeOwner
{
	unsigned char m_pad00[ 0x08 ];
	Player *m_owningPlayer;
};

class Rva002A9BF2
{
public:
	void *rva002A9BF2();
};

class Object
{
public:
	Player *getControllingPlayer() const;
	unsigned char m_pad00[ 0x74 ];
	unsigned int m_id;
};

class Team
{
public:
	Player *getControllingPlayer() const;
	void rva0039D84A(Object *obj);
	int getTeamKey() const { return m_key34; }
	Relationship getRelationship(const Team *that) const;

private:
	unsigned char m_pad00[ 0x30 ];
	TeamPrototypeOwner *m_proto; // +0x30
	int m_key34; // +0x34
	unsigned char m_pad38[ 0x114 - 0x38 ];
	unsigned int m_target; // +0x114
	RetailPlayerRelationMap *m_teamRelations; // +0x118
	RetailPlayerRelationMap *m_playerRelations; // +0x11C
};

Player *Team::getControllingPlayer() const
{
	if( !m_proto )
		return 0;
	return m_proto->m_owningPlayer;
}

// ?rva0039D84A@Team@@QAEXPAVObject@@@Z, retail 0x0039D84A (63 bytes).
// Team::rva0039D84A(Object*): clears Team+0x114 when arg null else stores
// Object+0x74 id only for computer players (Player+0x5c == 1) with non-zero
// difficulty via rowed Rva002A9BF2::rva002A9BF2. Shape matches the BFME1/ZH
// Team::setTeamTargetObject donor with BFME2 deltas (Team proto +0x30 vs +0x04
// target +0x114 vs +0xE8 Player type +0x5c vs +0x2c Object id +0x74 same).
// Same TU as getControllingPlayer so the second call reuses ecx as retail does.
void Team::rva0039D84A(Object *obj)
{
	if( obj == 0 )
	{
		m_target = 0;
		return;
	}
	if( getControllingPlayer()->m_playerType != 1 )
		return;
	if( ((Rva002A9BF2 *)getControllingPlayer())->rva002A9BF2() == 0 )
		return;
	m_target = obj->m_id;
}

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
