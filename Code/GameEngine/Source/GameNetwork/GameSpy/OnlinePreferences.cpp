// cl: /O1 /EHsc /arch:SSE /DNDEBUG /MD /D_STLP_USE_STATIC_LIB
// stlport
//
// Per-profile online preference files: Zero Hour's QuickMatchPreferences,
// GameSpyMiscPreferences and LadderPreferences constructors, which BFME 2 roots under
// "Online Files" (Zero Hour used "GeneralsOnline"). Retail keeps them far
// from UserPreferences.cpp (0x005DF1A3 and 0x00559711), so they get their
// own unit. The UserPreferences model is the one in
// Code/GameEngine/Source/Common/UserPreferences.cpp.

#include <map>
#include <stdlib.h>

struct _iobuf;
typedef struct _iobuf FILE;
extern "C" __declspec(dllimport) FILE *__cdecl _wfopen(const unsigned short *name, const unsigned short *mode);
extern "C" __declspec(dllimport) int __cdecl fprintf(FILE *fp, const char *fmt, ...);
extern "C" __declspec(dllimport) int __cdecl fclose(FILE *fp);
extern "C" __declspec(dllimport) char *__cdecl fgets(char *buf, int n, FILE *fp);

typedef bool Bool;
typedef int Int;
typedef float Real;

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
	friend class UnicodeString;
	StringBase(const T *text);
	StringBase(const StringBase<T> &other);
	void releaseBuffer();

public:
	StringBase() : m_data(0) {}
	~StringBase();
	Int compare(const char *other) const;
	Int compareNoCase(const char *other) const;
	void set(const T *text);
	void trim(void);
	Bool nextToken(StringBase *token, const char *seps);
	void concat(const StringBase &other);

protected:
	BfmeStringData<T> *m_data;
};

template <> class StringBase<unsigned short>
{
	friend class UnicodeString;
	StringBase(const StringBase &other);
	void releaseBuffer();

public:
	StringBase() : m_data(0) {}
	~StringBase() { releaseBuffer(); }
	bool isEmpty() const;
	void set(const StringBase &other);
	void concat(const StringBase &other);

protected:
	BfmeStringData<unsigned short> *m_data;
};

class AsciiString : public StringBase<char>
{
public:
	static const AsciiString TheEmptyString;

	AsciiString() {}
	AsciiString(const char *text) : StringBase<char>(text) {}
	AsciiString(const AsciiString &other) : StringBase<char>(other) {}
	AsciiString &operator=(const AsciiString &other);
	AsciiString &operator=(const char *text) { set(text); return *this; }

	const char *str() const { return m_data ? &m_data->text[0] : ""; }
	Bool isEmpty() const { return m_data == 0 || m_data->length == 0; }
	void format(const char *fmt, ...);
	void toLower();
	Bool operator==(const char *other) const { return compare(other) == 0; }
};

class UnicodeString : public StringBase<unsigned short>
{
public:
	UnicodeString() {}
	UnicodeString(const UnicodeString &other) : StringBase<unsigned short>(other) {}
	UnicodeString &operator=(const UnicodeString &other) { set(other); return *this; }
	void translate(const char *text);
	const unsigned short *str() const { return m_data ? &m_data->text[0] : L""; }
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

typedef _STL::map<AsciiString, AsciiString> PreferenceMap;

class UserPreferences : public PreferenceMap
{
public:
	UserPreferences();
	virtual ~UserPreferences();

	// MSVC lays overloaded virtuals out in reverse declaration order, so
	// load(UnicodeString) takes slot 1 and load(AsciiString) slot 2.
	virtual Bool load(const AsciiString &fname);
	virtual Bool load(const UnicodeString &fname);
	virtual Bool write(void);

	virtual Bool getBool(const AsciiString &key, Bool defaultValue) const;
	virtual Real getReal(const AsciiString &key, Real defaultValue) const;
	virtual Int getInt(const AsciiString &key, Int defaultValue) const;
	virtual Int getEnumIndex(const char *key, const char **names, Int count, Int defaultValue) const;
	virtual AsciiString getAsciiString(const AsciiString &key, const AsciiString &defaultValue) const;

