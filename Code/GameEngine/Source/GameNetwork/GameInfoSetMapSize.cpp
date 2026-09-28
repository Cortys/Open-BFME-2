// cl: /O1 /DNDEBUG /MD /EHsc
// stlport
// ?setMapSize@GameInfo@@QAEXI@Z @0x00400F5A (187B):
// GameInfo::setMapSize. BFME1 GameInfo.cpp donor verbatim (DEBUG_LOG compiled
// out) with the same BFME2 deltas as the setMapCRC twin 0x00400E9F: SLOT_PLAYER
// 6 via inlined isHuman plus direct m_hasMap at +0x09, MapMetaData CRC at +0x2C
// (node+0x40) compared against m_mapCRC at +0x44 (donor copy-paste, also in
// retail), m_map at +0x40, stored field m_mapSize at +0x48, m_inGame at +0x10,
// getLocalSlotNum at vtable +0x34 slot 13. TheMapCache at 0x00DFF12C,
// AsciiString copy/toLower/release via 0x365F0/0x36A70/0x36410, getSlot rowed
// 0x3FF29F. Twin of setMapCRC differing only by stored offset. No new pins.
#include <map>

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

template <typename T> class StringBase
{
	friend class AsciiString;
	StringBase(const T *text);
	StringBase(const StringBase<T> &other);
	void releaseBuffer();
public:
	StringBase() : m_data(0) {}
	~StringBase() { releaseBuffer(); }
	void toLower();
protected:
	BfmeStringData<T> *m_data;
};

class AsciiString : public StringBase<char>
{
public:
	AsciiString() {}
	AsciiString(const AsciiString &other) : StringBase<char>(other) {}
	~AsciiString() {}
	void toLower() { StringBase<char>::toLower(); }
};

bool operator<(const AsciiString &left, const AsciiString &right);

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

class MapMetaData
{
public:
	char m_pad[0x2C];
	UnsignedInt m_CRC;
};

class MapCache : public _STL::map<AsciiString, MapMetaData>
{
};

extern MapCache *TheMapCache;

class GameSlot
{
public:
	Bool isHuman() const { return m_state == 6; }
	void *m_vtable;
	Int m_state;
	Bool m_isAccepted;
	Bool m_hasMap;
};

class GameInfo
{
public:
	virtual void slot00() = 0;
	virtual void slot04() = 0;
	virtual void slot08() = 0;
	virtual void slot0c() = 0;
	virtual void slot10() = 0;
	virtual void slot14() = 0;
	virtual void slot18() = 0;
	virtual void slot1c() = 0;
	virtual void slot20() = 0;
	virtual void slot24() = 0;
	virtual void slot28() = 0;
	virtual void slot2c() = 0;
	virtual void slot30() = 0;
	virtual Int getLocalSlotNum() const = 0;
	GameSlot *getSlot(Int slotNum);
	void setMapSize(UnsignedInt mapSize);
private:
	char m_pad0C[0x0C];
	Bool m_inGame;
	char m_pad11[0x2F];
	AsciiString m_mapName;
	UnsignedInt m_mapCRC;
	UnsignedInt m_mapSize;
};

void GameInfo::setMapSize(UnsignedInt mapSize)
{
	m_mapSize = mapSize;
	if (!TheMapCache)
		return;
	if (m_inGame && getLocalSlotNum() >= 0) {
		AsciiString lowerMap = m_mapName;
		lowerMap.toLower();
		_STL::map<AsciiString, MapMetaData>::iterator it = TheMapCache->find(lowerMap);
		if (it == TheMapCache->end()) {
			GameSlot *slot = getSlot(getLocalSlotNum());
			if (slot->isHuman())
				slot->m_hasMap = false;
		} else if (m_mapCRC != it->second.m_CRC) {
			GameSlot *slot = getSlot(getLocalSlotNum());
			if (slot->isHuman())
				slot->m_hasMap = false;
		} else {
			GameSlot *slot = getSlot(getLocalSlotNum());
			if (slot->isHuman())
				slot->m_hasMap = true;
		}
	}
}
