// cl: /Ireference/shims/bfme2_ascii /Ireference/shims/bfmealloc /O1 /EHsc /arch:SSE /DNDEBUG /MD /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_CRTIMP= /D_STLP_NO_EXCEPTIONS
// stlport

// Open-BFME: GameSpyInfo methods in PeerDefs.cpp (reconciled from Zero Hour's
// GameNetwork/GameSpy/PeerDefs.cpp and PeerDefsImplementation.h).

#include <utility>
#undef _STLP_DEFAULT_CONSTRUCTED
#define _STLP_DEFAULT_CONSTRUCTED(T) T()
#define _BFME_RETAIL_TREE_INSERT_LAYOUT
#include <map>
#include <set>

typedef int Int;
typedef unsigned int UnsignedInt;
typedef bool Bool;

template <typename T> struct BfmeStringData
{
	int refCount;
	unsigned short length;
	unsigned short capacity;
	T text[1];
};

#include "ascii_string.h"
#include "unicode_string.h"

namespace _STL
{
template <> struct less<AsciiString>
{
	bool operator()(const AsciiString &left, const AsciiString &right) const
	{
		return left < right;
	}
};
}

class GameWindow;
class GameSpyGroupRoom;
class BuddyInfo {};

class GameSpyStagingRoom
{
public:
	virtual ~GameSpyStagingRoom();
	static void operator delete(void *p) { ::operator delete(p); }
};

class PlayerInfo
{
public:
	AsciiString m_name;
	AsciiString m_locale;
	AsciiString m_clan;
	Int m_wins;
	Int m_losses;
	Int m_profileID;
	Int m_flags;
	Int m_rankPoints;
	Int m_side;
	Int m_preorder;
	Int m_dc;
	Int m_desync;
	Int m_pad;
	~PlayerInfo();
};

struct AsciiComparator
{
	bool operator()(AsciiString s1, AsciiString s2) const;
};

typedef _STL::set<AsciiString> IgnoreList;
typedef _STL::map<Int, AsciiString> SavedIgnoreMap;
typedef _STL::map<Int, GameSpyGroupRoom> GroupRoomMap;
typedef _STL::map<Int, GameSpyStagingRoom *> StagingRoomMap;
typedef _STL::map<Int, BuddyInfo> BuddyInfoMap;
typedef _STL::map<AsciiString, PlayerInfo, AsciiComparator> PlayerInfoMap;
typedef _STL::map<AsciiString, AsciiString> PreferenceMap;

class UserPreferences : public PreferenceMap
{
public:
	UserPreferences();
	virtual ~UserPreferences();
	virtual Bool load(const AsciiString &fname);
	virtual Bool load(const UnicodeString &fname);
	virtual Bool write(void);
	void rva003B2322(const AsciiString &val, Int num, Bool flag);
protected:
	UnicodeString m_filename;
};

class IgnorePreferences : public UserPreferences
{
public:
	IgnorePreferences();
	virtual ~IgnorePreferences();
	SavedIgnoreMap getIgnores(void);
};

extern Int GetAdditionalDisconnectsFromUserFile(Int playerID);

class GameSpyInfo
{
public:
	virtual void setLocalName(AsciiString name);
	virtual AsciiString getLocalName(void);
	virtual AsciiString getLocalEmail(void);
	virtual void setLocalEmail(AsciiString email);
	virtual AsciiString getLocalPassword(void);
	virtual void setLocalPassword(AsciiString passwd);
	virtual void setLocalBaseName(AsciiString name);
	virtual AsciiString getLocalBaseName(void);

	virtual void setCurrentGroupRoom(Int groupID);
	virtual void playerLeftGroupRoom(AsciiString nick);

	virtual GameSpyStagingRoom *findStagingRoomByID(Int id);
	virtual Bool rva00383207(GameSpyStagingRoom *room);
	virtual void clearStagingRoomList(void);
	virtual GameSpyStagingRoom *getCurrentStagingRoom(void);
	virtual Bool hasStagingRoomListChanged(void);
	virtual Bool rva00381DC4(void);

	virtual Bool isBuddy(Int id);

	virtual void setMOTD(const AsciiString &motd);

