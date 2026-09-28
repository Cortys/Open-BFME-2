// cl: /DNDEBUG /MD /EHsc /O1
//
// ScriptActions::doTeamAvailableForRecruitment, retail 0x003C01AB, 55 bytes.
// Target evidence: action template 0x5E is TEAM_AVAILABLE_FOR_RECRUITMENT and
// executeAction calls VA 0x007C01AB; Ghidra boundary is 0x003C01AB/55. Retail
// copies the team name through the pinned StringBase copy constructor and uses
// the pinned ScriptEngine::getTeamNamed body. On success it writes byte +0x110
// to 1 and byte +0x111 to the requested availability value.
// Donor facts: BFME1 ScriptActions.cpp maps this action to
// doTeamAvailableForRecruitment and calls Team::setRecruitable. Target-backed
// writes establish only the two byte offsets and values.

typedef bool Bool;

template <class T>
class StringBase
{
    friend class AsciiString;

private:
    StringBase(const StringBase &);
    ~StringBase();
    void *m_buffer;
};

class AsciiString : public StringBase<char>
{
public:
    AsciiString &operator=(const AsciiString &);
};

class Team
{
public:
    void setRecruitable(Bool availability)
    {
        m_recruitable = 1;
        m_available = availability;
    }

private:
    char m_pad[0x110];
    unsigned char m_recruitable;
    unsigned char m_available;
};

class ScriptEngine
{
public:
    Team *getTeamNamed(AsciiString team, Bool exact);
};

class ScriptActions
{
protected:
    void doTeamAvailableForRecruitment(const AsciiString &, Bool);
};

void ScriptActions::doTeamAvailableForRecruitment(const AsciiString &teamName, Bool availability)
{
    Team *theTeam = (*(ScriptEngine **)0x00DFE16C)->getTeamNamed(teamName, false);
    if (!theTeam) {
        return;
    }
    theTeam->setRecruitable(availability);
}
