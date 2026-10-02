// cl: /O2 /DNDEBUG /MD
// Target reconstruction: complete Ghidra boundary 0x007B9A50, 40B,
// registered through CRT atexit by the 12B body at 0x007B5410.
// The global head's original name and node payload are unknown. Retail
// saves each first-word next pointer, frees the node through the matched
// game allocator _free (0x00030830), then updates the global at VA E07C08.
extern "C" void __cdecl free(void *);
extern "C" int __cdecl atexit(void (__cdecl *callback)());

struct RvaCleanupNode
{
    RvaCleanupNode *next;
};
// g_chainHeadAtE07C08: matched references place it at VA 0xe07c08 (retail .data initial value 0).
RvaCleanupNode * g_chainHeadAtE07C08 = 0;
// g_chainHeadAtE1D060: matched references place it at VA 0xe1d060 (retail .data initial value 0).
RvaCleanupNode * g_chainHeadAtE1D060 = 0;

void rva007B9A50()
{
    while (g_chainHeadAtE07C08) {
        RvaCleanupNode *next = g_chainHeadAtE07C08->next;
        free(g_chainHeadAtE07C08);
        g_chainHeadAtE07C08 = next;
    }
}

// Independently proven 40B boundary at 0x007B9C80 and atexit registration
// at 0x007B67F0. This is a second list, with its own global at VA E1D060.
void rva007B9C80()
{
    while (g_chainHeadAtE1D060) {
        RvaCleanupNode *next = g_chainHeadAtE1D060->next;
        free(g_chainHeadAtE1D060);
        g_chainHeadAtE1D060 = next;
    }
}

// 12B registration body, bounded by int3 at 7B540F and after ret7B541B.
void rva007B5410()
{
    atexit(rva007B9A50);
}

// Independent 12B registration bounded by int3 and ret at 0x007B67FB.
void rva007B67F0()
{
    atexit(rva007B9C80);
}

// Three more lists of the same shape, each with its own 40-byte cleanup and
// 12-byte atexit registration (byte-identical to the pairs above but for the
// head and cleanup operands). Each head is zero-filled .bss that only its
// cleanup references, so it is defined here.

RvaCleanupNode *g_chainHeadAtDF3680;

void rva007B7130()
{
    while (g_chainHeadAtDF3680) {
        RvaCleanupNode *next = g_chainHeadAtDF3680->next;
        free(g_chainHeadAtDF3680);
        g_chainHeadAtDF3680 = next;
    }
}

// 12B registration at 0x007ACE10, bounded by int3/ret on both sides.
void rva007ACE10()
{
    atexit(rva007B7130);
}

RvaCleanupNode *g_chainHeadAtDF3694;

void rva007B7160()
{
    while (g_chainHeadAtDF3694) {
        RvaCleanupNode *next = g_chainHeadAtDF3694->next;
        free(g_chainHeadAtDF3694);
        g_chainHeadAtDF3694 = next;
    }
}

// 12B registration at 0x007ACE20, bounded by int3/ret on both sides.
void rva007ACE20()
{
    atexit(rva007B7160);
}

RvaCleanupNode *g_chainHeadAtDFCEC8;

void rva007B74C0()
{
    while (g_chainHeadAtDFCEC8) {
        RvaCleanupNode *next = g_chainHeadAtDFCEC8->next;
        free(g_chainHeadAtDFCEC8);
        g_chainHeadAtDFCEC8 = next;
    }
}

// 12B registration at 0x007ACF90, bounded by int3/ret on both sides.
void rva007ACF90()
{
    atexit(rva007B74C0);
}
