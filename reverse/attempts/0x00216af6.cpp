// ?rva00216AF6@Rva00216AF6@@QAEXXZ
// partial score=0.97 date=2026-09-30
// ?rva00216AF6@Rva00216AF6@@QAEXXZ
// partial score=0.97 date=2026-09-29
// cl: /O1 /MD
// ?rva00216AF6@Rva00216AF6@@QAEXXZ 0x00216AF6 73B evidence: clears vector of node ptrs at +4/+8 via rowed stdcall free 0x00216787 then flag at +0x10; chain from 0x00216787 landing; caller 0x00216B95
struct Rva00216787Node {
    int m_head;
    void *m_strs;
};
struct Rva00216AF6Node {
    struct Rva00216AF6Node *m_next;
};
extern void __stdcall Rva00216787Free(Rva00216787Node *p);
class Rva00216AF6 {
    int m_pad0;
    Rva00216AF6Node **m_begin;
    Rva00216AF6Node **m_end;
    int m_padC;
    int m_flag10;
public:
    void rva00216AF6();
};
// ?rva00216AF6@Rva00216AF6@@QAEXXZ present-unmatched
void Rva00216AF6::rva00216AF6()
{
    for (unsigned i = 0; i < (unsigned)(m_end - m_begin); ++i) {
        Rva00216AF6Node *n = m_begin[i];
        while (n) {
            Rva00216AF6Node *next = n->m_next;
            Rva00216787Free((Rva00216787Node *)n);
            n = next;
        }
        m_begin[i] = 0;
    }
    m_flag10 = 0;
}
