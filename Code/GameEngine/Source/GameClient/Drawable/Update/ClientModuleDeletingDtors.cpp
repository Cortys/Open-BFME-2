// cl: /O1 /MD
//
// Scalar deleting-destructor wrappers with audited owner attributions.
// Target facts: 28-byte flag-test wrappers, their call destinations, and the
// vtable slot-0 links below. Owner evidence is stated per body; retail module
// registrations and class-name strings are distinguished from donor-derived
// class spellings. A named slot alone does not establish the complete owner.
// See docs/reconstruction/deleting-destructor-identity-audit.md.
//
// These minimal declarations emit the wrappers, not complete class layouts.
// No bases, member layout, or destructor implementation are claimed here.
// The noinline empty destructor is an unmatched compilation scaffold; the
// verified wrapper call resolves to the retail destructor through its pin.

// ??_GRadarMarkerClientUpdate@@UAEPAXI@Z @0x004C9CDB 28B: slot 0 of vtable 0x00C5EDB8; calls ??1 at 0x004C9C38.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x004C9BF3 uses class-name string "RadarMarkerClientUpdate".
class RadarMarkerClientUpdate { public: __declspec(noinline) virtual ~RadarMarkerClientUpdate(); };
// ??1RadarMarkerClientUpdate@@UAE@XZ present-unmatched
RadarMarkerClientUpdate::~RadarMarkerClientUpdate() {}
void RadarMarkerClientUpdate_Delete(RadarMarkerClientUpdate *p) { delete p; }

// ??_GRadarMarkerClientUpdateModuleData@@UAEPAXI@Z @0x004C9D77 28B: slot 0 of vtable 0x00C5EDF8; calls ??1 at 0x004C9CA5.
// Owner evidence (audited 2026-09-26): retail registration RadarMarkerClientUpdate -> data factory RVA 0x00252B11 -> ctor RVA 0x004C9C98; primary vptr store RVA 0x004C9C9A.
class RadarMarkerClientUpdateModuleData { public: __declspec(noinline) virtual ~RadarMarkerClientUpdateModuleData(); };
// ??1RadarMarkerClientUpdateModuleData@@UAE@XZ present-unmatched
RadarMarkerClientUpdateModuleData::~RadarMarkerClientUpdateModuleData() {}
void RadarMarkerClientUpdateModuleData_Delete(RadarMarkerClientUpdateModuleData *p) { delete p; }

// ??_GAnimationSoundClientBehavior@@UAEPAXI@Z @0x004C9F45 28B: slot 0 of vtable 0x00C5EE80; calls ??1 at 0x004C9DC9.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x004C9EF3 uses class-name string "AnimationSoundClientBehavior".
class AnimationSoundClientBehavior { public: __declspec(noinline) virtual ~AnimationSoundClientBehavior(); };
// ??1AnimationSoundClientBehavior@@UAE@XZ present-unmatched
AnimationSoundClientBehavior::~AnimationSoundClientBehavior() {}
void AnimationSoundClientBehavior_Delete(AnimationSoundClientBehavior *p) { delete p; }

// ??_GAnimationSoundClientBehaviorModuleData@@UAEPAXI@Z @0x004CA74C 28B: slot 0 of vtable 0x00C5EED0; calls ??1 at 0x004CA768.
// Owner evidence (audited 2026-09-26): retail registration AnimationSoundClientBehavior -> data factory RVA 0x00252BC2 -> ctor RVA 0x004CA70D; primary vptr store RVA 0x004CA725.
class AnimationSoundClientBehaviorModuleData { public: __declspec(noinline) virtual ~AnimationSoundClientBehaviorModuleData(); };
// ??1AnimationSoundClientBehaviorModuleData@@UAE@XZ present-unmatched
AnimationSoundClientBehaviorModuleData::~AnimationSoundClientBehaviorModuleData() {}
void AnimationSoundClientBehaviorModuleData_Delete(AnimationSoundClientBehaviorModuleData *p) { delete p; }

// ??_GUpgradeSoundSelectorClientBehaviorModuleData@@UAEPAXI@Z @0x004CBACE 28B: slot 0 of vtable 0x00C5F250; calls ??1 at 0x004CBAEA.
// Owner evidence (audited 2026-09-26): retail registration UpgradeSoundSelectorClientBehavior -> data factory RVA 0x00252C64 -> ctor RVA 0x004CB9F3; primary vptr store RVA 0x004CB9FF.
class UpgradeSoundSelectorClientBehaviorModuleData { public: __declspec(noinline) virtual ~UpgradeSoundSelectorClientBehaviorModuleData(); };
// ??1UpgradeSoundSelectorClientBehaviorModuleData@@UAE@XZ present-unmatched
UpgradeSoundSelectorClientBehaviorModuleData::~UpgradeSoundSelectorClientBehaviorModuleData() {}
void UpgradeSoundSelectorClientBehaviorModuleData_Delete(UpgradeSoundSelectorClientBehaviorModuleData *p) { delete p; }

// ??_GModelConditionAudioLoopClientBehavior@@UAEPAXI@Z @0x004CC179 28B: slot 0 of vtable 0x00C5F458; calls ??1 at 0x004CC0FE.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x004CBF13 uses class-name string "ModelConditionAudioLoopClientBehavior".
class ModelConditionAudioLoopClientBehavior { public: __declspec(noinline) virtual ~ModelConditionAudioLoopClientBehavior(); };
// ??1ModelConditionAudioLoopClientBehavior@@UAE@XZ present-unmatched
ModelConditionAudioLoopClientBehavior::~ModelConditionAudioLoopClientBehavior() {}
void ModelConditionAudioLoopClientBehavior_Delete(ModelConditionAudioLoopClientBehavior *p) { delete p; }

// ??_GModelConditionAudioLoopClientBehaviorModuleData@@UAEPAXI@Z @0x004CC31B 28B: slot 0 of vtable 0x00C5F4A8; calls ??1 at 0x004CC226.
// Owner evidence (audited 2026-09-26): retail registration ModelConditionAudioLoopClientBehavior -> data factory RVA 0x00252D9A -> ctor RVA 0x004CC20A; primary vptr store RVA 0x004CC216.
class ModelConditionAudioLoopClientBehaviorModuleData { public: __declspec(noinline) virtual ~ModelConditionAudioLoopClientBehaviorModuleData(); };
// ??1ModelConditionAudioLoopClientBehaviorModuleData@@UAE@XZ present-unmatched
ModelConditionAudioLoopClientBehaviorModuleData::~ModelConditionAudioLoopClientBehaviorModuleData() {}
void ModelConditionAudioLoopClientBehaviorModuleData_Delete(ModelConditionAudioLoopClientBehaviorModuleData *p) { delete p; }
