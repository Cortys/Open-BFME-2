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
    char unknown[0x10];
public:
    ~Rva004E2E58();
};

class Rva003EF14ASecondary {
public:
    virtual void slot0();
    // ?Rva003EF14ASecondary::~Rva003EF14ASecondary present-unmatched
    ~Rva003EF14ASecondary() {}
};

class Rva003EF14A : public Rva003EF14ABase {
    void *unknown04;
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
