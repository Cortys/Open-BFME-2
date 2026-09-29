// cl: /O1 /DNDEBUG /MD /EHsc
// ?rva00535CE4@UserPreferences@@QAEHVAsciiString@@@Z @0x00535CE4 74B
// UserPreferences Losses path: append Losses to by-value AsciiString, slot6 virtual
// with (arg, 0), return its int, EH dtor via releaseBuffer.
// Evidence: concat 0x00005629, slot6 0x18, releaseBuffer 0x00036410, ret 4,
// unblocks 5, callers 10, sibling UserPreferencesWinsLossesVs.
// ?rva0053587C@UserPreferences@@QAEXVAsciiString@@H@Z @0x0053587C 71B
// UserPreferences Points path: append Points, slot 0x2C virtual with (arg, x), void ret 8.
// Evidence: concat Points 0x00868E24, slot 0x2C, releaseBuffer, unblocks 2, callers 2,
// sibling 0x00535CE4 same TU(flags pins).
// ?rva00535BAF@UserPreferences@@QAEXVAsciiString@@H@Z @0x00535BAF 71B
// UserPreferences Wins path: append Wins, slot 0x2C with (arg, x), void ret 8.
// Evidence: concat Wins 0x00868E7C, slot 0x2C, releaseBuffer, gap between 0x0053587C
// and 0x00535CE4 same TU, unblocks 2 callers 2.
// ?rva00535C9D@UserPreferences@@QAEXVAsciiString@@H@Z @0x00535C9D 71B
// UserPreferences Losses-void path: append Losses slot 0x2C with (arg, x) void ret 8.
// Evidence: concat Losses 0x00868E84 slot 0x2C releaseBuffer gap Wins-Losses same TU.
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
	virtual void v7();
	virtual void v8();
	virtual void v9();
	virtual void v10();
	virtual void v11(const AsciiString &s, int x);
	int rva00535CE4(AsciiString arg);
	void rva0053587C(AsciiString arg, int x);
	void rva00535BAF(AsciiString arg, int x);
	void rva00535C9D(AsciiString arg, int x);
};

int UserPreferences::rva00535CE4(AsciiString arg)
{
	arg.concat("Losses");
	int ret = v6(arg, 0);
	return ret;
}

void UserPreferences::rva0053587C(AsciiString arg, int x)
{
	arg.concat("Points");
	v11(arg, x);
}

void UserPreferences::rva00535BAF(AsciiString arg, int x)
{
	arg.concat("Wins");
	v11(arg, x);
}

void UserPreferences::rva00535C9D(AsciiString arg, int x)
{
	arg.concat("Losses");
	v11(arg, x);
}
