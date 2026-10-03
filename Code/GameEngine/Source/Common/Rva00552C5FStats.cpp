// cl: /O1 /MD
// ?Rva00552C5FGet@@YAEXZ 0x00552C5F 27B: free returns 1 if stats connected else init==0; callers 0x0055819C
extern "C" int __cdecl IsStatsConnected();
extern "C" int __cdecl InitStatsConnection(int);

unsigned char __cdecl Rva00552C5FGet()
{
	if (IsStatsConnected())
		return 1;
	return (unsigned char)(InitStatsConnection(0) == 0);
}
