// cl: /MD /D_STLP_USE_STATIC_LIB
// stlport

extern const char g_Rva0107301CEmptyString[];

struct Rva0084DBText
{
    char unused[0x14];
    const char *text;
};

const char *Rva0084DBC0GetText(const Rva0084DBText *owner)
{
    const char *text = owner->text;
    return text ? text : g_Rva0107301CEmptyString;
}

const char *Rva0084DC40GetText(const Rva0084DBText *owner)
{
    const char *text = owner->text;
    return text ? text : g_Rva0107301CEmptyString;
}

struct Rva0084D860CodePage
{
    unsigned int unknown;
    unsigned int codePage;
};

struct Rva0084D860CpInfo
{
    unsigned int MaxCharSize;
    unsigned char remainder[16];
};
// The target IAT identifies kernel32!GetCPInfo; the BFME1 C++ declaration
// lacked C linkage and compiled an unresolved C++-mangled import reference.
extern "C" __declspec(dllimport) int __stdcall GetCPInfo(unsigned int, Rva0084D860CpInfo *);

bool Rva0084D860IsSingleByte(const Rva0084D860CodePage *owner)
{
    Rva0084D860CpInfo info;
    GetCPInfo(owner->codePage, &info);
    return info.MaxCharSize == 1;
}

// Target 0x00020AF0: address-derived name because the BFME1 donor is an ICF twin.
unsigned int Rva00020AF0(const Rva0084D860CodePage *owner)
{
    Rva0084D860CpInfo info;
    if (GetCPInfo(owner->codePage, &info))
        return info.MaxCharSize;
    return 0;
}
