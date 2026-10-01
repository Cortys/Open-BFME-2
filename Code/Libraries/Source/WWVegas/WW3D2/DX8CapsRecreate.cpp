// cl: /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc
// Distinct TU for ?Rva001207B0Init@@YAXPAX@Z @ 0x001207B0 (152B).
// BFME1's ?d_00906e70@@YAXXZ (b1 0x00906E70) is the identical body with a
// 0x2AC caps object; BFME2 builds the proven 0x2E4 DX8Caps here. The standing
// ?Rva001207B0Init@@YAXPAX@Z pin carries the caller evidence (first call in
// Do_Onetime_Device_Dependent_Inits), so the BFME2 token name is kept and
// the BFME1 object-symbol (?Compute_Caps@DX8Wrapper@@...) is not spent.
// The delete goes through BfmeEnumerationCaps (whose out-of-line dtor the
// ledger already owns at 0x0011CD40); the placement-new builds a DX8Caps
// whose ctor row the ledger owns at 0x0012C670. Global names are TU-local:
// their addresses bind from the retail DIR32 slots the same way the
// ShowAssertCrashDialog transfer's data globals did.

struct IDirect3D8 {};
struct IDirect3DDevice8 {};

enum WW3DFormat
{
	WW3D_FORMAT_UNKNOWN = 0
};

struct _D3DADAPTER_IDENTIFIER8
{
	char m_pad[0x44C];
};

class BfmeEnumerationCaps
{
public:
	~BfmeEnumerationCaps();
};

class DX8Caps
{
public:
	DX8Caps(IDirect3D8 *direct3d, IDirect3DDevice8 *device,
		WW3DFormat format, const _D3DADAPTER_IDENTIFIER8 &adapter);

private:
	char m_pad[0x2E4]; // proven retail class size (ctor TU static assert)
};

void *__cdecl operator new(unsigned int size);
void __cdecl operator delete(void *block);

extern BfmeEnumerationCaps *g_currentCaps;
extern IDirect3D8 *g_d3dInterface;
extern IDirect3DDevice8 *g_d3dDevice;
extern _D3DADAPTER_IDENTIFIER8 g_adapterIdentifier;

// ?Rva001207B0Init@@YAXPAX@Z
void __cdecl Rva001207B0Init(void *device)
{
	delete g_currentCaps;
	g_currentCaps = (BfmeEnumerationCaps *)new DX8Caps(g_d3dInterface,
		g_d3dDevice, (WW3DFormat)(int)device, g_adapterIdentifier);
}

// ?g_d3dInterface@@3PAUIDirect3D8@@A: the global at this VA is ?D3DInterface@DX8Wrapper@@1PAUIDirect3D8@@A; this name is an alias for it.
#pragma comment(linker, "/alternatename:?g_d3dInterface@@3PAUIDirect3D8@@A=?D3DInterface@DX8Wrapper@@1PAUIDirect3D8@@A")
#pragma comment(linker, "/alternatename:?G009EDA30@@3HA=?D3DInterface@DX8Wrapper@@1PAUIDirect3D8@@A")
// ?g_adapterIdentifier@@3U_D3DADAPTER_IDENTIFIER8@@A: the global at VA 0xdec5e8 is ?CurrentAdapterIdentifier@DX8Wrapper@@1U_D3DADAPTER_IDENTIFIER8@@A.
#pragma comment(linker, "/alternatename:?g_adapterIdentifier@@3U_D3DADAPTER_IDENTIFIER8@@A=?CurrentAdapterIdentifier@DX8Wrapper@@1U_D3DADAPTER_IDENTIFIER8@@A")
// ?g_d3dInterface@@3PAUIDirect3D8@@A: the global at VA 0xdeda30 is ?D3DInterface@DX8Wrapper@@1PAUIDirect3D8@@A.
#pragma comment(linker, "/alternatename:?g_d3dInterface@@3PAUIDirect3D8@@A=?D3DInterface@DX8Wrapper@@1PAUIDirect3D8@@A")
// ?g_currentCaps@@3PAVBfmeEnumerationCaps@@A: the global at VA 0xdeda7c is ?CurrentCaps@DX8Wrapper@@1PAVDX8Caps@@A.
#pragma comment(linker, "/alternatename:?g_currentCaps@@3PAVBfmeEnumerationCaps@@A=?CurrentCaps@DX8Wrapper@@1PAVDX8Caps@@A")
