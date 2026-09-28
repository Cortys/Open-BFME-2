// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// ?rva003F498A@Rva003F498A@@QAEXPAVRva003F498ACallback@@@Z, retail 0x003F498A, 188 bytes.
// Triple-nested vector scan calling a virtual predicate on each int and
// returning early on false. Outer vector<Rva003F498AOuter 28B> at +0x18,
// middle vector<Rva003F498AInner 48B> at +4 of each outer, inner
// vector<int> at +4 of each middle. Sizes divide by 0x1C and 0x30 with
// push-const idiv and by 4 with sar 2. Callers 0x002B25EF 0x002B37FF
// 0x002B323C 0x003F4AD8 0x003F6A91 build 8-byte visitor structs with
// vtables 0x007FE000 0x007FDFF0 0x007FDFEC 0x00C37080 0x00C37064 and call
// here; slot 0 takes one int and returns bool in al. Flags and layout from
// neighbours stlport_asciistring_record_bodies.cpp and
// stlport_pod_vector_bodies.cpp with the same // cl:.
#include <vector>

class Rva003F498ACallback {
public:
    virtual bool invoke(int v) = 0;
};

struct Rva003F498AInner {
    int unk0;
    _STL::vector<int> vals;
    char pad[32];
};

struct Rva003F498AOuter {
    int unk0;
    _STL::vector<Rva003F498AInner> inners;
    _STL::vector<int> ints;
};

class Rva003F498A {
    char m_pad0[0x18];
    _STL::vector<Rva003F498AOuter> m_outers;
public:
    void rva003F498A(Rva003F498ACallback* cb);
    int rva003F46A8(int idx);
};

void Rva003F498A::rva003F498A(Rva003F498ACallback* cb)
{
    for (unsigned i = 0; i < m_outers.size(); ++i) {
        Rva003F498AOuter& o = m_outers[i];
        for (unsigned j = 0; j < o.inners.size(); ++j) {
            Rva003F498AInner& in = o.inners[j];
            for (unsigned k = 0; k < in.vals.size(); ++k) {
                if (!cb->invoke(in.vals[k]))
                    return;
            }
        }
    }
}

int Rva003F498A::rva003F46A8(int idx)
{
    Rva003F498AOuter& o = m_outers[idx];
    return (int)o.ints.size();
}
