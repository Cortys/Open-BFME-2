// cl: /O1 /Og /MD /EHsc
// ?Rva004161F1Notify@@YAXVAsciiString@@VUnicodeString@@@Z @0x004161F1 198B
// Buddy multiple-online notification: TheGameText fetch Buddy string plus set
// via 0x00037150; releaseBuffer 0x00036E70; UnicodeString format via 0x006CB660;
// timeGetTime IAT; globals 0x00A04904 0x00A0308C 0x00A03090 0x00A03098
// 0x00A03094; chat login via rowed 0x00517048; caller 0x004163E1.
typedef unsigned short wchar_t;

extern "C" __declspec(dllimport) unsigned long __stdcall timeGetTime(void);

template <typename T> class StringBase
{
	friend class AsciiString;
	friend class UnicodeString;
	StringBase() : m_data(0) {}
	StringBase(const StringBase<T> &that);
	StringBase(const T *s);
	void releaseBuffer();
public:
	void set(const StringBase<T> &other);
	struct Header
	{
		int ref_count;
		unsigned short length;
		unsigned short capacity;
		T data[1];
	};
	Header *m_data;
};

class AsciiString
{
public:
	AsciiString(const AsciiString &that) : m_data(that.m_data) {}
	~AsciiString() { m_data.releaseBuffer(); }
	StringBase<char> m_data;
};

class UnicodeString
{
public:
	UnicodeString() {}
	UnicodeString(const UnicodeString &that) : m_data(that.m_data) {}
	UnicodeString(const wchar_t *s) : m_data(s) {}
	~UnicodeString() { m_data.releaseBuffer(); }
	void __cdecl format(const UnicodeString *fmt, ...);
	UnicodeString &operator=(const UnicodeString &other)
	{
		m_data.set(other.m_data);
		return *this;
	}
	const wchar_t *str() const
	{
		static const wchar_t TheNullChr = 0;
		return m_data.m_data ? &m_data.m_data->data[0] : &TheNullChr;
	}
	StringBase<wchar_t> m_data;
};

class GameTextInterface
{
public:
	virtual ~GameTextInterface() {}
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
	virtual void slot34() = 0;
	virtual UnicodeString fetch(const char *label, bool *exists = 0) = 0;
};

extern GameTextInterface *TheGameText;

struct Rva00517048
{
	void rva00517048(const UnicodeString &text);
};

extern Rva00517048 *g_Va00A04904;
extern unsigned char g_Va00A0308C;
extern int g_Va00A03090;
extern int g_Va00A03098;
extern unsigned char g_Va00A03094;
#define TheBuddy00517048Owner g_Va00A04904
#define G_BuddyFlag8C g_Va00A0308C
#define G_BuddyCount90 g_Va00A03090
#define G_BuddyTime98 g_Va00A03098
#define G_BuddyFlag94 g_Va00A03094

void __cdecl Rva004161F1Notify(AsciiString a, UnicodeString u)
{
	if (TheBuddy00517048Owner != 0)
	{
		if (G_BuddyFlag8C != 0 && G_BuddyCount90 > 1)
		{
			u = TheGameText->fetch("Buddy:MultipleOnlineNotification", 0);
		}
		StringBase<char>::Header *h = a.m_data.m_data;
		if (h != 0 && h->length != 0)
		{
			const char *txt = (const char *)&h->data[0];
			u.format(&u, txt);
		}
		unsigned long t = timeGetTime();
		G_BuddyTime98 = (int)(t + 0xBB8);
		G_BuddyFlag94 = 1;
		TheBuddy00517048Owner->rva00517048(u);
	}
}

class BfmeMemberRV
{
public:
	bool bfmeAskRV();
};

class Player
{
public:
	char m_pad[0x280];
	int m_color280;
};

enum NameKeyType
{
	NAMEKEY_INVALID = 0
};

class PlayerList
{
public:
	Player *findPlayerWithNameKey(NameKeyType key);
};

class NameKeyGenerator
{
public:
	NameKeyType nameToKey(const AsciiString &s);
};

class GameSlot
{
public:
	void *m_vtable;
	int m_state;
	bool m_isAccepted;
	bool m_hasMap;
	bool m_isMuted;
	char m_pad0B;
	int m_color;
	int m_startPos;
	int m_bfme14;
	int m_playerTemplate;
	int m_teamNumber;
	int m_bfme20;
	int m_origColor;
	int m_origStartPos;
	int m_origPlayerTemplate;
	UnicodeString m_name30;
public:
	AsciiString m_name34;
};

class GameInfo
{
public:
	virtual int slot00();
	virtual int slot04();
	virtual int slot08();
	virtual int slot0c();
	virtual int slot10();
	virtual int slot14();
	virtual int slot18();
	virtual int slot1c();
	virtual int slot20();
	virtual int slot24();
	virtual int slot28();
	virtual int slot2c();
	virtual int slot30();
	virtual int getLocalSlot();
	GameSlot *getSlot(int i);
};

class RGBColor
{
public:
	void setFromInt(int v);
	int m00;
	int m04;
	int m08;
};

class InGameUI
{
public:
	virtual ~InGameUI() {}
	virtual void i00() = 0;
	virtual void i04() = 0;
	virtual void i08() = 0;
	virtual void i0c() = 0;
	virtual void i10() = 0;
	virtual void i14() = 0;
	virtual void i18() = 0;
	virtual void i1c() = 0;
	virtual void i20() = 0;
	virtual void i24() = 0;
	virtual void i28() = 0;
	virtual void i2c() = 0;
	virtual void i30() = 0;
	virtual void i34() = 0;
	virtual void i38() = 0;
	virtual void i3c() = 0;
	virtual void __cdecl slot44(const RGBColor *color, UnicodeString fmt, const wchar_t *txt) = 0;
	virtual void i48() = 0;
	virtual void __cdecl slot4c(UnicodeString fmt, const wchar_t *txt) = 0;
};

extern GameInfo *TheGameInfo;
extern NameKeyGenerator *TheNameKeyGenerator;
extern PlayerList *ThePlayerList;
extern InGameUI *TheInGameUI;
extern const wchar_t g_00C3A458[];

void __cdecl Rva004162B7Notify(AsciiString a, UnicodeString u)
{
	int localSlot = TheGameInfo->getLocalSlot();
	GameSlot *slot = TheGameInfo->getSlot(localSlot);
	AsciiString tmp(slot->m_name34);
	NameKeyType key = TheNameKeyGenerator->nameToKey(tmp);
	Player *player = ThePlayerList->findPlayerWithNameKey(key);
	if (player == 0)
	{
		TheInGameUI->slot4c(UnicodeString(g_00C3A458), u.str());
	}
	else
	{
		bool skip = !((BfmeMemberRV *)player)->bfmeAskRV();
		if (skip)
			goto done;
		GameSlot *lslot = TheGameInfo->getSlot(localSlot);
		if (*(const unsigned char *)((const char *)lslot + 0xa) != 0)
			goto done;
		RGBColor color;
		color.setFromInt(player->m_color280);
		TheInGameUI->slot44(&color, UnicodeString(g_00C3A458), u.str());
	done:;
	}
}

class GameLogic
{
public:
	char m_pad[0x110];
	int m_110;
};

extern GameLogic *TheGameLogic;

void __cdecl Rva004163E1Notify(AsciiString a, UnicodeString u)
{
	if (TheGameLogic->m_110 != 5)
		Rva004161F1Notify(a, u);
	else
		Rva004162B7Notify(a, u);
}
