// cl: /O1 /MD
// ?rva0037E421@Rva0037E421@@QAEPAXH@Z @0x0037E421 48B
// Bounds-checked accessor for the 216-byte (0xD8) element vector at +0x04/+0x08.
// Returns null when index < 0 or index >= (finish-start)/216 via signed idiv (cdq),
// else start+index*216. Proven by 14 direct callers needing this exact shape.
// Unlock lane; landing unblocks 11 functions. No donor; recipe follows
// Rva00219B9EAccessor signed-idiv precedent with /O1 keeping idiv.
// Honest-address name: owner unknown so Rva0037E421 class, void* return, int index.
struct Elem216 { char data[0xD8]; };
struct Vec216 { Elem216 *m_start; Elem216 *m_finish; Elem216 *m_end; };
static __forceinline unsigned VecSize(Vec216 *v) { return v->m_finish - v->m_start; }
static __forceinline Elem216 &VecAt(Vec216 *v, int i) { return v->m_start[i]; }
class Rva0037E421 {
    int m_00;
    Vec216 m_vec;
public:
    void *rva0037E421(int index);
};
void *Rva0037E421::rva0037E421(int index)
{
    if (index < 0)
        return 0;
    unsigned int count = VecSize(&m_vec);
    if ((unsigned int)index < count)
        return &VecAt(&m_vec, index);
    return 0;
}
