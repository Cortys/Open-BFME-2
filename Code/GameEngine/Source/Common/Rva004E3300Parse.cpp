// cl: /O1 /DNDEBUG /DWIN32 /MD /EHsc
// ?Rva004E3300Parse@@YAXPAVINI@@PAVRva00566D7B@@@Z @ 0x004E3300 (130B).
// SplineCamera parse: null-check INI and out else throw INIException(3) with
// retail literal; temp Rva004E32F2 via rowed ctor 0x004E32D5, initFromINI
// 0x0002DE78 against table g_00C61FB8, append via rowed 0x00566D7B.
// Chain lane: temp ctor just landed. No callers.
struct FieldParse;

class INI
{
public:
    void initFromINI(void *what, const FieldParse *parseTable);
};

struct INIException
{
    char *mFailureMessage;
    int mErrorCode;
    INIException(int argCount, const char *format, ...);
    INIException(const INIException &that);
    ~INIException();
};

class RvaVec002B80CE
{
public:
    ~RvaVec002B80CE();
private:
    void *m_begin;
    void *m_end;
    void *m_storage;
};

class Rva004E32F2
{
public:
    Rva004E32F2();
    virtual ~Rva004E32F2() {}
private:
    int m_04;
    bool m_08;
    RvaVec002B80CE m_0C;
};

class Rva00566D7B
{
public:
    void rva00566D7B(const Rva004E32F2 &v);
};

extern const FieldParse g_00C61FB8;

void Rva004E3300Parse(INI *ini, Rva00566D7B *out)
{
    if (ini && out)
    {
        Rva004E32F2 tmp;
        ini->initFromINI(&tmp, &g_00C61FB8);
        out->rva00566D7B(tmp);
    }
    else
        throw INIException(3, "SplineCamera::ParseINIBlock::Invalid data passed in.");
}
