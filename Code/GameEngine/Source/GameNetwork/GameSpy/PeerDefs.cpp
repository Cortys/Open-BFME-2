// cl: /Ireference/shims/bfme2_ascii /O1 /EHsc /arch:SSE /DNDEBUG /MD /D_STLP_USE_STATIC_LIB
// stlport

// Open-BFME: GameSpyInfo methods in PeerDefs.cpp (reconciled from Zero Hour's
// GameNetwork/GameSpy/PeerDefs.cpp and PeerDefsImplementation.h).

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
class GameSpyStagingRoom;
class GameSpyGroupRoom;
class BuddyInfo;
class PlayerInfo;

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

	virtual Bool hasStagingRoomListChanged(void);
	virtual Bool rva00381DC4(void);

	virtual void setMOTD(const AsciiString &motd);

	virtual IgnoreList returnIgnoreList(void);
	virtual void addToIgnoreList(AsciiString nick);
	virtual void removeFromIgnoreList(AsciiString nick);
	virtual Bool isIgnored(AsciiString nick);

	virtual void setLocalIPs(UnsignedInt internalIP, UnsignedInt externalIP);

	virtual Bool isDisconnectedAfterGameStart(Int *reason) const;
	virtual void markAsDisconnectedAfterGameStart(Int reason);

	virtual Bool didPlayerPreorder(Int profileID) const;
	virtual void markPlayerAsPreorder(Int profileID);

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

