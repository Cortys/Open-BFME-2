// ?getSciencePurchaseCost@ScienceStore@@QBEHW4ScienceType@@@Z
// partial score=0.93 date=2026-09-28
// ?getSciencePurchaseCost@ScienceStore@@QBEHW4ScienceType@@@Z
// partial score=0.93 date=2026-09-28
// cl: /O1 /DNDEBUG /MD /EHsc

// ?getSciencePurchaseCost@ScienceStore@@QBEHW4ScienceType@@@Z @0x001FF3DC
// (86B): ScienceStore::getSciencePurchaseCost, BFME1 Science.cpp shape with
// BFME2 multiplayer refactor: TheGameLogic->isInMultiplayerGame (row 0x42235)
// covers GAME_LAN(1)/GAME_INTERNET(5), mode word at +0x110 covers
// GAME_SKIRMISH(2) and GAME_REPLAY(3)+TheRecorder->isMultiplayer (row
// 0x37B18C). Costs at +0x28/+0x2c, grantable at +0x30. Callers 0x1FF4D3,
// 0x2AD826 compare the cost against purchase points.

enum ScienceType
{
	SCIENCE_INVALID = -1
};

class ScienceInfo
{
	char m_pad[0x28];
public:
	int m_sciencePurchasePointCost;
	int m_sciencePurchasePointCostMP;
};

class GameLogic
{
	char m_pad[0x110];
public:
	int m_gameMode;
	bool isInMultiplayerGame();
};

class RecorderClass
{
public:
	bool isMultiplayer();
};

#define TheGameLogic (*(GameLogic **)0x00DFE78C)
#define TheRecorder (*(RecorderClass **)0x00E02290)

class ScienceStore
{
	const ScienceInfo *findScienceInfo(ScienceType st) const;
public:
	int getSciencePurchaseCost(ScienceType st) const;
};

// ?getSciencePurchaseCost@ScienceStore@@QBEHW4ScienceType@@@Z present-unmatched
int ScienceStore::getSciencePurchaseCost(ScienceType st) const
{
	const ScienceInfo *si = findScienceInfo(st);
	GameLogic *game = TheGameLogic;
	if (si)
	{
		if (!game->isInMultiplayerGame())
		{
			int mode = game->m_gameMode;
			if (mode != 2)
			{
				if (mode != 3)
					return si->m_sciencePurchasePointCost;
				RecorderClass *rec = TheRecorder;
				if (!rec || !rec->isMultiplayer())
					return si->m_sciencePurchasePointCost;
			}
		}
		return si->m_sciencePurchasePointCostMP;
	}
	return 0;
}
