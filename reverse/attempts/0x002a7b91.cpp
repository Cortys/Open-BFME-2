// ?getPlayerFromMask@PlayerList@@QAEPAVPlayer@@H@Z
// partial score=0.93 date=2026-09-27
// ?getPlayerFromMask@PlayerList@@QAEPAVPlayer@@H@Z
// partial score=0.93 date=2026-09-27
// cl: /O1 /DNDEBUG /MD /EHsc
//
// ?getPlayerFromMask@PlayerList@@QAEPAVPlayer@@H@Z,
// retail 0x002A7B91, 56 bytes. Dedicated TU.
//
// Battle for Middle-earth reference
// (reference/open-bfme-1/Code/GameEngine/Source/Common/RTS/PlayerList.cpp,
// PlayerList::getPlayerFromMask): zero-guard plus getNthPlayer loop with
// inlined 1-shift-plus-m-playerIndex-at-0x54. Battle for Middle-earth 2 caps
// the loop at 20 (retail cmp edx 0x14) where the reference uses 32. Leaf
// except for the rowed getNthPlayer at 0x002A7A29.

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
	Player *getPlayerFromMask(Int mask);
};

// ?getPlayerFromMask@PlayerList@@QAEPAVPlayer@@H@Z present-unmatched
Player *PlayerList::getPlayerFromMask(Int mask)
{
	if (mask == 0)
		return NULL;

	Player *player = NULL;
	Int i;

	for (i = 0; i < 20; i++)
	{
		player = getNthPlayer(i);
		if (player && player->getPlayerMask() == mask)
			return player;
	}
	return NULL;
}
