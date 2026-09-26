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

// ??_GThreatFinderUpdate@@UAEPAXI@Z @0x003ED0A8 28B: slot 0 of vtable 0x00C360CC; calls ??1 at 0x003ECF64.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x003ECCD6 uses class-name string "ThreatFinderUpdate".
class ThreatFinderUpdate { public: __declspec(noinline) virtual ~ThreatFinderUpdate(); };
// ??1ThreatFinderUpdate@@UAE@XZ present-unmatched
ThreatFinderUpdate::~ThreatFinderUpdate() {}
void ThreatFinderUpdate_Delete(ThreatFinderUpdate *p) { delete p; }

// ??_GSpecialAbilityUpdate@@UAEPAXI@Z @0x004522F0 28B: slot 0 of vtable 0x00C3FBA8; calls ??1 at 0x00451F45.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x0044F054 uses class-name string "SpecialAbilityUpdate".
class SpecialAbilityUpdate { public: __declspec(noinline) virtual ~SpecialAbilityUpdate(); };
// ??1SpecialAbilityUpdate@@UAE@XZ present-unmatched
SpecialAbilityUpdate::~SpecialAbilityUpdate() {}
void SpecialAbilityUpdate_Delete(SpecialAbilityUpdate *p) { delete p; }

// ??_GFloodUpdate@@UAEPAXI@Z @0x0048E603 28B: slot 0 of vtable 0x00C4C948; calls ??1 at 0x0048E454.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x0048E0FA uses class-name string "FloodUpdate".
class FloodUpdate { public: __declspec(noinline) virtual ~FloodUpdate(); };
// ??1FloodUpdate@@UAE@XZ present-unmatched
FloodUpdate::~FloodUpdate() {}
void FloodUpdate_Delete(FloodUpdate *p) { delete p; }

// ??_GAutoPickUpUpdate@@UAEPAXI@Z @0x00495DAA 28B: slot 0 of vtable 0x00C4F06C; calls ??1 at 0x00495C48.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x00495CEC uses class-name string "AutoPickUpUpdate".
class AutoPickUpUpdate { public: __declspec(noinline) virtual ~AutoPickUpUpdate(); };
// ??1AutoPickUpUpdate@@UAE@XZ present-unmatched
AutoPickUpUpdate::~AutoPickUpUpdate() {}
void AutoPickUpUpdate_Delete(AutoPickUpUpdate *p) { delete p; }

// ??_GAttributeModifierAuraUpdate@@UAEPAXI@Z @0x0049B884 28B: slot 0 of vtable 0x00C50D2C; calls ??1 at 0x0049B6DD.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x0049B5DC uses class-name string "AttributeModifierAuraUpdate".
class AttributeModifierAuraUpdate { public: __declspec(noinline) virtual ~AttributeModifierAuraUpdate(); };
// ??1AttributeModifierAuraUpdate@@UAE@XZ present-unmatched
AttributeModifierAuraUpdate::~AttributeModifierAuraUpdate() {}
void AttributeModifierAuraUpdate_Delete(AttributeModifierAuraUpdate *p) { delete p; }

// ??_GProductionUpdate@@UAEPAXI@Z @0x0049E34C 28B: slot 0 of vtable 0x00C515BC; calls ??1 at 0x0049E1BF.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x0049E15E uses class-name string "ProductionUpdate".
class ProductionUpdate { public: __declspec(noinline) virtual ~ProductionUpdate(); };
// ??1ProductionUpdate@@UAE@XZ present-unmatched
ProductionUpdate::~ProductionUpdate() {}
void ProductionUpdate_Delete(ProductionUpdate *p) { delete p; }

// ??_GBroadcastStealthUpdate@@UAEPAXI@Z @0x004A35AD 28B: slot 0 of vtable 0x00C52364; calls ??1 at 0x004A3555.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x004A34C6 uses class-name string "BroadcastStealthUpdate".
class BroadcastStealthUpdate { public: __declspec(noinline) virtual ~BroadcastStealthUpdate(); };
// ??1BroadcastStealthUpdate@@UAE@XZ present-unmatched
BroadcastStealthUpdate::~BroadcastStealthUpdate() {}
void BroadcastStealthUpdate_Delete(BroadcastStealthUpdate *p) { delete p; }

// ??_GLargeGroupAudioUpdate@@UAEPAXI@Z @0x004ABB1B 28B: slot 0 of vtable 0x00C549BC; calls ??1 at 0x004AB8DC.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x004AB897 uses class-name string "LargeGroupAudioUpdate".
class LargeGroupAudioUpdate { public: __declspec(noinline) virtual ~LargeGroupAudioUpdate(); };
// ??1LargeGroupAudioUpdate@@UAE@XZ present-unmatched
LargeGroupAudioUpdate::~LargeGroupAudioUpdate() {}
void LargeGroupAudioUpdate_Delete(LargeGroupAudioUpdate *p) { delete p; }

// ??_GDestroyEnvironmentUpdate@@UAEPAXI@Z @0x004AC7AD 28B: slot 0 of vtable 0x00C54D64; calls ??1 at 0x004AC767.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x004AC686 uses class-name string "DestroyEnvironmentUpdate".
class DestroyEnvironmentUpdate { public: __declspec(noinline) virtual ~DestroyEnvironmentUpdate(); };
// ??1DestroyEnvironmentUpdate@@UAE@XZ present-unmatched
DestroyEnvironmentUpdate::~DestroyEnvironmentUpdate() {}
void DestroyEnvironmentUpdate_Delete(DestroyEnvironmentUpdate *p) { delete p; }

// ??_GAIGateUpdate@@UAEPAXI@Z @0x004B0926 28B: slot 0 of vtable 0x00C56480; calls ??1 at 0x004B0802.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x004B087C uses class-name string "AIGateUpdate".
class AIGateUpdate { public: __declspec(noinline) virtual ~AIGateUpdate(); };
// ??1AIGateUpdate@@UAE@XZ present-unmatched
AIGateUpdate::~AIGateUpdate() {}
void AIGateUpdate_Delete(AIGateUpdate *p) { delete p; }

// ??_GEmotionTrackerUpdate@@UAEPAXI@Z @0x004B15CA 28B: slot 0 of vtable 0x00C5667C; calls ??1 at 0x004B1322.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x004B1393 uses class-name string "EmotionTrackerUpdate".
class EmotionTrackerUpdate { public: __declspec(noinline) virtual ~EmotionTrackerUpdate(); };
// ??1EmotionTrackerUpdate@@UAE@XZ present-unmatched
EmotionTrackerUpdate::~EmotionTrackerUpdate() {}
void EmotionTrackerUpdate_Delete(EmotionTrackerUpdate *p) { delete p; }

// ??_GDockUpdate@@UAEPAXI@Z @0x0058A177 28B: slot 0 of vtable 0x00C70378; calls ??1 at 0x0058A0F4.
// Owner evidence (audited 2026-09-26): donor ctor RVA 0x0058A290 stores this primary vptr at RVA 0x0058A2C5 and a separate interface vptr at +0x20; slot-3 xfer RVA 0x0058A410 corroborates the dock fields and member order.
class DockUpdate { public: __declspec(noinline) virtual ~DockUpdate(); };
// ??1DockUpdate@@UAE@XZ present-unmatched
DockUpdate::~DockUpdate() {}
void DockUpdate_Delete(DockUpdate *p) { delete p; }
