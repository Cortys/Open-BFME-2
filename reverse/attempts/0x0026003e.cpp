// ?Rva0026003EGet@@YAHHPAXMM@Z
// partial score=0.97 date=2026-09-30
// ?Rva0026003EGet@@YAHHPAXMM@Z
// partial score=0.97 date=2026-09-30
// cl: /O1 /MD /arch:SSE /G7
// ?Rva0026003EGet@@YAHHPAXMM@Z @0x0026003E 158B
// Evidence: unlock lane, callers at 0x002601B7 0x0026026E in 0x002600DC, callee fabs 0x00629210 rowed.
extern "C" double __cdecl fabs(double v);

struct Rva0026003EState {
    char m_pad[0x24];
    float m_vals[15];
    unsigned char m_flag60;
};

// ?Rva0026003EGet@@YAHHPAXMM@Z present-unmatched
int __cdecl Rva0026003EGet(int a, void *objRaw, float f1, float f2)
{
    Rva0026003EState *obj = (Rva0026003EState *)objRaw;
    float diff = (float)fabs(f2 - f1);
    if (obj->m_flag60) {
        int i2 = (int)f2;
        int i1 = (int)f1;
        int *p;
        if (i2 < i1)
            p = &i2;
        else
            p = &i1;
        return (int)(obj->m_vals[a] * diff) + *p;
    } else {
        int i2 = (int)f2;
        int i1 = (int)f1;
        int m = (a < 15) ? a : 15;
        int clamped;
        if (m <= 0)
            clamped = 0;
        else if (a >= 15)
            clamped = 15;
        else
            clamped = a;
        int *p = (i2 < i1) ? &i2 : &i1;
        return ((int)diff / 15) * clamped + *p;
    }
}
