// ?rva006D2CB0@Rva006D2A60@@QAEPAXXZ
// partial score=0.5 date=2026-10-04
// cl: /O2 /DNDEBUG /MD
// ?rva006D2CB0@Rva006D2A60@@QAEPAXXZ @ 0x006D2CB0 (138B).
//
// AptValueGCAllocator block walk: starting at this+4 (the first block of the
// allocator's block list), it scans each block's value area from block+0xC to
// block+0xC + (block[+4] - block[+8]), advancing by each value's own size
// (the rowed-with-pin accessor 0x006D2930), and returns the first value whose
// mbIsAllocated bit is set. The mode byte at VA 0x00E177E0 selects which word
// carries the bit (mode 4 -> value+4, mode 0 -> value+0); any other mode
// asserts false at AptValueGCAllocator.h line 0xE2. Returns 0 across all
// blocks.
//
// Separate TU from the 0x006D29E0 alloc body: that body views the allocated
// object (bitfield at +4), while this one views the pool itself (+4 is the
// block-list head), and the two cannot share one class layout.

extern void (__cdecl *g_bfmeAptAssertAtE17734)(const char *, const char *, int);
extern int g_bfmeAptBreakOnAssertAtDDC01C;

extern unsigned char g_bfmeAptGCAllocModeAtE177E0;
// g_bfmeAptGCAllocModeAtE177E0: the mode byte read at VA 0xe177e0 (zero-filled .bss).

class Rva006D2A60
{
public:
	void *rva006D2CB0();
	int rva006D2930(int mode);

	struct Block
	{
		Block *m_next;
		int m_field4;
		int m_field8;
	};

	int m_pad0;
	Block *m_blocks;
};

void *Rva006D2A60::rva006D2CB0()
{
	Block *block = m_blocks;
	while (block != 0)
	{
		char *start = (char *)block + 0xc;
		char *cursor = start;
		while (cursor >= start &&
			cursor < start + (block->m_field4 - block->m_field8))
		{
			if (g_bfmeAptGCAllocModeAtE177E0 == 4)
			{
				if ((*(unsigned char *)(cursor + 4) & 1) != 0)
					return cursor;
			}
			else if (g_bfmeAptGCAllocModeAtE177E0 == 0)
			{
				if ((*(unsigned char *)cursor & 1) != 0)
					return cursor;
			}
			else
			{
				g_bfmeAptAssertAtE17734("false",
					"..\\..\\include\\apt\\AptValueGCAllocator.h", 0xE2);
				if (g_bfmeAptBreakOnAssertAtDDC01C) { __asm int 3 }
			}
			cursor += ((Rva006D2A60 *)cursor)->rva006D2930(g_bfmeAptGCAllocModeAtE177E0);
		}
		block = block->m_next;
	}
	return 0;
}
