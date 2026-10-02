// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD /EHsc
//
// ?rva00357475@ScriptEngine@@QAEHABVAsciiString@@PA_N@Z, retail 0x00357475
// (476B). Player-name to player-mask resolution behind the Parameter
// resolver 0x00357B82. Zero Hour's ScriptEngine::getPlayerFromAsciiString
// grown into BFME's mask selectors: "<This Player's Enemies/Allies...>" and
// "<Local Player's ...>" ask the player list for every player in a
// relationship (0x002A7C70, pinned; 4 enemies, 3 allies incl self, 2 allies),
// "<This Player>", "<This Player's Enemy>" (0x00356F6E, ZH
// getSkirmishEnemyPlayer's slot) and "<Local Player>" give one bit,
// "<All Players>" every bit (rowed 0x002A7D30); anything else is looked up by
// name key and reported when unknown. *matchedSpecialName is cleared only on
// that last path, so callers cache only real player names. BFME 1 names the
// function getPlayerMaskFromAsciiString; the row stays address-derived.

#include "ascii_string.h"

typedef bool Bool;

enum NameKeyType { NAMEKEY_INVALID = 0 };

class NameKeyGenerator
{
public:
	NameKeyType nameToKey(const AsciiString &name);
};
extern NameKeyGenerator *TheNameKeyGenerator;

class Player
{
public:
	int getPlayerIndex() const { return m_playerIndex; }
	int getPlayerMask() const { return 1 << m_playerIndex; }

private:
	unsigned char m_pad00[0x54];
	int m_playerIndex; // +0x54
};

class PlayerList
{
public:
	Player *getLocalPlayer() { return m_local; }
	Player *findPlayerWithNameKey(NameKeyType key);
	int rva002A7C70(int playerIndex, int relationship, int flags);
	int rva002A7D30();

private:
	unsigned char m_pad00[0x10];
	Player *m_local; // +0x10
};
extern PlayerList *ThePlayerList;

class ScriptEngine
{
public:
	Player *getCurrentPlayer();
	Player *rva00356F6E();
	void AppendDebugMessage(const AsciiString &strToAdd, Bool forcePause);
	int rva00357475(const AsciiString &name, Bool *matchedSpecialName);
};
extern ScriptEngine *TheScriptEngine;

int ScriptEngine::rva00357475(const AsciiString &name, Bool *matchedSpecialName)
{
	if (matchedSpecialName)
		*matchedSpecialName = true;
	if (!TheScriptEngine->getCurrentPlayer())
		return 0;

	int mask = 0;
	int thisIndex = TheScriptEngine->getCurrentPlayer()->getPlayerIndex();
	int localIndex = ThePlayerList->getLocalPlayer()->getPlayerIndex();
	if (name.compare("<This Player's Enemies>") == 0)
		mask = ThePlayerList->rva002A7C70(thisIndex, 4, 0);
	else if (name.compare("<This Player's Allies incl Self>") == 0)
		mask = ThePlayerList->rva002A7C70(thisIndex, 3, 0);
	else if (name.compare("<This Player's Allies>") == 0)
		mask = ThePlayerList->rva002A7C70(thisIndex, 2, 0);
	else if (name.compare("<This Player>") == 0)
		mask = getCurrentPlayer()->getPlayerMask();
	else if (name.compare("<This Player's Enemy>") == 0)
		mask = rva00356F6E()->getPlayerMask();
	else if (name.compare("<Local Player>") == 0)
		mask = ThePlayerList->getLocalPlayer()->getPlayerMask();
	else if (name.compare("<Local Player's Enemies>") == 0)
		mask = ThePlayerList->rva002A7C70(localIndex, 4, 0);
	else if (name.compare("<Local Player's Allies incl Self>") == 0)
		mask = ThePlayerList->rva002A7C70(localIndex, 3, 0);
	else if (name.compare("<Local Player's Allies>") == 0)
		mask = ThePlayerList->rva002A7C70(localIndex, 2, 0);
	else if (name.compare("<All Players>") == 0)
		mask = ThePlayerList->rva002A7D30();
	else {
		if (matchedSpecialName)
			*matchedSpecialName = false;
		Player *player = ThePlayerList->findPlayerWithNameKey(TheNameKeyGenerator->nameToKey(name));
		if (player)
			mask = player->getPlayerMask();
		else {
			AsciiString msg;
			msg.format("***Invalid Player name: \"%s\"***", name.str());
			AppendDebugMessage(msg, false);
		}
	}
	return mask;
}
