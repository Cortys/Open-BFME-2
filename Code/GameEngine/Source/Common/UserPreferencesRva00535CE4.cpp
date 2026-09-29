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
// ?rva00535D2E@UserPreferences@@QAEXVAsciiString@@H@Z @0x00535D2E 71B
// UserPreferences WinStreak-void path: append WinStreak slot 0x2C with (arg, x) void ret 8.
// Evidence: concat WinStreak 0x00868E8C slot 0x2C releaseBuffer gap same TU unlock.
// ?rva00535DBF@UserPreferences@@QAEXVAsciiString@@H@Z @0x00535DBF 71B
// UserPreferences LossStreak-void path: append LossStreak slot 0x2C with (arg, x) void ret 8.
// Evidence: concat LossStreak 0x00868E98 slot 0x2C releaseBuffer gap same TU unlock.
// ?rva00535E50@UserPreferences@@QAEXVAsciiString@@H@Z @0x00535E50 71B
// UserPreferences BestWinStreak-void path: append BestWinStreak slot 0x2C with (arg, x) void ret 8.
// Evidence: concat BestWinStreak 0x00868EA4 slot 0x2C releaseBuffer gap same TU unlock.
// ?rva00535EE1@UserPreferences@@QAEXVAsciiString@@H@Z @0x00535EE1 71B
// UserPreferences WorstLossStreak-void path: append WorstLossStreak slot 0x2C with (arg, x) void ret 8.
// Evidence: concat WorstLossStreak 0x00868EB4 slot 0x2C releaseBuffer gap same TU unlock.
// ?rva00535F72@UserPreferences@@QAEXH@Z @0x00535F72 72B
// UserPreferences OverallWinStreak-void path: local AsciiString OverallWinStreak slot 0x2C with (tmp, x) void ret 4.
// Evidence: StringBase PBD ctor 0x00037BA0 slot 0x2C releaseBuffer gap same TU unlock.
// ?rva00535FBA@UserPreferences@@QAEHXZ @0x00535FBA 73B
// UserPreferences OverallWinStreak-getter path: local AsciiString OverallWinStreak slot 0x18 with (tmp, 0) int ret 0.
// Evidence: StringBase PBD ctor 0x00037BA0 slot 0x18 releaseBuffer gap same TU unlock.
// ?rva005358C3@UserPreferences@@QAEHVAsciiString@@@Z @0x005358C3 74B
// UserPreferences Points-getter path: append Points to by-value AsciiString slot 0x18 with (arg, 0) int ret 4.
// Evidence: concat Points 0x00868E24 slot 0x18 releaseBuffer gap same TU unlock.
// ?rva00535BF6@UserPreferences@@QAEHVAsciiString@@@Z @0x00535BF6 74B
// UserPreferences Wins-getter path: append Wins to by-value AsciiString slot 0x18 with (arg, 0) int ret 4.
// Evidence: concat Wins 0x00868E7C slot 0x18 releaseBuffer gap same TU unlock.
// ?rva00535C40@UserPreferences@@QAEHXZ @0x00535C40 93B
// UserPreferences total-wins path: sum Wins-getter over 6 faction table slot 0x18 chain.
// Evidence: faction table 0x009BE9B0 calls 0x00535BF6 chain same TU.
// ?rva005373AF@UserPreferences@@QAEHXZ @0x005373AF 93B
// UserPreferences total-losses path: sum Losses-getter over 6 faction table slot 0x18 chain.
// Evidence: faction table 0x009BE9B0 calls 0x00535CE4 chain same TU.
// ?rva0053734E@UserPreferences@@QAEHVAsciiString@@@Z @0x0053734E 97B
// UserPreferences total-games path: Wins-getter plus Losses-getter over same by-value faction arg chain.
// Evidence: copy 0x000365F0 calls 0x00535BF6 0x00535CE4 releaseBuffer ret 4 chain same TU.
// ?rva00537C28@UserPreferences@@QAEHXZ @0x00537C28 23B
// UserPreferences grand-total path: total-losses plus total-wins chain.
// Evidence: calls 0x005373AF 0x00535C40 ret 0 chain same TU.
// ?rva00536C61@UserPreferences@@QAEXVAsciiString@@H@Z @0x00536C61 71B
// UserPreferences BattlesLostRTS-void path: append BattlesLostRTS slot 0x2C with (arg, x) void ret 8.
// Evidence: concat BattlesLostRTS 0x00869084 slot 0x2C releaseBuffer gap same TU.
// ?rva00536CA8@UserPreferences@@QAEHVAsciiString@@@Z @0x00536CA8 74B
// UserPreferences BattlesLostRTS-getter path: append BattlesLostRTS to by-value AsciiString slot 0x18 with (arg, 0) int ret 4.
// Evidence: concat BattlesLostRTS 0x00869084 slot 0x18 releaseBuffer gap same TU.
// ?rva00536CF2@UserPreferences@@QAEXVAsciiString@@H@Z @0x00536CF2 71B
// UserPreferences BattlesWonRTS-void path: append BattlesWonRTS slot 0x2C with (arg, x) void ret 8.
// Evidence: concat BattlesWonRTS 0x00869094 slot 0x2C releaseBuffer gap same TU.
// ?rva00536D39@UserPreferences@@QAEHVAsciiString@@@Z @0x00536D39 74B
// UserPreferences BattlesWonRTS-getter path: append BattlesWonRTS to by-value AsciiString slot 0x18 with (arg, 0) int ret 4.
// Evidence: concat BattlesWonRTS 0x00869094 slot 0x18 releaseBuffer gap same TU.
// ?rva00536D83@UserPreferences@@QAEXVAsciiString@@H@Z @0x00536D83 71B
// UserPreferences BattlesLostAutoResolve-void path: append BattlesLostAutoResolve slot 0x2C with (arg, x) void ret 8.
// Evidence: concat BattlesLostAutoResolve 0x008690A4 slot 0x2C releaseBuffer gap same TU.
// ?rva00536DCA@UserPreferences@@QAEHVAsciiString@@@Z @0x00536DCA 74B
// UserPreferences BattlesLostAutoResolve-getter path: append BattlesLostAutoResolve to by-value AsciiString slot 0x18 with (arg, 0) int ret 4.
// Evidence: concat BattlesLostAutoResolve 0x008690A4 slot 0x18 releaseBuffer gap same TU.
// ?rva00536E14@UserPreferences@@QAEXVAsciiString@@H@Z @0x00536E14 71B
// UserPreferences BattlesWonAutoResolve-void path: append BattlesWonAutoResolve slot 0x2C with (arg, x) void ret 8.
// Evidence: concat BattlesWonAutoResolve 0x008690BC slot 0x2C releaseBuffer gap same TU.
// ?rva00536E5B@UserPreferences@@QAEHVAsciiString@@@Z @0x00536E5B 74B
// UserPreferences BattlesWonAutoResolve-getter path: append BattlesWonAutoResolve to by-value AsciiString slot 0x18 with (arg, 0) int ret 4.
// Evidence: concat BattlesWonAutoResolve 0x008690BC slot 0x18 releaseBuffer gap same TU.
// ?rva00535D75@UserPreferences@@QAEHVAsciiString@@@Z @0x00535D75 74B
// UserPreferences WinStreak-getter path: append WinStreak to by-value AsciiString slot 0x18 with (arg, 0) int ret 4.
// Evidence: concat WinStreak 0x00868E8C slot 0x18 releaseBuffer gap same TU unlock.
// ?rva00535E06@UserPreferences@@QAEHVAsciiString@@@Z @0x00535E06 74B
// UserPreferences LossStreak-getter path: append LossStreak to by-value AsciiString slot 0x18 with (arg, 0) int ret 4.
// Evidence: concat LossStreak 0x00868E98 slot 0x18 releaseBuffer gap same TU unlock.
// ?rva00535E97@UserPreferences@@QAEHVAsciiString@@@Z @0x00535E97 74B
// UserPreferences BestWinStreak-getter path: append BestWinStreak to by-value AsciiString slot 0x18 with (arg, 0) int ret 4.
// Evidence: concat BestWinStreak 0x00868EA4 slot 0x18 releaseBuffer gap same TU unlock.
// ?rva00535F28@UserPreferences@@QAEHVAsciiString@@@Z @0x00535F28 74B
// UserPreferences WorstLossStreak-getter path: append WorstLossStreak to by-value AsciiString slot 0x18 with (arg, 0) int ret 4.
// Evidence: concat WorstLossStreak 0x00868EB4 slot 0x18 releaseBuffer gap same TU unlock.
// ?rva0053595E@UserPreferences@@QAEXVAsciiString@@M@Z @0x0053595E 75B
// UserPreferences LongestGameTime-setter path: append LongestGameTime to by-value AsciiString slot 0x28 with (arg, float) void ret 8.
// Evidence: concat LongestGameTime 0x00868E38 slot 0x28 releaseBuffer gap same TU unlock.
// ?rva0053590D@UserPreferences@@QAEMVAsciiString@@@Z @0x0053590D 81B
// UserPreferences TimePlayed-getter path: append TimePlayed to by-value AsciiString slot 0x14 with (arg, 0.0f) float ret 4.
// Evidence: concat TimePlayed 0x00868E2C slot 0x14 releaseBuffer fldz fstp gap same TU unlock.
// ?rva005359A9@UserPreferences@@QAEMVAsciiString@@@Z @0x005359A9 81B
// UserPreferences LongestGameTime-getter path: append LongestGameTime to by-value AsciiString slot 0x14 with (arg, 0.0f) float ret 4.
// Evidence: concat LongestGameTime 0x00868E38 slot 0x14 releaseBuffer fldz fstp gap same TU unlock.
// ?rva00535A45@UserPreferences@@QAEMVAsciiString@@@Z @0x00535A45 81B
// UserPreferences ShortestGameTime-getter path: append ShortestGameTime to by-value AsciiString slot 0x14 with (arg, 0.0f) float ret 4.
// Evidence: concat ShortestGameTime 0x00868E48 slot 0x14 releaseBuffer fldz fstp gap same TU unlock.
// ?rva00535AE1@UserPreferences@@QAEMVAsciiString@@@Z @0x00535AE1 81B
// UserPreferences AverageGameTime-getter path: append AverageGameTime to by-value AsciiString slot 0x14 with (arg, 0.0f) float ret 4.
// Evidence: concat AverageGameTime 0x00868E5C slot 0x14 releaseBuffer fldz fstp gap same TU unlock.
// ?rva005359FA@UserPreferences@@QAEXVAsciiString@@M@Z @0x005359FA 75B
// UserPreferences ShortestGameTime-setter path: append ShortestGameTime to by-value AsciiString slot 0x28 with (arg, float) void ret 8.
// Evidence: concat ShortestGameTime 0x00868E48 slot 0x28 releaseBuffer gap same TU unlock.
// ?rva00535A96@UserPreferences@@QAEXVAsciiString@@M@Z @0x00535A96 75B
// UserPreferences AverageGameTime-setter path: append AverageGameTime to by-value AsciiString slot 0x28 with (arg, float) void ret 8.
// Evidence: concat AverageGameTime 0x00868E5C slot 0x28 releaseBuffer gap same TU unlock.
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
	virtual void v0();
	virtual void v1();
	virtual void v2();
	virtual void v3();
	virtual void v4();
	virtual float v5(const AsciiString &s, float x);
	virtual int v6(const AsciiString &s, int x);
	virtual void v7();
	virtual void v8();
	virtual void v9();
	virtual void v10(const AsciiString &s, float x);
	virtual void v11(const AsciiString &s, int x);
	int rva00535CE4(AsciiString arg);
	void rva0053587C(AsciiString arg, int x);
	void rva00535BAF(AsciiString arg, int x);
	void rva00535C9D(AsciiString arg, int x);
	void rva00535D2E(AsciiString arg, int x);
	void rva00535DBF(AsciiString arg, int x);
	void rva00535E50(AsciiString arg, int x);
	void rva00535EE1(AsciiString arg, int x);
	void rva00535F72(int x);
	int rva00535FBA();
	int rva005358C3(AsciiString arg);
	int rva00535BF6(AsciiString arg);
	int rva00535C40();
	int rva005373AF();
	int rva0053734E(AsciiString arg);
	int rva00537C28();
	void rva00536C61(AsciiString arg, int x);
	int rva00536CA8(AsciiString arg);
	void rva00536CF2(AsciiString arg, int x);
	int rva00536D39(AsciiString arg);
	void rva00536D83(AsciiString arg, int x);
	int rva00536DCA(AsciiString arg);
	void rva00536E14(AsciiString arg, int x);
	int rva00536E5B(AsciiString arg);
	int rva00535D75(AsciiString arg);
	int rva00535E06(AsciiString arg);
	int rva00535E97(AsciiString arg);
	int rva00535F28(AsciiString arg);
	void rva0053595E(AsciiString arg, float x);
	float rva0053590D(AsciiString arg);
	float rva005359A9(AsciiString arg);
	float rva00535A45(AsciiString arg);
	float rva00535AE1(AsciiString arg);
	void rva005359FA(AsciiString arg, float x);
	void rva00535A96(AsciiString arg, float x);
};

