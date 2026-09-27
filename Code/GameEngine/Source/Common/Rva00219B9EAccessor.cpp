// cl: /O1 /Ob2 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB
// stlport
// ?rva00219B9E@Rva00219B9E@@QAEPAXI@Z @0x00219B9E 44B
// Bounds-checked accessor for the 216-byte (0xD8) element vector at +0x14/+0x18.
// Returns null when index >= (finish-start)/216 via signed idiv (cdq), else
// start+index*216. Proven by 12 direct callers needing this exact shape:
// 0x00219BE1/0x00219C1F return dword counts from the element's +0x3c/+0x30
// vectors, 0x00219C00/0x00219C3E forward two indices into those inner vectors,
// 0x00219C5D adds 0x68 to the returned element. Outer chain 0x00219E74/
// 0x00219E9F/0x00219F00 indexes a 32-byte outer vector at +0x14C/+0x150 then
// calls here; top callers at 0x00406E53/0x00406E65/0x00406E8F read the global
// at 0x009FE344. Landing unblocks 24 functions (14 fully ready). No donor;
// recipe follows ObjectFilter signed-idiv precedent with /O1 keeping idiv.
// Honest-address name: owner unknown so Rva00219B9E class, void* return.
struct Elem216 {
    char m_00[0x10];
    int m_10;
    int m_14;
    int m_18;
    int m_1C;
    char m_20[0x64 - 0x20];
    int m_64;
    char m_68[0xD8 - 0x68];
};
struct Vec216 {
    Elem216 *m_start;
    Elem216 *m_finish;
    Elem216 *m_end;
};
static __forceinline unsigned VecSize(const Vec216 *v) { return v->m_finish - v->m_start; }
static __forceinline Elem216 &VecAt(Vec216 *v, unsigned i) { return v->m_start[i]; }
class Rva00219B9E {
    char m_pad[0x14];
    Vec216 m_vec;
public:
    void *rva00219B9E(unsigned int index);
    int rva00219CDF(unsigned int index);
    int rva00219CF6(unsigned int index);
    int rva00219D0D(unsigned int index);
    int rva00219D24(unsigned int index);
    int rva00219C93(unsigned int index);
};
void *Rva00219B9E::rva00219B9E(unsigned int index)
{
    void *result = 0;
    unsigned int count = VecSize(&m_vec);
    if (index < count)
        result = &VecAt(&m_vec, index);
    return result;
}
// ?rva00219CDF@Rva00219B9E@@QAEHI@Z @0x00219CDF 23B: returns element+0x10 or 0.
// Chain of 0x00219B9E; caller 0x0021A016 (outer 32B vector at +0x14C) needs it.
int Rva00219B9E::rva00219CDF(unsigned int index)
{
    void *p = rva00219B9E(index);
    if (p)
        return ((Elem216 *)p)->m_10;
    return 0;
}
// ?rva00219CF6@Rva00219B9E@@QAEHI@Z @0x00219CF6 23B: returns element+0x14 or 0.
// Chain of 0x00219B9E; caller 0x0021A041 needs it.
int Rva00219B9E::rva00219CF6(unsigned int index)
{
    void *p = rva00219B9E(index);
    if (p)
        return ((Elem216 *)p)->m_14;
    return 0;
}
// ?rva00219D0D@Rva00219B9E@@QAEHI@Z @0x00219D0D 23B: returns element+0x18 or 0.
// Chain of 0x00219B9E; caller 0x0021A06C needs it.
int Rva00219B9E::rva00219D0D(unsigned int index)
{
    void *p = rva00219B9E(index);
    if (p)
        return ((Elem216 *)p)->m_18;
    return 0;
}
// ?rva00219D24@Rva00219B9E@@QAEHI@Z @0x00219D24 23B: returns element+0x1C or 0.
// Chain of 0x00219B9E; caller 0x0021A097 needs it.
int Rva00219B9E::rva00219D24(unsigned int index)
{
    void *p = rva00219B9E(index);
    if (p)
        return ((Elem216 *)p)->m_1C;
    return 0;
}
// ?rva00219C93@Rva00219B9E@@QAEHI@Z @0x00219C93 24B: returns element+0x64 or -1.
// Chain of 0x00219B9E; caller 0x00219FE3 needs it. Null path uses or eax,-1.
int Rva00219B9E::rva00219C93(unsigned int index)
{
    void *p = rva00219B9E(index);
    if (!p)
        return -1;
    return ((Elem216 *)p)->m_64;
}
