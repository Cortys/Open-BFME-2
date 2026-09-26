// cl: /O1 /MD
//
// Scalar deleting destructors (28B flag-test ??_G shape) whose owning class
// the image names:
// push esi / mov esi,ecx / call <dtor> / test [esp+8],1 / je / push esi /
// call ??3 (0x2FD60) / pop ecx / mov eax,esi / pop esi / ret 4.
//
// Target facts, per class below: the ??_G bytes; the destructor it calls; the
// vtable holding the ??_G in slot 0; and the evidence tying that vtable to the
// class -- the class's own constructor installs it, and/or other slots of it
// that no other vtable shares already carry the class's name in the ledger.
// Carried from those ledger rows: the class names themselves.
// Not established: each class's layout, bases and destructor body. Every class
// is declared with only the virtual destructor the ??_G needs;
// __declspec(noinline) keeps it out of line so the ??_G calls it through the
// pin, and the empty body is a placeholder, not a claim.

// ??_GRadarMarkerClientUpdate@@UAEPAXI@Z @0x004C9CDB 28B: slot 0 of vtable 0x00C5EDB8; calls ??1 at 0x004C9C38.
// Owner evidence: installed by ??0RadarMarkerClientUpdate@@QAE@PAVThing@@PBVModuleData@@@Z; class-unique slots 4 ?rva0004C9BF3@RadarMarkerClientUpdate@@SA?AW4NameKeyType@@XZ.
class RadarMarkerClientUpdate { public: __declspec(noinline) virtual ~RadarMarkerClientUpdate(); };
// ??1RadarMarkerClientUpdate@@UAE@XZ present-unmatched
RadarMarkerClientUpdate::~RadarMarkerClientUpdate() {}
void RadarMarkerClientUpdate_Delete(RadarMarkerClientUpdate *p) { delete p; }

// ??_GRadarMarkerClientUpdateModuleData@@UAEPAXI@Z @0x004C9D77 28B: slot 0 of vtable 0x00C5EDF8; calls ??1 at 0x004C9CA5.
// Owner evidence: sole named installer ??0RadarMarkerClientUpdateModuleData@@QAE@XZ.
class RadarMarkerClientUpdateModuleData { public: __declspec(noinline) virtual ~RadarMarkerClientUpdateModuleData(); };
// ??1RadarMarkerClientUpdateModuleData@@UAE@XZ present-unmatched
RadarMarkerClientUpdateModuleData::~RadarMarkerClientUpdateModuleData() {}
void RadarMarkerClientUpdateModuleData_Delete(RadarMarkerClientUpdateModuleData *p) { delete p; }

// ??_GAnimationSoundClientBehavior@@UAEPAXI@Z @0x004C9F45 28B: slot 0 of vtable 0x00C5EE80; calls ??1 at 0x004C9DC9.
// Owner evidence: class-unique slots 4 ?rva0004C9EF3@AnimationSoundClientBehavior@@SA?AW4NameKeyType@@XZ.
class AnimationSoundClientBehavior { public: __declspec(noinline) virtual ~AnimationSoundClientBehavior(); };
// ??1AnimationSoundClientBehavior@@UAE@XZ present-unmatched
AnimationSoundClientBehavior::~AnimationSoundClientBehavior() {}
void AnimationSoundClientBehavior_Delete(AnimationSoundClientBehavior *p) { delete p; }

// ??_GAnimationSoundClientBehaviorModuleData@@UAEPAXI@Z @0x004CA74C 28B: slot 0 of vtable 0x00C5EED0; calls ??1 at 0x004CA768.
// Owner evidence: sole named installer ??0AnimationSoundClientBehaviorModuleData@@QAE@XZ.
class AnimationSoundClientBehaviorModuleData { public: __declspec(noinline) virtual ~AnimationSoundClientBehaviorModuleData(); };
// ??1AnimationSoundClientBehaviorModuleData@@UAE@XZ present-unmatched
AnimationSoundClientBehaviorModuleData::~AnimationSoundClientBehaviorModuleData() {}
void AnimationSoundClientBehaviorModuleData_Delete(AnimationSoundClientBehaviorModuleData *p) { delete p; }

// ??_GUpgradeSoundSelectorClientBehaviorModuleData@@UAEPAXI@Z @0x004CBACE 28B: slot 0 of vtable 0x00C5F250; calls ??1 at 0x004CBAEA.
// Owner evidence: sole named installer ??0UpgradeSoundSelectorClientBehaviorModuleData@@QAE@XZ.
class UpgradeSoundSelectorClientBehaviorModuleData { public: __declspec(noinline) virtual ~UpgradeSoundSelectorClientBehaviorModuleData(); };
// ??1UpgradeSoundSelectorClientBehaviorModuleData@@UAE@XZ present-unmatched
UpgradeSoundSelectorClientBehaviorModuleData::~UpgradeSoundSelectorClientBehaviorModuleData() {}
void UpgradeSoundSelectorClientBehaviorModuleData_Delete(UpgradeSoundSelectorClientBehaviorModuleData *p) { delete p; }

// ??_GModelConditionAudioLoopClientBehavior@@UAEPAXI@Z @0x004CC179 28B: slot 0 of vtable 0x00C5F458; calls ??1 at 0x004CC0FE.
// Owner evidence: installed by ??0ModelConditionAudioLoopClientBehavior@@QAE@PAVThing@@PBVModuleData@@@Z; class-unique slots 4 ?rva0004CBF13@ModelConditionAudioLoopClientBehavior@@SA?AW4NameKeyType@@XZ.
class ModelConditionAudioLoopClientBehavior { public: __declspec(noinline) virtual ~ModelConditionAudioLoopClientBehavior(); };
// ??1ModelConditionAudioLoopClientBehavior@@UAE@XZ present-unmatched
ModelConditionAudioLoopClientBehavior::~ModelConditionAudioLoopClientBehavior() {}
void ModelConditionAudioLoopClientBehavior_Delete(ModelConditionAudioLoopClientBehavior *p) { delete p; }

// ??_GModelConditionAudioLoopClientBehaviorModuleData@@UAEPAXI@Z @0x004CC31B 28B: slot 0 of vtable 0x00C5F4A8; calls ??1 at 0x004CC226.
// Owner evidence: sole named installer ??0ModelConditionAudioLoopClientBehaviorModuleData@@QAE@XZ.
class ModelConditionAudioLoopClientBehaviorModuleData { public: __declspec(noinline) virtual ~ModelConditionAudioLoopClientBehaviorModuleData(); };
// ??1ModelConditionAudioLoopClientBehaviorModuleData@@UAE@XZ present-unmatched
ModelConditionAudioLoopClientBehaviorModuleData::~ModelConditionAudioLoopClientBehaviorModuleData() {}
void ModelConditionAudioLoopClientBehaviorModuleData_Delete(ModelConditionAudioLoopClientBehaviorModuleData *p) { delete p; }
