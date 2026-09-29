// cl: /O1 /DNDEBUG /MD /EHsc
// ?rva00535CE4@UserPreferences@@QAEHVAsciiString@@@Z @0x00535CE4 74B
// UserPreferences Losses path: append Losses to by-value AsciiString, slot6 virtual
// with (arg, 0), return its int, EH dtor via releaseBuffer.
// Evidence: concat 0x00005629, slot6 0x18, releaseBuffer 0x00036410, ret 4,
// unblocks 5, callers 10, sibling UserPreferencesWinsLossesVs.
template <typename T>
class StringBase
{
	friend class AsciiString;
public:
	void concat(const char *s);
private:
	StringBase() : m_data(0) {}
	StringBase(const StringBase<T> &that);
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
	~AsciiString() { m_data.releaseBuffer(); }
	void concat(const char *s) { m_data.concat(s); }
private:
	StringBase<char> m_data;
};

class UserPreferences
{
public:
	virtual void v0();
	virtual void v1();
	virtual void v2();
	virtual void v3();
	virtual void v4();
	virtual void v5();
	virtual int v6(const AsciiString &s, int x);
	int rva00535CE4(AsciiString arg);
};

int UserPreferences::rva00535CE4(AsciiString arg)
{
	arg.concat("Losses");
	int ret = v6(arg, 0);
	return ret;
}
