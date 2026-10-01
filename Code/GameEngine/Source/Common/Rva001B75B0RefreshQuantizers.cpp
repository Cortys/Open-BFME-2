// Donor: Open-BFME-1 10af19f44a89ab7ecc23195bb9a842ceafbc02c9,
// game/GameEngine/Source/Common/Rva009A4D00TableInit.cpp, b1 0x009A6B40.
// Target: [0x001B75B0,0x001B760D), RET then INT3 padding. The opaque
// receiver compares words at +0x38 and +0x3C+4*index, copies +4 to +0x38,
// resets its inverse map, then calls verified RVAs 0x001B71F0/0x001B70A0.
// No original function, owner class or vendor identity is asserted.
//
// The two table labels preserve existing linked references. Their required
// 64-dword contents are independently copied from target VAs 0x00BD8460
// and 0x00BD8560. No larger native data extent or data-progress claim is made.
// SHA256: permutation 477a41fa6d9fd843864600082cefe2f3ccc83da572a45c14efe90b579d2cec0f;
// identity fea7b32778ecbdd7adee1941e98c89cf96bbc762f5f1beb0be24e36a456fbbc5.
//
// Both retail calls push self plus a forwarded word and clean 16 bytes
// together. The linked quantizer emission view reads only self; the typed
// call adapter retains that extra unused word without inventing a new callee
// pin or claiming the original native formal parameter count.

#include <string.h>

struct Rva009A6780State;
struct BfmeS1040;
void Rva009A6780BuildQuantizers(Rva009A6780State *);
void bfmeApply1040(BfmeS1040 *, int);

int g_rva01142308[64] = {
    0, 1, 8, 16, 9, 2, 3, 10, 17, 24, 32, 25, 18, 11, 4, 5,
    12, 19, 26, 33, 40, 48, 41, 34, 27, 20, 13, 6, 7, 14, 21, 28,
    35, 42, 49, 56, 57, 50, 43, 36, 29, 22, 15, 23, 30, 37, 44, 51,
    58, 59, 52, 45, 38, 31, 39, 46, 53, 60, 61, 54, 47, 55, 62, 63
};
int g_rva01142408[64] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
    32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
    48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63
};

static __forceinline unsigned codecWord(const char *p)
{
    unsigned value;
    memcpy(&value, p, 4);
    return value;
}

static __forceinline void resetInverseMap(char *bytes)
{
    int *table = g_rva01142408;
    memcpy(bytes + 0x13c, &table, 4);
    for (int i = 0; i < 64; ++i)
        bytes[0x140 + g_rva01142308[i]] = (char)i;
}

void Rva001B75B0RefreshQuantizers(void *self, int forwarded)
{
    char *bytes = static_cast<char *>(self);
    unsigned index = codecWord(bytes);
    int selected = codecWord(bytes + 0x3c + index * 4);
    int current = codecWord(bytes + 0x38);
    if (selected == current)
        return;
    memcpy(bytes + 0x38, bytes + 4, 4);
    resetInverseMap(bytes);

    typedef void (__cdecl *QuantizerCaller)(Rva009A6780State *, int);
    reinterpret_cast<QuantizerCaller>(Rva009A6780BuildQuantizers)(
        static_cast<Rva009A6780State *>(self), forwarded);
    bfmeApply1040(static_cast<BfmeS1040 *>(self), forwarded);
}
