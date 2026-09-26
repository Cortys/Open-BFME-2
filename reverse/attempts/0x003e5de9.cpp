// ?evaluateIsDestroyed@ScriptConditions@@IAE_NPAVParameter@@@Z
// partial score=0.82 date=2026-09-26
// cl: /O2 /EHsc
// Target-side adaptation of the BFME1 ScriptConditions::evaluateIsDestroyed
// body. Identity is supported by the retail condition dispatcher, the target
// getTeamNamed call shape, the Team readiness field and the hasAnyObjects call.

typedef bool Bool;

class AsciiString
{
public:
	AsciiString(const AsciiString &that);
	~AsciiString();
};

class Parameter
{
public:
	const AsciiString &getString() const
	{
		return *(const AsciiString *)(m_bytes + 0x10);
	}

private:
	char m_bytes[0x14];
};

class Team
{
public:
	Bool isReady() const { return m_ready; }
	Bool hasAnyObjects(Bool includeDead);

private:
	char m_pad[0x128];
	Bool m_ready;
};

class ScriptEngine
{
public:
	Team *getTeamNamed(AsciiString name, Bool exact);
};

#define TheScriptEngine (*(ScriptEngine **)0x00DFE16C)

class ScriptConditions
{
	protected:
	Bool evaluateIsDestroyed(Parameter *pTeamParm);
};

Bool ScriptConditions::evaluateIsDestroyed(Parameter *pTeamParm)
{
	Team *theTeam = TheScriptEngine->getTeamNamed(pTeamParm->getString(), false);
	if (theTeam) {
		if (!theTeam->isReady())
			return false;
		return !theTeam->hasAnyObjects(false);
	}
	return false;
}
