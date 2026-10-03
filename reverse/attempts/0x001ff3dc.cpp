// ?getSciencePurchaseCost@ScienceStore@@QBEHW4ScienceType@@@Z
// partial score=0.97 date=2026-10-03
// cl: /O1 /DNDEBUG /MD /EHsc
enum ScienceType { SCIENCE_INVALID = -1 };
class ScienceInfo { char m_pad[0x28]; public: int m_sciencePurchasePointCost; int m_sciencePurchasePointCostMP; };
class GameLogic { char m_pad[0x110]; public: int m_gameMode; bool isInMultiplayerGame(); };
class RecorderClass { public: bool isMultiplayer(); };
#define TheGameLogic (*(GameLogic **)0x00DFE78C)
#define TheRecorder (*(RecorderClass **)0x00E02290)
class ScienceStore { const ScienceInfo *findScienceInfo(ScienceType st) const; public: int getSciencePurchaseCost(ScienceType st) const; };
int ScienceStore::getSciencePurchaseCost(ScienceType st) const
{
	const ScienceInfo *si = findScienceInfo(st);
	if (si)
	{
		GameLogic *game = TheGameLogic;
		if (game->isInMultiplayerGame() || game->m_gameMode == 2 ||
		    (game->m_gameMode == 3 && TheRecorder && TheRecorder->isMultiplayer()))
			return si->m_sciencePurchasePointCostMP;
		return si->m_sciencePurchasePointCost;
	}
	return 0;
}
