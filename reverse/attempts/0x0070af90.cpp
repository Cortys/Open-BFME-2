// ?rva0070AF90@AptNativeHash@@QAEPAUEntry@1@PAVEAStringC@@@Z
// partial score=0.95 date=2026-10-01
// cl: /O2 /MD
// ?rva0070AF90@AptNativeHash@@QAEPAUEntry@1@PAVEAStringC@@@Z @0x0070AF90 482B
// Evidence: layout mnTotalSize+0 mpData+4 Entry 8B from AptNativeHashBFME2.cpp neighbours 0x0070AB30/0x0070B180; callees hash 0x006D2F40 IsEmpty 0x006D2F30 equals 0x006D36F0 hasData 0x006CD4A0 all rowed; asserts pKey nBoundMax nBoundMin with file AptNativeHash.cpp lines 0x351 0x388 0x389; callers 0x0070B2C0/0x0070B380.
extern void (__cdecl *g_bfmeAptAssertAtE17734)(const char *, const char *, int);
extern int g_bfmeAptBreakOnAssertAtDDC01C;
class EAStringC {
public:
    unsigned short rva006D2F40() const;
    bool IsEmpty() const;
    bool rva006D36F0(const EAStringC *pOther) const;
};
class AsciiString {
    void *m_data;
public:
    bool hasData() const;
};
class AptValue;
class AptNativeHash {
    struct Entry { AsciiString key; AptValue *value; };
    int mnTotalSize;
    Entry *mpData;
    AptValue *mp__proto__;
    AptValue *mpPrototype;
    unsigned int nEventHandlers;
public:
    Entry *rva0070AF90(EAStringC *pKey);
};
// ?rva0070AF90@AptNativeHash@@QAEPAUEntry@1@PAVEAStringC@@@Z present-unmatched
AptNativeHash::Entry *AptNativeHash::rva0070AF90(EAStringC *pKey)
{
    if (!pKey) {
        g_bfmeAptAssertAtE17734("pKey != NULL", "C:\\projects\\bfme2patch103\\bfme2\\Code\\Libraries\\Source\\Apt\\AptNativeHash.cpp", 0x351);
        if (g_bfmeAptBreakOnAssertAtDDC01C) {
            __asm int 3
        }
    }
    int nIndex = pKey->rva006D2F40() & (mnTotalSize - 1);
    if (!mpData[nIndex].key.hasData())
        return 0;
    if (!((const EAStringC *)&mpData[nIndex].key)->IsEmpty()) {
        if (((const EAStringC *)&mpData[nIndex].key)->rva006D36F0(pKey))
            return &mpData[nIndex];
    }
    int nBoundMin = nIndex - 8;
    int nBoundMax;
    if (nBoundMin < 0) {
        nBoundMin = 0;
        nBoundMax = 0x10;
        if (mnTotalSize <= 0x10)
            nBoundMax = mnTotalSize - 1;
    } else {
        nBoundMax = nIndex + 8;
        if (nBoundMax > mnTotalSize - 1) {
            nBoundMax = mnTotalSize - 1;
            nBoundMin = nBoundMax - 0x10;
            if (nBoundMin < 0)
                nBoundMin = 0;
        }
    }
    if (!(nBoundMax < mnTotalSize)) {
        g_bfmeAptAssertAtE17734("nBoundMax < mnTotalSize", "C:\\projects\\bfme2patch103\\bfme2\\Code\\Libraries\\Source\\Apt\\AptNativeHash.cpp", 0x388);
        if (g_bfmeAptBreakOnAssertAtDDC01C) {
            __asm int 3
        }
    }
    if (!(nBoundMin < nBoundMax)) {
        g_bfmeAptAssertAtE17734("nBoundMin < nBoundMax", "C:\\projects\\bfme2patch103\\bfme2\\Code\\Libraries\\Source\\Apt\\AptNativeHash.cpp", 0x389);
        if (g_bfmeAptBreakOnAssertAtDDC01C) {
            __asm int 3
        }
    }
    int nFwdCur = nIndex;
    int nFwdCount = nBoundMax - nIndex;
    if (nFwdCount != 0) {
        do {
            ++nFwdCur;
            --nFwdCount;
            if (!mpData[nFwdCur].key.hasData())
                return 0;
            if (((const EAStringC *)&mpData[nFwdCur].key)->IsEmpty())
                continue;
            if (((const EAStringC *)&mpData[nFwdCur].key)->rva006D36F0(pKey))
                return &mpData[nFwdCur];
        } while (nFwdCount != 0);
    }
    int nBackCur = nIndex;
    int nBackCount = nIndex - nBoundMin;
    if (nBackCount == 0)
        return 0;
    do {
        --nBackCur;
        --nBackCount;
        if (!mpData[nBackCur].key.hasData())
            return 0;
        if (((const EAStringC *)&mpData[nBackCur].key)->IsEmpty())
            continue;
        if (((const EAStringC *)&mpData[nBackCur].key)->rva006D36F0(pKey))
            return &mpData[nBackCur];
    } while (nBackCount != 0);
    return 0;
}
