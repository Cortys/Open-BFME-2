// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD /EHsc
// Target-only view of the complete 110B destructor at 0x003EF14A.
// The queue's Rva00382574 name is refuted by this body's different layout.
// Target facts: primary vptr C363C8; unregister this from global E02E88 via
// matched 2B7250; cleanup 3EE9F1(this); secondary vptr at +4C becomes
// C363B8; destroy narrow strings +1C/+18 via matched 36410; destroy the
// container at +8 through 4E2E58; restore primary base vptr BFDF68.
// Original class, container type, and member names remain unknown.
#include "ascii_string.h"

class CreateAHeroData;
class Rva002B7250 {
public:
    void rva002B7250(CreateAHeroData *);
};
extern Rva002B7250 g_registryAtE02E88;
extern const void *const g_vtableAtBFDF68[];

class Rva003EF14ABase {
public:
    virtual void slot0();
    // ?Rva003EF14ABase::~Rva003EF14ABase present-unmatched
    ~Rva003EF14ABase() { *(const void **)this = g_vtableAtBFDF68; }
};

class Rva004E2E58 {
    // Opaque span between the independently observed member at +8 and
    // string at +18. Its exact container extent is not yet established.
    char unknown[0x10];
public:
    ~Rva004E2E58();
    void rva004E21D5();
};

class Rva003EF14ASecondary {
public:
    virtual void slot0();
    // ?Rva003EF14ASecondary::~Rva003EF14ASecondary present-unmatched
    ~Rva003EF14ASecondary() {}
};

// Only the two called vslots and reference word are recovered. The names
// and signatures of unused slots remain opaque in this local call view.
class Rva003EE9F1Ref {
public:
    virtual void slot00() = 0;
    virtual void slot04() = 0;
    virtual void slot08() = 0;
    virtual void slot0C() = 0;
    virtual void slot10() = 0;
    virtual void slot14() = 0;
    virtual void slot18() = 0;
    virtual void slot1C() = 0;
    virtual void slot20() = 0;
    virtual void slot24() = 0;
    virtual void slot28() = 0;
    virtual void slot2C() = 0;
    virtual void slot30() = 0;
    virtual void slot34() = 0;
    virtual void slot38() = 0;
    virtual void slot3C() = 0;
    virtual void slot40() = 0;
    unsigned references;
    // ?Rva003EE9F1Ref::dropReference present-unmatched
    void dropReference() {
        if (--references == 0)
            slot00();
    }
};

class Rva003EF14A : public Rva003EF14ABase {
    Rva003EE9F1Ref *ref04;
    Rva004E2E58 container08;
    AsciiString string18;
    AsciiString string1C;
    char unknown20[0x2C];
    Rva003EF14ASecondary secondary4C;
public:
    virtual void slot0();
    ~Rva003EF14A();
    void rva003EE9F1();
};

Rva003EF14A::~Rva003EF14A()
{
    g_registryAtE02E88.rva002B7250((CreateAHeroData *)this);
    rva003EE9F1();
}

// Complete 41B body; cleans values in the +8 container, calls ref vslot
// +40, drops the +4 count, calls ref vslot 0 on zero, and clears this+4.
void Rva003EF14A::rva003EE9F1()
{
    container08.rva004E21D5();
    if (ref04) {
        ref04->slot40();
        ref04->dropReference();
        ref04 = 0;
    }
}
