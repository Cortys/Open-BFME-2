// ?rva007097B0@AptScriptFunctionBase@@SAHPAX@Z
// partial score=0.97 date=2026-10-04
// ?rva007097B0@AptScriptFunctionBase@@SAHPAX@Z
// partial score=0.97 date=2026-10-01
// ?rva007097B0@AptScriptFunctionBase@@SAHPAX@Z
// partial score=0.97 date=2026-10-01
// cl: /O2 /MD
// APT0.19.03 May2006 Xbox release donor supplies class and method spellings.
// Target assertions name AptObject/AptScriptFunction.cpp and independently name
// spRegBlockBase (VA E1834C), spRegBlockCurrentFrameBase (E18350),
// snRegBlockCurrentFrameCount (E18354) and gpUndefinedValue (E18078).
// Signed loop bound E18358 is named snRegisterBlockSize by donor PDB only.
// Target Shutdown calls the already matched scalar operator delete at 2FD60.
// Initialize709610+91 uses the same globals and matched operator new2FDA0.
// AptInitParmsT::iRegArraySize name comes from final donor TPI2DEF; target
// independently loads a signed dword at+30. Only that parameter prefix is modeled.
// Target full spans709670+190 /709730+117 agree with donor records and returns.
extern void (__cdecl *g_bfmeAptAssertAtE17734)(const char *,const char *,int);
extern int g_bfmeAptBreakOnAssertAtDDC01C;
void __debugbreak();
#pragma intrinsic(__debugbreak)
class AptValue
{
public:
	virtual void AddRef();
	virtual void Release();
};
struct AptInitParmsT { unsigned char unaccessed[48]; int iRegArraySize; };
void *__cdecl operator new(unsigned int);
extern AptValue *gpUndefinedValue;
void __cdecl operator delete(void *);
class AptScriptFunctionBase {
    static AptValue **spRegBlockBase, **spRegBlockCurrentFrameBase;
    static int snRegBlockCurrentFrameCount, snRegisterBlockSize;
public:
    static void InitializeStaticData(const AptInitParmsT &);
    static void ShutdownStaticData();
    static void *PushStaticData();
    static int rva007097B0(void *pSaveBase);
};
#define CHECK_AT(cond,text,line) if (!(cond)) { g_bfmeAptAssertAtE17734(text,"C:\\projects\\bfme2patch103\\bfme2\\Code\\Libraries\\Source\\Apt\\AptObject\\AptScriptFunction.cpp",line); if (g_bfmeAptBreakOnAssertAtDDC01C) __debugbreak(); }
void AptScriptFunctionBase::ShutdownStaticData()
{
    CHECK_AT(spRegBlockCurrentFrameBase == spRegBlockBase,"spRegBlockCurrentFrameBase == spRegBlockBase",117);
    CHECK_AT(snRegBlockCurrentFrameCount == 0,"snRegBlockCurrentFrameCount == 0",118);
    for(int i=0;i<snRegisterBlockSize;++i) {
        CHECK_AT(spRegBlockBase[i] == gpUndefinedValue,"spRegBlockBase[i] == gpUndefinedValue",123);
    }
    operator delete(spRegBlockBase);
    spRegBlockBase=0;
    spRegBlockCurrentFrameBase=0;
}
void *AptScriptFunctionBase::PushStaticData()
{
    CHECK_AT(spRegBlockBase,"spRegBlockBase",159);
    CHECK_AT(spRegBlockCurrentFrameBase,"spRegBlockCurrentFrameBase",160);
    void *saved=spRegBlockCurrentFrameBase;
    spRegBlockCurrentFrameBase+=snRegBlockCurrentFrameCount;
    snRegBlockCurrentFrameCount=0;
    return saved;
}

void AptScriptFunctionBase::InitializeStaticData(const AptInitParmsT &parms)
{
    snRegisterBlockSize=parms.iRegArraySize;
    spRegBlockBase=(AptValue **)operator new(snRegisterBlockSize*sizeof(AptValue *));
    spRegBlockCurrentFrameBase=spRegBlockBase;
    for(int i=0;i<snRegisterBlockSize;++i) spRegBlockBase[i]=gpUndefinedValue;
    snRegBlockCurrentFrameCount=0;
}

// ?rva007097B0@AptScriptFunctionBase@@SAHPAX@Z present-unmatched
int AptScriptFunctionBase::rva007097B0(void *pSaveBase)
{
    CHECK_AT(spRegBlockBase,"spRegBlockBase",195);
    CHECK_AT(pSaveBase>=spRegBlockBase && pSaveBase<=spRegBlockCurrentFrameBase,"pSaveBase >= spRegBlockBase && pSaveBase <= spRegBlockCurrentFrameBase",199);
    for(int i=0;i<snRegBlockCurrentFrameCount;++i) {
        AptValue *tmp=spRegBlockCurrentFrameBase[i];
        spRegBlockCurrentFrameBase[i]=gpUndefinedValue;
        tmp->Release();
    }
    int n=(char *)spRegBlockCurrentFrameBase-(char *)pSaveBase;
    spRegBlockCurrentFrameBase=(AptValue **)pSaveBase;
    n>>=2;
    snRegBlockCurrentFrameCount=n;
    return n;
}
