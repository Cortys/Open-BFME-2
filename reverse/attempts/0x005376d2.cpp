// ?rva005376D2@UserPreferences@@QAE?AVAsciiString@@XZ
// partial score=0.93 date=2026-09-28
// ?rva005376D2@UserPreferences@@QAE?AVAsciiString@@XZ
// partial score=0.93 date=2026-09-28
// cl: /O1 /EHsc /arch:SSE /DNDEBUG /MD /D_STLP_USE_STATIC_LIB
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
	void set(const T *text);
protected:
	BfmeStringData<T> *m_data;
};

class AsciiString : public StringBase<char>
{
public:
	AsciiString() {}
	AsciiString(const AsciiString &other) : StringBase<char>(other) {}
	~AsciiString() {}
	AsciiString &operator=(const AsciiString &other);
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
	AsciiString rva00537616(AsciiString a);
	AsciiString rva0053755A(AsciiString a);
	AsciiString rva005376D2();
	AsciiString rva005377B6();
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

static const char *kFactions[] = { "Men", "Elves", "Dwarves", "Isengard", "Mordor", "Wild" };

AsciiString UserPreferences::rva00537616(AsciiString a)
{
	AsciiString best;
	AsciiString cur;
	Int max = 0;
	for (Int i = 0; i < 6; ++i) {
		cur.set(kFactions[i]);
		Int v = rva00537505(a, cur);
		if (v > max) {
			best = cur;
			max = v;
		}
	}
	return best;
}

AsciiString UserPreferences::rva0053755A(AsciiString a)
{
	AsciiString best;
	AsciiString cur;
	Int max = 0;
	for (Int i = 0; i < 6; ++i) {
		cur.set(kFactions[i]);
		Int v = rva0053745E(a, cur);
		if (v > max) {
			best = cur;
			max = v;
		}
	}
	return best;
}

AsciiString UserPreferences::rva005376D2()
{
	AsciiString best;
	AsciiString outer;
	AsciiString inner;
	Int max = 0;
	for (Int i = 0; i < 6; ++i) {
		outer.set(kFactions[i]);
		for (Int j = 0; j < 6; ++j) {
			inner.set(kFactions[j]);
			Int v = rva0053745E(outer, inner);
			if (v > max) {
				best = inner;
				max = v;
			}
		}
	}
	return best;
}

AsciiString UserPreferences::rva005377B6()
{
	AsciiString best;
	AsciiString outer;
	AsciiString inner;
	Int max = 0;
	for (Int i = 0; i < 6; ++i) {
		outer.set(kFactions[i]);
		for (Int j = 0; j < 6; ++j) {
			inner.set(kFactions[j]);
			Int v = rva00537505(outer, inner);
			if (v > max) {
				best = inner;
				max = v;
			}
		}
	}
	return best;
}
