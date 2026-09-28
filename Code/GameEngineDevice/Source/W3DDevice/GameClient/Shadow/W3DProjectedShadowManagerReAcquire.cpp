// cl: /O1 /DNDEBUG /MD /EHsc /DWIN32 /D_WINDOWS /arch:SSE /G7
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
class W3DProjectedShadowManager
{
public:
	bool ReAcquireResources();
private:
	BfmeDynamicNativeVB *m_vertexBuffer;
	DX8IndexBufferClass *m_indexBuffer;
};
bool W3DProjectedShadowManager::ReAcquireResources()
{
	if (!m_vertexBuffer)
		m_vertexBuffer = new BfmeDynamicNativeVB(2, 0x7530, 1, 0);
	if (!m_indexBuffer)
		m_indexBuffer = new DX8IndexBufferClass(0x7530, DX8IndexBufferClass::USAGE_DYNAMIC);
	return true;
}
