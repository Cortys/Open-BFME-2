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

// ??_GThreatFinderUpdate@@UAEPAXI@Z @0x003ED0A8 28B: slot 0 of vtable 0x00C360CC; calls ??1 at 0x003ECF64.
// Owner evidence: installed by ??0ThreatFinderUpdate@@QAE@PAVThing@@PBVModuleData@@@Z; class-unique slots 4 ?rva0003ECCD6@ThreatFinderUpdate@@SA?AW4NameKeyType@@XZ.
class ThreatFinderUpdate { public: __declspec(noinline) virtual ~ThreatFinderUpdate(); };
// ??1ThreatFinderUpdate@@UAE@XZ present-unmatched
ThreatFinderUpdate::~ThreatFinderUpdate() {}
void ThreatFinderUpdate_Delete(ThreatFinderUpdate *p) { delete p; }

// ??_GSpecialAbilityUpdate@@UAEPAXI@Z @0x004522F0 28B: slot 0 of vtable 0x00C3FBA8; calls ??1 at 0x00451F45.
// Owner evidence: class-unique slots 4 ?rva00044F054@SpecialAbilityUpdate@@SA?AW4NameKeyType@@XZ.
class SpecialAbilityUpdate { public: __declspec(noinline) virtual ~SpecialAbilityUpdate(); };
// ??1SpecialAbilityUpdate@@UAE@XZ present-unmatched
SpecialAbilityUpdate::~SpecialAbilityUpdate() {}
void SpecialAbilityUpdate_Delete(SpecialAbilityUpdate *p) { delete p; }

// ??_GFloodUpdate@@UAEPAXI@Z @0x0048E603 28B: slot 0 of vtable 0x00C4C948; calls ??1 at 0x0048E454.
// Owner evidence: installed by ??0FloodUpdate@@QAE@PAVThing@@PBVModuleData@@@Z; class-unique slots 4 ?rva00048E0FA@FloodUpdate@@SA?AW4NameKeyType@@XZ.
class FloodUpdate { public: __declspec(noinline) virtual ~FloodUpdate(); };
// ??1FloodUpdate@@UAE@XZ present-unmatched
FloodUpdate::~FloodUpdate() {}
void FloodUpdate_Delete(FloodUpdate *p) { delete p; }

// ??_GAutoPickUpUpdate@@UAEPAXI@Z @0x00495DAA 28B: slot 0 of vtable 0x00C4F06C; calls ??1 at 0x00495C48.
// Owner evidence: installed by ??0AutoPickUpUpdate@@QAE@PAVThing@@PBVModuleData@@@Z; class-unique slots 4 ?rva000495CEC@AutoPickUpUpdate@@SA?AW4NameKeyType@@XZ.
class AutoPickUpUpdate { public: __declspec(noinline) virtual ~AutoPickUpUpdate(); };
// ??1AutoPickUpUpdate@@UAE@XZ present-unmatched
AutoPickUpUpdate::~AutoPickUpUpdate() {}
void AutoPickUpUpdate_Delete(AutoPickUpUpdate *p) { delete p; }

// ??_GAttributeModifierAuraUpdate@@UAEPAXI@Z @0x0049B884 28B: slot 0 of vtable 0x00C50D2C; calls ??1 at 0x0049B6DD.
// Owner evidence: installed by ??0AttributeModifierAuraUpdate@@QAE@PAVThing@@PBVModuleData@@@Z; class-unique slots 4 ?rva00049B5DC@AttributeModifierAuraUpdate@@SA?AW4NameKeyType@@XZ.
class AttributeModifierAuraUpdate { public: __declspec(noinline) virtual ~AttributeModifierAuraUpdate(); };
// ??1AttributeModifierAuraUpdate@@UAE@XZ present-unmatched
AttributeModifierAuraUpdate::~AttributeModifierAuraUpdate() {}
void AttributeModifierAuraUpdate_Delete(AttributeModifierAuraUpdate *p) { delete p; }

// ??_GProductionUpdate@@UAEPAXI@Z @0x0049E34C 28B: slot 0 of vtable 0x00C515BC; calls ??1 at 0x0049E1BF.
// Owner evidence: installed by ??0ProductionUpdate@@QAE@PAVThing@@PBVModuleData@@@Z; class-unique slots 4 ?rva00049E15E@ProductionUpdate@@SA?AW4NameKeyType@@XZ.
class ProductionUpdate { public: __declspec(noinline) virtual ~ProductionUpdate(); };
// ??1ProductionUpdate@@UAE@XZ present-unmatched
ProductionUpdate::~ProductionUpdate() {}
void ProductionUpdate_Delete(ProductionUpdate *p) { delete p; }