static const char *kFactions[] = { "Men", "Elves", "Dwarves", "Isengard", "Mordor", "Wild" };

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

void UserPreferences::rva00535D2E(AsciiString arg, int x)
{
	arg.concat("WinStreak");
	v11(arg, x);
}

void UserPreferences::rva00535DBF(AsciiString arg, int x)
{
	arg.concat("LossStreak");
	v11(arg, x);
}

void UserPreferences::rva00535E50(AsciiString arg, int x)
{
	arg.concat("BestWinStreak");
	v11(arg, x);
}

void UserPreferences::rva00535EE1(AsciiString arg, int x)
{
	arg.concat("WorstLossStreak");
	v11(arg, x);
}

void UserPreferences::rva00535F72(int x)
{
	AsciiString tmp("OverallWinStreak");
	v11(tmp, x);
}

int UserPreferences::rva00535FBA()
{
	AsciiString tmp("OverallWinStreak");
	int ret = v6(tmp, 0);
	return ret;
}

int UserPreferences::rva005358C3(AsciiString arg)
{
	arg.concat("Points");
	int ret = v6(arg, 0);
	return ret;
}

int UserPreferences::rva00535BF6(AsciiString arg)
{
	arg.concat("Wins");
	int ret = v6(arg, 0);
	return ret;
}

