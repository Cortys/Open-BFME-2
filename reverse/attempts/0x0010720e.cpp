// ?Rva0010720ESet@@YGXH@Z
// partial score=0.92 date=2026-10-01
// ?Rva0010720ESet@@YGXH@Z
// partial score=0.92 date=2026-10-01
// cl: /O1 /DNDEBUG /MD /EHsc /DWIN32 /D_WINDOWS /arch:SSE
// ?ReAcquireResources@W3DProjectedShadowManager@@QAE_NXZ @0x0010716D 127B
// Target evidence: retail checks [this+0] then [this+4] for null, creates
// BfmeDynamicNativeVB(2 0x7530 1 0) size 0x20 and DX8IndexBufferClass(0x7530 1)
// size 0x18 via operator new 0x0002FDA0, always returns true. Called from
// W3DShadowManager::ReAcquireResources 0x0009A3A5.
// Donor evidence: BFME1 W3DProjectedShadowManager::ReAcquireResources names
// the owner; BFME2 body uses BfmeDynamicNativeVB + DX8IndexBufferClass.
// Inference: two buffer members at +0/+4, no vtable in this layout.
typedef unsigned int Uint;
typedef unsigned short UShort;
void *__cdecl operator new(Uint s);
void __cdecl operator delete(void *p);
class RefCountClass
{
public:
	virtual void Delete_This() {}
	void Release_Ref()
	{
		if (--m_refs == 0)
			Delete_This();
	}
	int m_refs;
};
class BfmeDynamicNativeVB : public RefCountClass
{
public:
	BfmeDynamicNativeVB(Uint a, UShort b, Uint c, Uint d);
private:
	char _t[0x18];
};
class DX8IndexBufferClass : public RefCountClass
{
public:
	enum UsageType { USAGE_DEFAULT = 0, USAGE_DYNAMIC = 1 };
	DX8IndexBufferClass(Uint count, UsageType u);
private:
	char _t[0x10];
};
class VertexBufferClass
{
public:
	class WriteLockClass
	{
	public:
		WriteLockClass(VertexBufferClass *b, int flags);
	private:
		char _t[0xC];
	};
};
class IndexBufferClass
{
public:
	class WriteLockClass
	{
	public:
		WriteLockClass(IndexBufferClass *b, int flags);
	private:
		char _t[0xC];
	};
};
class W3DProjectedShadowManager
{
public:
	bool ReAcquireResources();
	void rva001072C9();
private:
	BfmeDynamicNativeVB *m_vertexBuffer;
	DX8IndexBufferClass *m_indexBuffer;
	char _pad08[4];
	VertexBufferClass::WriteLockClass *m_vertexLock;
	IndexBufferClass::WriteLockClass *m_indexLock;
	int m_14;
	int m_18;
};

class DX8Caps
{
public:
	char m_pad91[0x91];
	unsigned char m_flag91;
};

class DX8Wrapper
{
public:
	static void __cdecl Set_DX8_Render_State(unsigned long state, unsigned int value);
	static DX8Caps *CurrentCaps;
};
bool W3DProjectedShadowManager::ReAcquireResources()
{
	if (!m_vertexBuffer)
		m_vertexBuffer = new BfmeDynamicNativeVB(2, 0x7530, 1, 0);
	if (!m_indexBuffer)
		m_indexBuffer = new DX8IndexBufferClass(0x7530, DX8IndexBufferClass::USAGE_DYNAMIC);
	return true;
}
void W3DProjectedShadowManager::rva001072C9()
{
	m_vertexLock = new VertexBufferClass::WriteLockClass((VertexBufferClass *)m_vertexBuffer, 0x2800);
	m_indexLock = new IndexBufferClass::WriteLockClass((IndexBufferClass *)m_indexBuffer, 0x2800);
	m_14 = 0x7530;
	m_18 = 0x7530;
}

// ?Rva0010720ESet@@YGXH@Z present-unmatched
void __stdcall Rva0010720ESet(int arg)
{
	int one = 1;
	if (arg == 0) {
		DX8Wrapper::Set_DX8_Render_State(0x36, one);
		DX8Wrapper::Set_DX8_Render_State(0x35, one);
	} else {
		DX8Wrapper::Set_DX8_Render_State(0x35, one);
		DX8Wrapper::Set_DX8_Render_State(0x37, one);
	}
	if (!(DX8Wrapper::CurrentCaps->m_flag91 & 1))
		return;
	DX8Wrapper::Set_DX8_Render_State(0xb9, one);
	DX8Wrapper::Set_DX8_Render_State(0x16, one);
	if (arg == 0) {
		DX8Wrapper::Set_DX8_Render_State(0x37, 8);
		DX8Wrapper::Set_DX8_Render_State(0xbb, one);
		DX8Wrapper::Set_DX8_Render_State(0xba, one);
		DX8Wrapper::Set_DX8_Render_State(0xbc, 7);
	} else {
		DX8Wrapper::Set_DX8_Render_State(0x36, 7);
		DX8Wrapper::Set_DX8_Render_State(0xba, one);
		DX8Wrapper::Set_DX8_Render_State(0xbc, one);
		DX8Wrapper::Set_DX8_Render_State(0xbb, 8);
	}
	DX8Wrapper::Set_DX8_Render_State(0xbd, 8);
}
