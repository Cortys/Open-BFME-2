// ?getEachPlayerFromMask@PlayerList@@QAEPAVPlayer@@AAH@Z
// partial score=0.93 date=2026-09-27
// ?getEachPlayerFromMask@PlayerList@@QAEPAVPlayer@@AAH@Z
// partial score=0.93 date=2026-09-27
// cl: /O1 /DNDEBUG /MD /EHsc
//
// ?getEachPlayerFromMask@PlayerList@@QAEPAVPlayer@@AAH@Z,
// retail 0x002A7BC9, 66 bytes. Dedicated TU.
//
// Battle for Middle-earth reference
// (reference/open-bfme-1/Code/GameEngine/Source/Common/RTS/PlayerList.cpp,
// PlayerList::getEachPlayerFromMask): getNthPlayer loop with inlined
// 1-shift-plus-m-playerIndex-at-0x54 tested against the mask reference then
// cleared. Battle for Middle-earth 2 caps the loop at 20 (retail cmp esi
// 0x14) where the reference uses 32. Leaf except for the rowed getNthPlayer
// at 0x002A7A29.

typedef int Int;

#define NULL 0

class Player
{
public:
	Int getPlayerMask() const { return 1 << m_playerIndex; }

private:
	unsigned char m_pad[0x54];
	Int m_playerIndex; // +0x54
};

class PlayerList
{
public:
	Player *getNthPlayer(Int i);
	Player *getEachPlayerFromMask(Int &maskToAdjust);
};

// ?getEachPlayerFromMask@PlayerList@@QAEPAVPlayer@@AAH@Z present-unmatched
Player *PlayerList::getEachPlayerFromMask(Int &maskToAdjust)
{
	Player *player = NULL;
	Int i;

	for (i = 0; i < 20; i++)
	{
		player = getNthPlayer(i);
		if (player && (player->getPlayerMask() & maskToAdjust))
		{
			maskToAdjust &= (~player->getPlayerMask());
			return player;
		}
	}

	maskToAdjust = 0;
	return NULL;
}