	virtual void setBool(const AsciiString &key, Bool val);
	virtual void setReal(const AsciiString &key, Real val);
	virtual void setInt(const AsciiString &key, Int val);
	virtual void setAsciiString(const AsciiString &key, const AsciiString &val);

protected:
	UnicodeString m_filename;
};

// The GameSpy session info singleton (0x00E02320), as far as the ignore
// list reaches it: getLocalProfileID sits in vtable slot 0x7C.
class GameSpyInfoInterface
{
public:
	virtual void _M_slot_00();
	virtual void _M_slot_04();
	virtual void _M_slot_08();
	virtual void _M_slot_0c();
	virtual void _M_slot_10();
	virtual void _M_slot_14();
	virtual void _M_slot_18();
	virtual void _M_slot_1c();
	virtual void _M_slot_20();
	virtual void _M_slot_24();
	virtual void _M_slot_28();
	virtual void _M_slot_2c();
	virtual void _M_slot_30();
	virtual void _M_slot_34();
	virtual void _M_slot_38();
	virtual void _M_slot_3c();
	virtual void _M_slot_40();
	virtual void _M_slot_44();
	virtual void _M_slot_48();
	virtual void _M_slot_4c();
	virtual void _M_slot_50();
	virtual void _M_slot_54();
	virtual void _M_slot_58();
	virtual void _M_slot_5c();
	virtual void _M_slot_60();
	virtual void _M_slot_64();
	virtual void _M_slot_68();
	virtual void _M_slot_6c();
	virtual void _M_slot_70();
	virtual void _M_slot_74();
	virtual void _M_slot_78();
	virtual Int getLocalProfileID();
};

extern GameSpyInfoInterface *TheGameSpyInfo;

class QuickMatchPreferences : public UserPreferences
{
public:
	QuickMatchPreferences();
	virtual ~QuickMatchPreferences();
	void setColor(Int val);
	Int getColor(void);
	void setSide(Int val);
	Int getSide(void);
};

class GameSpyMiscPreferences : public UserPreferences
{
public:
	GameSpyMiscPreferences();
	virtual ~GameSpyMiscPreferences();
	int rva00559782();
	void rva005597CB(int val);
	void rva0055986F(AsciiString val);
	void rva00559924(AsciiString val);
	AsciiString rva00559813();
	AsciiString rva005598C8();
};

// ??0QuickMatchPreferences@@QAE@XZ @0x5DF1A3
QuickMatchPreferences::QuickMatchPreferences()
{
	AsciiString userPrefFilename;
	userPrefFilename.format("%s\\QMPref%d.ini", "Online Files", TheGameSpyInfo->getLocalProfileID());
	load(userPrefFilename);
}

void QuickMatchPreferences::setColor(Int val)
{
	setInt("Color", val);
}

Int QuickMatchPreferences::getColor(void)
{
	return getInt("Color", 0);
}

void QuickMatchPreferences::setSide(Int val)
{
	setInt("Side", val);
}

Int QuickMatchPreferences::getSide(void)
{
	return getInt("Side", 0);
}

// ??0GameSpyMiscPreferences@@QAE@XZ @0x559711
GameSpyMiscPreferences::GameSpyMiscPreferences()
{
	AsciiString userPrefFilename;
	userPrefFilename.format("%s\\GSMiscPref%d.ini", "Online Files", TheGameSpyInfo->getLocalProfileID());
	load(userPrefFilename);
}

int GameSpyMiscPreferences::rva00559782()
{
	return getInt("Locale", 0);
}

void GameSpyMiscPreferences::rva005597CB(int val)
{
	setInt("Locale", val);
}

void GameSpyMiscPreferences::rva0055986F(AsciiString val)
{
	setAsciiString("ToolTipCachedStats", val);
}

void GameSpyMiscPreferences::rva00559924(AsciiString val)
{
	setAsciiString("AllOtherCachedStats", val);
}

AsciiString GameSpyMiscPreferences::rva00559813()
{
	return getAsciiString("ToolTipCachedStats", AsciiString::TheEmptyString);
}

AsciiString GameSpyMiscPreferences::rva005598C8()
{
	return getAsciiString("AllOtherCachedStats", AsciiString::TheEmptyString);
}

typedef long time_t;
typedef unsigned short UnsignedShort;

class LadderPref
{
public:
	LadderPref(const LadderPref &other);
	~LadderPref();

	UnicodeString name;
	AsciiString address;
	UnsignedShort port;
	time_t lastPlayDate;
};

AsciiString AsciiStringToQuotedPrintable(AsciiString original);
AsciiString UnicodeStringToQuotedPrintable(UnicodeString original);

typedef _STL::map<time_t, LadderPref> LadderPrefMap;

// Zero Hour's recent-ladder preferences: a UserPreferences file plus the
// parsed LadderPrefMap at +0x14; write is overridden (vtable 0x00C77788
// slot 3 is 0x005E0026).
class LadderPreferences : public UserPreferences
{
public:
	LadderPreferences();
	virtual ~LadderPreferences();
	virtual Bool write(void);

private:
	LadderPrefMap m_ladders;
};

// ??0LadderPreferences@@QAE@XZ @0x5DFFD3
LadderPreferences::LadderPreferences()
{
}

// ??1LadderPreferences@@UAE@XZ @0x5DFF7B
LadderPreferences::~LadderPreferences()
{
}

// ??1LadderPref@@QAE@XZ @0x5BA3C0
LadderPref::~LadderPref()
{
}

// ?write@LadderPreferences@@UAE_NXZ @0x5E0026
Bool LadderPreferences::write(void)
{
	clear();

	static const Int MAX_LADDERS = 5;
	LadderPrefMap::iterator lpIt;
	Int count;
	for (lpIt = m_ladders.begin(), count = 0;
		lpIt != m_ladders.end() && count < MAX_LADDERS;
		++lpIt, ++count)
	{
		LadderPref p = lpIt->second;
		AsciiString ladName;
		AsciiString ladData;
		ladName.format("%s:%d", AsciiStringToQuotedPrintable(p.address).str(), p.port);
		ladData.format("%s:%d", UnicodeStringToQuotedPrintable(p.name).str(), p.lastPlayDate);
		AsciiString &slot = (*this)[ladName];
		slot = ladData;
	}

	return UserPreferences::write();
}

// ?Rva0055A087Format@@YAXPAHPAVAsciiString@@@Z @0x0055A087 (86B): formats ten
// ints from the array as "%d " into a temp then concats into the output.
// Evidence: caller 0x0044DE18 passes its int array plus temp AsciiString;
// shared "%d " literal at 0x007E3AC0 plus rowed format 0x00038150 and concat
// 0x00006987; loop 0xa matches ten ints.
void __cdecl Rva0055A087Format(int *vals, AsciiString *out)
{
	AsciiString tmp;
	for (int i = 0; i < 10; ++i) {
		tmp.format("%d ", vals[i]);
		out->concat(tmp);
	}
}
