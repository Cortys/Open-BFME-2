// ??0LargeGroupAudioUpdateModuleData@@QAE@XZ
// partial score=0.96 date=2026-09-27
// ??0LargeGroupAudioUpdateModuleData@@QAE@XZ
// partial score=0.96 date=2026-09-27
// cl: /O1 /EHsc /DNDEBUG /MD
//
// ??0LargeGroupAudioUpdateModuleData@@QAE@XZ, retail 0x004ABED8, 111 bytes.
// LargeGroupAudioUpdate data ctor over INI table 0x00C54868 (TimeBetweenUpdatesMin
// at +0x14 via parseDurationUnsignedInt, TimeBetweenUpdatesVariation at +0x18,
// UnitWeight ushort at +0x1c via parseUnsignedShort, Key ObjectCreationList at +8).
// Defaults: Min ceil(0.005*500.0)=3, Variation 1, UnitWeight 1. Empty
// UpdateModuleData base with declared-only dtor arms EH state 0 before the Key
// call; explicit vtable slot 0x00C549F8 with no virtuals; registry insert via
// rowed Rva004ABEAE with global 0x00E03CE0 as this. Donor BFME1 copy ctor only.

extern "C" __declspec(dllimport) double __cdecl ceil(double value);

float g_largeGroupAudioMsecScale = 0.005f;

class ObjectCreationList
{
public:
	ObjectCreationList();
	~ObjectCreationList();
private:
	unsigned char m_pad[0xC];
};

struct Rva001408C0Target
{
	int x;
};

struct Rva00E03CE0
{
	void Rva004ABEAE(Rva001408C0Target *md);
};

class UpdateModuleData
{
public:
	UpdateModuleData() {}
	~UpdateModuleData();
};

class LargeGroupAudioUpdateModuleData : public UpdateModuleData
{
public:
	LargeGroupAudioUpdateModuleData();

private:
	const void *m_vtable;
	int m_unused04;
	ObjectCreationList m_key;
	unsigned int m_timeBetweenUpdatesMin;
	unsigned int m_timeBetweenUpdatesVariation;
	unsigned short m_unitWeight;
	unsigned char m_pad1E[2];
};

typedef char LargeGroupAudioUpdateModuleDataSizeCheck[sizeof(LargeGroupAudioUpdateModuleData) == 0x20 ? 1 : -1];

// ??0LargeGroupAudioUpdateModuleData@@QAE@XZ present-unmatched
LargeGroupAudioUpdateModuleData::LargeGroupAudioUpdateModuleData()
	: UpdateModuleData()
	, m_vtable(reinterpret_cast<const void *>(0x00C549F8))
	, m_timeBetweenUpdatesMin((unsigned int)ceil(g_largeGroupAudioMsecScale * 500.0f))
	, m_timeBetweenUpdatesVariation(1)
	, m_unitWeight(1)
{
	reinterpret_cast<Rva00E03CE0 *>(0x00E03CE0)->Rva004ABEAE(reinterpret_cast<Rva001408C0Target *>(this));
}
