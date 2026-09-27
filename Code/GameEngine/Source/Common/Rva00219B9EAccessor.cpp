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
struct Elem216 { char data[0xD8]; };
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
};
void *Rva00219B9E::rva00219B9E(unsigned int index)
{
    void *result = 0;
    unsigned int count = VecSize(&m_vec);
    if (index < count)
        result = &VecAt(&m_vec, index);
    return result;
}
