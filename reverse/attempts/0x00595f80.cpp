// ?flagNeedToRefresh@FirewallHelperClass@@QAEX_N@Z
// partial score=0.98 date=2026-10-01
// ?flagNeedToRefresh@FirewallHelperClass@@QAEX_N@Z
// partial score=0.98 date=2026-10-01
// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ?flagNeedToRefresh@FirewallHelperClass@@QAEX_N@Z @0x00595F80 215B evidence: ZH FirewallHelper.cpp flagNeedToRefresh plus BFME1 same with TRUE FALSE FirewallNeedToRefresh strings via OptionPreferences write; callers 0x005700E0 0x005A899B pass this+bool; donor void flagNeedToRefresh(Bool)
#include <map>

typedef bool Bool;
typedef int Int;

template <typename T> class StringBase
{
	friend class AsciiString;
	friend class FirewallHelperClass;
	StringBase(const T *text);
	StringBase(const StringBase<T> &other);
	void set(const StringBase<T> &other);
	void releaseBuffer();
public:
	StringBase() : m_data(0) {}
	~StringBase() { releaseBuffer(); }
protected:
	void *m_data;
};

class AsciiString : public StringBase<char>
{
public:
	AsciiString() {}
	AsciiString(const char *text) : StringBase<char>(text) {}
	AsciiString(const AsciiString &other) : StringBase<char>(other) {}
	~AsciiString() {}
	AsciiString &operator=(const AsciiString &other);
};

template <> class StringBase<unsigned short>
{
	friend class UnicodeString;
	void releaseBuffer();
public:
	StringBase() : m_data(0) {}
	~StringBase() { releaseBuffer(); }
protected:
	void *m_data;
};

class UnicodeString : public StringBase<unsigned short>
{
public:
	UnicodeString() {}
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

namespace _STL
{
template <> AsciiString &map<AsciiString, AsciiString, less<AsciiString>, allocator<pair<const AsciiString, AsciiString> > >::operator[](const AsciiString &key);
}

class UserPreferences : public PreferenceMap
{
public:
	UserPreferences();
	virtual ~UserPreferences();
	virtual Bool write(void);
protected:
	UnicodeString m_filename;
};

class Rva002E4272 : public UserPreferences
{
public:
	virtual ~Rva002E4272();
};

class OptionPreferences : public Rva002E4272
{
public:
	OptionPreferences();
};

class FirewallHelperClass
{
public:
	void flagNeedToRefresh(Bool flag);
};

// ?flagNeedToRefresh@FirewallHelperClass@@QAEX_N@Z present-unmatched
void FirewallHelperClass::flagNeedToRefresh(Bool flag)
{
	OptionPreferences prefs;
	(prefs)["FirewallNeedToRefresh"].set(flag ? AsciiString("TRUE") : AsciiString("FALSE"));
	prefs.write();
}
