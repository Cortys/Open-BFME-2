// cl: /O1 /DNDEBUG /MD /EHsc /arch:SSE
// ?Rva0056866ALess@@YG_NPBX0@Z @0x0056866A 71B. Stdcall 10-byte key ordering
// for the 0x00568xxx RB-tree family (2 floats + word at +8). Retail compares
// floats with comiss/ja (greater-true) and word with sbb/neg (less-true).
// Evidence: callees none (leaf); callers are tree find 0x00568A41 and insert
// 0x00569295 which both pass node key at +0x10 and search key; /arch:SSE gives
// movss/comiss, /O1 gives pop-free ret-8 shape like sibling Less 0x006038D4.
// ?Rva00568A9DCopy@@YAXPAXPBX@Z @0x00568A9D 31B. Cdecl 10-byte key copy
// (4+4+2) with null-dest guard. Evidence: sole caller is node create
// 0x00568D95 which allocates 0x1c and copies input key to node+0x10; no
// callees; matches with /O1 (same flags as neighbour stlport_lower_bound).
struct Rva0056866AKey {
    float x;
    float y;
    unsigned short w;
};
bool __stdcall Rva0056866ALess(const void *a_, const void *b_)
{
    const Rva0056866AKey *a = (const Rva0056866AKey *)a_;
    const Rva0056866AKey *b = (const Rva0056866AKey *)b_;
    if (a->x < b->x)
        return false;
    if (a->x > b->x)
        return true;
    if (a->y < b->y)
        return false;
    if (a->y > b->y)
        return true;
    return a->w < b->w;
}
void __cdecl Rva00568A9DCopy(void *dest, const void *src)
{
    if (!dest)
        return;
    *(unsigned int *)dest = *(const unsigned int *)src;
    *((unsigned int *)dest + 1) = *((const unsigned int *)src + 1);
    *(unsigned short *)((unsigned char *)dest + 8) = *(const unsigned short *)((const unsigned char *)src + 8);
}
