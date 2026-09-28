// ?rva002B59FF@Rva002B59FF@@QAE_NXZ
// partial score=0.93 date=2026-09-28
// ?rva002B59FF@Rva002B59FF@@QAE_NXZ
// partial score=0.93 date=2026-09-28
// cl: /DNDEBUG /MD /EHsc /O1 /Ob2
// stlport
#include <vector>
//
// ?rva002B59FF@Rva002B59FF@@QAE_NXZ, retail 0x002B59FF, 96 bytes.
// Gap-page unlock draining 002B5xxx: bool predicate with no stack args (ret).
// Returns false unless int at +0xF4 is 0 or 4 and the pointed-to int vector at
// +0xB0 (start +0x14 finish +0x18) is empty, then consults two singletons and
// two members: false->true on ToBeDetermined 0x0023C6A4 via 0x00DFE78C,
// true->false on ToBeDetermined 0x002BE8D4 via 0x00DFEF18, false on byte at
// +0xE8 non-zero, false->true on ToBeDetermined 0x002B5073 with mask 4 via
// vector at +0xCC, else false. Callers at 0x002B5A6B (adjacent 0x002B5A5F
// same-this) and 0x003FA8AA. Callees all rowed. Layout is TU-local honest
// views; original class identity unproven so Rva self-class.

typedef bool Bool;

class Rva0023C6A4
{
public:
    bool rva0023C6A4();
};

class Rva002BE8D4
{
public:
    bool rva002BE8D4();
};

class Rva002B5073
{
public:
    bool rva002B5073(int mask);
};

#define TheRva00DFE78C (*(Rva0023C6A4 **)0x00DFE78C)
#define TheRva00DFEF18 (*(Rva002BE8D4 **)0x00DFEF18)

struct Rva002B59FFHolder
{
    char pad[0x14];
    _STL::vector<int> vec; // +0x14 for size>>2 empty check via STL
};

class Rva002B59FF
{
public:
    bool rva002B59FF();

private:
    char pad00_B0[0xB0];
    Rva002B59FFHolder *m_B0; // +0xB0
    char padB4_CC[0xCC - 0xB4];
    char vecCC[12]; // +0xCC rowed helper vector slot
    char padD8_E8[0xE8 - 0xD8];
    bool m_E8; // +0xE8
    char padE9_F4[0xF4 - 0xE9];
    int m_F4; // +0xF4
};

// ?rva002B59FF@Rva002B59FF@@QAE_NXZ present-unmatched
bool Rva002B59FF::rva002B59FF()
{
    if ((m_F4 == 0 || m_F4 == 4) &&
        (m_B0->vec.size() == 0)) {
        if (!TheRva00DFE78C->rva0023C6A4())
            return true;
        if (!TheRva00DFEF18->rva002BE8D4() && m_E8 == 0) {
            if (!((Rva002B5073 *)this)->rva002B5073(4))
                return true;
        }
    }
    return false;
}
