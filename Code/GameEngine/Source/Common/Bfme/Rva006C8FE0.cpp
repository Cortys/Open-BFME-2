// cl: /O2 /EHs /MD /D_STLP_USE_STATIC_LIB /Ireference/shims/bfme2_ascii
// stlport
// ?Rva006C8FE0Get@@YA_NPAUHKEY__@@UStr12@@1AAV?$basic_string@DV?$char_traits@D@_STL@@V?$allocator@D@2@@_STL@@@Z @0x006C8FE0 323B registry string read two 12B structs register-q; evidence: RegOpenKeyExA 0x20019 RegQueryValueExA RegCloseKey assign free x2 bool return; callers 0x006C9130x2
#include <string>
#include <string.h>
struct HKEY__;
typedef HKEY__ *HKEY;
typedef unsigned long DWORD;
typedef long LONG;
#define ERROR_SUCCESS 0L
extern "C" __declspec(dllimport) LONG __stdcall RegOpenKeyExA(HKEY hKey, const char *lpSubKey, DWORD ulOptions, DWORD samDesired, HKEY *phkResult);
extern "C" __declspec(dllimport) LONG __stdcall RegQueryValueExA(HKEY hKey, const char *lpValueName, DWORD *lpReserved, DWORD *lpType, unsigned char *lpData, DWORD *lpcbData);
extern "C" __declspec(dllimport) LONG __stdcall RegCloseKey(HKEY hKey);
extern "C" void __cdecl free(void *p);
struct Str12 { char *p; int len; int max; ~Str12() { if (p) free(p); } };
bool Rva006C8FE0Get(HKEY hKey, Str12 subKey, Str12 valueName, _STL::string &out)
{
	HKEY handle;
	DWORD size = 256;
	DWORD type;
	char buffer[256];
	register LONG q;
	if (RegOpenKeyExA(hKey, subKey.p, 0, 0x20019, &handle) == ERROR_SUCCESS) {
		q = RegQueryValueExA(handle, valueName.p, 0, &type, (unsigned char *)buffer, &size);
		RegCloseKey(handle);
		if (q == ERROR_SUCCESS) {
			out.assign((const char *)buffer, (const char *)buffer + strlen(buffer));
			return true;
		}
	}
	return false;
}
