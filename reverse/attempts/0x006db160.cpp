// ?allocBlock@Rva006DB160@@QAEPAXH@Z
// partial score=0.95 date=2026-10-01
// cl: /O2 /MD
#include <string.h>

extern void *(__cdecl *g_00E17728)(unsigned int);
extern void (__cdecl *g_bfmeAptAssertAtE17734)(const char *, const char *, int);
extern int g_bfmeAptBreakOnAssertAtDDC01C;
void __debugbreak();
#pragma intrinsic(__debugbreak)

struct _DOGMA_MemPool
{
    _DOGMA_MemPool *mpNextPool;
    unsigned int mnPoolSize;
    unsigned int mnPoolFree;
};

class Rva006DAFE0Opaque
{
public:
    void *rva006DAFE0(unsigned int nSize);
};

class Rva006DB160
{
    void **m_table;
    _DOGMA_MemPool *m_firstPool;
    unsigned int m_poolSize;
    unsigned int m_maxSize;
    union {
        unsigned int m_cfg;
        struct {
            unsigned char m_nextIdx;
            unsigned char m_sizeIdx;
            unsigned char m_prevIdx;
            unsigned char m_minByte;
        };
    };
    int m_used;
    int m_count;
public:
    void *allocBlock(int blockSize);
};

void *Rva006DB160::allocBlock(int blockSize)
{
    Rva006DB160 *self = this;
    int aligned = blockSize;
    if ((aligned & 3) != 0)
        aligned = (aligned & ~3) + 4;
    unsigned int minSize = (unsigned int)self->m_minByte & 0xf;
    if ((unsigned int)aligned < minSize)
        aligned = (int)minSize;
    if ((unsigned int)aligned > self->m_maxSize)
        return g_00E17728((unsigned int)blockSize);

    _DOGMA_MemPool *pool;
    ++self->m_used;
    if (self->m_table[(unsigned int)aligned >> 2] != 0)
        return reinterpret_cast<Rva006DAFE0Opaque *>(self)->rva006DAFE0((unsigned int)aligned);

    pool = self->m_firstPool;
    do {
        if (pool->mnPoolFree >= (unsigned int)aligned)
            break;
        pool = pool->mpNextPool;
    } while (pool != 0);
    if (pool == 0) {
        pool = (_DOGMA_MemPool *)g_00E17728(self->m_poolSize);
        memset(pool, 0x0d, self->m_poolSize);
        unsigned int poolSize = self->m_poolSize;
        _DOGMA_MemPool *nextPool = self->m_firstPool;
        unsigned int initialFree = poolSize + (unsigned int)(signed char)0xf1;
        pool->mnPoolSize = initialFree;
        pool->mnPoolFree = initialFree;
        pool->mpNextPool = nextPool;
        self->m_firstPool = pool;
        if (pool->mnPoolFree < (unsigned int)aligned) {
            g_bfmeAptAssertAtE17734("pPool->CanFitBytes( nSize )", "C:\\projects\\bfme2patch103\\bfme2\\Code\\Libraries\\Source\\Apt\\DogmaAllocator.cpp", 0x1b9);
            if (g_bfmeAptBreakOnAssertAtDDC01C)
                __asm int 3
        }
        unsigned int oldFree = pool->mnPoolFree;
        unsigned int used = pool->mnPoolSize - oldFree;
        pool->mnPoolFree = oldFree - (unsigned int)aligned;
        return (unsigned char *)pool + 12 + used;
    }

    unsigned int oldFree = pool->mnPoolFree;
    unsigned int used = pool->mnPoolSize - oldFree;
    pool->mnPoolFree = oldFree - (unsigned int)aligned;
    return (unsigned char *)pool + 12 + used;
}
