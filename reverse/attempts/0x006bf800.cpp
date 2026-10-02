// ?_M_fill_insert@?$vector@UBfmeStringRecord00063BE4@@V?$allocator@UBfmeStringRecord00063BE4@@@_STL@@@_STL@@QAEXPAUBfmeStringRecord00063BE4@@IABU3@@Z
// partial score=0.91 date=2026-10-02
// cl: /O2 /Ob1 /G6 /GX- /Ireference/shims/bfme2_ascii
// stlport
// Banked unverified continuation for served 0x006BF800/332B. Target's constructor at
// 0x00063BE4 establishes seven words, AsciiString at +1C and bytes +20/+21.
// Application class and scalar meanings remain unknown. This is a target
// ABI view, not an assertion that all users of the shared copy constructor
// had one application class. The visible /O2 constructor is unverified:
// it is79B but differs at+D from the kept native79B constructor. Removing
// its body causes fill-helper inlining and a359B caller; retain visibility
// for the closest caller shape, but do not land this whole TU as-is.
// The forced four-argument false-tag fill interface restores the caller's
// complete 332-byte non-relocation shape. Remaining calls: copy 6BE840/126B,
// fill 6BE8C0/115B, overflow 6BF5E0/268B unresolved; copy_backward and fill
// currently resolve to this record's other instantiations AD897/AD806 instead
// of native 6BE370/6BE270. Do not accept those existing names as identities
// for the new addresses. Native construction loops copy all seven words,
// call StringBase copy365F0 and copy bytes20/21. Visible constructors,
// /Ob2, donor mixed scalars and explicit /Ot did not reproduce their loops.
// Native loops keep additional pointers induced from+18; the current record
// model does not explain that induction. The existing assignment views group
// words+10..+18 as a three-word subobject; that deserves further study.
// The existing char-traits __find_if pin at6BE8C0 conflicts with that native
// construction behavior; its caller needs independent reconciliation.
#include "ascii_string.h"
#include <vector>

struct BfmeStringRecord00063BE4
{
    unsigned int word0, word1, word2, word3, word4, word5, word6;
    AsciiString text;
    unsigned char tail0, tail1;
    BfmeStringRecord00063BE4(const BfmeStringRecord00063BE4 &o) throw()
      : word0(o.word0), word1(o.word1), word2(o.word2), word3(o.word3),
        word4(o.word4), word5(o.word5), word6(o.word6), text(o.text),
        tail0(o.tail0), tail1(o.tail1) {}
    BfmeStringRecord00063BE4 &operator=(const BfmeStringRecord00063BE4 &) throw();
};
typedef char BfmeRecord36Width[(sizeof(BfmeStringRecord00063BE4) == 36) ? 1 : -1];

namespace _STL
{
    template <>
    __forceinline BfmeStringRecord00063BE4 *uninitialized_fill_n(
        BfmeStringRecord00063BE4 *first, unsigned count,
        const BfmeStringRecord00063BE4 &value)
    {
        return __uninitialized_fill_n(first, count, value, __false_type());
    }
}

template void _STL::vector<BfmeStringRecord00063BE4>::_M_fill_insert(
    BfmeStringRecord00063BE4 *, unsigned, const BfmeStringRecord00063BE4 &);
