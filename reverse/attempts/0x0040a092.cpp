// ?Rva0040A092Parse@@YAXPAVINI@@PAXPAPBVCommandButton@@H@Z
// partial score=0.99 date=2026-10-01
// cl: /Ireference/shims/bfme2_ascii /O1 /Ob2 /EHs /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// ?Rva0040A092Parse@@YAXPAVINI@@PAXPAPBVCommandButton@@H@Z @0x0040A092 173B
// Evidence: chain lane; calls rowed findCommandButton 0x0031BE3C via g_bfmeWorldRV, INI getNextToken 0x2DF97 getFilename 0x2C005 getLineNum 0x2BBED, INIException 0x2F681 throw via pinned _CxxThrowException; stores found button into out[index]; prev Rva00409FCC.cpp same flags/layout.
#include "ascii_string.h"

class INI
{
public:
    const char *getNextToken(const char *delim);
    AsciiString getFilename() const;
    int getLineNum() const;
};

class CommandButton
{
};

class ControlBar
{
public:
    const CommandButton *findCommandButton(const AsciiString &name);
};

struct BfmeWorldRV;
extern struct BfmeWorldRV *g_bfmeWorldRV;
extern const char g_00C39070[];

class INIException
{
public:
    char *mFailureMessage;
    int m_argCount;
    INIException(int argCount, const char *format, ...);
    INIException(const INIException &that);
    ~INIException();
    INIException &operator=(const INIException &that);
};

// ?Rva0040A092Parse@@YAXPAVINI@@PAXPAPBVCommandButton@@H@Z present-unmatched
void Rva0040A092Parse(INI *ini, void *unused, const CommandButton **out, int index)
{
    const char *token = ini->getNextToken(0);
    const CommandButton *found;
    {
        AsciiString tmp(token);
        found = ((ControlBar *)(void *)g_bfmeWorldRV)->findCommandButton(tmp);
    }
    if (found == 0) {
        const AsciiString filename = ini->getFilename();
        const char *fname = filename.str();
        int line = ini->getLineNum();
        throw INIException(3, g_00C39070, token, fname, line);
    }
    out[index] = found;
}
