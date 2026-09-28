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
	~UnicodeString() { m_data.releaseBuffer(); }
	void __cdecl format(const UnicodeString *fmt, ...);
	UnicodeString &operator=(const UnicodeString &other)
	{
		m_data.set(other.m_data);
		return *this;
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