	virtual void addToSavedIgnoreList(Int profileID, AsciiString nick);
	virtual void removeFromSavedIgnoreList(Int profileID);
	virtual Bool isSavedIgnored(Int profileID);
	virtual SavedIgnoreMap returnSavedIgnoreList(void);
	virtual void loadSavedIgnoreList(void);

	virtual IgnoreList returnIgnoreList(void);
	virtual void addToIgnoreList(AsciiString nick);
	virtual void removeFromIgnoreList(AsciiString nick);
	virtual Bool isIgnored(AsciiString nick);

	virtual void setLocalIPs(UnsignedInt internalIP, UnsignedInt externalIP);

	virtual Bool isDisconnectedAfterGameStart(Int *reason) const;
	virtual void markAsDisconnectedAfterGameStart(Int reason);

	virtual Bool didPlayerPreorder(Int profileID) const;
	virtual void markPlayerAsPreorder(Int profileID);

	virtual void readAdditionalDisconnects(void);

private:
	Bool m_sawFullGameList;				// +0x04
	Bool m_isDisconAfterGameStart;		// +0x05
	unsigned char m_pad0006[2];			// +0x06..+0x07
	Int m_disconReason;					// +0x08
	AsciiString m_rawMotd;				// +0x0C
	AsciiString m_rawConfig;			// +0x10
	AsciiString m_pingString;			// +0x14
	GroupRoomMap m_groupRooms;			// +0x18..+0x23
	StagingRoomMap m_stagingRooms;		// +0x24..+0x2F
	Bool m_stagingRoomsDirty;			// +0x30
	unsigned char m_pad0031[3];			// +0x31..+0x33
	BuddyInfoMap m_buddyMap;			// +0x34..+0x3F
	BuddyInfoMap m_buddyRequestMap;		// +0x40..+0x4B
	PlayerInfoMap m_playerInfoMap;		// +0x4C..+0x57
	void *m_buddyMessages;				// +0x58
	Int m_currentGroupRoomID;			// +0x5C
	AsciiString m_unk0060;				// +0x60
	Int m_unk0064;						// +0x64
	Int m_unk0068;						// +0x68
	Bool m_gotGroupRoomList;			// +0x6C
	unsigned char m_pad006D[3];			// +0x6D..+0x6F
	AsciiString m_localName;			// +0x70
	Int m_localProfileID;				// +0x74
	AsciiString m_localPasswd;			// +0x78
	AsciiString m_localEmail;			// +0x7C
	AsciiString m_localBaseName;		// +0x80
	unsigned char m_cachedLocalPlayerStats[0x548]; // +0x84..+0x5CB
	Bool m_disallowAsainText;			// +0x5CC
	Bool m_disallowNonAsianText;		// +0x5CD
	unsigned char m_pad05CE[2];			// +0x5CE..+0x5CF
	UnsignedInt m_internalIP;			// +0x5D0
	UnsignedInt m_externalIP;			// +0x5D4
	Int m_maxMessagesPerUpdate;			// +0x5D8
	Int m_joinedStagingRoom;			// +0x5DC
	Bool m_isHosting;					// +0x5E0
	unsigned char m_pad05E1[3];			// +0x5E1..+0x5E3
	unsigned char m_localStagingRoom[0x1020]; // +0x5E4..+0x1603
	Int m_localStagingRoomID;			// +0x1604
	IgnoreList m_ignoreList;			// +0x1608..+0x1613
	SavedIgnoreMap m_savedIgnoreMap;	// +0x1614..+0x161F
	_STL::set<GameWindow *> m_textWindows; // +0x1620..+0x162B
	_STL::set<Int> m_preorderPlayers;	// +0x162C..+0x1637
	Int m_additionalDisconnects;		// +0x1638
};

// ?didPlayerPreorder@GameSpyInfo@@UBE_NH@Z @0x00383580 32B
Bool GameSpyInfo::didPlayerPreorder(Int profileID) const
{
	_STL::set<Int>::const_iterator it = m_preorderPlayers.find(profileID);
	return (it != m_preorderPlayers.end());
}

// ?markPlayerAsPreorder@GameSpyInfo@@UAEXH@Z @0x00383E80 28B
void GameSpyInfo::markPlayerAsPreorder(Int profileID)
{
	m_preorderPlayers.insert(profileID);
}

