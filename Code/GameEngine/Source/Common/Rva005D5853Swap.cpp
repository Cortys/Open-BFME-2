// cl: /O1 /MD
// ?Rva005D5853Swap@@YAXPAURva005D5853@@0@Z @0x005D5853 35B.
// Swap of 8-byte outer (ptr at +0 plus bool at +4 with padding) via tmp struct copy plus member assigns.
// Same layout as banked Rva005D5AB3 partial (ptr plus bool). Callers are sort partition 0x005D5D61 and 0x005D58C4.
struct Rva005D5853 {
    void *m_ptr;
    bool m_flag;
};
void Rva005D5853Swap(Rva005D5853 *a, Rva005D5853 *b)
{
    Rva005D5853 tmp = *a;
    a->m_ptr = b->m_ptr;
    a->m_flag = b->m_flag;
    b->m_ptr = tmp.m_ptr;
    b->m_flag = tmp.m_flag;
}
