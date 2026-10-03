// ?rva000EE04A@W3DPropBuffer@@QAEXPBUCoord3D@@M@Z
// partial score=0.9 date=2026-10-03
// cl: /O1 /G7 /arch:SSE /MD /EHsc /DNDEBUG /DWIN32 /D_WINDOWS /D_STLP_USE_STATIC_LIB /D_CRTIMP= /D_STLP_USE_MALLOC /D_STLP_NO_EXCEPTIONS /DBFME_MODULE_NO_MPO /DZH_EMIT_POOL_GLUE /Ireference/shims/bfmerendobj /Ireference/shims/debugvtable /Ireference/shims/sweep /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/Compression /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/debug /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngineDevice/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWDebug /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Main /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/Wwutil /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDownload /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDebug /Ireference/open-bfme-1/Code/Libraries/Source/Compression /Ireference/shims/bfmeanimobj /Ireference/shims/indexbuffercount /Ireference/shims/bfmecaps /Ireference/shims/bfmehcanim /Ireference/shims/bfmevector /Ireference/shims/bfmemapper /Ireference/shims/meshmatdesclayout /Ireference/shims/bfmeshader /Ireference/shims/bfmecpudetect /Ireference/shims/bfmepool /Ireference/open-bfme-1/Code/GameEngine/Include/Precompiled /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include/GameNetwork /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWAudio /Ireference/shims/bfmealloc /Ireference/shims/bfmehashtable /Ireference/shims/bfmelist /Ireference/shims/asciistring_downloadmanager /Ireference/shims/stlp_nodealloc /Ireference/shims/asciistring_thin /ICode/GameEngine/Source/Common /Ireference/shims/w3droadbuffer /Ireference/shims/bfmeterraintracks /ICode/Libraries/Include/Lib
// ?rva000EE04A@W3DPropBuffer@@QAEXPBVCoord3D@@M@Z @0x000EE04A 232B
// W3DPropBuffer radius clear. Evidence: MAX_PROPS 4000 stride 0x30 count at +0x2EE04 flag byte +0x2EE08, location/bounds clear plus propType -1 and ref release like removeProp, caller 0x00068073 passes (pos, radius) with this from +0x3858, float global g_Va00BBB8D8 for Radius.
struct Coord3D
{
	float x;
	float y;
	float z;
	void set(float nx, float ny, float nz) { x = nx; y = ny; z = nz; }
};
struct Vector3
{
	float x;
	float y;
	float z;
	void set(float nx, float ny, float nz) { x = nx; y = ny; z = nz; }
};
struct SphereClass
{
	Vector3 Center;
	float Radius;
};
class RenderObjClass
{
public:
	virtual void Delete_This();
	void Release_Ref()
	{
		--m_refCount;
		if (m_refCount == 0)
			Delete_This();
	}
private:
	int m_refCount;
};
struct TProp
{
	RenderObjClass *m_robj;
	int id;
	Coord3D location;
	int propType;
	int ss;
	int visible;
	SphereClass bounds;
};
class W3DPropBuffer
{
public:
	void rva000EE04A(const Coord3D *pos, float radius);
private:
	void *m_vptr;
	TProp m_props[4000];
	int m_numProps;
	bool m_anythingChanged;
};
extern float g_Va00BBB8D8;
// ?rva000EE04A@W3DPropBuffer@@QAEXPBVCoord3D@@M@Z present-unmatched
void W3DPropBuffer::rva000EE04A(const Coord3D *pos, float radius)
{
	for (int i = 0; i < m_numProps; ++i)
	{
		if (m_props[i].m_robj == 0)
			continue;
		const float *pp = &pos->x;
		const float *qp = &m_props[i].location.x;
		float dx = qp[0] - pp[0];
		float dz = qp[2] - pp[2];
		float dy = qp[1] - pp[1];
		float distSq = dz * dz + dy * dy + dx * dx;
		if (radius * radius <= distSq)
			continue;
		m_props[i].location.set(0, 0, 0);
		RenderObjClass *robj = m_props[i].m_robj;
		m_props[i].propType = -1;
		if (robj != 0)
		{
			robj->Release_Ref();
			m_props[i].m_robj = 0;
		}
		m_props[i].bounds.Center.set(0, 0, 0);
		m_props[i].bounds.Radius = g_Va00BBB8D8;
		m_anythingChanged = true;
	}
}