// ?setLocalIPs@GameSpyInfo@@UAEXII@Z @0x00381D9E 23B
void GameSpyInfo::setLocalIPs(UnsignedInt internalIP, UnsignedInt externalIP)
{
	m_internalIP = internalIP;
	m_externalIP = externalIP;
}

// ?rva00381DC4@GameSpyInfo@@UAE_NXZ @0x00381DC4 22B
Bool GameSpyInfo::rva00381DC4(void)
{
	return m_isHosting || m_joinedStagingRoom;
}

// ?hasStagingRoomListChanged@GameSpyInfo@@UAE_NXZ @0x00381DDA 8B
Bool GameSpyInfo::hasStagingRoomListChanged(void)
{
	Bool val = m_stagingRoomsDirty;
	m_stagingRoomsDirty = false;
	return val;
}

// ?setMOTD@GameSpyInfo@@UAEXABVAsciiString@@@Z @0x0038200D 8B
void GameSpyInfo::setMOTD(const AsciiString &motd)
{
	m_rawMotd = motd;
}

// ?addToIgnoreList@GameSpyInfo@@UAEXVAsciiString@@@Z @0x003846A8 61B
void GameSpyInfo::addToIgnoreList(AsciiString nick)
{
	m_ignoreList.insert(nick);
}

// ?removeFromIgnoreList@GameSpyInfo@@UAEXVAsciiString@@@Z @0x003871BF 55B
void GameSpyInfo::removeFromIgnoreList(AsciiString nick)
{
	m_ignoreList.erase(nick);
}

// ?isIgnored@GameSpyInfo@@UAE_NVAsciiString@@@Z @0x003846E5 41B
Bool GameSpyInfo::isIgnored(AsciiString nick)
{
	return m_ignoreList.find(nick) != m_ignoreList.end();
}

// ?returnIgnoreList@GameSpyInfo@@UAE?AV?$set@VAsciiString@@U?$less@VAsciiString@@@_STL@@V?$allocator@VAsciiString@@@3@@_STL@@XZ @0x00385AFE 30B
IgnoreList GameSpyInfo::returnIgnoreList(void)
{
	return m_ignoreList;
}

// ?isDisconnectedAfterGameStart@GameSpyInfo@@UBE_NPAH@Z @0x00386104 19B
Bool GameSpyInfo::isDisconnectedAfterGameStart(Int *reason) const
{
	if (reason != 0)
		*reason = m_disconReason;
	return m_isDisconAfterGameStart;
}

// ?markAsDisconnectedAfterGameStart@GameSpyInfo@@UAEXH@Z @0x00386117 14B
void GameSpyInfo::markAsDisconnectedAfterGameStart(Int reason)
{
	m_isDisconAfterGameStart = true;
	m_disconReason = reason;
}

// ?setLocalName@GameSpyInfo@@UAEXVAsciiString@@@Z @0x00386188 52B
void GameSpyInfo::setLocalName(AsciiString name)
{
	m_localName = name;
}

// ?getLocalName@GameSpyInfo@@UAE?AVAsciiString@@XZ @0x003861BC 27B
AsciiString GameSpyInfo::getLocalName(void)
{
	return m_localName;
}

// ?getLocalEmail@GameSpyInfo@@UAE?AVAsciiString@@XZ @0x003861D7 27B
AsciiString GameSpyInfo::getLocalEmail(void)
{
	return m_localEmail;
}

// ?setLocalEmail@GameSpyInfo@@UAEXVAsciiString@@@Z @0x003861F2 52B
void GameSpyInfo::setLocalEmail(AsciiString email)
{
	m_localEmail = email;
}

// ?getLocalPassword@GameSpyInfo@@UAE?AVAsciiString@@XZ @0x00386226 27B
AsciiString GameSpyInfo::getLocalPassword(void)
{
	return m_localPasswd;
}

// ?setLocalPassword@GameSpyInfo@@UAEXVAsciiString@@@Z @0x00386241 52B
void GameSpyInfo::setLocalPassword(AsciiString passwd)
{
	m_localPasswd = passwd;
}

