// cl: /O2 /MD
// PC predicates named by the corresponding checked-cast assertion strings.
// Signed seven-bit type occupies bits25..31; this is PC evidence, not PDB layout.
extern void (__cdecl *g_bfmeAptAssertAtE17734)(const char *, const char *, int);
extern int g_bfmeAptBreakOnAssertAtDDC01C;
void __debugbreak();
#pragma intrinsic(__debugbreak)
class BfmeAptValue006DCD20 {
    virtual void vtableSlot0();
    struct { unsigned int unknown : 25; int type : 7; } flags;
public:
    bool isUndefined() const;
    int isLookup() const;
    int isInteger() const;
    int isRegister() const;
    int isFloat() const;
    int isString() const;
    int isBoolean() const;
    int isNativeFunction() const;
    int isScriptFunction() const;
    int isDate() const;
    int isKey() const;
    int isMath() const;
    int isScriptColour() const;
    int isObject() const;
    int isPrototype() const;
    int isTextFormat() const;
    int isMovieClip() const;
    int isStage() const;
};
// Corresponding checked casts at 6DCD50/90/D0 and 6DCE10/50 assert these
// exact predicate names. Type numbers are independently decoded from PC.
// Godfather final PDB corroborates names but is structurally incompatible:
// its AptValue is4B and enum ends36; PC stores flags+4 and permits types<47.
// In particular PC isString accepts1 or42; do not copy the other enum wholesale.

int BfmeAptValue006DCD20::isLookup() const
{
    if (!this) {
        g_bfmeAptAssertAtE17734("this","c:\\projects\\bfme2patch103\\bfme2\\code\\libraries\\source\\apt\\AptValue/AptValue.inl",1459);
        if (g_bfmeAptBreakOnAssertAtDDC01C) __debugbreak();
    }
    if (flags.type == 8 && !isUndefined()) return 1;
    return 0;
}

int BfmeAptValue006DCD20::isInteger() const
{
    if (!this) {
        g_bfmeAptAssertAtE17734("this","c:\\projects\\bfme2patch103\\bfme2\\code\\libraries\\source\\apt\\AptValue/AptValue.inl",1535);
        if (g_bfmeAptBreakOnAssertAtDDC01C) __debugbreak();
    }
    if (flags.type == 7 && !isUndefined()) return 1;
    return 0;
}

int BfmeAptValue006DCD20::isRegister() const
{
    if (!this) {
        g_bfmeAptAssertAtE17734("this","c:\\projects\\bfme2patch103\\bfme2\\code\\libraries\\source\\apt\\AptValue/AptValue.inl",1560);
        if (g_bfmeAptBreakOnAssertAtDDC01C) __debugbreak();
    }
    if (flags.type == 4 && !isUndefined()) return 1;
    return 0;
}

int BfmeAptValue006DCD20::isFloat() const
{
    if (!this) {
        g_bfmeAptAssertAtE17734("this","c:\\projects\\bfme2patch103\\bfme2\\code\\libraries\\source\\apt\\AptValue/AptValue.inl",1585);
        if (g_bfmeAptBreakOnAssertAtDDC01C) __debugbreak();
    }
    if (flags.type == 6 && !isUndefined()) return 1;
    return 0;
}

int BfmeAptValue006DCD20::isString() const
{
    if (!this) {
        g_bfmeAptAssertAtE17734("this","c:\\projects\\bfme2patch103\\bfme2\\code\\libraries\\source\\apt\\AptValue/AptValue.inl",1484);
        if (g_bfmeAptBreakOnAssertAtDDC01C) __debugbreak();
    }
    if ((flags.type == 1 || flags.type == 42) && !isUndefined()) return 1;
    return 0;
}

int BfmeAptValue006DCD20::isBoolean() const
{
    if (!this) {
        g_bfmeAptAssertAtE17734("this","c:\\projects\\bfme2patch103\\bfme2\\code\\libraries\\source\\apt\\AptValue/AptValue.inl",1510);
        if (g_bfmeAptBreakOnAssertAtDDC01C) __debugbreak();
    }
    if (flags.type == 5 && !isUndefined()) return 1;
    return 0;
}

