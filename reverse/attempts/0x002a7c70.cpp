// ?getPlayersWithRelationship@PlayerList@@QAEIHI_N@Z
// partial score=0.93 date=2026-09-28
// ?getPlayersWithRelationship@PlayerList@@QAEIHI_N@Z
// partial score=0.93 date=2026-09-28
// cl: /O1 /DNDEBUG /MD /EHsc
// ?getPlayersWithRelationship@PlayerList@@QAEIHI_N@Z, retail 0x002A7C70, 192 bytes.
// Evidence: BFME1 donor PlayerListGetPlayersWithRelationship.cpp (3-arg reverse
// plus default 0xf); rowed getNthPlayer 0x2A7A29 plus getRelationship 0x2AD0C6;
// PlayerList count +0x14, Player index +0x54, defaultTeam +0x2ec; 11 waiters.
typedef int Int;
typedef unsigned int UnsignedInt;
typedef unsigned int PlayerMaskType;

class Team
{
};

enum Relationship
{
	ENEMIES = 0,
	NEUTRAL = 1,
	ALLIES = 2
};

enum AllowPlayerRelationship
{
	ALLOW_SAME_PLAYER = 0x01,
	ALLOW_ALLIES = 0x02,
	ALLOW_ENEMIES = 0x04,
	ALLOW_NEUTRAL = 0x08
};

class Player
{
public:
	unsigned int getPlayerMask() const { return 1u << m_playerIndex; }
	Team *getDefaultTeam() const { return m_defaultTeam; }
	Relationship getRelationship(const Team *that) const;

private:
	char m_pad00[0x54];
	int m_playerIndex; // +0x54
	char m_pad58[0x2ec - 0x54 - 4];
	Team *m_defaultTeam; // +0x2ec
};

class PlayerList
{
public:
	Player *getNthPlayer(Int i);
	PlayerMaskType getPlayersWithRelationship(Int playerIndex, UnsignedInt allowedRelationships, bool reverse);

private:
	char m_pad00[0x14];
	Int m_playerCount; // +0x14
};

// ?getPlayersWithRelationship@PlayerList@@QAEIHI_N@Z present-unmatched
PlayerMaskType PlayerList::getPlayersWithRelationship(Int playerIndex, UnsignedInt allowedRelationships, bool reverse)
{
	PlayerMaskType retVal = 0;

	if (allowedRelationships == 0)
		return retVal;

	Player *srcPlayer = getNthPlayer(playerIndex);
	if (!srcPlayer)
		return retVal;

	if (allowedRelationships & ALLOW_SAME_PLAYER)
		retVal |= srcPlayer->getPlayerMask();

	for (Int i = 0; i < m_playerCount; ++i)
	{
		Player *player = getNthPlayer(i);
		if (!player || player == srcPlayer)
			continue;

		Relationship relationship;
		if (!reverse)
			relationship = srcPlayer->getRelationship(player->getDefaultTeam());
		else
			relationship = player->getRelationship(srcPlayer->getDefaultTeam());

		switch (relationship)
		{
		default:
			if (allowedRelationships == 0x0f)
				retVal |= player->getPlayerMask();
			break;
		case ALLIES:
			if (allowedRelationships & ALLOW_ALLIES)
				retVal |= player->getPlayerMask();
			break;
		case NEUTRAL:
			if (allowedRelationships & ALLOW_NEUTRAL)
				retVal |= player->getPlayerMask();
			break;
		case ENEMIES:
			if (allowedRelationships & ALLOW_ENEMIES)
				retVal |= player->getPlayerMask();
			break;
		}
	}

	return retVal;
}
