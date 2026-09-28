// ?rva003F44A9@Rva003F44A9@@QAEPAXXZ
// partial score=0.97 date=2026-09-28
// ?rva003F44A9@Rva003F44A9@@QAEPAXXZ
// partial score=0.97 date=2026-09-28
// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// ?rva003F44A9@Rva003F44A9@@QAEPAXXZ retail 0x003F44A9 68 bytes.
// First-empty finder over vector<Element*> at +4 where Element has
// StringBase<char> at +0x18 (isEmpty row 0x00001E2F). Returns first
// element whose string is empty else 0. Callers 0x003F4ABB 0x003F4FBD.
// Layout from Rva003F498AInner middle 48B with vector at +4 and outer
// 28B at +0x18. Current body 67B: first size calc uses cached base
// (sub eax edi plus early push edi) vs retail reload (sub eax [esi+4]
// plus late push edi). Loop plus return already match.
#include <vector>
template <class CHAR> class StringBase { void *m_data; public: bool isEmpty() const; };
struct Rva003F44A9Element { char m_pad[24]; StringBase<char> m_str; };
class Rva003F44A9 {
    char m_pad0[4];
    _STL::vector<Rva003F44A9Element *> m_list;
public:
    void *rva003F44A9();
};
void *Rva003F44A9::rva003F44A9()
{
    Rva003F44A9Element **base = m_list.begin();
    Rva003F44A9Element **cur = base;
    for (unsigned i = 0; i < m_list.size(); ++i) {
        if ((*cur)->m_str.isEmpty())
            return base[i];
        ++cur;
    }
    return 0;
}