// ?setLocalBaseName@GameSpyInfo@@UAEXVAsciiString@@@Z @0x00386275 55B
void GameSpyInfo::setLocalBaseName(AsciiString name)
{
	m_localBaseName = name;
}

// ?getLocalBaseName@GameSpyInfo@@UAE?AVAsciiString@@XZ @0x003862AC 30B
AsciiString GameSpyInfo::getLocalBaseName(void)
{
	return m_localBaseName;
}

// ?readAdditionalDisconnects@GameSpyInfo@@UAEXXZ @0x003853C6 20B
void GameSpyInfo::readAdditionalDisconnects(void)
{
	m_additionalDisconnects = GetAdditionalDisconnectsFromUserFile(m_localProfileID);
}

// ?isBuddy@GameSpyInfo@@UAE_NH@Z @0x003835D7 29B
Bool GameSpyInfo::isBuddy(Int id)
{
	return m_buddyMap.find(id) != m_buddyMap.end();
}

// ?findStagingRoomByID@GameSpyInfo@@UAEPAVGameSpyStagingRoom@@H@Z @0x00383846 31B
GameSpyStagingRoom *GameSpyInfo::findStagingRoomByID(Int id)
{
	StagingRoomMap::iterator it = m_stagingRooms.find(id);
	if (it != m_stagingRooms.end())
		return it->second;
	return 0;
}

// ?getCurrentStagingRoom@GameSpyInfo@@UAEPAVGameSpyStagingRoom@@XZ @0x003835A0 48B
GameSpyStagingRoom *GameSpyInfo::getCurrentStagingRoom(void)
{
	if (m_isHosting || m_joinedStagingRoom)
		return reinterpret_cast<GameSpyStagingRoom *>(&m_localStagingRoom);

	StagingRoomMap::iterator it = m_stagingRooms.find(m_localStagingRoomID);
	if (it != m_stagingRooms.end())
		return it->second;
	return 0;
}

// ?clearStagingRoomList@GameSpyInfo@@UAEXXZ @0x00382E2F 68B
void GameSpyInfo::clearStagingRoomList(void)
{
	Int numRoomsRemoved = 0;
	m_sawFullGameList = false;
	m_stagingRoomsDirty = false;

	StagingRoomMap::iterator it = m_stagingRooms.begin();
	while (it != m_stagingRooms.end())
	{
		++numRoomsRemoved;

		::delete it->second;
		m_stagingRooms.erase(it);
		it = m_stagingRooms.begin();
	}
	if (numRoomsRemoved > 0)
	{
	}
}

// ?setCurrentGroupRoom@GameSpyInfo@@UAEXH@Z @0x003862DB 18B
void GameSpyInfo::setCurrentGroupRoom(Int groupID)
{
	m_currentGroupRoomID = groupID;
	m_playerInfoMap.clear();
}

// ?playerLeftGroupRoom@GameSpyInfo@@UAEXVAsciiString@@@Z @0x00384660 72B
void GameSpyInfo::playerLeftGroupRoom(AsciiString nick)
{
	PlayerInfoMap::iterator it = m_playerInfoMap.find(nick);
	if (it != m_playerInfoMap.end())
	{
		m_playerInfoMap.erase(it);
	}
}

// ?addToSavedIgnoreList@GameSpyInfo@@UAEXHVAsciiString@@@Z @0x00385E2A 118B
void GameSpyInfo::addToSavedIgnoreList(Int profileID, AsciiString nick)
{
	m_savedIgnoreMap[profileID] = nick;
	IgnorePreferences pref;
	pref.rva003B2322(nick, profileID, true);
	pref.write();
}

// ?removeFromSavedIgnoreList@GameSpyInfo@@UAEXH@Z @0x00385B1C 92B
void GameSpyInfo::removeFromSavedIgnoreList(Int profileID)
{
	m_savedIgnoreMap.erase(profileID);
	IgnorePreferences pref;
	pref.rva003B2322(AsciiString::TheEmptyString, profileID, false);
	pref.write();
}

// ?isSavedIgnored@GameSpyInfo@@UAE_NH@Z @0x003839B9 32B
Bool GameSpyInfo::isSavedIgnored(Int profileID)
{
	return m_savedIgnoreMap.find(profileID) != m_savedIgnoreMap.end();
}
