// ?rva005F0647@Rva005F0647@@QAEPAXI@Z @0x005F0647 37B.
// Deleting-dtor shape: releases holder target via rowed fastcall Release at 0x0007DEEF
// then conditionally deletes this when flag bit0 is set and returns this.
// Unblocks 0x005F0C39. TU-local honest-address views.
// cl: /O1 /MD
struct TargetRef00217D4C { virtual void *destroy(unsigned int); int references; };
void __fastcall ReleaseTreeHintRef00217D4C(TargetRef00217D4C *);
void operator delete(void *);
struct Rva005F0647Holder { char pad[4]; TargetRef00217D4C target; };
struct Rva005F0647 { Rva005F0647Holder *holder; void *rva005F0647(unsigned int); };
void *Rva005F0647::rva005F0647(unsigned int flags)
{
    if (holder)
        ReleaseTreeHintRef00217D4C(&holder->target);
    if (flags & 1)
        ::operator delete(this);
    return this;
}
