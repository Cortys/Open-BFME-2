// cl: /O1 /EHsc /arch:SSE /DNDEBUG /MD /D_STLP_USE_STATIC_LIB
//
// UserPreferences WinsVs/LossesVs helpers (retail 0x0053740C/82, 0x0053745E/85,
// 0x005374B3/82, 0x00537505/85).
// Each builds "<outer>WinsVs<inner>" or "<outer>LossesVs<inner>" from a
// by-value outer AsciiString plus "WinsVs"/"LossesVs" plus an inner faction
// string, then forwards to the UserPreferences virtual at slot 6 (getInt,
// +0x18, default 0) or slot 11 (setInt, +0x2C). Vtable layout mirrors
// Common/UserPreferences.cpp (13 slots: dtor, 2 loads, write, 5 getters,
// 4 setters) so the indirect offsets match; the mirror omits the map base
// and m_filename since these bodies touch only the vtable.
// Evidence: "WinsVs" at 0x00869120, "LossesVs" at 0x00869128; faction table
// at 0x009BE9B0 (Men/Elves/Dwarves/Isengard/Mordor/Wild); callers 0x0053755A,
// 0x00537616 (outer = [ebp+0x0C]) and 0x005376D2/0x005377B6 (outer/inner loop
// factions), plus 0x005BF4BC (RealTimeStatsPreferences at [ebp-0x2C]) and
// 0x005BFD35 (StrategicStatsPreferences at [ebp-0x28]); no BFME1 donor
// (no WinsVs/LossesVs hits in open-bfme-1/game). Class proven by shared use
// from both RealTime and Strategic stats objects (common UserPreferences base).

typedef int Int;
typedef bool Bool;
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
	StringBase(const T *text);
	StringBase(const StringBase<T> &other);
	void releaseBuffer();
public:
	StringBase() : m_data(0) {}
	~StringBase() { releaseBuffer(); }
	void concat(const T *text);
	void concat(const StringBase<T> &other);
protected:
	BfmeStringData<T> *m_data;
};

class AsciiString : public StringBase<char>
{
public:
	AsciiString() {}
	AsciiString(const AsciiString &other) : StringBase<char>(other) {}
	~AsciiString() {}
};

class UnicodeString;

class UserPreferences
{
public:
	virtual ~UserPreferences();
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

	Int rva00537505(AsciiString a, const AsciiString &b);
	void rva005374B3(AsciiString a, const AsciiString &b, Int v);
	Int rva0053745E(AsciiString a, const AsciiString &b);
	void rva0053740C(AsciiString a, const AsciiString &b, Int v);
};

Int UserPreferences::rva00537505(AsciiString a, const AsciiString &b)
{
	a.concat("LossesVs");
	a.concat(b);
	return getInt(a, 0);
}

void UserPreferences::rva005374B3(AsciiString a, const AsciiString &b, Int v)
{
	a.concat("LossesVs");
	a.concat(b);
	setInt(a, v);
}

Int UserPreferences::rva0053745E(AsciiString a, const AsciiString &b)
{
	a.concat("WinsVs");
	a.concat(b);
	return getInt(a, 0);
}

void UserPreferences::rva0053740C(AsciiString a, const AsciiString &b, Int v)
{
	a.concat("WinsVs");
	a.concat(b);
	setInt(a, v);
}