int UserPreferences::rva00535C40()
{
	AsciiString dummy;
	int sum = 0;
	for (int i = 0; i < 6; ++i)
		sum += rva00535BF6(AsciiString(kFactions[i]));
	return sum;
}

int UserPreferences::rva005373AF()
{
	AsciiString dummy;
	int sum = 0;
	for (int i = 0; i < 6; ++i)
		sum += rva00535CE4(AsciiString(kFactions[i]));
	return sum;
}

int UserPreferences::rva0053734E(AsciiString arg)
{
	int wins = rva00535BF6(arg);
	int losses = rva00535CE4(arg);
	return wins + losses;
}

int UserPreferences::rva00537C28()
{
	int losses = rva005373AF();
	int wins = rva00535C40();
	return losses + wins;
}

void UserPreferences::rva00536C61(AsciiString arg, int x)
{
	arg.concat("BattlesLostRTS");
	v11(arg, x);
}

int UserPreferences::rva00536CA8(AsciiString arg)
{
	arg.concat("BattlesLostRTS");
	int ret = v6(arg, 0);
	return ret;
}

void UserPreferences::rva00536CF2(AsciiString arg, int x)
{
	arg.concat("BattlesWonRTS");
	v11(arg, x);
}

int UserPreferences::rva00536D39(AsciiString arg)
{
	arg.concat("BattlesWonRTS");
	int ret = v6(arg, 0);
	return ret;
}

