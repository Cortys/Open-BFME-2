// cl: /O1 /DNDEBUG /MD /EHsc
//
// ?getUnitNamed@ScriptEngine@@QAEPAVObject@@PAVParameter@@@Z
// Retail 0x003588E7, 76 bytes.
//
// Target identity: ScriptEngine::getUnitNamed taking Parameter* at slot 26
// vtable+0x68. BFME1 ScriptConditionsCanBuildAtBase spells this slot taking
// Parameter* while ZH Scripts.h gives the Parameter layout with string at
// +0x10. Target reads ObjectID at Parameter+0x24 for findObjectByID at
// 0x49DC5 then string at +0x10 for isEmpty and by-value lookupUnitByValue
// at 0x358752. 40+ script callers pass Parameter* through this slot.
//
template<class T>
class StringBase
{
    friend class AsciiString;
    StringBase(const StringBase &);
public:
    bool isEmpty() const;
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
    bool isEmpty() const { return ((const StringBase<char> *)this)->isEmpty(); }
private:
    char *m_text;
};

class Object;
enum ObjectID
{
    INVALID_OBJECT_ID = 0
};

class GameLogic
{
public:
    Object *findObjectByID(ObjectID id);
};

#define TheGameLogic (*(GameLogic **)0x00DFE78C)

class Parameter
{
public:
    const AsciiString &getString() const { return m_string; }
    ObjectID getObjectID() const { return (ObjectID)m_objectID; }
private:
    int m_paramType; // +0x00
    char m_pad04[4]; // +0x04
    int m_int; // +0x08
    float m_real; // +0x0C
    AsciiString m_string; // +0x10
    char m_coord[12]; // +0x14
    int m_pad20; // +0x20
    int m_objectID; // +0x24
};

class Rva00358752Opaque
{
public:
    Object *lookupUnitByValue(AsciiString);
};

class ScriptEngine
{
public:
    Object *getUnitNamed(Parameter *);
};

Object *ScriptEngine::getUnitNamed(Parameter *p)
{
    ObjectID id = p->getObjectID();
    if (id != INVALID_OBJECT_ID) {
        Object *o = TheGameLogic->findObjectByID(id);
        if (o)
            return o;
    }
    const AsciiString &s = p->getString();
    if (s.isEmpty())
        return 0;
    return ((Rva00358752Opaque *)this)->lookupUnitByValue(s);
}
