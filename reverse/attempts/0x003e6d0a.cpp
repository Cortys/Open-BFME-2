// ?evaluateNamedEnteredArea@ScriptConditions@@IAE_NPAVParameter@@0@Z
// partial score=0.85 date=2026-09-26
// cl: /DNDEBUG /MD /EHsc /arch:SSE2 /Oy-
// BFME1 donor: evaluateNamedEnteredArea; retail inert-kind test is inlined.
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
class Object
{
public:
    bool isKindOfInert() const
    {
        const char *drawable = *(const char * const *)((const char *)this + 4);
        return (*(const unsigned char *)(drawable + 0x113) & 2) != 0;
    }
    Bool didEnter(PolygonTrigger *);
};
class ScriptEngine
{ public: Object *getUnitNamed(Parameter *); PolygonTrigger *getQualifiedTriggerAreaByName(AsciiString); };
class ScriptConditions
{ protected: Bool evaluateNamedEnteredArea(Parameter *, Parameter *); };
#define TheScriptEngine (*(ScriptEngine **)0x00DFE16C)
Bool ScriptConditions::evaluateNamedEnteredArea(Parameter *unitParm, Parameter *triggerParm)
{
    ScriptEngine *engine = TheScriptEngine;
    Object *unit = engine->getUnitNamed(unitParm);
    if (!unit || unit->isKindOfInert())
        return false;
    engine = TheScriptEngine;
    PolygonTrigger *trigger = engine->getQualifiedTriggerAreaByName(triggerParm->getString());
    if (!trigger)
        return false;
    return unit->didEnter(trigger);
}
