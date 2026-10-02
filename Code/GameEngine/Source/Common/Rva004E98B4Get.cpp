// cl: /O1 /MD
// ?Rva004E98B4Get@@YGMH@Z @0x004E98B4 42B free stdcall float Get(int unused) wraps rowed GetGameLogicRandomValueReal 0x00234092 with globals file-line 180 caller 0x004E9DA8
float __cdecl GetGameLogicRandomValueReal(float lo, float hi, char *file, int line);
extern float g_00C62800;
extern float g_00C62804;
extern char g_00C62808[];

float __stdcall Rva004E98B4Get(int unused)
{
    return GetGameLogicRandomValueReal(g_00C62804, g_00C62800, g_00C62808, 0xB4);
}
