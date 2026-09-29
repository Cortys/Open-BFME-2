// cl: /O1 /MD
// ?Rva002198ECAdjustHeap@@YAXPAPAXHHPAXP6A_N11@Z@Z @0x002198EC 91B
// __adjust_heap for 4-byte entries: percolate hole down then tail-call __push_heap.
// Evidence: packet disassembly matches STL __adjust_heap shape; calls rowed
// ?Rva0021956EPushHeap at 0x0021956E with (first,hole,top,value,comp); stride 4.
typedef bool (__cdecl *HeapLess)(void *a, void *b);

void __cdecl Rva0021956EPushHeap(void **first, int holeIndex, int topIndex, void *value, HeapLess comp);

void __cdecl Rva002198ECAdjustHeap(void **first, int holeIndex, int len, void *value, HeapLess comp)
{
	int topIndex = holeIndex;
	int secondChild = holeIndex + holeIndex + 2;
	while (secondChild < len) {
		if (comp(first[secondChild], first[secondChild - 1]))
			--secondChild;
		first[holeIndex] = first[secondChild];
		holeIndex = secondChild;
		secondChild += secondChild + 2;
	}
	if (secondChild == len) {
		first[holeIndex] = first[secondChild - 1];
		holeIndex = secondChild - 1;
	}
	Rva0021956EPushHeap(first, holeIndex, topIndex, value, comp);
}
