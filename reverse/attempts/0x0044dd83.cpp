// ?rva0044DD83@GameModePreferences@@QAEXVAsciiString@@@Z
// partial score=0.97 date=2026-09-29
// ?rva0044DD83@GameModePreferences@@QAEXVAsciiString@@@Z
// partial score=0.97 date=2026-09-29
// cl: /O1 /EHsc /arch:SSE /DNDEBUG /MD /D_STLP_USE_STATIC_LIB
// stlport
//
// Game-mode-keyed preferences (vtable 0x00C3EF60, retail 0x0044D50D-
// 0x0044D774): a UserPreferences whose typed accessors store every key as
// "<mode>:<key>", with mode 0 = "Rts", 1 = "Strat" (War of the Ring) and
// anything else unprefixed. The prefixed key is formatted into a scratch
// AsciiString member (+0x18) and handed to the base accessor; write is a
// plain forward. The class name is descriptive -- no retail spelling is
// known. LANPreferences (vtable 0x00C3EF04) derives from it. The
// UserPreferences model is the one in Common/UserPreferences.cpp.

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

protected:
	BfmeStringData<T> *m_data;
};

template <> class StringBase<unsigned short>
{
	friend class UnicodeString;
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

class GameModePreferences : public UserPreferences
{
public:
	GameModePreferences(Int mode);
	virtual ~GameModePreferences();

	virtual Bool write(void);
	virtual Bool getBool(const AsciiString &key, Bool defaultValue) const;
	virtual Real getReal(const AsciiString &key, Real defaultValue) const;
	virtual Int getInt(const AsciiString &key, Int defaultValue) const;
	virtual void setBool(const AsciiString &key, Bool val);
	virtual void setReal(const AsciiString &key, Real val);
	virtual void setInt(const AsciiString &key, Int val);

	Int getStrategicScenario(void);
	void setStrategicScenario(Int scenario);
	Int rva0054F5A4(void);
	void rva0054F7C0(Int val);
	void rva0044DDFB(int *vals);
	Int rva0044D836(void);
	void rva0044DC54(Int val);
	void rva0044DCB9(Int val);
	void rva0044DD1E(Int val);
	void rva0044DD83(AsciiString val);

private:
	const AsciiString &makeKey(const char *key) const;

	Int m_mode;
	mutable AsciiString m_key;
};

// ?write@GameModePreferences@@UAE_NXZ @0x44D50D
Bool GameModePreferences::write(void)
{
	return UserPreferences::write();
}

// ?makeKey@GameModePreferences@@ABEABVAsciiString@@PBD@Z @0x44D512
const AsciiString &GameModePreferences::makeKey(const char *key) const
{
	const char *prefix = "";
	switch (m_mode)
	{
		case 0: prefix = "Rts"; break;
		case 1: prefix = "Strat"; break;
	}
	m_key.format("%s:%s", prefix, key);
	return m_key;
}

// ??0GameModePreferences@@QAE@H@Z @0x44D54B
GameModePreferences::GameModePreferences(Int mode) : m_mode(mode)
{
}

// ??1GameModePreferences@@UAE@XZ @0x44D56A
GameModePreferences::~GameModePreferences()
{
}

// ?getStrategicScenario@GameModePreferences@@QAEHXZ @0x44D5A5
Int GameModePreferences::getStrategicScenario(void)
{
	return getInt("StrategicScenario", -1);
}

// ?setStrategicScenario@GameModePreferences@@QAEXH@Z @0x44D5EE
void GameModePreferences::setStrategicScenario(Int scenario)
{
	setInt("StrategicScenario", scenario);
}

// ?setBool@GameModePreferences@@UAEXABVAsciiString@@_N@Z @0x44D636
void GameModePreferences::setBool(const AsciiString &key, Bool val)
{
	UserPreferences::setBool(makeKey(key.str()), val);
}

// ?setReal@GameModePreferences@@UAEXABVAsciiString@@M@Z @0x44D665
void GameModePreferences::setReal(const AsciiString &key, Real val)
{
	UserPreferences::setReal(makeKey(key.str()), val);
}

// ?setInt@GameModePreferences@@UAEXABVAsciiString@@H@Z @0x44D698
void GameModePreferences::setInt(const AsciiString &key, Int val)
{
	UserPreferences::setInt(makeKey(key.str()), val);
}

// ?getBool@GameModePreferences@@UBE_NABVAsciiString@@_N@Z @0x44D6C7
Bool GameModePreferences::getBool(const AsciiString &key, Bool defaultValue) const
{
	return UserPreferences::getBool(makeKey(key.str()), defaultValue);
}

// ?getReal@GameModePreferences@@UBEMABVAsciiString@@M@Z @0x44D6F6
Real GameModePreferences::getReal(const AsciiString &key, Real defaultValue) const
{
	return UserPreferences::getReal(makeKey(key.str()), defaultValue);
}

// ?getInt@GameModePreferences@@UBEHABVAsciiString@@H@Z @0x44D729
Int GameModePreferences::getInt(const AsciiString &key, Int defaultValue) const
{
	return UserPreferences::getInt(makeKey(key.str()), defaultValue);
}

// ?rva0054F5A4@GameModePreferences@@QAEHXZ retail 0x0054F5A4 58B.
// LobbyRoomID getter over the mode-keyed map: find makeKey("LobbyRoomID")
// and atoi the value or 0 when missing/empty.
// Evidence: makeKey 0x0044D512; map find 0x001F8437; atoi IAT; callers
// 0x00385595 0x003855B6; prev Rva0054F508 ctor 0x0054F52F.
Int GameModePreferences::rva0054F5A4(void)
{
	PreferenceMap::const_iterator it = find(makeKey("LobbyRoomID"));
	if (it == end())
		return 0;
	return atoi(it->second.str());
}

// Color-limit globals at 0x00A022F4: +0x38 count source plus +0x40 cached limit.
struct Rva00A022F4
{
	char m_pad[0x38];
	int m_38;
	int m_3C;
	int m_40;
};

extern Rva00A022F4 *g_00A022F4;

// ?rva0044D836@GameModePreferences@@QAEHXZ @0x0044D836 (86B): Color getter
// over the mode-keyed map with -1 for missing or out of range plus lazy
// cached limit from 0x00A022F4.
// Evidence: makeKey 0x0044D512; map find 0x001F8437; atoi IAT; limit
// 0x00A022F4 plus 0x38 plus 0x40; callers 0x00249E23 0x00446853.
Int GameModePreferences::rva0044D836(void)
{
	PreferenceMap::const_iterator it = find(makeKey("Color"));
	if (it == end())
		return -1;
	int v = atoi(it->second.str());
	if (v < -1)
		return -1;
	int *limit = &g_00A022F4->m_40;
	if (*limit == 0)
		*limit = g_00A022F4->m_38;
	if (v < *limit)
		return v;
	return -1;
}

// ?rva0054F7C0@GameModePreferences@@QAEXH@Z retail 0x0054F7C0 101B.
// LobbyRoomID setter: format "%d" then map makeKey("LobbyRoomID") slot assign.
// Evidence: format 0x00038150; makeKey 0x0044D512; map subscript 0x002031FB;
// AsciiString assign pin 0x000366F0; releaseBuffer 0x00036410; caller 0x005A3899.
void GameModePreferences::rva0054F7C0(Int val)
{
	AsciiString tmp;
	tmp.format("%d", val);
	AsciiString &slot = (*this)[makeKey("LobbyRoomID")];
	slot = tmp;
}

// ?rva0044DC54@GameModePreferences@@QAEXH@Z @0x0044DC54 (101B): Hero setter
// via "%d" format then map makeKey("Hero") slot assign.
// Evidence: format 0x00038150; makeKey 0x0044D512; map subscript 0x002031FB;
// AsciiString assign pin 0x000366F0; releaseBuffer 0x00036410; callers
// 0x0044579D 0x0059F999; prev 0x0044D836 next 0x0044DDFB.
void GameModePreferences::rva0044DC54(Int val)
{
	AsciiString tmp;
	tmp.format("%d", val);
	AsciiString &slot = (*this)[makeKey("Hero")];
	slot = tmp;
}

// ?rva0044DCB9@GameModePreferences@@QAEXH@Z @0x0044DCB9 (101B): Color setter
// via "%d" format then map makeKey("Color") slot assign.
// Evidence: format 0x00038150; makeKey 0x0044D512; map subscript 0x002031FB;
// AsciiString assign pin 0x000366F0; releaseBuffer 0x00036410; callers
// 0x00445593 0x0059F985; prev 0x0044DC54 next 0x0044DDFB.
void GameModePreferences::rva0044DCB9(Int val)
{
	AsciiString tmp;
	tmp.format("%d", val);
	AsciiString &slot = (*this)[makeKey("Color")];
	slot = tmp;
}

// ?rva0044DD1E@GameModePreferences@@QAEXH@Z @0x0044DD1E (101B): PlayerTemplate
// setter via "%d" format then map makeKey("PlayerTemplate") slot assign.
// Evidence: format 0x00038150; makeKey 0x0044D512; map subscript 0x002031FB;
// AsciiString assign pin 0x000366F0; releaseBuffer 0x00036410; prev 0x0044DCB9
// next 0x0044DDFB.
void GameModePreferences::rva0044DD1E(Int val)
{
	AsciiString tmp;
	tmp.format("%d", val);
	AsciiString &slot = (*this)[makeKey("PlayerTemplate")];
	slot = tmp;
}

// ?rva0044DD83@GameModePreferences@@QAEXVAsciiString@@@Z 0x0044DD83 120B evidence: Map setter via QuotedPrintable then makeKey Map slot assign; callers 0x0050CFE6 0x0059F9C2; between rva0044DD1E and rva0044DDFB
AsciiString AsciiStringToQuotedPrintable(AsciiString original);
// ?rva0044DD83@GameModePreferences@@QAEXVAsciiString@@@Z present-unmatched
void GameModePreferences::rva0044DD83(AsciiString val)
{
	AsciiString tmp(AsciiStringToQuotedPrintable(val));
	AsciiString &slot = (*this)[makeKey("Map")];
	slot = tmp;
}

// ?rva0044DDFB@GameModePreferences@@QAEXPAH@Z @0x0044DDFB (95B): Rules setter
// over the mode-keyed map via ten-int array formatter into tmp then slot assign.
// Evidence: formatter 0x0055A087; makeKey 0x0044D512; map subscript 0x002031FB;
// AsciiString assign pin 0x000366F0; releaseBuffer 0x00036410; callers
// 0x004442CB 0x0059EC3F; prev GameModePreferences 0x0044D758.
void __cdecl Rva0055A087Format(int *vals, AsciiString *out);
void GameModePreferences::rva0044DDFB(int *vals)
{
	AsciiString tmp;
	Rva0055A087Format(vals, &tmp);
	AsciiString &slot = (*this)[makeKey("Rules")];
	slot = tmp;
}

// Zero Hour's LANPreferences on the mode-keyed base (vtable 0x00C3EF04).
// BFME 2 renamed its file NetworkPref.ini and loads it from a separate
// member rather than inline in the constructor.
class LANPreferences : public GameModePreferences
{
public:
	LANPreferences(Int mode);
	virtual ~LANPreferences();

	Bool loadFromIniFile(void);
};

// The destructor (0x0044D285) and its deleting form (0x0044D290) are rowed
// under address names in Rva0044D56ADerived.cpp.

// ?loadFromIniFile@LANPreferences@@QAE_NXZ @0x44D2AC
Bool LANPreferences::loadFromIniFile(void)
{
	return UserPreferences::load("NetworkPref.ini");
}

// ??0LANPreferences@@QAE@H@Z @0x44D2F5
LANPreferences::LANPreferences(Int mode) : GameModePreferences(mode)
{
	loadFromIniFile();
}
