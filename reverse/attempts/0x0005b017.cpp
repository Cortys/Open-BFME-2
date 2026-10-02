// ?isMusicAlreadyLoaded@AudioManager@@UBE_NXZ
// partial score=0.7 date=2026-10-02
// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD /EHsc
// AudioManager::isMusicAlreadyLoaded, target RVA 0x0005B017, Ghidra 288B.
// Semantic guide: BFME1 GameAudio.cpp isMusicAlreadyLoaded / ZH same body.
// Donor revision: 10af19f44a89ab7ecc23195bb9a842ceafbc02c9.
// Target evidence: primary Miles audio vtable VA 0xBC55B0 slot 0x14C,
// followed by the CD-status getter; table installed by target 0x5CF83.
// Target selects the first eligible counted event, returns true if none,
// and uses the target's 144B filename record rather than donor AudioEventRTS.
// Event +0xB0 and flag +0x49 meanings remain target-derived structural views.
#include "ascii_string.h"
class OpaqueRefCounted { public: void Release_Ref(); };
struct OpaqueRefElement4 {
    OpaqueRefCounted *referent;
    __forceinline ~OpaqueRefElement4() { if (referent) referent->Release_Ref(); }
    OpaqueRefElement4 &operator=(const OpaqueRefElement4 &other);
};
class AudioEventInfo {
public:
    char m_unknown00[0x49];
    unsigned char m_flags49;
    char m_unknown4A[0x66];
    int m_kindB0;
};
class AudioEventInfoRef {
public:
    AudioEventInfoRef() : m_info(0) {}
    AudioEventInfoRef(const AudioEventInfo *info);
    AudioEventInfoRef &operator=(const AudioEventInfoRef &other);

    const AudioEventInfo *m_info;
};
class Rva000411084 {
public:
    Rva000411084() {}
    Rva000411084(const Rva000411084 &other) : m_current(other.m_current), m_owner(other.m_owner) {}
    void *next();
    void *m_current;
    void *m_owner;
};
class Rva000427195 { public: Rva000411084 rva00427195() const; };
struct AudioEventNode {
    AudioEventNode *m_next;
    AsciiString m_key;
    const AudioEventInfo *m_info;
};
class BfmeStringTailRecord144 {
public:
    BfmeStringTailRecord144(const OpaqueRefElement4 &info, int mode);
    virtual ~BfmeStringTailRecord144();
    void rva002D9ADC();
    AsciiString rva002DA838();
private:
    char m_body[0x8c];
};
class FileSystem { public: bool doesFileExist(const char *filename) const; };
extern FileSystem *TheFileSystem;
class AudioManager {
public: virtual bool isMusicAlreadyLoaded() const;
private:
    char m_unknown[0xb8];
    Rva000427195 m_allAudioEventInfo;
};
// ?isMusicAlreadyLoaded@AudioManager@@UBE_NXZ
bool AudioManager::isMusicAlreadyLoaded() const
{
    OpaqueRefElement4 musicToLoad = {0};
    Rva000411084 it = m_allAudioEventInfo.rva00427195();
    while (it.m_current != 0) {
        const AudioEventInfo *aet = ((AudioEventNode *)it.m_current)->m_info;
        if (aet) {
            AudioEventInfoRef ref(aet);
            const AudioEventInfo *info = ref.m_info;
            struct ScopedRelease {
                OpaqueRefCounted *info;
                __forceinline ~ScopedRelease() { info->Release_Ref(); }
            } release = {(OpaqueRefCounted *)info};
            if (info->m_kindB0 == 0 && !(info->m_flags49 & 6))
                musicToLoad = *(const OpaqueRefElement4 *)&ref;
        }
        it.next();
        if (musicToLoad.referent) break;
    }
    if (!musicToLoad.referent) return true;
    BfmeStringTailRecord144 aud(musicToLoad, 2);
    aud.rva002D9ADC();
    AsciiString astr = aud.rva002DA838();
    return TheFileSystem->doesFileExist(astr.str());
}

#pragma comment(linker, "/alternatename:??4AudioEventInfoRef@@QAEAAV0@ABV0@@Z=??4OpaqueRefElement4@@QAEAAU0@ABU0@@Z")

// Trial-only helper pins (removed from live symbols.csv when banking):
// ??0BfmeStringTailRecord144@@QAE@ABUOpaqueRefElement4@@H@Z = 0x002D97D6
// ?rva002D9ADC@BfmeStringTailRecord144@@QAEXXZ = 0x002D9ADC
// ?rva002DA838@BfmeStringTailRecord144@@QAE?AVAsciiString@@XZ = 0x002DA838
// ?rva00427195@Rva000427195@@QBE?AVRva000411084@@XZ = 0x00427195
// ??4AudioEventInfoRef@@QAEAAV0@ABV0@@Z = 0x00239099
// All read independently from 0x0005B017 call sites; helper names are structural.
