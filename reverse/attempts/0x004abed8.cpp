// ??0LargeGroupAudioUpdateModuleData@@QAE@XZ
// partial score=0.94 date=2026-09-30
// cl: /O1 /EHsc /DNDEBUG /MD
// LargeGroupAudioUpdateModuleData default constructor @0x4ABED8 (111B). INI
// table 0x00C54868 names the members; retail state 1 unwinds this+8 through
// the ObjectCreationList dtor 0x3ED94F and state 0 through the base dtor.
// This honest model (real vtable, extern globals, no volatile) reproduces the
// earlier stash byte for byte: the sole gap is retail's fstp qword [esp] before
// mov byte [ebp-4],1 where cl emits the state byte first. Refuted here: init
// list vs body vs mixed, double temporary, operand order, ZH-style inline
// ConvertDurationFromMsecsToFrames wrapper, /G3-/G7 /GB /Os /Op /Oy- /Oi-
// /Ob1 /Ob2 /Za /arch:SSE. The global at 0x009BA4EC is LOGICFRAMES_PER_MSEC_REAL
// (0.005) and 500.0f is a compiler literal.
extern "C" __declspec(dllimport) double __cdecl ceil(double value);
extern const float g_009BA4EC;
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
extern Rva00E03CE0 g_00E03CE0;
class UpdateModuleData
{
public:
	UpdateModuleData() {}
	virtual ~UpdateModuleData();
};
class LargeGroupAudioUpdateModuleData : public UpdateModuleData
{
public:
	LargeGroupAudioUpdateModuleData();
	virtual ~LargeGroupAudioUpdateModuleData();
private:
	int m_unused04;
	ObjectCreationList m_key;
	unsigned int m_timeBetweenUpdatesMin;
	unsigned int m_timeBetweenUpdatesVariation;
	unsigned short m_unitWeight;
};
// ??0LargeGroupAudioUpdateModuleData@@QAE@XZ @0x004ABED8
LargeGroupAudioUpdateModuleData::LargeGroupAudioUpdateModuleData() :
	m_timeBetweenUpdatesMin((unsigned int)ceil(g_009BA4EC * 500.0f)),
	m_timeBetweenUpdatesVariation(1),
	m_unitWeight(1)
{
	g_00E03CE0.Rva004ABEAE(reinterpret_cast<Rva001408C0Target *>(this));
}
