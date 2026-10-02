// cl: /DNDEBUG /MD /EHsc /arch:SSE2 /O1
// ZH donor: GeneralsMD ScriptConditions.cpp evaluateTeamStateIs and
// evaluateTeamStateIsNot. Target evidence: the evaluateCondition jump table
// (0x007EC5C0) sends cases 11 and 12 to 0x003E9471 and 0x003E94E5, which
// initConditionTemplates names TEAM_STATE_IS and TEAM_STATE_IS_NOT; both
// compare the team state string at +0x44 with a copied parameter string via
// the rowed StringBase<char>::compare 0x000069D6.
// Private AsciiString/StringBase (not the shared header), as in
// SidesList_findSideInfo.cpp: retail stores no EH state for the copied name
// around the compare call, which needs compare declared throw().

template <typename T> class StringBase
{
	friend class AsciiString;

public:
	int compare(const StringBase &s) const throw();

private:
	StringBase(const StringBase &s);
	void releaseBuffer();

	void *m_data;
};

class AsciiString
{
public:
	AsciiString(const AsciiString &s)
	{
		((StringBase<char> *)this)->StringBase<char>::StringBase(*(const StringBase<char> *)&s);
	}
	~AsciiString() { ((StringBase<char> *)this)->releaseBuffer(); }
	int compare(const AsciiString &s) const throw()
	{
		return ((const StringBase<char> *)this)->compare(*(const StringBase<char> *)&s);
	}

private:
	char *m_text;
};

inline bool operator==(const AsciiString &a, const AsciiString &b) { return a.compare(b) == 0; }

class Parameter
{
public:
	const AsciiString &getString() const { return m_string; }
	unsigned char m_beforeInt[8]; int m_int; float m_real; AsciiString m_string;
	unsigned char m_afterString[8];
};
class Team
{
public:
	const AsciiString &getState() const { return m_state; }
	unsigned char m_pad00[0x44];
	AsciiString m_state;
};
class ScriptEngine
{
public:
	Team *getTeamNamed(AsciiString, bool);
};
extern ScriptEngine *TheScriptEngine;
class ScriptConditions
{
protected:
	bool evaluateTeamStateIs(Parameter *, Parameter *);
	bool evaluateTeamStateIsNot(Parameter *, Parameter *);
};
bool ScriptConditions::evaluateTeamStateIs(Parameter *pTeamParm, Parameter *pStateParm)
{
	Team *theTeam = TheScriptEngine->getTeamNamed(pTeamParm->getString(), false);
	AsciiString stateName = pStateParm->getString();
	if (theTeam) {
		return (theTeam->getState() == stateName);
	}
	return false;
}
bool ScriptConditions::evaluateTeamStateIsNot(Parameter *pTeamParm, Parameter *pStateParm)
{
	Team *theTeam = TheScriptEngine->getTeamNamed(pTeamParm->getString(), false);
	AsciiString stateName = pStateParm->getString();
	if (theTeam) {
		return (!(theTeam->getState() == stateName));
	}
	return false;
}
