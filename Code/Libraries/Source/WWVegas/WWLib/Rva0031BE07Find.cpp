// cl: /Ireference/shims/bfme2_ascii /O1 /GX /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// ?rva0031BE07@Rva0031BE07@@QAEPAXABV?$StringBase@D@@@Z @0x0031BE07 53B
// Unlocks 0x0031BE58/153 and 0x001DAF81/255; LINK BONUS via 0x0031BE3C.
// String-keyed node search at this+0x2C via rowed StringBase::compare 0x000069D6
// and pinned getFinalOverride 0x001E35DF (pin ?getFinalOverride@Overridable@@QBEPBV1@XZ); callers at 0x001DAFB7 0x0031BE40 0x0031BE85 0x0031BEC0
// pass StringBase temps (0x0031BE58 builds from Command_* literals).
// Donor: none; honest Rva class; layout from retail offsets.
#include "ascii_string.h"

class Overridable
{
public:
    const Overridable *getFinalOverride() const;
};

struct Rva0031BE07Node
{
    void *m_unk00;
    Overridable *m_nextOverride;
    unsigned char m_pad08[8];
    StringBase<char> m_name;
    unsigned char m_pad14[4];
    Rva0031BE07Node *m_next;
};

struct Rva0031BE07
{
    unsigned char m_pad[0x2c];
    Rva0031BE07Node *m_head;
    void *rva0031BE07(const StringBase<char> &key);
};

void *Rva0031BE07::rva0031BE07(const StringBase<char> &key)
{
    Rva0031BE07Node *node = m_head;
    while (node) {
        if (node->m_name.compare(key) == 0) {
            if (node->m_nextOverride != 0)
                return (void *)node->m_nextOverride->getFinalOverride();
            return node;
        }
        node = node->m_next;
    }
    return 0;
}
