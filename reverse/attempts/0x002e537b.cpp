// ?rva002E537B@OptionPreferences@@QAEXH@Z
// partial score=0.94 date=2026-09-29
// ?rva002E537B@OptionPreferences@@QAEXH@Z
// partial score=0.94 date=2026-09-28
// cl: /O1 /EHsc /DNDEBUG /MD /D_STLP_USE_STATIC_LIB
// stlport
// ?rva002E43A6@OptionPreferences@@QAEXH@Z 0x002E43A6 72B
// Evidence: hardcoded FirewallBehavior key (string 0x7EB734) via rowed
// StringBase ctor 0x00037BA0; virtual setInt slot 0x2c (UserPreferences
// vtable: 13 slots, setInt is index 11); temp teardown via releaseBuffer
// 0x00036410; neighbors OptionPreferences ctor/siblings; caller 0x005194F6.
#include <map>
#include <stdlib.h>
#include <string.h>

typedef bool Bool;
typedef int Int;

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
private:
	StringBase(const T *text);
	StringBase(const StringBase<T> &other);
	~StringBase() { releaseBuffer(); }
	void releaseBuffer();
	BfmeStringData<T> *m_data;

public:
	StringBase() : m_data(0) {}
	void set(const T *text);
	const T *str() const { return m_data ? &m_data->text[0] : (const T *)""; }
};

class AsciiString : private StringBase<char>
{
public:
	AsciiString() {}
	AsciiString(const char *text) : StringBase<char>(text) {}
	AsciiString(const AsciiString &other) : StringBase<char>(other) {}
	~AsciiString() {}
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

// Retail LOD level-name table at 0xDB95F4, defined in
// OptionPreferences_getStaticGameDetail.cpp; this TU only references it.
extern const char *BfmeLODLevelNames[];

class UserPreferences : public PreferenceMap
{
public:
	UserPreferences();
	virtual ~UserPreferences();

	virtual Bool load(const AsciiString &fname);
	virtual Bool load(const class UnicodeString &fname);
	virtual Bool write(void);

	virtual Bool getBool(const AsciiString &key, Bool defaultValue) const;
	virtual float getReal(const AsciiString &key, float defaultValue) const;
	virtual Int getInt(const AsciiString &key, Int defaultValue) const;
	virtual Int getEnumIndex(const char *key, const char **names, Int count, Int defaultValue) const;
	virtual AsciiString getAsciiString(const AsciiString &key, const AsciiString &defaultValue) const;

	virtual void setBool(const AsciiString &key, Bool val);
	virtual void setReal(const AsciiString &key, float val);
	virtual void setInt(const AsciiString &key, Int val);
	virtual void setAsciiString(const AsciiString &key, const AsciiString &val);
};

class OptionPreferences : public UserPreferences
{
public:
	virtual ~OptionPreferences();
	void rva002E43A6(Int val);
	void rva002E43EE(short val);
	void rva002E4438(unsigned short val);
	void rva002E537B(Int val);
};

void OptionPreferences::rva002E43A6(Int val)
{
	setInt(AsciiString("FirewallBehavior"), val);
}

// ?rva002E43EE@OptionPreferences@@QAEXF@Z 0x002E43EE 74B
// Evidence: FirewallPortAllocationDelta key (string 0x7EB700) via rowed
// StringBase ctor 0x00037BA0; virtual setInt slot 0x2c with movsx word arg;
// temp teardown via releaseBuffer 0x00036410; twin of rva002E43A6 above.
void OptionPreferences::rva002E43EE(short val)
{
	setInt(AsciiString("FirewallPortAllocationDelta"), val);
}

// ?rva002E4438@OptionPreferences@@QAEXG@Z 0x002E4438 74B
// Evidence: FirewallPortOverride key (string 0x7EB71C) via rowed StringBase
// ctor 0x00037BA0; virtual setInt slot 0x2c with movzx word arg; temp
// teardown via releaseBuffer 0x00036410; third sibling above.
void OptionPreferences::rva002E4438(unsigned short val)
{
	setInt(AsciiString("FirewallPortOverride"), val);
}

// ?rva002E537B@OptionPreferences@@QAEXH@Z 0x002E537B 127B
// Evidence: IdealStaticGameLOD key (string 0x804D1C); -1 erases the key via
// rowed string-tree erase 0x002E4ED1, else writes BfmeLODLevelNames[val]
// through base-map subscript 0x002031FB plus StringBase::set 0x000055F5;
// table shared with OptionPreferences_getStaticGameDetail.cpp.
// ?rva002E537B@OptionPreferences@@QAEXH@Z present-unmatched
void OptionPreferences::rva002E537B(Int val)
{
	if (val != -1)
		(*this)[AsciiString("IdealStaticGameLOD")].set(BfmeLODLevelNames[val]);
	else
		erase(AsciiString("IdealStaticGameLOD"));
}
