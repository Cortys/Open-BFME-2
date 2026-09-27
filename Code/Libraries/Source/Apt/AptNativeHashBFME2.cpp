// cl: /O2 /MD
// Reconstructed from BFME2 and APT 0.19.03 Xbox final donor evidence.
// Donor: ears_godfather_f PDB GUID 729627e9-b922-4d59-9b50-e116a2834635 age24;
// SHA256 8f9525adc557812dfe2866ce0d621904bfce9f9ba83341f85ec330f0b8fc4fb5.
// All five complete bodies are raw-exact in the donor and retail. Donor PDB/MAP
// supplies class/member spellings; target instructions independently establish
// offsets 0/4/8/12/16, 8-byte entries, and AddRef/Release virtual slots 0/4.
// Target constructor 0x70A740 initializes those fields and cites AptNativeHash.cpp;
// its constant-string indices 0/120 and hashes 0x6BBD/0x699 are reused by caller
// 0x70B410 to select Set__Proto__ / SetPrototype. The resize path 0x70ABC0
// constructs the same 20-byte hash and calls DestroyGCPointers at 0x70AC5B.
// Target 0x70A610 also cites AptNativeHash.h and uses the same entry layout.
// AptValue below declares only the accessed virtual interface, not its full ABI.
// Entry is a local view: the key is opaque here, not a recovered donor key type.
class AptValue {
public:
    virtual void AddRef();
    virtual void Release();
};
class AptNativeHash {
    struct Entry { void *key; AptValue *value; };
    int mnTotalSize;
    Entry *mpData;
    AptValue *mp__proto__;
    AptValue *mpPrototype;
    unsigned int nEventHandlers;
public:
    void Set__Proto__(AptValue *const value);
    void SetPrototype(AptValue *const value);
    void Unset__Proto__();
    void UnsetPrototype();
    void DestroyGCPointers();
};
void AptNativeHash::Set__Proto__(AptValue *const value)
{
    if (value) value->AddRef();
    if (mp__proto__) mp__proto__->Release();
    mp__proto__ = value;
}
void AptNativeHash::SetPrototype(AptValue *const value)
{
    if (value) value->AddRef();
    if (mpPrototype) mpPrototype->Release();
    mpPrototype = value;
}
void AptNativeHash::Unset__Proto__()
{
    if (mp__proto__) {
        mp__proto__->Release();
        mp__proto__ = 0;
    }
}
void AptNativeHash::UnsetPrototype()
{
    if (mpPrototype) {
        mpPrototype->Release();
        mpPrototype = 0;
    }
}
void AptNativeHash::DestroyGCPointers()
{
    if (mpPrototype) {
        mpPrototype->Release();
        mpPrototype = 0;
    }
    if (mp__proto__) {
        mp__proto__->Release();
        mp__proto__ = 0;
    }
    if (mpData) {
        for (int i = 0; i < mnTotalSize; ++i) {
            if (mpData[i].value) {
                mpData[i].value->Release();
                mpData[i].value = 0;
            }
        }
        nEventHandlers = 0;
    }
}