// ??_GBroadcastStealthUpdate@@UAEPAXI@Z @0x004A35AD 28B: slot 0 of vtable 0x00C52364; calls ??1 at 0x004A3555.
// Owner evidence: class-unique slots 4 ?rva0004A34C6@BroadcastStealthUpdate@@SA?AW4NameKeyType@@XZ.
class BroadcastStealthUpdate { public: __declspec(noinline) virtual ~BroadcastStealthUpdate(); };
// ??1BroadcastStealthUpdate@@UAE@XZ present-unmatched
BroadcastStealthUpdate::~BroadcastStealthUpdate() {}
void BroadcastStealthUpdate_Delete(BroadcastStealthUpdate *p) { delete p; }

// ??_GLargeGroupAudioUpdate@@UAEPAXI@Z @0x004ABB1B 28B: slot 0 of vtable 0x00C549BC; calls ??1 at 0x004AB8DC.
// Owner evidence: installed by ??0LargeGroupAudioUpdate@@QAE@PAVThing@@PBVModuleData@@@Z; class-unique slots 4 ?rva004AB897@LargeGroupAudioUpdate@@SA?AW4NameKeyType@@XZ.
class LargeGroupAudioUpdate { public: __declspec(noinline) virtual ~LargeGroupAudioUpdate(); };
// ??1LargeGroupAudioUpdate@@UAE@XZ present-unmatched
LargeGroupAudioUpdate::~LargeGroupAudioUpdate() {}
void LargeGroupAudioUpdate_Delete(LargeGroupAudioUpdate *p) { delete p; }

// ??_GDestroyEnvironmentUpdate@@UAEPAXI@Z @0x004AC7AD 28B: slot 0 of vtable 0x00C54D64; calls ??1 at 0x004AC767.
// Owner evidence: installed by ??0DestroyEnvironmentUpdate@@QAE@PAVThing@@PBVModuleData@@@Z; class-unique slots 3 ?xfer@DestroyEnvironmentUpdate@@MAEXPAVXfer@@@Z and 4 ?rva0004AC686@DestroyEnvironmentUpdate@@SA?AW4NameKeyType@@XZ.
class DestroyEnvironmentUpdate { public: __declspec(noinline) virtual ~DestroyEnvironmentUpdate(); };
// ??1DestroyEnvironmentUpdate@@UAE@XZ present-unmatched
DestroyEnvironmentUpdate::~DestroyEnvironmentUpdate() {}
void DestroyEnvironmentUpdate_Delete(DestroyEnvironmentUpdate *p) { delete p; }

// ??_GAIGateUpdate@@UAEPAXI@Z @0x004B0926 28B: slot 0 of vtable 0x00C56480; calls ??1 at 0x004B0802.
// Owner evidence: installed by ??0AIGateUpdate@@QAE@PAVThing@@PBVModuleData@@@Z; class-unique slots 3 ?xfer@AIGateUpdate@@MAEXPAVXfer@@@Z and 4 ?rva0004B087C@AIGateUpdate@@SA?AW4NameKeyType@@XZ.
class AIGateUpdate { public: __declspec(noinline) virtual ~AIGateUpdate(); };
// ??1AIGateUpdate@@UAE@XZ present-unmatched
AIGateUpdate::~AIGateUpdate() {}
void AIGateUpdate_Delete(AIGateUpdate *p) { delete p; }

// ??_GEmotionTrackerUpdate@@UAEPAXI@Z @0x004B15CA 28B: slot 0 of vtable 0x00C5667C; calls ??1 at 0x004B1322.
// Owner evidence: class-unique slots 4 ?rva0004B1393@EmotionTrackerUpdate@@SA?AW4NameKeyType@@XZ.
class EmotionTrackerUpdate { public: __declspec(noinline) virtual ~EmotionTrackerUpdate(); };
// ??1EmotionTrackerUpdate@@UAE@XZ present-unmatched
EmotionTrackerUpdate::~EmotionTrackerUpdate() {}
void EmotionTrackerUpdate_Delete(EmotionTrackerUpdate *p) { delete p; }

// ??_GDockUpdate@@UAEPAXI@Z @0x0058A177 28B: slot 0 of vtable 0x00C70378; calls ??1 at 0x0058A0F4.
// Owner evidence: installed by ??0DockUpdate@@QAE@PAVThing@@PBVModuleData@@@Z; class-unique slots 3 ?xfer@DockUpdate@@MAEXPAVXfer@@@Z.
class DockUpdate { public: __declspec(noinline) virtual ~DockUpdate(); };
// ??1DockUpdate@@UAE@XZ present-unmatched
DockUpdate::~DockUpdate() {}
void DockUpdate_Delete(DockUpdate *p) { delete p; }
