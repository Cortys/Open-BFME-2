// cl: /O2 /DNDEBUG /MD
// Target reconstruction: complete Ghidra boundary 0x007B9A50, 40B,
// registered through CRT atexit by the 12B body at 0x007B5410.
// The global head's original name and node payload are unknown. Retail
// saves each first-word next pointer, frees the node through the matched
// game allocator _free (0x00030830), then updates the global at VA E07C08.
extern "C" void __cdecl free(void *);

struct RvaCleanupNode
{
    RvaCleanupNode *next;
};
extern RvaCleanupNode *g_chainHeadAtE07C08;

void rva007B9A50()
{
    while (g_chainHeadAtE07C08) {
        RvaCleanupNode *next = g_chainHeadAtE07C08->next;
        free(g_chainHeadAtE07C08);
        g_chainHeadAtE07C08 = next;
    }
}
