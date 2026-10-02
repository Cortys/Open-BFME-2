// ?initBlocksRva009B3EC0@@YAXPAX@Z
// g_Rva009B3E40Arr0: matched references place it at VA 0xdb7c28; zero-filled at retail, sized to the
// 0x4-byte gap before the next known global there.
int g_Rva009B3E40Arr0[1];
extern int g_Rva009B3E40Arr1[];
extern int g_Rva009B3E40Arr2[];
extern int g_Rva009B3E40Arr3[];
extern void* g_Rva009B3EC0Blocks[];

void initBlocksRva009B3EC0(void* self)
{
	*(void***)((char*)self + 0x13c) = g_Rva009B3EC0Blocks;

	for (int i = 0; i < 0x40; i += 4) {
		*((char*)g_Rva009B3EC0Blocks[g_Rva009B3E40Arr0[i]] + (unsigned)self + 0x140) = (char)(i + 0);
		*((char*)g_Rva009B3EC0Blocks[g_Rva009B3E40Arr1[i]] + (unsigned)self + 0x140) = (char)(i + 1);
		*((char*)g_Rva009B3EC0Blocks[g_Rva009B3E40Arr2[i]] + (unsigned)self + 0x140) = (char)(i + 2);
		*((char*)g_Rva009B3EC0Blocks[g_Rva009B3E40Arr3[i]] + (unsigned)self + 0x140) = (char)(i + 3);
	}
}
