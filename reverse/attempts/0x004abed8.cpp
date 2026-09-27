// ??0LargeGroupAudioUpdateModuleData@@QAE@XZ
// partial score=0.93 date=2026-09-27
// ??0LargeGroupAudioUpdateModuleData@@QAE@XZ
// partial score=0.93 date=2026-09-27
// cl: /O1 /GX /DNDEBUG /MD
//
// ??0LargeGroupAudioUpdateModuleData@@QAE@XZ, retail 0x004ABED8, 111 bytes.
// Default ctor over INI table 0x00C54868 (TimeBetweenUpdates-led GroupAudio
// table; buildFieldParse rowed at 0x4AB800; pool key LargeGroupAudioUpdate
// rowed at 0x4AB897; factory friend_newModuleData rowed at 0x24F362 news
// 0x20, sole caller). Donor is BFME1 LargeGroupAudioUpdateModuleData/Ctor
// thunk plus copy ctor (OCL at +8, ints at +0x14/+0x18, word at +0x1c).
// Layout: vtable 0x00C549F8 at +0, untouched +4 pad, ObjectCreationList at
// +8 (12B, rowed ctor 0x1F81BF), frame count at +0x14 via ceil(0.005f times
// shared float at 0xBC7A54), 1 at +0x18, 1 at +0x1c. Registry insert via
// rowed Rva004ABEAE 0x4ABEAE on global 0x00E03CE0. Empty UpdateModuleData
// base with declared-only dtor arms EH state 0 before the OCL call (state
// 1 after), Production/BoneFX precedent. ceil is dllimport (IAT), ftol2
// via (int) cast, x87 fld/fmul (no /arch:SSE).

extern "C" __declspec(dllimport) double __cdecl ceil(double value);

class UpdateModuleData
{
public:
	UpdateModuleData() {}
	~UpdateModuleData();
};

class ObjectCreationList
{
public:
	ObjectCreationList();
	~ObjectCreationList();

private:
	unsigned char m_pad[12];
};

struct Rva001408C0Target
{
	int m_x;
};

class Rva00E03CE0
{
public:
	void Rva004ABEAE(Rva001408C0Target *md);
};

class LargeGroupAudioUpdateModuleData : public UpdateModuleData
{
public:
	LargeGroupAudioUpdateModuleData();

private:
	void *m_vtable;
	int m_unused04;
	ObjectCreationList m_ocl;
	int m_time;
	int m_unk18;
	unsigned short m_unk1C;
};

// ??0LargeGroupAudioUpdateModuleData@@QAE@XZ present-unmatched
LargeGroupAudioUpdateModuleData::LargeGroupAudioUpdateModuleData()
	: m_vtable(reinterpret_cast<void *>(0x00C549F8))
	, m_ocl()
	, m_time((int)ceil(*(const float *)0x00DBA4EC * *(const float *)0x00BC7A54))
	, m_unk18(1)
	, m_unk1C(1)
{
	reinterpret_cast<Rva00E03CE0 *>(0x00E03CE0)->Rva004ABEAE(
		reinterpret_cast<Rva001408C0Target *>(this));
}
