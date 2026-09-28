// ?Rva00075A23Draw@@YAXHH@Z
// partial score=0.97 date=2026-09-28
// ?Rva00075A23Draw@@YAXHH@Z
// partial score=0.97 date=2026-09-28
// cl: /DNDEBUG /DWIN32 /D_WINDOWS /MD /GX- /O1 /arch:SSE /G7 /GS-
// ?Rva00075A23Draw@@YAXHH@Z retail 0x00075A23 (437B).
// Fullscreen quad via dynamic VB ring (50x4 verts): guards on VB null and
// TheGlobalData+0xC60==-1, Set_Vertex_Buffer(NULL,0), AppendLock(VB,index*4,4,
// DISCARD-if-index-0-else-NOOVERWRITE), NDC positions (-1/1,0,1) with
// 0.5/w,0.5/h texel UVs (1.0/0.5/-1.0/0.0 literals), unlock, rebind VB,
// device SetVertexShader slot 0x15C with FVF global, Draw strip (index*4,2),
// index=(index+1)%50. Callers 0x00077392/0x0007BDAD/0x000FAC37/0x00111C05 push
// (w,h) __cdecl void; callees rowed Set_Vertex_Buffer/AppendLock/bfme00120700
// plus AppendLock-dtor pin; sibling 0x00075746 drawViewport shares VB/index/
// device/counter globals and /O1/SSE/G7 shape. /GX-/GS- for retail's no-EH
// no-cookie frame; /O1 for EBP frame and or/and -1/0 idioms.

struct GlobalDataCheck
{
	char m_pad[0xC60];
	int m_check;
};

extern GlobalDataCheck *TheGlobalData;

class VertexBufferClass
{
public:
	class AppendLockClass
	{
		VertexBufferClass *m_vb;
		void *m_verts;
		void *m_lock;
	public:
		AppendLockClass(VertexBufferClass *vb, unsigned start, unsigned range, int flags);
		~AppendLockClass();
		void *Get_Vertex_Array() const { return m_verts; }
	};
};

class DX8Wrapper
{
public:
	static void Set_Vertex_Buffer(const VertexBufferClass *vb, unsigned stream);
	static void bfmeRva00120700(unsigned start, unsigned count);
};

struct DeviceVtbl
{
	void *m_pad[87];
	long (__stdcall *m_setVertexShader)(void *device, unsigned fvf);
};

struct DeviceObj
{
	DeviceVtbl *m_vtable;
};

extern DeviceObj *g_deviceObj;
extern VertexBufferClass *g_vb;
extern int g_quadIndex;
extern unsigned g_fvfShader;
extern unsigned g_numberOfDX8Calls;

struct Vec4
{
	float x, y, z, w;
};

struct QuadVertex
{
	Vec4 pos;
	int diffuse;
	float u, v;
};

// ?Rva00075A23Draw@@YAXHH@Z present-unmatched
void Rva00075A23Draw(int width, int height)
{
	if (g_vb == 0)
		return;
	if (TheGlobalData->m_check != -1)
		return;
	DX8Wrapper::Set_Vertex_Buffer(0, 0);
	int index = g_quadIndex;
	int flags = !index ? 0x2000 : 0x1000;
	{
		VertexBufferClass::AppendLockClass lock(g_vb, index * 4, 4, flags);
		QuadVertex *v = (QuadVertex *)lock.Get_Vertex_Array();
		float invW = 1.0f / (float)width;
		invW *= 0.5f;
		float invH = 1.0f / (float)height;
		invH *= 0.5f;
		Vec4 tmp;
		tmp.x = 1.0f;
		tmp.y = 1.0f;
		tmp.z = 0.0f;
		tmp.w = 1.0f;
		v[0].pos = tmp;
		tmp.x = 1.0f;
		tmp.y = -1.0f;
		tmp.z = 0.0f;
		tmp.w = 1.0f;
		v[1].pos = tmp;
		v[0].diffuse |= -1;
		v[1].diffuse |= -1;
		v[2].diffuse |= -1;
		tmp.x = -1.0f;
		tmp.y = 1.0f;
		tmp.z = 0.0f;
		tmp.w = 1.0f;
		v[2].pos = tmp;
		v[0].u = 1.0f + invW;
		v[1].u = 1.0f + invW;
		v[0].v = invH;
		v[1].v = 1.0f + invH;
		v[2].u = invW;
		v[2].v = invH;
		tmp.x = -1.0f;
		tmp.y = -1.0f;
		tmp.z = 0.0f;
		tmp.w = 1.0f;
		v[3].pos = tmp;
		v[3].diffuse |= -1;
		v[3].u = invW;
		v[3].v = 1.0f + invH;
	}
	DX8Wrapper::Set_Vertex_Buffer(g_vb, 0);
	g_deviceObj->m_vtable->m_setVertexShader(g_deviceObj, g_fvfShader);
	++g_numberOfDX8Calls;
	DX8Wrapper::bfmeRva00120700(g_quadIndex * 4, 2);
	if (++g_quadIndex >= 50)
		g_quadIndex = 0;
}