void UserPreferences::rva00536D83(AsciiString arg, int x)
{
	arg.concat("BattlesLostAutoResolve");
	v11(arg, x);
}

int UserPreferences::rva00536DCA(AsciiString arg)
{
	arg.concat("BattlesLostAutoResolve");
	int ret = v6(arg, 0);
	return ret;
}

void UserPreferences::rva00536E14(AsciiString arg, int x)
{
	arg.concat("BattlesWonAutoResolve");
	v11(arg, x);
}

int UserPreferences::rva00536E5B(AsciiString arg)
{
	arg.concat("BattlesWonAutoResolve");
	int ret = v6(arg, 0);
	return ret;
}

int UserPreferences::rva00535D75(AsciiString arg)
{
	arg.concat("WinStreak");
	int ret = v6(arg, 0);
	return ret;
}

int UserPreferences::rva00535E06(AsciiString arg)
{
	arg.concat("LossStreak");
	int ret = v6(arg, 0);
	return ret;
}

int UserPreferences::rva00535E97(AsciiString arg)
{
	arg.concat("BestWinStreak");
	int ret = v6(arg, 0);
	return ret;
}

int UserPreferences::rva00535F28(AsciiString arg)
{
	arg.concat("WorstLossStreak");
	int ret = v6(arg, 0);
	return ret;
}

void UserPreferences::rva0053595E(AsciiString arg, float x)
{
	arg.concat("LongestGameTime");
	v10(arg, x);
}

float UserPreferences::rva0053590D(AsciiString arg)
{
	arg.concat("TimePlayed");
	float ret = v5(arg, 0.0f);
	return ret;
}

float UserPreferences::rva005359A9(AsciiString arg)
{
	arg.concat("LongestGameTime");
	float ret = v5(arg, 0.0f);
	return ret;
}

float UserPreferences::rva00535A45(AsciiString arg)
{
	arg.concat("ShortestGameTime");
	float ret = v5(arg, 0.0f);
	return ret;
}

float UserPreferences::rva00535AE1(AsciiString arg)
{
	arg.concat("AverageGameTime");
	float ret = v5(arg, 0.0f);
	return ret;
}

void UserPreferences::rva005359FA(AsciiString arg, float x)
{
	arg.concat("ShortestGameTime");
	v10(arg, x);
}

void UserPreferences::rva00535A96(AsciiString arg, float x)
{
	arg.concat("AverageGameTime");
	v10(arg, x);
}
