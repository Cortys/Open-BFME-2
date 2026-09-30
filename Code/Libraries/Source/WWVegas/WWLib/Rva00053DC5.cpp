// cl: /O1 /EHsc /D_STLP_NO_EXCEPTIONS /MD /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_CRTIMP= /D_BFME_RETAIL_TREE_INSERT_LAYOUT
// ?rva00053DC5@Rva00053DC5@@QAEXPAX@Z @0x00053DC5 45B: thiscall free-loop.
// Recurses on +0xC then frees node and follows +0x8; called from 0x00054B9A
// list-head resetter which proves list-container context. Callees all rowed:
// self-recursion plus row 0x00030830 free. Unlocks 0x00054B9A.
extern "C" void __cdecl free(void *block);

struct Node53DC5
{
    char m_pad[8];
    void *m_next8;
    void *m_nextC;
};

class Rva00053DC5
{
public:
    void rva00053DC5(void *node);
};

void Rva00053DC5::rva00053DC5(void *node)
{
    Node53DC5 *n = (Node53DC5 *)node;
    if (n == 0)
        return;
    do
    {
        rva00053DC5(n->m_nextC);
        Node53DC5 *next = (Node53DC5 *)n->m_next8;
        free(n);
        n = next;
    } while (n != 0);
}
