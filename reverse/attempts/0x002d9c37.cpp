// ?rva002D9C37@AudioEventRTS@@QBE_NXZ
// partial score=0.98 date=2026-09-28
// ?rva002D9C37@AudioEventRTS@@QBE_NXZ
// partial score=0.98 date=2026-09-28
// cl: /O1
// ?rva002D9C37@AudioEventRTS@@QBE_NXZ @ 0x002D9C37 67B (ours 66B, 1B diff: retail has extra dec edx before jmp false)
// AudioEventRTS::isPositionalAudio shape via getSoundClass caller at 0x002D9D39 (case 2 calls this, neg/sbb/and/inc/inc to 4/2).
// Donor: BFME1 AudioEventRTS::isPositionalAudio (AudioEventRTS.cpp:729, BitTest m_type ST_WORLD, ownerType/ID check) and
// AudioEventRTSClassification.cpp getSoundClass mapping. Callers in MilesAudioManager (0x0005160F, 0x00054839, 0x00060869 etc.).
// Layout: this+8 eventInfo, this+0x34 ownerID, this+0x38 ownerType (0 true, 1-5 ID!=0, else false);
// eventInfo+0x48 typeFlags bit2 (ST_WORLD), +0xB0 field (2 flagcheck, 3 owner, else false). Duplicated owner cases force
// dec-chain + push esi/xor esi/cmp/sub esi idioms; per-case if(ID!=0) return true + shared false gives branch tail.
// Near miss: only retail extra dec edx at +0x17 (dec,dec,je,dec,je,dec,jmp vs ours dec,dec,je,dec,je,jmp).

struct AudioEventInfoRva002D9C37
{
    char m_pad00[0x48];
    unsigned char m_typeFlags;
    char m_pad49[0xB0 - 0x49];
    int m_fieldB0;
};

class AudioEventRTS
{
public:
    bool rva002D9C37() const;

private:
    char m_pad00[8];
    const AudioEventInfoRva002D9C37 *m_eventInfo;
    char m_pad0C[0x34 - 0x0C];
    int m_ownerID;
    int m_ownerType;
};

bool AudioEventRTS::rva002D9C37() const
{
    if (m_eventInfo) {
        switch (m_eventInfo->m_fieldB0) {
        case 2:
            if ((m_eventInfo->m_typeFlags & 2) == 0)
                return false;
            break;
        case 3:
            break;
        default:
            return false;
        }
    }
    switch (m_ownerType) {
    case 0:
        return true;
    case 1:
        if (m_ownerID != 0)
            return true;
        break;
    case 2:
        if (m_ownerID != 0)
            return true;
        break;
    case 3:
        if (m_ownerID != 0)
            return true;
        break;
    case 4:
        if (m_ownerID != 0)
            return true;
        break;
    case 5:
        if (m_ownerID != 0)
            return true;
        break;
    default:
        break;
    }
    return false;
}
