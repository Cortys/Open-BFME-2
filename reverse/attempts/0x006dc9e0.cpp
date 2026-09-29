// ?rva006DC9E0@Rva006DC9E0@@QAEHXZ
// partial score=0.94 date=2026-09-29
// ?rva006DC9E0@Rva006DC9E0@@QAEHXZ
// partial score=0.94 date=2026-09-29
// cl: /O2 /MD
// ?rva006DC9E0@Rva006DC9E0@@QAEHXZ @0x006DC9E0 123B
// Evidence: thiscall no args returns bool (xor 0 / mov 1); calls GetString 0x5E/0x64,
// Rva0070A5C0::Find via global 0x00E18650, virtual slot 3 (0xC) twice plus this slot 3
// and node walk via +8 with edi/ebx sentinels from +0xC fields; callers 0x006DFBF8 0x0070857A.
class EAStringC;
EAStringC *__cdecl Rva0070B4F0GetString(int eSC);

struct Mid {
    char pad8[8];
    void *field8;
    void *fieldC;
};

struct VirtObj {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Mid *virt3();
};

struct Finder {
public:
    VirtObj *rva0070A5C0(EAStringC *s);
};

extern Finder *g_00E18650;

class Rva006DC9E0 {
public:
    int rva006DC9E0();
};

// ?rva006DC9E0@Rva006DC9E0@@QAEHXZ present-unmatched
int Rva006DC9E0::rva006DC9E0()
{
    EAStringC *s1 = Rva0070B4F0GetString(0x5E);
    VirtObj *f1 = g_00E18650->rva0070A5C0(s1);
    Mid *m1 = f1->virt3();
    void *edi = m1->fieldC;
    EAStringC *s2 = Rva0070B4F0GetString(0x64);
    VirtObj *f2 = g_00E18650->rva0070A5C0(s2);
    Mid *m2 = f2->virt3();
    void *ebx = m2->fieldC;
    if (this == edi)
        return 1;
    VirtObj *self = (VirtObj *)this;
    Mid *m = self->virt3();
    if (!m)
        return 0;
    while (true) {
        VirtObj *node = (VirtObj *)m->field8;
        if (!node)
            return 0;
        if (node == edi)
            return 1;
        if (node == ebx)
            return 0;
        m = node->virt3();
        if (!m)
            return 0;
    }
}
