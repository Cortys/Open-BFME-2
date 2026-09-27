// ??1W3DTankDraw@@UAE@XZ
// partial score=0.97 date=2026-09-27
// ??1W3DTankDraw@@UAE@XZ
// partial score=0.97 date=2026-09-27
// cl: /O1 /DNDEBUG /MD /EHsc
//
// ??1W3DTankDraw@@UAE@XZ, retail 0x000CE960, 142 bytes.
// W3DTankDraw dtor: reinstalls vtables 0xBCCBE8/+0xC 0xBCC588/+0x10 0xBCA08C,
// releases 4 treads at +0x304 (each 0x14, REF_PTR_RELEASE via inline
// Release_Ref dec at +4 then slot-0 Delete_This), conditionally destroys the
// two 12-byte intrusive handles at +0x2F4/+0x2E8 through the rowed
// ??1BfmeParticleSystemHandle@@QAE@XZ at 0x4CBC0 when m_system!=0, then calls
// the pinned MI base dtor at 0xC79C9. Layout: opaque MI base (12B) plus shared
// MiBase1 plus per-class B2 gives +0/+0xC/+0x10; pad to 0x2E8 covers the true
// W3DScriptedModelDraw members (ctor at 0xC0DD8 proves 0x2E8); handles and
// treads match ctor 0xCEA6C (handles zeroed at 0x2E8/0x2F4, TreadObjectInfo
// ctor 0xCDFB1 for 4x0x14 at 0x304, prevRenderObj at 0x300). Donor BFME1
// W3DTankDrawDestructor.cpp/W3DTankDraw.cpp treads loop; BFME2 deltas:
// handles are 12-byte intrusive (not ParticleSystem*) with caller-side guard
// (DefaultModuleHeadBaseDtor precedent: trivial store plus explicit
// conditional destroy). Evidence: deleting wrapper 0xCEB2C slot 0 of
// 0xBCCBE8 calls here; slot 4 pool key 0xCE9EE uses "W3DTankDraw" string.

class RefCountClass
{
public:
	virtual void Delete_This();
	void Release_Ref()
	{
		if (--NumRefs == 0)
			Delete_This();
	}
	int NumRefs;
};

class RenderObjClass : public RefCountClass
{
};

struct TreadObjectInfo
{
	RenderObjClass *m_robj;
	unsigned char m_rest[0x10];
};

struct BfmeParticleSystemHandle
{
	~BfmeParticleSystemHandle();
	void *m_system;
	void *m_previous;
	void *m_next;
};

struct HandleStore
{
	void *m_ptr0;
	void *m_ptr1;
	void *m_ptr2;
};

class Rva000C79C9
{
public:
	virtual ~Rva000C79C9();

private:
	char m_pad04[8];
};

class MiBase1
{
public:
	virtual void f1();
};

class W3DTankDraw_B2
{
public:
	virtual void f2();
};

class W3DTankDraw : public Rva000C79C9, public MiBase1, public W3DTankDraw_B2
{
public:
	virtual ~W3DTankDraw();

private:
	unsigned char m_pad14[0x2E8 - 0x14];
	HandleStore m_treadDebrisLeft;
	HandleStore m_treadDebrisRight;
	void *m_prevRenderObj;
	TreadObjectInfo m_treads[4];
};

// ??1W3DTankDraw@@UAE@XZ present-unmatched
W3DTankDraw::~W3DTankDraw()
{
	for (int i = 0; i < 4; ++i)
	{
		RenderObjClass *robj = m_treads[i].m_robj;
		if (robj)
		{
			robj->Release_Ref();
			m_treads[i].m_robj = 0;
		}
	}
	BfmeParticleSystemHandle *pRight = (BfmeParticleSystemHandle *)&m_treadDebrisRight;
	if (pRight->m_system != 0)
		pRight->~BfmeParticleSystemHandle();
	BfmeParticleSystemHandle *pLeft = (BfmeParticleSystemHandle *)&m_treadDebrisLeft;
	if (pLeft->m_system != 0)
		pLeft->~BfmeParticleSystemHandle();
}
