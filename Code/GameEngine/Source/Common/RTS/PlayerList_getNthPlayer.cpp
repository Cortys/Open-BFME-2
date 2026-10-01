// cl: /O1 /DNDEBUG /MD /EHsc
//
// ?getNthPlayer@PlayerList@@QAEPAVPlayer@@H@Z,
// retail 0x002A7A29, 22 bytes,
// ?getPlayerFromMask@PlayerList@@QAEPAVPlayer@@H@Z,
// retail 0x002A7B91, 56 bytes, and
// ?getEachPlayerFromMask@PlayerList@@QAEPAVPlayer@@AAH@Z,
// retail 0x002A7BC9, 66 bytes.
//
// Battle for Middle-earth reference
// (reference/open-bfme-1/Code/GameEngine/Source/Common/RTS/PlayerList.cpp,
// PlayerList::getNthPlayer): bounds-checked indexed accessor over the player
// array. Battle for Middle-earth 2 caps the index at 20 (retail cmp eax,0x14;
// the five 0x2A7AB6-family loop bodies and the 0x2A79A9 init body all iterate
// the same 0x14 count, and the count lives at +0x14 over the inline player
// pointer array at +0x18 per the landed findPlayerWithNameKey row), where the
// reference uses 32. Leaf, no pins.
//
// getPlayerFromMask: BFME1 reference PlayerList::getPlayerFromMask, zero
// guard plus getNthPlayer loop over 20 slots comparing getPlayerMask.
//
// getEachPlayerFromMask: ZH donor GeneralsMD PlayerList.cpp. Target evidence:
// thiscall ret 4 taking the mask by reference; walks getNthPlayer over the 20
// slots, tests 1 << Player +0x54 (getPlayerMask) against the mask, clears
// that bit and returns the player, else zeroes the mask and returns null.
// Both loops keep a value in edx across the getNthPlayer call (the loop index
// in getPlayerFromMask, the mask pointer here), which cl only does when the
// callee was compiled earlier in the same TU, so the three bodies share this
// file as they shared retail's PlayerList.cpp.

typedef int Int;

typedef int PlayerMaskType;

#define NULL 0
#define MAX_PLAYER_COUNT 20
#define BitTest(x, i) (((x) & (i)) != 0)

class Player
{
public:
	PlayerMaskType getPlayerMask() const { return 1 << m_playerIndex; }

private:
	unsigned char m_pad[0x54];
	Int m_playerIndex; // +0x54
};

class PlayerList
{
public:
	Player *getNthPlayer(Int i);
	Player *getPlayerFromMask(PlayerMaskType mask);
	Player *getEachPlayerFromMask(PlayerMaskType &maskToAdjust);

private:
	unsigned char m_pad[0x14];
	Int m_playerCount; // +0x14
	Player *m_players[1]; // +0x18
};

// ?getNthPlayer@PlayerList@@QAEPAVPlayer@@H@Z
Player *PlayerList::getNthPlayer(Int i)
{
	if (i < 0 || i >= 20)
	{
		return NULL;
	}
	return m_players[i];
}

// ?getPlayerFromMask@PlayerList@@QAEPAVPlayer@@H@Z
Player *PlayerList::getPlayerFromMask(PlayerMaskType mask)
{
	if (mask == 0)
		return NULL;

	Player *player = NULL;
	Int i;

	for (i = 0; i < MAX_PLAYER_COUNT; i++)
	{
		player = getNthPlayer(i);
		if (player && player->getPlayerMask() == mask)
			return player;
	}
	return NULL;
}

// ?getEachPlayerFromMask@PlayerList@@QAEPAVPlayer@@AAH@Z
Player *PlayerList::getEachPlayerFromMask(PlayerMaskType &maskToAdjust)
{
	Player *player = NULL;
	Int i;

	for (i = 0; i < MAX_PLAYER_COUNT; i++)
	{
		player = getNthPlayer(i);
		if (player && BitTest(player->getPlayerMask(), maskToAdjust))
		{
			maskToAdjust &= (~player->getPlayerMask());
			return player;
		}
	}

	maskToAdjust = 0;
	return NULL;
}
