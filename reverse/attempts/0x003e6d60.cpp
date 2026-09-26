// ?evaluateNamedExitedArea@ScriptConditions@@IAE_NPAVParameter@@0@Z
// partial score=0.84 date=2026-09-26
// ?evaluateNamedExitedArea@ScriptConditions@@IAE_NPAVParameter@@0@Z
// cl: /DNDEBUG /MD /EHsc /arch:SSE2 /Oy-
// BFME1 donor: ScriptConditions.cpp.
typedef bool Bool;
template <class T> class StringBase
{ friend class AsciiString; private: StringBase(const StringBase &); ~StringBase(); };
class AsciiString
{
public:
    AsciiString(const AsciiString &that) { ((StringBase<char> *)this)->StringBase<char>::StringBase(*(const StringBase<char> *)&that); }
    ~AsciiString();
private: char *m_text;
};
class Parameter
{
public:
    const AsciiString &getString() const { return m_string; }
    unsigned char m_beforeInt[8]; int m_int; float m_real; AsciiString m_string;
    unsigned char m_afterString[8];
};
class PolygonTrigger;
class Object { public: Bool didExit(PolygonTrigger *); };
class ScriptEngine
{ public: Object *getUnitNamed(Parameter *); PolygonTrigger *getQualifiedTriggerAreaByName(AsciiString); };
class ScriptConditions
{ protected: Bool evaluateNamedExitedArea(Parameter *, Parameter *); };
#define TheScriptEngine (*(ScriptEngine **)0x00DFE16C)
Bool ScriptConditions::evaluateNamedExitedArea(Parameter *unitParm, Parameter *triggerParm)
{
    Object *unit = TheScriptEngine->getUnitNamed(unitParm);
    if (!unit) return false;
    PolygonTrigger *trigger = TheScriptEngine->getQualifiedTriggerAreaByName(triggerParm->getString());
    if (!trigger) return false;
    return unit->didExit(trigger);
}
