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
class AsciiString { public: AsciiString(const AsciiString &); AsciiString &operator=(const AsciiString &); __forceinline ~AsciiString() { releaseBuffer(); } protected: void releaseBuffer(); private: void *m_data; public: static AsciiString TheEmptyString; };
template <typename T> class StringBase {
public: StringBase(const char *s); __forceinline ~StringBase() { releaseBuffer(); } protected: void releaseBuffer(); private: void *m_data; };
struct IntVec { int *m_start; int *m_finish; int *m_end; };
struct Elem216 {
    char m_00[0x0C];
    AsciiString m_0C;
    int m_10;
    int m_14;
    int m_18;
    int m_1C;
    AsciiString m_20;
    char m_24[0x30 - 0x24];
    IntVec m_30;
    IntVec m_3C;
    char m_48[0x64 - 0x48];
    int m_64;
    char m_68[0xD8 - 0x68];
};
struct Vec216 {
    Elem216 *m_start;
    Elem216 *m_finish;
    Elem216 *m_end;
};
struct OuterElem32 { char m_00[32]; };
struct Vec32 {
    OuterElem32 *m_start;
    OuterElem32 *m_finish;
    OuterElem32 *m_end;
};
static __forceinline unsigned VecSize(const Vec216 *v) { return v->m_finish - v->m_start; }
static __forceinline Elem216 &VecAt(Vec216 *v, unsigned i) { return v->m_start[i]; }
static __forceinline unsigned Vec32Size(const Vec32 *v) { return v->m_finish - v->m_start; }
static __forceinline OuterElem32 &Vec32At(Vec32 *v, unsigned i) { return v->m_start[i]; }
class Rva00219B9E {
    char m_pad[0x14];
    Vec216 m_vec;
    char m_pad2[0x14C - 0x20];
    Vec32 m_outer;
public:
    void *rva00219B9E(unsigned int index);
    int rva00219CDF(unsigned int index);
    int rva00219CF6(unsigned int index);
    int rva00219D0D(unsigned int index);
    int rva00219D24(unsigned int index);
    int rva00219C93(unsigned int index);
    void *rva00219CAB(unsigned int index);
    void *rva00219CC5(unsigned int index);
    int rva00219BE1(unsigned int index);
    int rva00219C1F(unsigned int index);
    void *rva0021AE56(unsigned int index);
    void *rva0021AEB9(unsigned int index);
    void *rva0021AF7E(unsigned int index);
    void *rva0021AFEA(unsigned int index);
    void *rva0021B1B4(unsigned int o, unsigned int i);
    void *rva0021B2A2(unsigned int o, unsigned int i);
    void *rva0021A134(unsigned int index);
    int rva0021A016(unsigned int o, unsigned int i);
    int rva0021A041(unsigned int o, unsigned int i);
    int rva0021A06C(unsigned int o, unsigned int i);
    int rva0021A097(unsigned int o, unsigned int i);
    void *rva0021A1B6(unsigned int o, unsigned int i);
    void *rva0021A15D(unsigned int o, unsigned int i);
    void *rva0021B05A(unsigned int index);
    void *rva0021B0CA(unsigned int index);
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
// ?rva00219CAB@Rva00219B9E@@QAEPAXI@Z @0x00219CAB 26B: returns element+0x0C or empty.
// Chain of 0x00219B9E; caller 0x0021B22E needs it. Fallback is TheEmptyString.
void *Rva00219B9E::rva00219CAB(unsigned int index)
{
    void *p = rva00219B9E(index);
    if (p)
        return &((Elem216 *)p)->m_0C;
    return &AsciiString::TheEmptyString;
}
// ?rva00219CC5@Rva00219B9E@@QAEPAXI@Z @0x00219CC5 26B: returns element+0x20 or empty.
// Chain of 0x00219B9E; caller 0x0021A15D needs it. Fallback is TheEmptyString.
void *Rva00219B9E::rva00219CC5(unsigned int index)
{
    void *p = rva00219B9E(index);
    if (p)
        return &((Elem216 *)p)->m_20;
    return &AsciiString::TheEmptyString;
}
// ?rva00219BE1@Rva00219B9E@@QAEHI@Z @0x00219BE1 31B: inner int-vector count at +0x3C.
// Chain of 0x00219B9E; caller 0x00219E74 needs it. Pointer diff gives sar 2.
int Rva00219B9E::rva00219BE1(unsigned int index)
{
    void *p = rva00219B9E(index);
    if (p)
        return ((Elem216 *)p)->m_3C.m_finish - ((Elem216 *)p)->m_3C.m_start;
    return 0;
}
// ?rva00219C1F@Rva00219B9E@@QAEHI@Z @0x00219C1F 31B: inner int-vector count at +0x30.
// Chain of 0x00219B9E; callers 0x00219EF4/0x0022027F need it via 0x00219ED5.
int Rva00219B9E::rva00219C1F(unsigned int index)
{
    void *p = rva00219B9E(index);
    if (p)
        return ((Elem216 *)p)->m_30.m_finish - ((Elem216 *)p)->m_30.m_start;
    return 0;
}
// ?rva0021AE56@Rva00219B9E@@QAEPAXI@Z @0x0021AE56 99B
// Subclass-name accessor with function-static fallback "ERROR: Invalid SubCalssIndex".
// Chain of 0x00219B9E; static constructed via rowed StringBase<char> PBD 0x00037BA0
// with atexit cleanup; null path returns the static, else element+8.
// Caller 0x0021B215.
void *Rva00219B9E::rva0021AE56(unsigned int index)
{
    static StringBase<char> err("ERROR: Invalid SubCalssIndex");
    void *p = rva00219B9E(index);
    if (p)
        return (char *)p + 8;
    return &err;
}
// ?rva0021AEB9@Rva00219B9E@@QAEPAXI@Z @0x0021AEB9 99B
// Twin of 0x0021AE56 above with element+4: same static fallback literal,
// same rowed callees; caller 0x0021B303.
void *Rva00219B9E::rva0021AEB9(unsigned int index)
{
    static StringBase<char> err("ERROR: Invalid SubCalssIndex");
    void *p = rva00219B9E(index);
    if (p)
        return (char *)p + 4;
    return &err;
}
// ?rva0021AF7E@Rva00219B9E@@QAEPAXI@Z @0x0021AF7E 108B
// Outer 32-byte vector accessor at +0x14C with static "ERROR: Invalid CalssIndex"
// fallback; callers 0x0021CB79 0x005B20FB.
void *Rva00219B9E::rva0021AF7E(unsigned int index)
{
    static StringBase<char> err("ERROR: Invalid CalssIndex");
    unsigned int count = Vec32Size(&m_outer);
    if (index < count)
        return &Vec32At(&m_outer, index);
    return &err;
}
// ?rva0021AFEA@Rva00219B9E@@QAEPAXI@Z @0x0021AFEA 112B
// Twin of 0x0021AF7E returning outer element+4; same literal and callees;
// callers 0x0021CB51 0x005B55B4.
void *Rva00219B9E::rva0021AFEA(unsigned int index)
{
    static StringBase<char> err("ERROR: Invalid CalssIndex");
    unsigned int count = Vec32Size(&m_outer);
    if (index < count)
        return (char *)&Vec32At(&m_outer, index) + 4;
    return &err;
}
// ?rva0021B05A@Rva00219B9E@@QAEPAXI@Z @0x0021B05A 112B
// Twin of 0x0021AF7E/0x0021AFEA returning outer element+8; same literal
// and callees; caller 0x0021CBA1.
void *Rva00219B9E::rva0021B05A(unsigned int index)
{
    static StringBase<char> err("ERROR: Invalid CalssIndex");
    unsigned int count = Vec32Size(&m_outer);
    if (index < count)
        return (char *)&Vec32At(&m_outer, index) + 8;
    return &err;
}
// ?rva0021B0CA@Rva00219B9E@@QAEPAXI@Z @0x0021B0CA 112B
// Twin returning outer element+0xC; same literal and callees;
// caller 0x005B56FC.
void *Rva00219B9E::rva0021B0CA(unsigned int index)
{
    static StringBase<char> err("ERROR: Invalid CalssIndex");
    unsigned int count = Vec32Size(&m_outer);
    if (index < count)
        return (char *)&Vec32At(&m_outer, index) + 0xC;
    return &err;
}
// ?rva0021B1B4@Rva00219B9E@@QAEPAXII@Z @0x0021B1B4 122B
// Two-level lookup: outer 32B vector at +0x14C selects the element, then the
// rowed 0x0021AE56 accessor resolves the inner index; either level falls back
// to its own static error string. Outer elements share the +0x14 Vec216
// prefix the callee reads, hence the layout-compatible reinterpret cast.
void *Rva00219B9E::rva0021B1B4(unsigned int o, unsigned int i)
{
    static StringBase<char> err("ERROR: Invalid CalssIndex");
    unsigned int count = Vec32Size(&m_outer);
    if (o < count) {
        OuterElem32 *base = m_outer.m_start;
        return ((Rva00219B9E *)&base[o])->rva0021AE56(i);
    }
    return &err;
}
// ?rva0021B2A2@Rva00219B9E@@QAEPAXII@Z @0x0021B2A2 122B
// Twin of 0x0021B1B4 resolving through the +4 accessor 0x0021AEB9;
// callers 0x0021CC0C 0x005B561A.
void *Rva00219B9E::rva0021B2A2(unsigned int o, unsigned int i)
{
    static StringBase<char> err("ERROR: Invalid CalssIndex");
    unsigned int count = Vec32Size(&m_outer);
    if (o < count) {
        OuterElem32 *base = m_outer.m_start;
        return ((Rva00219B9E *)&base[o])->rva0021AEB9(i);
    }
    return &err;
}
// ?rva0021A134@Rva00219B9E@@QAEPAXI@Z @0x0021A134 41B
// Outer 32-byte vector accessor at +0x14C returning element+0x10 or TheEmptyString.
// Same outer vector as 0x0021AF7E/0x0021AFEA; +0x10 holds an AsciiString.
// Proven by callers 0x004085A1/0x00409490 forwarding the result to StringBase copy 0x000365F0.
void *Rva00219B9E::rva0021A134(unsigned int index)
{
    unsigned int count = Vec32Size(&m_outer);
    if (index < count)
        return (char *)&Vec32At(&m_outer, index) + 0x10;
    return &AsciiString::TheEmptyString;
}
// ?rva0021A016@Rva00219B9E@@QAEHII@Z @0x0021A016 43B
// Two-level int lookup: outer 32B vector at +0x14C selects the element, then the
// rowed 0x00219CDF accessor resolves the inner index; out-of-range returns 0.
// Same reinterpret-cast pattern as 0x0021B1B4/0x0021B2A2. Caller 0x00407037.
int Rva00219B9E::rva0021A016(unsigned int o, unsigned int i)
{
    unsigned int count = Vec32Size(&m_outer);
    if (o < count) {
        OuterElem32 *base = m_outer.m_start;
        return ((Rva00219B9E *)&base[o])->rva00219CDF(i);
    }
    return 0;
}
// ?rva0021A041@Rva00219B9E@@QAEHII@Z @0x0021A041 43B
// Twin of 0x0021A016 resolving through the +0x14 accessor 0x00219CF6;
// caller 0x00407050.
int Rva00219B9E::rva0021A041(unsigned int o, unsigned int i)
{
    unsigned int count = Vec32Size(&m_outer);
    if (o < count) {
        OuterElem32 *base = m_outer.m_start;
        return ((Rva00219B9E *)&base[o])->rva00219CF6(i);
    }
    return 0;
}
// ?rva0021A06C@Rva00219B9E@@QAEHII@Z @0x0021A06C 43B
// Twin resolving through the +0x18 accessor 0x00219D0D; caller 0x00407069.
int Rva00219B9E::rva0021A06C(unsigned int o, unsigned int i)
{
    unsigned int count = Vec32Size(&m_outer);
    if (o < count) {
        OuterElem32 *base = m_outer.m_start;
        return ((Rva00219B9E *)&base[o])->rva00219D0D(i);
    }
    return 0;
}
// ?rva0021A097@Rva00219B9E@@QAEHII@Z @0x0021A097 43B
// Twin resolving through the +0x1C accessor 0x00219D24; caller 0x005B1B81.
int Rva00219B9E::rva0021A097(unsigned int o, unsigned int i)
{
    unsigned int count = Vec32Size(&m_outer);
    if (o < count) {
        OuterElem32 *base = m_outer.m_start;
        return ((Rva00219B9E *)&base[o])->rva00219D24(i);
    }
    return 0;
}
// ?rva0021A1B6@Rva00219B9E@@QAEPAXII@Z @0x0021A1B6 43B
// Twin returning the inner element itself via rowed 0x00219B9E; null on miss.
// Callers 0x0021D58E/0x00409A93.
void *Rva00219B9E::rva0021A1B6(unsigned int o, unsigned int i)
{
    unsigned int count = Vec32Size(&m_outer);
    if (o < count) {
        OuterElem32 *base = m_outer.m_start;
        return ((Rva00219B9E *)&base[o])->rva00219B9E(i);
    }
    return 0;
}
// ?rva0021A15D@Rva00219B9E@@QAEPAXII@Z @0x0021A15D 46B
// Two-level string lookup: outer 32B vector at +0x14C selects the element,
// then the rowed 0x00219CC5 accessor resolves the inner index to element+0x20;
// out-of-range returns TheEmptyString. Same reinterpret-cast pattern as
// 0x0021A016/0x0021A1B6. Caller 0x004085D7.
void *Rva00219B9E::rva0021A15D(unsigned int o, unsigned int i)
{
    unsigned int count = Vec32Size(&m_outer);
    if (o < count) {
        OuterElem32 *base = m_outer.m_start;
        return ((Rva00219B9E *)&base[o])->rva00219CC5(i);
    }
    return &AsciiString::TheEmptyString;
}
