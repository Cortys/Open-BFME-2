// ?rva003C0E32@ScriptActions@@IAEXABVAsciiString@@H@Z
// partial score=0.93 date=2026-10-01
// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD /EHsc
// ?rva003C0E32@ScriptActions@@IAEXABVAsciiString@@H@Z, retail 0x003C0E32 85 bytes.
// Target evidence: ScriptActions dispatch caller at 0x003CD166, AsciiString temp via
// pinned StringBase copy 0x000365F0, ScriptEngine global 0x009FE16C, pinned
// lookupUnitByValue 0x00358752, Object module list at +0x244 with +0x0C iface slot
// 0x40 then slot 0 with int arg, ret 8. Prev/next ScriptActions share flags.
// Donor facts: BFME1 ScriptActions team/unit patterns plus Object +0x244 module
// array precedent; honest address name, second arg int per neighbour shape.
#include "ascii_string.h"

class ScriptEngine;
extern ScriptEngine *g_Va009FE16C;

class Rva00358752Opaque
{
public:
    class Object *lookupUnitByValue(AsciiString);
};

class ActionTarget
{
public:
    virtual void apply(int value);
};

class ModIface
{
public:
    virtual void s00();
    virtual void s01();
    virtual void s02();
    virtual void s03();
    virtual void s04();
    virtual void s05();
    virtual void s06();
    virtual void s07();
    virtual void s08();
    virtual void s09();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual ActionTarget *slot16();
};

class ModBase
{
public:
    virtual void s00();

private:
    unsigned int m_data[2];
};

class Module : public ModBase, public ModIface
{
};

class Object
{
public:
    char m_pad[0x244];
    Module **m_modules;
};

class ScriptActions
{
protected:
    void rva003C0E32(const AsciiString &, int);
};

// ?rva003C0E32@ScriptActions@@IAEXABVAsciiString@@H@Z present-unmatched
void ScriptActions::rva003C0E32(const AsciiString &name, int value)
{
    Object *obj = ((Rva00358752Opaque *)g_Va009FE16C)->lookupUnitByValue(name);
    if (obj) {
        Module **pp = obj->m_modules;
        ActionTarget *found = 0;
        for (;;) {
            Module *m = *pp;
            if (!m) {
                found = 0;
                break;
            }
            ActionTarget *r = m->slot16();
            if (r) {
                found = r;
                break;
            }
            ++pp;
        }
        if (found) {
            found->apply(value);
        }
    }
}