int BfmeAptValue006DCD20::isNativeFunction() const
{
    if (!this) {
        g_bfmeAptAssertAtE17734("this","c:\\projects\\bfme2patch103\\bfme2\\code\\libraries\\source\\apt\\AptValue/AptValue.inl",1610);
        if (g_bfmeAptBreakOnAssertAtDDC01C) __debugbreak();
    }
    if (flags.type == 9 && !isUndefined()) return 1;
    return 0;
}

int BfmeAptValue006DCD20::isScriptFunction() const
{
    if (!this) {
        g_bfmeAptAssertAtE17734("this","c:\\projects\\bfme2patch103\\bfme2\\code\\libraries\\source\\apt\\AptValue/AptValue.inl",1635);
        if (g_bfmeAptBreakOnAssertAtDDC01C) __debugbreak();
    }
    if (flags.type >= 43 && flags.type <= 45 && !isUndefined()) return 1;
    return 0;
}

int BfmeAptValue006DCD20::isDate() const
{
    if (!this) {
        g_bfmeAptAssertAtE17734("this","c:\\projects\\bfme2patch103\\bfme2\\code\\libraries\\source\\apt\\AptValue/AptValue.inl",1944);
        if (g_bfmeAptBreakOnAssertAtDDC01C) __debugbreak();
    }
    if (flags.type == 29 && !isUndefined()) return 1;
    return 0;
}

// ?isKey@BfmeAptValue006DCD20@@QBEHXZ, retail 0x006DC440, 78 bytes.
// Predicate for type 24 (0x30000000), "this" assert at AptValue.inl:1763.
// Evidence: caller 0x006DD020 asserts "isKey()" after calling it; second caller
// 0x006EACE2; same /O2 shape as isDate/isBoolean siblings in this TU.
int BfmeAptValue006DCD20::isKey() const
{
    if (!this) {
        g_bfmeAptAssertAtE17734("this","c:\\projects\\bfme2patch103\\bfme2\\code\\libraries\\source\\apt\\AptValue/AptValue.inl",1763);
        if (g_bfmeAptBreakOnAssertAtDDC01C) __debugbreak();
    }
    if (flags.type == 24 && !isUndefined()) return 1;
    return 0;
}

// ?isMath@BfmeAptValue006DCD20@@QBEHXZ, retail 0x006DC4E0, 78 bytes.
// Predicate for type 23 (0x2E000000), "this" assert at AptValue.inl:1816.
// Evidence: caller 0x006DD060 asserts "isMath()" after calling it;
// same /O2 shape as siblings in this TU.
int BfmeAptValue006DCD20::isMath() const
{
    if (!this) {
        g_bfmeAptAssertAtE17734("this","c:\\projects\\bfme2patch103\\bfme2\\code\\libraries\\source\\apt\\AptValue/AptValue.inl",1816);
        if (g_bfmeAptBreakOnAssertAtDDC01C) __debugbreak();
    }
    if (flags.type == 23 && !isUndefined()) return 1;
    return 0;
}

// ?isScriptColour@BfmeAptValue006DCD20@@QBEHXZ, retail 0x006DC530, 78 bytes.
// Predicate for type 26 (0x34000000), "this" assert at AptValue.inl:1843.
// Evidence: caller 0x006DD0A0 asserts "isScriptColour()" after calling it;
// same /O2 shape as siblings in this TU.
int BfmeAptValue006DCD20::isScriptColour() const
{
    if (!this) {
        g_bfmeAptAssertAtE17734("this","c:\\projects\\bfme2patch103\\bfme2\\code\\libraries\\source\\apt\\AptValue/AptValue.inl",1843);
        if (g_bfmeAptBreakOnAssertAtDDC01C) __debugbreak();
    }
    if (flags.type == 26 && !isUndefined()) return 1;
    return 0;
}

