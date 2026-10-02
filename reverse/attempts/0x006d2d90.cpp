// ?Rva006D2D90Init@@YAXXZ
// partial score=0.88 date=2026-10-02
// cl: /O1 /MD
// ?Rva006D2D90Init@@YAXXZ @0x006D2D90 89B evidence byte table g_00CE8B70 plus globals E177E0-E177E8 plus caller 0x006CC380
// Scans the 47-byte Apt eType table at 0x00CE8B70 (indices 1..46) for min/max,
// seeds three bytes to 0/4/8, stores max dword and min clamped to 12.
extern unsigned char g_00E177E0;
extern unsigned char g_00E177E1;
extern unsigned char g_00E177E2;
extern int g_00E177E4;
extern unsigned char g_00E177E8;
extern unsigned char g_00CE8B70[];

// ?Rva006D2D90Init@@YAXXZ present-unmatched
void __cdecl Rva006D2D90Init()
{
	g_00E177E2 = 0;
	g_00E177E0 = 4;
	g_00E177E8 = 8;
	int maxVal = 0;
	unsigned int minVal = 1000000;
	for (int i = 1; i < 0x2f; ++i) {
		unsigned int v = g_00CE8B70[i];
		if (v > (unsigned int)maxVal)
			maxVal = (int)v;
		if (v < minVal)
			minVal = v;
	}
	g_00E177E4 = maxVal;
	if (minVal < 12) {
		g_00E177E1 = 12;
		return;
	}
	g_00E177E1 = (unsigned char)minVal;
}
