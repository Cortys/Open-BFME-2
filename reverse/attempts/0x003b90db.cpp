// ??0Rva003B90DB@@QAE@XZ
// partial score=0.95 date=2026-10-01
// cl: /Os /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ??0Rva003B90DB@@QAE@XZ @0x003B90DB 73B — ctor with baseConstruct + Snapshot stub + two BfmeE16 vectors + two bools; donor stlport_vector_e16_o1.cpp for BfmeE16; caller 0x0022F7F9; next row LivingWorldCampaignManager name getter
#include <vector>
struct BfmeE16 { float x, y, z, w; };
extern const void *const g_00BBB554[];
extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)
class __declspec(novtable) BFME2NativeNetwork {
public:
    __forceinline BFME2NativeNetwork() { baseConstruct(); }
    virtual ~BFME2NativeNetwork() { _ReadWriteBarrier(); }
    BFME2NativeNetwork *baseConstruct();
private:
    virtual void unused() = 0;
    char m_flag;
    int m_value;
};
class __declspec(novtable) SnapshotBase {
public:
    __forceinline SnapshotBase() { m_val = 0; *(const void **)this = g_00BBB554; }
private:
    virtual void unused() = 0;
    int m_val;
};
class Rva003B90DB : public BFME2NativeNetwork, public SnapshotBase {
public:
    Rva003B90DB();
private:
    _STL::vector<BfmeE16, _STL::allocator<BfmeE16> > m_vec14;
    _STL::vector<BfmeE16, _STL::allocator<BfmeE16> > m_vec20;
    bool m_b1;
    bool m_b2;
};
// ??0Rva003B90DB@@QAE@XZ present-unmatched
Rva003B90DB::Rva003B90DB()
    : m_vec14(_STL::allocator<BfmeE16>()), m_vec20(_STL::allocator<BfmeE16>())
{
    m_b1 = false;
    m_b2 = false;
}
