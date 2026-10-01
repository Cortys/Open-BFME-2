// ?Rva001F7F1CGet@@YAXPAXH@Z
// partial score=0.92 date=2026-10-01
// ?Rva001F7F1CGet@@YAXPAXH@Z
// partial score=0.92 date=2026-10-01
// ?Rva001F7F1CGet@@YAXPAXH@Z
// partial score=0.92 date=2026-10-01
// cl: /O1 /MD /arch:SSE /EHsc
// ?Rva001F7F1CGet@@YAXPAXH@Z present-unmatched
class ParticleSystem;
extern ParticleSystem *Make001FCBD7();
struct Vec2001F529D { float x; float y; };
class Rva001F529D { public: void rva001F529D(Vec2001F529D *out); };
struct BfmeParticleSystemHandle { ~BfmeParticleSystemHandle(); void *m_system; void *m_prev; void *m_next; };
class RvaSmartPtr12 {
public:
    RvaSmartPtr12(const RvaSmartPtr12 &that);
    ~RvaSmartPtr12() { if (m_ptr != 0) ((BfmeParticleSystemHandle *)this)->~BfmeParticleSystemHandle(); }
    void *m_ptr;
    int m_pad04;
    int m_pad08;
};
class Rva001F6C54SmartField { public: RvaSmartPtr12 get() const; };
class ParticleSystemManager;
extern ParticleSystemManager *TheParticleSystemManager;
struct FinalVtbl { void *slots[34]; void (__stdcall *slot)(void *, int, void *); };
struct FinalObj { FinalVtbl *vtbl; };
struct Float4 { float a; float b; float c; float d; };
void __cdecl Rva001F7F1CGet(void *obj, int arg)
{
    float dest[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
    if (TheParticleSystemManager != 0 && ((Rva001F6C54SmartField *)TheParticleSystemManager)->get().m_ptr != 0) {
        RvaSmartPtr12 tmp2 = ((Rva001F6C54SmartField *)TheParticleSystemManager)->get();
        ParticleSystem *sys = (ParticleSystem *)tmp2.m_ptr;
        if (sys == 0)
            sys = Make001FCBD7();
        Vec2001F529D v;
        ((Rva001F529D *)sys)->rva001F529D(&v);
        Float4 tmpArr;
        tmpArr.a = v.x;
        tmpArr.b = v.y;
        tmpArr.c = 0.0f;
        tmpArr.d = 0.0f;
        *(Float4 *)dest = tmpArr;
    }
    FinalObj *o = (FinalObj *)obj;
    o->vtbl->slot(obj, arg, dest);
}
