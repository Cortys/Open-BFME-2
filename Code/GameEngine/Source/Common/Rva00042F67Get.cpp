// cl: /GX-
// ?Rva00042F67Get@@YAHXZ @ 0x00042F67 (6B): global dword getter reading
// 0x00DEDA34 (mov eax,[mem]; ret). Ported from Open-BFME-1
// Code/GameEngine/Source/Common/GlobalDwordGetters.cpp (same shape; the
// load address is a .data global). Dedicated TU so no caller inlines the
// load (Rva007EB810Get precedent).

extern int g_Va00DEDA34;

int Rva00042F67Get(void)
{
	return g_Va00DEDA34;
}
// ?g_Va00DEDA34@@3HA: the global at VA 0xdeda34 is ?D3DDevice@DX8Wrapper@@1PAUIDirect3DDevice8@@A.
#pragma comment(linker, "/alternatename:?g_Va00DEDA34@@3HA=?D3DDevice@DX8Wrapper@@1PAUIDirect3DDevice8@@A")