// ?isObject@BfmeAptValue006DCD20@@QBEHXZ, retail 0x006DC5E0, 78 bytes.
// Predicate for type 27 (0x36000000), "this" assert at AptValue.inl:1894.
// Evidence: caller 0x006DD0E0 asserts "isObject()" after calling it;
// same /O2 shape as siblings in this TU.
int BfmeAptValue006DCD20::isObject() const
{
    if (!this) {
        g_bfmeAptAssertAtE17734("this","c:\\projects\\bfme2patch103\\bfme2\\code\\libraries\\source\\apt\\AptValue/AptValue.inl",1894);
        if (g_bfmeAptBreakOnAssertAtDDC01C) __debugbreak();
    }
    if (flags.type == 27 && !isUndefined()) return 1;
    return 0;
}

// ?isPrototype@BfmeAptValue006DCD20@@QBEHXZ, retail 0x006DC630, 78 bytes.
// Predicate for type 28 (0x38000000), "this" assert at AptValue.inl:1919.
// Evidence: caller 0x006DD120 asserts "isPrototype()" after calling it;
// same /O2 shape as siblings in this TU.
int BfmeAptValue006DCD20::isPrototype() const
{
    if (!this) {
        g_bfmeAptAssertAtE17734("this","c:\\projects\\bfme2patch103\\bfme2\\code\\libraries\\source\\apt\\AptValue/AptValue.inl",1919);
        if (g_bfmeAptBreakOnAssertAtDDC01C) __debugbreak();
    }
    if (flags.type == 28 && !isUndefined()) return 1;
    return 0;
}

// ?isTextFormat@BfmeAptValue006DCD20@@QBEHXZ, retail 0x006DC6D0, 78 bytes.
// Predicate for type 36 (0x48000000), "this" assert at AptValue.inl:1969.
// Evidence: caller 0x006DD1A0 asserts "isTextFormat()" after calling it;
// same /O2 shape as siblings in this TU.
int BfmeAptValue006DCD20::isTextFormat() const
{
    if (!this) {
        g_bfmeAptAssertAtE17734("this","c:\\projects\\bfme2patch103\\bfme2\\code\\libraries\\source\\apt\\AptValue/AptValue.inl",1969);
        if (g_bfmeAptBreakOnAssertAtDDC01C) __debugbreak();
    }
    if (flags.type == 36 && !isUndefined()) return 1;
    return 0;
}

// ?isMovieClip@BfmeAptValue006DCD20@@QBEHXZ, retail 0x006DC720, 78 bytes.
// Predicate for type 30 (0x3C000000), "this" assert at AptValue.inl:1994.
// Evidence: caller 0x006DD1E0 asserts "isMovieClip()" after calling it;
// same /O2 shape as siblings in this TU.
int BfmeAptValue006DCD20::isMovieClip() const
{
    if (!this) {
        g_bfmeAptAssertAtE17734("this","c:\\projects\\bfme2patch103\\bfme2\\code\\libraries\\source\\apt\\AptValue/AptValue.inl",1994);
        if (g_bfmeAptBreakOnAssertAtDDC01C) __debugbreak();
    }
    if (flags.type == 30 && !isUndefined()) return 1;
    return 0;
}

// ?isStage@BfmeAptValue006DCD20@@QBEHXZ, retail 0x006DC770, 78 bytes.
// Predicate for type 39 (0x4E000000), "this" assert at AptValue.inl:2021.
// Evidence: caller 0x006DD320 asserts "isStage()" after calling it;
// same /O2 shape as siblings in this TU.
int BfmeAptValue006DCD20::isStage() const
{
    if (!this) {
        g_bfmeAptAssertAtE17734("this","c:\\projects\\bfme2patch103\\bfme2\\code\\libraries\\source\\apt\\AptValue/AptValue.inl",2021);
        if (g_bfmeAptBreakOnAssertAtDDC01C) __debugbreak();
    }
    if (flags.type == 39 && !isUndefined()) return 1;
    return 0;
}
