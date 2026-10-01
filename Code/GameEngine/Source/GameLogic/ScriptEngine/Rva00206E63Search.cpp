// cl: /Ireference/shims/bfme2_ascii /O1 /EHsc /MD
//
// ?Rva00206E63Search@@YAXPAVINI@@@Z @0x00206E63 100B: chain sibling of 0x00206DFF.
// Builds local Rva003B39C7 via ctor 0x003B39C7, initFromINI with table
// g_00BE3908, then if g_Va009FE16C is set calls Rva00205A8D::rva00205A8D with
// the local as Arg205A8D, then dtor 0x002045AB. Evidence: packet disassembly
// identical to 0x00206DFF except callee 0x00205A8D; Arg layout same strings.

#include "ascii_string.h"

struct FieldParse;
class INI
{
public:
    void initFromINI(void *what, const FieldParse *table);
};

struct Rva003B39C7
{
    int m00;
    AsciiString m04;
    AsciiString m08;
    AsciiString m0C;
    int m10;
    int m14;
    AsciiString m18[12];
    int m48;
    int m4C[12];
    AsciiString m7C;
    Rva003B39C7();
    ~Rva003B39C7();
};

extern const FieldParse g_00BE3908[];

struct Arg205A8D
{
    char _pad0[4];
    AsciiString m_4;
    AsciiString m_8;
    AsciiString m_C;
    char _pad10[0x7c - 0x10];
    AsciiString m_7c;
};

class Rva00205A8D
{
public:
    void rva00205A8D(Arg205A8D *arg);
};

class ScriptEngine;
extern ScriptEngine *g_Va009FE16C;

void __cdecl Rva00206E63Search(INI *ini)
{
    Rva003B39C7 tmp;
    ini->initFromINI(&tmp, g_00BE3908);
    if (g_Va009FE16C)
        ((Rva00205A8D *)g_Va009FE16C)->rva00205A8D((Arg205A8D *)&tmp);
}
