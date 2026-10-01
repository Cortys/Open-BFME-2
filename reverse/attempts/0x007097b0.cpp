// ?rva007097B0@AptScriptFunctionBase@@SAHPAX@Z
// partial score=0.93 date=2026-10-01
// ?rva007097B0@AptScriptFunctionBase@@SAHPAX@Z
// partial score=0.93 date=2026-10-01
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
class AptValue {
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
// ?rva007097B0@AptScriptFunctionBase@@SAHPAX@Z @0x007097B0 171B: PopStaticData
// counterpart of PushStaticData. Evidence: same 4 class statics and assert file
// AptObject/AptScriptFunction.cpp as siblings; string_xrefs pins both literals
// ("spRegBlockBase" line 195, "pSaveBase >= spRegBlockBase &&
// pSaveBase <= spRegBlockCurrentFrameBase" line 199); virtual slot-1 Release on
// each cleared register matches BfmeAptValue006DCD20::Release; cdecl 1-arg
// signature from caller 0x006FD340 (push eax + call + add esp,4); return is a
// signed pointer difference (sub + sar 2). Honest address name: real name unproven.
// ?rva007097B0@AptScriptFunctionBase@@SAHPAX@Z present-unmatched
int AptScriptFunctionBase::rva007097B0(void *pSaveBase)
{
    CHECK_AT(spRegBlockBase,"spRegBlockBase",195);
    AptValue **save=(AptValue **)pSaveBase;
    CHECK_AT(save >= spRegBlockBase && save <= spRegBlockCurrentFrameBase,"pSaveBase >= spRegBlockBase && pSaveBase <= spRegBlockCurrentFrameBase",199);
    for(int i=0;i<snRegBlockCurrentFrameCount;++i) {
        AptValue *reg=spRegBlockCurrentFrameBase[i];
        spRegBlockCurrentFrameBase[i]=gpUndefinedValue;
        reg->Release();
    }
    AptValue **oldBase=spRegBlockCurrentFrameBase;
    spRegBlockCurrentFrameBase=save;
    snRegBlockCurrentFrameCount=oldBase-save;
    return snRegBlockCurrentFrameCount;
}
