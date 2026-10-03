// ??0Rva001495A0@@QAE@XZ
// partial score=0.93 date=2026-10-03
// cl: /G7 /arch:SSE /DNDEBUG /MD /EHsc
//
// ??0Rva001495A0@@QAE@XZ, retail 0x001495A0, 204 bytes. Unlock-lane ctor:
// calls RenderObjClass ctor at 0x0013BF00, sets two vptrs (RenderObjClass is
// RefCountClass + MultiListObjectClass, hence two stores), constructs the
// LightEnvironmentClass member at +0xCC via rowed 0x0013F410, takes a unique
// id from g_00DF36A8, spreads g_Va00BBB8D8 (1.0f) over +0x2F4/+0x2F8/+0x2FC
// and zeroes the rest. +0xC4 model slot matches Rva001498B0Cluster. Size
// 0x324 matches Rva00149F20Holder. Naming: __thiscall, owner unknown.
// Near miss (v3): 204/204 B, 43/43 insns, only retail `add eax,1` before the
// 314/318/31C stores vs ours after the 320 store is left. /Os, barriers and
// volatile all cascade. Next: pin the add early without moving the 320 store.

class RefCountClass
{
public:
	RefCountClass();
	virtual ~RefCountClass();

private:
	int m_refCount;	// +0x04: second vptr lands at +0x08
};

class MultiListObjectClass
{
public:
	MultiListObjectClass();
	virtual ~MultiListObjectClass();
};

class RenderObjClass : public RefCountClass, public MultiListObjectClass
{
public:
	RenderObjClass();
};

class LightEnvironmentClass
{
public:
	LightEnvironmentClass();
};

extern int g_00DF36A8;
extern float g_Va00BBB8D8;

class Rva001495A0 : public RenderObjClass
{
public:
	Rva001495A0();

private:
	char m_pad0C[0xB8];
	void *m_model;	// +0xC4
	void *m_ptrC8;	// +0xC8
	LightEnvironmentClass m_lightEnv;	// +0xCC
	char m_padD0[0x224];
	float m_f2F4;	// +0x2F4
	float m_f2F8;	// +0x2F8
	float m_f2FC;	// +0x2FC
	int m_i300;	// +0x300
	int m_i304;	// +0x304
	int m_id;	// +0x308
	unsigned char m_b30C;	// +0x30C
	char m_pad30D[3];
	int m_i310;	// +0x310
	float m_f314;	// +0x314
	float m_f318;	// +0x318
	float m_f31C;	// +0x31C
	unsigned char m_b320;	// +0x320
};

// ??0Rva001495A0@@QAE@XZ present-unmatched
Rva001495A0::Rva001495A0() : m_model(0), m_ptrC8(0)
{
	int id = g_00DF36A8;
	float one = g_Va00BBB8D8;
	m_f2F4 = one;
	m_f2F8 = one;
	m_f2FC = one;
	m_i300 = 0;
	m_i304 = 0;
	m_id = id;
	m_b30C = 0;
	m_i310 = 0;
	++id;
	m_f314 = 0.0f;
	m_f318 = 0.0f;
	m_f31C = 0.0f;
	m_b320 = 0;
	g_00DF36A8 = id;
}
