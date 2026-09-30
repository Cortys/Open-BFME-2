// ??0Radar@@QAE@XZ
// partial score=0.98 date=2026-09-30
// ??0Radar@@QAE@XZ
// partial score=0.98 date=2026-09-30
// cl: /O1 /DNDEBUG /MD /arch:SSE /EHsc
//
// ??0Radar@@QAE@XZ, retail 0x002D87B9, 207 bytes. Radar constructor (chain:
// calls 0x002D7BD3 now ready). Evidence: stores Snapshot vtable 0x7BB554 then
// Radar vptrs 0xC0363C/+0 and 0xC03604/+4 matching RadarDtor; second-base
// baseConstruct 0x001B4E63 on +4; array m_events[64] at +0x2C via ??_L size
// 0x50 count 0x40 ctor 0x2D7CD9 dtor 0x2D7CE0; zeroes +0x1430/+0x14/+0x18/
// +0x10/+0x11 floats +0x1C/+0x20/+0x24/+0x28 extent +0x1434..+0x1448; calls
// rowed ?rva002D7BD3@Radar@@QAEXXZ and ?clearAllEvents@Radar@@IAEXXZ;
// trailer +0x1460=0. Layout from RadarDtor/Radar_reset/Radar_deleteListResources.

class Snapshot
{
public:
	virtual ~Snapshot();
	virtual void crc();
	virtual void loadPostProcess();
	virtual void xfer();
};

class BFME2NativeNetwork
{
public:
	BFME2NativeNetwork *baseConstruct();
};

class __declspec(novtable) RadarSecondBase
{
public:
	__forceinline RadarSecondBase() { ((BFME2NativeNetwork *)this)->baseConstruct(); }
	virtual ~RadarSecondBase();
	virtual void unused();
};

class RadarEventRef
{
public:
	void release();
};

class RadarEvent
{
public:
	RadarEvent();
	~RadarEvent();
private:
	char m_pad[0x4C];
	RadarEventRef *m_ref; // +0x4C
};

class Radar : public Snapshot, public RadarSecondBase
{
public:
	Radar();
	void rva002D7BD3();
protected:
	void clearAllEvents();
private:
	char m_pad08[0x10 - 0x08];
	bool m_hidden; // +0x10
	bool m_forceOn; // +0x11
	char m_pad12[0x14 - 0x12];
	void *m_objectList; // +0x14
	void *m_localList; // +0x18
	float m_avgTerrain; // +0x1C
	float m_avgWater; // +0x20
	float m_xSample; // +0x24
	float m_ySample; // +0x28
public:
	RadarEvent m_events[64]; // +0x2C
private:
	int m_eventTrailer; // +0x142C
public:
	void *m_radarWindow; // +0x1430
	float m_extent[6]; // +0x1434..+0x144C (Region3D min/max)
private:
	char m_pad144C[0x1460 - 0x144C];
	int m_1460; // +0x1460
};

// ??0RadarEvent@@QAE@XZ present-unmatched
RadarEvent::RadarEvent()
{
	m_ref = 0;
}

// ??1RadarEvent@@QAE@XZ present-unmatched
RadarEvent::~RadarEvent()
{
	if (m_ref)
		m_ref->release();
}

// ??0Radar@@QAE@XZ present-unmatched
Radar::Radar()
{
	m_radarWindow = 0;
	m_objectList = 0;
	m_localList = 0;
	m_hidden = false;
	m_forceOn = false;
	m_avgTerrain = 0.0f;
	m_avgWater = 0.0f;
	m_xSample = 0.0f;
	m_ySample = 0.0f;
	m_extent[0] = 0.0f;
	m_extent[1] = 0.0f;
	m_extent[2] = 0.0f;
	m_extent[3] = 0.0f;
	m_extent[4] = 0.0f;
	m_extent[5] = 0.0f;
	rva002D7BD3();
	m_1460 = 0;
	clearAllEvents();
}
