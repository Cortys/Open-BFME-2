// ??1WorkerAIUpdateModuleData@@UAE@XZ
// partial score=1.0 date=2026-09-26
// ??1WorkerAIUpdateModuleData@@UAE@XZ
// partial score=1.00 date=2026-09-26
// cl: /O1 /MD
// ??1WorkerAIUpdateModuleData@@UAE@XZ @0x002544B5 60B.
// True Worker dtor adjacent to rowed ctor 0x00254434 and factory 0x002544F1.
// Destroys SoundHolder at +0x90 via rowed Release_Ref 0x00050ED3 when non-null
// then base TransportAIUpdateModuleData via pinned 0x0026E1FC. Layout from
// rowed ctor (base 0x64 plus MaxBoxes through SuppliesDepletedVoice with +0x90
// zeroed; factory news 0x94; vtable 0x00BF23C8). Shape follows DeployStyle
// dtor 0x00255F70 (no vtable store plus single member plus Transport base)
// with AudioLoop SoundHolder pattern for the +0x90 release.
class OpaqueRefCounted
{
public:
	void Release_Ref();
};

struct SoundHolder
{
	~SoundHolder()
	{
		if (m_ptr)
			m_ptr->Release_Ref();
	}
	OpaqueRefCounted *m_ptr;
};

class __declspec(novtable) TransportAIUpdateModuleData
{
public:
	TransportAIUpdateModuleData();
	virtual ~TransportAIUpdateModuleData();

private:
	unsigned char m_pad[0x64 - 4];
};

class __declspec(novtable) WorkerAIUpdateModuleData : public TransportAIUpdateModuleData
{
public:
	virtual ~WorkerAIUpdateModuleData();

private:
	unsigned char m_pad64[0x90 - 0x64];
	SoundHolder m_holder90; // +0x90 SuppliesDepletedVoice holder zeroed by ctor
};

// ??1WorkerAIUpdateModuleData@@UAE@XZ present-unmatched
WorkerAIUpdateModuleData::~WorkerAIUpdateModuleData()
{
}
