// ?rva005C1AE4@Rva005C1A36@@QAEHH@Z
// partial score=0.9 date=2026-09-29
// ?rva005C1AE4@Rva005C1A36@@QAEHH@Z
// partial score=0.90 date=2026-09-29
// cl: /O1 /DNDEBUG /MD /EHs
// ?rva005C1AE4@Rva005C1A36@@QAEHH@Z @0x005C1AE4 73B
// Rva005C1A36 slot2 Points-by-faction-index path: faction table 0x009BE9B0 via index, held UserPreferences via slot 0x08, Points-getter 0x005358C3.
// Evidence: table 0x009BE9B0 PBD 0x00037BA0 held +0x2C slot 0x08 Points 0x005358C3 vtable 0x008743DC slot2 chain.
template <typename T>
class StringBase
{
	friend class AsciiString;
public:
	void concat(const char *s);
private:
	StringBase() : m_data(0) {}
	StringBase(const StringBase<T> &that);
	StringBase(const char *s);
	void releaseBuffer();
	struct Header
	{
		int ref_count;
		unsigned len;
		unsigned cap;
		T data[1];
	};
	Header *m_data;
};

class AsciiString
{
public:
	AsciiString() {}
	AsciiString(const AsciiString &that) : m_data(that.m_data) {}
	AsciiString(const char *s) : m_data(s) {}
	~AsciiString() { m_data.releaseBuffer(); }
	void concat(const char *s) { m_data.concat(s); }
private:
	StringBase<char> m_data;
};

class UserPreferences
{
public:
	int rva005358C3(AsciiString arg);
};

class Holder
{
public:
	virtual void v0();
	virtual void v1();
	virtual UserPreferences *v2();
};

class Rva005C1A36
{
public:
	virtual void v0();
	virtual void v1();
	virtual int v2(int idx);
	int rva005C1AE4(int idx);
private:
	char m_pad[0x28];
	Holder *m_held;
};

static const char *kFactions[] = { "Men", "Elves", "Dwarves", "Isengard", "Mordor", "Wild" };

int Rva005C1A36::rva005C1AE4(int idx)
{
	return m_held->v2()->rva005358C3(AsciiString(kFactions[idx]));
}
