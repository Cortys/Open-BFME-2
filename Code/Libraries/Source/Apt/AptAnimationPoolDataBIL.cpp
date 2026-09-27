// cl: /O2 /MD
// APT0.19.03 Xbox final donor PDB GUID 729627e9-b922-4d59-9b50-e116a2834635 age24.
// Donor PDB types 0x15C9E/0x155E5/0x3604 provide pool/member/type names.
// Retail independently establishes count+0x10, list+0x14, entry stride28,
// pointer+0, six-float matrix+4, and virtual AddRef/Release slots0/4.
// Complete bodies at RVA6E35A0(49) and6E35E0(81) equal the donor bytes.
// Retail caller6E15C0 cites AptCIH.h/.cpp; its button-type14 branch calls
// 6E35E0 at6E1873 with this from global E176D0 and a 24-byte matrix.
// Caller6CC880 clears the same pool via6E35A0 at6CC8B9.
// The class name is donor-supported; no full 172-byte donor pool layout is
// transferred. AptCIH declares only the virtual interface used by these bodies.
class AptCIH {
public:
    virtual void AddRef();
    virtual void Release();
};
struct AptMatrix { float a,b,c,d,tx,ty; };
struct ButtonHitTestRecord { AptCIH *pCIH; AptMatrix matrix; };
struct AptAnimationPoolData {
    unsigned char unaccessed[16];
    int mBILCount;
    ButtonHitTestRecord *aButtonInstanceList;
    void clearBIL();
    void appendButtonToBIL(AptCIH *button, AptMatrix *matrix);
};
void AptAnimationPoolData::clearBIL()
{
    for (int i=0;i<mBILCount;++i) aButtonInstanceList[i].pCIH->Release();
    mBILCount=0;
}
void AptAnimationPoolData::appendButtonToBIL(AptCIH *button, AptMatrix *matrix)
{
    aButtonInstanceList[mBILCount].pCIH=button;
    button->AddRef();
    aButtonInstanceList[mBILCount].matrix=*matrix;
    ++mBILCount;
}

typedef char AptMatrixSize[(sizeof(AptMatrix)==24)?1:-1];
typedef char ButtonHitTestRecordSize[(sizeof(ButtonHitTestRecord)==28)?1:-1];
