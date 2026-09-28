// cl: /O1 /DNDEBUG /MD /EHsc
// Retail RVA 0x003C0F09, 59 bytes.
// ?rva003C0F09@ScriptActions@@IAEXABVAsciiString@@H@Z
// Honest address name: ScriptActions team method dispatched from FUN_007ca4be
// (caller at 0x003CD35E). No donor found (BFME1 doTeamSetRepulsor iterates
// members instead). Target evidence: getTeamNamed pin 0x003584E9 with the
// by-value AsciiString temp pattern, then two flag bytes on Team at +0x110
// (set to 1) and +0x111 (set to (param != 0)).
// Prev doTeamExitAll / next doTeamSpinForFramecount share flags and patterns.
template<class T> class StringBase
{
    friend class AsciiString;
    StringBase(const StringBase &);
};
class AsciiString
{
public:
    AsciiString(const AsciiString &that)
    {
        ((StringBase<char> *)this)->StringBase<char>::StringBase(
            *(const StringBase<char> *)&that);
    }
    ~AsciiString();
private:
    char *m_text;
};
typedef bool Bool;

class Team
{
public:
    char m_pad[0x110];
    bool m_unk110;
    bool m_unk111;
};

class ScriptEngine
{
public:
    Team *getTeamNamed(AsciiString, Bool);
};

class ScriptActions
{
protected:
    void rva003C0F09(const AsciiString &, int);
};

void ScriptActions::rva003C0F09(const AsciiString &teamName, int value)
{
    Team *team = (*(ScriptEngine **)0x00DFE16C)->getTeamNamed((AsciiString &)teamName, false);
    if (!team)
        return;
    team->m_unk110 = true;
    team->m_unk111 = (value != 0);
}
