// ?Rva000754DEInit@@YAXXZ
// partial score=0.96 date=2026-10-02
// cl: /O1 /DNDEBUG /MD /EHsc
// ?Rva000754DEInit@@YAXXZ @0x000754DE (363B): free-function DX8 render-target init.
// Evidence: caller 0x00077F80; releases VB at g_00DE1F7C via refcount, creates
// BfmeDynamicNativeVB(0,0xC8,1,0x1C), checks 4 globals, then D3D CreateTexture
// path with GetSurfaceLevel. Naming: honest free-function Rva (unlock lane).

void *__cdecl operator new(unsigned);
void __cdecl operator delete(void *) throw();

class BfmeDynamicVBRefCount {
public:
	virtual void DeleteThis();
	int references;
};

class BfmeDynamicNativeVB : public BfmeDynamicVBRefCount {
public:
	BfmeDynamicNativeVB(unsigned, unsigned short, unsigned, unsigned);
	unsigned type;
	unsigned short vertexCount;
	int engineReferences;
	void *format;
	bool usesDeclaration;
	void *buffer;
};

extern BfmeDynamicNativeVB *g_00DE1F7C;
extern unsigned g_00DE1F80;
extern unsigned int g_Va009E1F64;
extern int g_Va001FDE68;
extern unsigned int g_Va009E1F6C;
extern void *g_00DE1F70;

typedef unsigned long DWORD;
typedef unsigned int UINT;
typedef long HRESULT;
struct Rva754DEDevice {
	virtual HRESULT __stdcall _V00(void) = 0;
	virtual HRESULT __stdcall _V01(void) = 0;
	virtual HRESULT __stdcall _V02(void) = 0;
	virtual HRESULT __stdcall _V03(void) = 0;
	virtual HRESULT __stdcall _V04(void) = 0;
	virtual HRESULT __stdcall _V05(void) = 0;
	virtual HRESULT __stdcall _V06(void) = 0;
	virtual HRESULT __stdcall _V07(void) = 0;
	virtual HRESULT __stdcall _V08(void) = 0;
	virtual HRESULT __stdcall _V09(void) = 0;
	virtual HRESULT __stdcall _V10(void) = 0;
	virtual HRESULT __stdcall _V11(void) = 0;
	virtual HRESULT __stdcall _V12(void) = 0;
	virtual HRESULT __stdcall _V13(void) = 0;
	virtual HRESULT __stdcall _V14(void) = 0;
	virtual HRESULT __stdcall _V15(void) = 0;
	virtual HRESULT __stdcall _V16(void) = 0;
	virtual HRESULT __stdcall _V17(void) = 0;
	virtual HRESULT __stdcall _V18(void) = 0;
	virtual HRESULT __stdcall _V19(void) = 0;
	virtual HRESULT __stdcall _V20(void) = 0;
	virtual HRESULT __stdcall _V21(void) = 0;
	virtual HRESULT __stdcall _V22(void) = 0;
	virtual HRESULT __stdcall CreateTexture(UINT, UINT, UINT, DWORD, DWORD, DWORD, void **, void *) = 0;
	virtual HRESULT __stdcall _V24(void) = 0;
	virtual HRESULT __stdcall _V25(void) = 0;
	virtual HRESULT __stdcall _V26(void) = 0;
	virtual HRESULT __stdcall _V27(void) = 0;
	virtual HRESULT __stdcall _V28(void) = 0;
	virtual HRESULT __stdcall _V29(void) = 0;
	virtual HRESULT __stdcall _V30(void) = 0;
	virtual HRESULT __stdcall _V31(void) = 0;
	virtual HRESULT __stdcall _V32(void) = 0;
	virtual HRESULT __stdcall _V33(void) = 0;
	virtual HRESULT __stdcall _V34(void) = 0;
	virtual HRESULT __stdcall _V35(void) = 0;
	virtual HRESULT __stdcall _V36(void) = 0;
	virtual HRESULT __stdcall _V37(void) = 0;
	virtual HRESULT __stdcall M38(UINT, void **) = 0;
	virtual HRESULT __stdcall _V39(void) = 0;
	virtual HRESULT __stdcall M40(void **) = 0;
};

struct Rva754DESurface {
	virtual HRESULT __stdcall _W00(void) = 0;
	virtual DWORD __stdcall _W01(void) = 0;
	virtual DWORD __stdcall Release(void) = 0;
	virtual HRESULT __stdcall _W03(void) = 0;
	virtual HRESULT __stdcall _W04(void) = 0;
	virtual HRESULT __stdcall _W05(void) = 0;
	virtual HRESULT __stdcall _W06(void) = 0;
	virtual HRESULT __stdcall _W07(void) = 0;
	virtual HRESULT __stdcall _W08(void) = 0;
	virtual HRESULT __stdcall _W09(void) = 0;
	virtual HRESULT __stdcall _W10(void) = 0;
	virtual HRESULT __stdcall _W11(void) = 0;
	virtual HRESULT __stdcall R12(void *) = 0;
};

