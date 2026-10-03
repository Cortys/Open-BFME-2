// ?Rva006C87B0Get@@YA_NPAUHKEY__@@UTwoStr@@PAI@Z
// partial score=0.93 date=2026-10-03
// cl: /O2 /EHs /MD
// ?Rva006C87B0Get@@YA_NPAUHKEY__@@UTwoStr@@PAI@Z @0x006C87B0 252B registry DWORD read single 24B two-string struct goto-fail data-before-type; evidence: RegOpenKeyExA 0x20019 RegQueryValueExA RegCloseKey free x2 bool return; callers 0x006C8AE0x2
struct HKEY__;
typedef HKEY__ *HKEY;
typedef unsigned long DWORD;
typedef long LONG;
typedef unsigned char BYTE;
#define ERROR_SUCCESS 0L
extern "C" __declspec(dllimport) LONG __stdcall RegOpenKeyExA(HKEY hKey, const char *lpSubKey, DWORD ulOptions, DWORD samDesired, HKEY *phkResult);
extern "C" __declspec(dllimport) LONG __stdcall RegQueryValueExA(HKEY hKey, const char *lpValueName, DWORD *lpReserved, DWORD *lpType, BYTE *lpData, DWORD *lpcbData);
extern "C" __declspec(dllimport) LONG __stdcall RegCloseKey(HKEY hKey);
extern "C" void __cdecl free(void *p);
struct TwoStr { char *p1; int a1; int b1; char *p2; int a2; int b2; ~TwoStr() { if (p1) free(p1); if (p2) free(p2); } };
// ?Rva006C87B0Get@@YA_NPAUHKEY__@@UTwoStr@@PAI@Z present-unmatched
bool Rva006C87B0Get(HKEY hKey, TwoStr keys, unsigned int *out)
{
	HKEY handle;
	DWORD size = 4;
	DWORD data;
	DWORD type;
	LONG ret = RegOpenKeyExA(hKey, keys.p1, 0, 0x20019, &handle);
	if (ret != ERROR_SUCCESS)
		goto fail;
	ret = RegQueryValueExA(handle, keys.p2, 0, &type, (BYTE *)&data, &size);
	RegCloseKey(handle);
	if (ret != ERROR_SUCCESS)
		goto fail;
	*out = data;
	return true;
fail:
	return false;
}
