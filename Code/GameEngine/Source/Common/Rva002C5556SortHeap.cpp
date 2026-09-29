// cl: /O1 /MD /G7
// ?Rva002C5556SortHeap@@YAXPAPAX0P6A_NPAX1@Z@Z @0x002C5556 58B
// sort_heap over 4-byte entries via rowed pop_heap 0x0021BAFC; caller
// 0x002C567B; same HeapLess comp. /G7 for retail and-al encoding.
typedef bool (__cdecl *HeapLess)(void *a, void *b);

void __cdecl Rva0021BAFCPopHeap(void **first, void **last, HeapLess comp);

void __cdecl Rva002C5556SortHeap(void **first, void **last, HeapLess comp)
{
	while ((((char *)last - (char *)first) & ~3) > 4) {
		Rva0021BAFCPopHeap(first, last, comp);
		--last;
	}
}
