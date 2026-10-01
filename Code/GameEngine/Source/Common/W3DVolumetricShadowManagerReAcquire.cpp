// cl: /O1 /MD /EHsc
// ?ReAcquireResources@W3DVolumetricShadowManager@@QAE_NXZ @0x000F09E1 148B: reacquire IB plus VB via D3DDevice then manager reacquire under DX8 lock. Evidence: LINK BONUS names this mangling plus donor ZH ReAcquireResources plus chain callee 0x000F0972 row plus callers 0x0009A270 0x0009A390.
void __cdecl BFME_DX8_Thread_Lock();
bool __cdecl BFME_DX8_Thread_Assert();
struct IDirect3DDevice8
{
	virtual void f00();
	virtual void f01();
	virtual void f02();
	virtual void f03();
	virtual void f04();
	virtual void f05();
	virtual void f06();
	virtual void f07();
	virtual void f08();
	virtual void f09();
	virtual void f10();
	virtual void f11();
	virtual void f12();
	virtual void f13();
	virtual void f14();
	virtual void f15();
	virtual void f16();
	virtual void f17();
	virtual void f18();
	virtual void f19();
	virtual void f20();
	virtual void f21();
	virtual void f22();
	virtual void f23();
	virtual void f24();
	virtual void f25();
	virtual long __stdcall CreateVertexBuffer(int a, int b, int c, int d, void **e, int f);
	virtual long __stdcall CreateIndexBuffer(int a, int b, int c, int d, void **e, int f);
};
class DX8Wrapper
{
public:
	static IDirect3DDevice8 *D3DDevice;
};
class Rva000F0972Releasable
{
public:
	virtual void f0();
	virtual void f1();
	virtual void __stdcall f2();
};
extern Rva000F0972Releasable *g_00DEBCE0;
extern Rva000F0972Releasable *g_00DEBCDC;
class W3DBufferManager
{
public:
	bool rva0011604D();
};
extern W3DBufferManager *g_00DEC3C0;
class Rva000F0912
{
public:
	void rva000F0972();
};
class W3DVolumetricShadowManager
{
public:
	bool ReAcquireResources();
};
struct Rva000F09E1LockGuard
{
	Rva000F09E1LockGuard() { BFME_DX8_Thread_Lock(); }
	~Rva000F09E1LockGuard() { BFME_DX8_Thread_Assert(); }
};
bool W3DVolumetricShadowManager::ReAcquireResources()
{
	Rva000F09E1LockGuard guard;
	((Rva000F0912 *)this)->rva000F0972();
	IDirect3DDevice8 *dev = DX8Wrapper::D3DDevice;
	if (dev->CreateIndexBuffer(0x8000, 0x208, 0x65, 0, (void **)&g_00DEBCE0, 0) < 0)
		return false;
	if (g_00DEBCDC == 0)
	{
		if (dev->CreateVertexBuffer(0x18000, 0x208, 0, 0, (void **)&g_00DEBCDC, 0) < 0)
			return false;
	}
	W3DBufferManager *mgr = g_00DEC3C0;
	if (mgr != 0)
	{
		if (!mgr->rva0011604D())
			return false;
	}
	return true;
}
