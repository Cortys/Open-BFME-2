// ?Rva009A86F0Allocate@@YAHPAX@Z
// partial score=0.93 date=2026-10-04
// ?Rva009A86F0Allocate@@YAHPAX@Z 0x001B9140 396B retail codec allocator; BFME1 donor declares it in BfmeCheckJX.cpp; callers bfmeCheckJX at 0x001B95E6; callees bfmeStepJW and Rva001B6400Allocation::operator new are rowed
struct CodecState;
struct Rva009A8910Context;
class Rva001B6400Allocation { public: enum AllocationTag { Zero = 0 }; static void* operator new(unsigned, AllocationTag); };
void bfmeStepJW(void*);
struct CodecAllocState {
    void* at00;
    void* at04;
    unsigned char pad08[0x104];
    void* at10c;
    void* at110;
    void* at114;
    void* at118;
    void* at11c;
    void* at120;
    unsigned char pad124[0x24];
    void* at148;
    void* at14c;
    unsigned char pad150[0xA8];
    unsigned at1f8;
    unsigned at1fc;
    unsigned char pad200[0x28];
    unsigned at228;
    unsigned char pad22c[0x4C0];
    void* at6ec;
    void* at6f0;
    void* at6f4;
    void* at6f8;
    void* at6fc;
    void* at700;
};
// ?Rva009A86F0Allocate@@YAHPAX@Z present-unmatched
int Rva009A86F0Allocate(void* p)
{
    CodecAllocState* s = (CodecAllocState*)p;
    bfmeStepJW(p);
    void* a1 = Rva001B6400Allocation::operator new(0x320, Rva001B6400Allocation::Zero);
    s->at00 = a1;
    if (!a1)
        goto fail;
    s->at04 = (void*)(((unsigned)a1 + 31) & ~31u);
    unsigned sz2 = (s->at1f8 + 10) * 16;
    void* a2 = Rva001B6400Allocation::operator new(sz2, Rva001B6400Allocation::Zero);
    s->at118 = a2;
    if (!a2)
        goto fail;
    unsigned sz3 = (s->at1f8 / 2 + 10) * 16;
    s->at10c = (void*)(((unsigned)a2 + 31) & ~31u);
    void* a3 = Rva001B6400Allocation::operator new(sz3, Rva001B6400Allocation::Zero);
    s->at11c = a3;
    if (!a3)
        goto fail;
    s->at110 = (void*)(((unsigned)a3 + 31) & ~31u);
    unsigned sz4 = ((s->at1f8 >> 1) + 10) * 16;
    void* a4 = Rva001B6400Allocation::operator new(sz4, Rva001B6400Allocation::Zero);
    s->at120 = a4;
    if (!a4)
        goto fail;
    s->at114 = (void*)(((unsigned)a4 + 31) & ~31u);
    unsigned sz5 = s->at228 + 0x20;
    void* a5 = Rva001B6400Allocation::operator new(sz5, Rva001B6400Allocation::Zero);
    s->at6f8 = a5;
    if (!a5)
        goto fail;
    unsigned sz6 = s->at228 + 0x20;
    s->at6ec = (void*)(((unsigned)a5 + 31) & ~31u);
    void* a6 = Rva001B6400Allocation::operator new(sz6, Rva001B6400Allocation::Zero);
    s->at6fc = a6;
    if (!a6)
        goto fail;
    unsigned sz7 = s->at228 * 4 + 0x20;
    s->at6f0 = (void*)(((unsigned)a6 + 31) & ~31u);
    void* a7 = Rva001B6400Allocation::operator new(sz7, Rva001B6400Allocation::Zero);
    s->at700 = a7;
    if (!a7)
        goto fail;
    unsigned sz8 = s->at1fc * 4 + 0x20;
    s->at6f4 = (void*)(((unsigned)a7 + 31) & ~31u);
    void* a8 = Rva001B6400Allocation::operator new(sz8, Rva001B6400Allocation::Zero);
    s->at14c = a8;
    if (!a8)
        goto fail;
    s->at148 = (void*)(((unsigned)a8 + 31) & ~31u);
    return 1;
fail:
    bfmeStepJW(p);
    return 0;
}
