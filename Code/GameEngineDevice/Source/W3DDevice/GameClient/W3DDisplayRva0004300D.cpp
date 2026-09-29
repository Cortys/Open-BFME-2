// cl: /O1 /MD
// ?Rva0004300DGet@@YA_JXZ, retail 0x0004300D, 23 bytes.
// Free-function QueryPerformanceCounter wrapper returning the 64-bit tick.
// Evidence: IAT kernel32 QueryPerformanceCounter; edx:eax return; callers
// 0x000437B6 0x00043E5B 0x00043EB8 0x000483C0.
extern "C" __declspec(dllimport) int __stdcall QueryPerformanceCounter(__int64 *ts);

__int64 __cdecl Rva0004300DGet()
{
	__int64 ts;
	QueryPerformanceCounter(&ts);
	return ts;
}
