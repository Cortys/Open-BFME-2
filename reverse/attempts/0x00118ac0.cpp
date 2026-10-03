// ?Rva00118AC0@@YAXXZ
// partial score=0.98 date=2026-10-03
// cl: /G7 /arch:SSE
// ?Rva00118AC0@@YAXXZ 0x00118AC0 138 unlock stencil-gated Clear via Has_Stencil caller 0x000A5A51
struct Vector3
{
	float X;
	float Y;
	float Z;
};
class DX8Wrapper
{
public:
	static bool Has_Stencil();
	static void Clear(bool clear_color, bool clear_z_stencil, bool clear_stencil, const Vector3 &color, float dest_alpha, float z, unsigned int stencil);
};
extern unsigned char g_Va00DB5FB8;
extern int g_Va00DB5FB4;
// ?Rva00118AC0@@YAXXZ present-unmatched
void __cdecl Rva00118AC0()
{
	g_Va00DB5FB8 = 1;
	if (DX8Wrapper::Has_Stencil())
	{
		int v = g_Va00DB5FB4 - 1;
		g_Va00DB5FB4 = v;
		if (v < 1)
			g_Va00DB5FB4 = 0xff;
		else if (v != 0xff)
			return;
		Vector3 black = { 0.0f, 0.0f, 0.0f };
		DX8Wrapper::Clear(false, false, true, black, 0.0f, 0.0f, 0);
	}
	else
	{
		Vector3 black = { 0.0f, 0.0f, 0.0f };
		DX8Wrapper::Clear(false, true, true, black, 0.0f, 0.0f, 0);
	}
}
