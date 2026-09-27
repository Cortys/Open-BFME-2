// cl: /GX-
// ?Rva000308E0AddHeap@@YAXII@Z @ 0x000308E0 16B
// Guarded AddHeap forwarder: if the init flag at 0x00DE0821 is set, tail-jumps
// to the resolved MemoryPool _AddHeap pointer at 0x00DE03E8 with the same
// (id, size) args, else returns. Evidence: callers at 0x0022542E 0x0022543E
// 0x00225449 0x00225454 push (id, size), 0x00030730 stores _AddHeap at
// 0x00DE03E8, flag 0x00DE0821 set only while _Init runs, sibling guard thunks
// at 0x00030890 0x000308B0. Honest address-derived name. No STL.
extern unsigned char g_Va00DE0821;
extern void (__cdecl *g_Va00DE03E8)(unsigned int id, unsigned int size);

void Rva000308E0AddHeap(unsigned int id, unsigned int size)
{
	if (g_Va00DE0821 != 0)
		g_Va00DE03E8(id, size);
}