struct Rva754DETexture {
	virtual HRESULT __stdcall _T00(void) = 0;
	virtual DWORD __stdcall _T01(void) = 0;
	virtual DWORD __stdcall Release(void) = 0;
	virtual HRESULT __stdcall _T03(void) = 0;
	virtual HRESULT __stdcall _T04(void) = 0;
	virtual HRESULT __stdcall _T05(void) = 0;
	virtual HRESULT __stdcall _T06(void) = 0;
	virtual HRESULT __stdcall _T07(void) = 0;
	virtual HRESULT __stdcall _T08(void) = 0;
	virtual HRESULT __stdcall _T09(void) = 0;
	virtual HRESULT __stdcall _T10(void) = 0;
	virtual HRESULT __stdcall _T11(void) = 0;
	virtual HRESULT __stdcall _T12(void) = 0;
	virtual HRESULT __stdcall _T13(void) = 0;
	virtual HRESULT __stdcall _T14(void) = 0;
	virtual HRESULT __stdcall _T15(void) = 0;
	virtual HRESULT __stdcall _T16(void) = 0;
	virtual HRESULT __stdcall _T17(void) = 0;
	virtual HRESULT __stdcall GetSurfaceLevel(UINT, void **) = 0;
};

struct Rva754DEDesc {
	DWORD Format;
	DWORD Type;
	DWORD Usage;
	DWORD Pool;
	DWORD MultiSampleType;
	DWORD MultiSampleQuality;
	UINT Width;
	UINT Height;
};

class DX8Wrapper {
public:
	static Rva754DEDevice *D3DDevice;
};

// ?Rva000754DEInit@@YAXXZ present-unmatched
void __cdecl Rva000754DEInit()
{
	BfmeDynamicNativeVB *vb = g_00DE1F7C;
	if (vb) {
		int *refs = (int *)vb + 1;
		--(*refs);
		if (*(volatile int *)refs == 0)
			vb->DeleteThis();
		g_00DE1F7C = 0;
	}
	g_00DE1F7C = new BfmeDynamicNativeVB(0, 0xC8, 1, 0x1C);
	g_00DE1F80 = 0;
	if (g_Va009E1F64)
		return;
	if (g_Va001FDE68)
		return;
	if (g_Va009E1F6C)
		return;
	if (g_00DE1F70)
		return;
	DX8Wrapper::D3DDevice->M38(0, (void **)&g_Va009E1F64);
	Rva754DESurface *surf = (Rva754DESurface *)g_Va009E1F64;
	Rva754DEDesc desc;
	surf->R12(&desc);
	HRESULT hr = DX8Wrapper::D3DDevice->CreateTexture(desc.Width, desc.Height, 1, 1, desc.Format, 0, (void **)&g_Va001FDE68, 0);
	if (hr != 0) {
		Rva754DESurface *old = (Rva754DESurface *)g_Va009E1F64;
		if (old)
			old->Release();
		g_Va009E1F64 = 0;
		g_Va001FDE68 = 0;
		return;
	}
	Rva754DETexture *tex = (Rva754DETexture *)g_Va001FDE68;
	hr = tex->GetSurfaceLevel(0, (void **)&g_Va009E1F6C);
	if (hr != 0) {
		Rva754DETexture *t = (Rva754DETexture *)g_Va001FDE68;
		if (t)
			t->Release();
		g_Va009E1F6C = 0;
		g_Va001FDE68 = 0;
		return;
	}
	hr = DX8Wrapper::D3DDevice->M40((void **)&g_00DE1F70);
	if (hr != 0) {
		Rva754DESurface *s1 = (Rva754DESurface *)g_Va009E1F6C;
		if (s1)
			s1->Release();
		Rva754DETexture *t2 = (Rva754DETexture *)g_Va001FDE68;
		if (t2)
			t2->Release();
		g_00DE1F70 = 0;
		g_Va009E1F6C = 0;
		g_Va001FDE68 = 0;
		return;
	}
}

#pragma comment(linker, "/alternatename:?D3DDevice@DX8Wrapper@@2PAVRva754DEDevice@@A=?D3DDevice@DX8Wrapper@@1PAUIDirect3DDevice8@@A")
