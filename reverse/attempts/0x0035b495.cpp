// ?rva0035B495@Rva0035B495@@QAEPAVRva002390CB@@PAV2@@Z
// partial score=0.92 date=2026-10-02
// cl: /O1 /DNDEBUG /MD /GX- /Oy- /Ireference/shims/bfme2_ascii
//
// ?rva0035B495@Rva0035B495@@QAEPAVRva002390CB@@PAV2@@Z @0x0035B495 63B
// Out-of-bounds-or-copy accessor over vector<Rva002390CB> at +0xd4 with index
// member at +0xfc: if count > index copy elem into out else default Upgrades
// into out, then return out. Sibling of 0x0035B456 (vec +0xc8) same recipe.
// Evidence: ecx-first thiscall ret 4; sar-3 count for 8B elems; callees
// 0x002390CB copy and 0x004CEE6E Upgrades default; caller 0x004DBB28;
// prev/next Common TUs share flags.
#include <vector>

#include "ascii_string.h"

extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)

class Rva0036CA00Str {
    void *m_item;
public:
    __declspec(nothrow) Rva0036CA00Str(const Rva0036CA00Str &other);
    ~Rva0036CA00Str();
};

class Rva002390CB {
    void *m_00;
    Rva0036CA00Str m_04;
public:
    __declspec(nothrow) Rva002390CB(const Rva002390CB &other);
    ~Rva002390CB();
};

class CashHackSpecialPowerModuleData {
public:
    class Upgrades {
    public:
        Upgrades();
    };
};

struct Rva0035B495Vec {
    Rva002390CB *begin;
    Rva002390CB *end;
    Rva002390CB *cap;
};

class Rva0035B495 {
    char m_pad[0xd4];
    Rva0035B495Vec m_vec;
    char m_padE0[0x1c];
    unsigned int m_fc;
public:
    Rva002390CB *rva0035B495(Rva002390CB *out);
};

// ?rva0035B495@Rva0035B495@@QAEPAVRva002390CB@@PAV2@@Z present-unmatched
Rva002390CB *Rva0035B495::rva0035B495(Rva002390CB *out)
{
    Rva0035B495Vec *v = &m_vec;
    unsigned int count = (unsigned int)(v->end - v->begin);
    unsigned int index = m_fc;
    if (count > index) {
        _ReadWriteBarrier();
        out->Rva002390CB::Rva002390CB(v->begin[index]);
    } else
        ((CashHackSpecialPowerModuleData::Upgrades *)out)->Upgrades::Upgrades();
    return out;
}
