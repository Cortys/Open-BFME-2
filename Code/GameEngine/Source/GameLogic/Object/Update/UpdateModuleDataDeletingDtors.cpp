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

// ??_GDeployStyleAIUpdateModuleData@@UAEPAXI@Z @0x00255F54 28B: slot 0 of vtable 0x00BF3440; calls ??1 at 0x00255F70.
// Owner evidence (audited 2026-09-26): retail registration DeployStyleAIUpdate -> data factory RVA 0x0025517E -> ctor RVA 0x00255154; primary vptr store RVA 0x0025515E.
class DeployStyleAIUpdateModuleData { public: __declspec(noinline) virtual ~DeployStyleAIUpdateModuleData(); };
// ??1DeployStyleAIUpdateModuleData@@UAE@XZ present-unmatched
DeployStyleAIUpdateModuleData::~DeployStyleAIUpdateModuleData() {}
void DeployStyleAIUpdateModuleData_Delete(DeployStyleAIUpdateModuleData *p) { delete p; }

// ??_GSlavedUpdateModuleData@@UAEPAXI@Z @0x00255FA5 28B: slot 0 of vtable 0x00BF34C0; calls ??1 at 0x00255FC1.
// Owner evidence (audited 2026-09-26): retail registration SlavedUpdate -> data factory RVA 0x00255340 -> ctor RVA 0x002552D7; primary vptr store RVA 0x002552DE.
class SlavedUpdateModuleData { public: __declspec(noinline) virtual ~SlavedUpdateModuleData(); };
// ??1SlavedUpdateModuleData@@UAE@XZ present-unmatched
SlavedUpdateModuleData::~SlavedUpdateModuleData() {}
void SlavedUpdateModuleData_Delete(SlavedUpdateModuleData *p) { delete p; }

// ??_GTransportAIUpdateModuleData@@UAEPAXI@Z @0x0026E67D 28B: slot 0 of vtable 0x00BFA288; calls ??1 at 0x0026E1FC.
// Owner evidence (audited 2026-09-26): retail registration TransportAIUpdate -> data factory RVA 0x0024BDF2 -> ctor RVA 0x0026E5D7; primary vptr store RVA 0x0026E5F2; constructor also used by AIUpdateInterface, HordeAIUpdate, HordeWorkerAIUpdate (no exclusive owner claim).
class TransportAIUpdateModuleData { public: __declspec(noinline) virtual ~TransportAIUpdateModuleData(); };
// ??1TransportAIUpdateModuleData@@UAE@XZ present-unmatched
TransportAIUpdateModuleData::~TransportAIUpdateModuleData() {}
void TransportAIUpdateModuleData_Delete(TransportAIUpdateModuleData *p) { delete p; }

// ??_GLaserUpdateModuleData@@UAEPAXI@Z @0x003631CC 28B: slot 0 of vtable 0x00C17120; calls ??1 at 0x003631E8.
// Owner evidence (audited 2026-09-26): retail registration LaserUpdate -> data factory RVA 0x0024D55A -> ctor RVA 0x00363147; primary vptr store RVA 0x0036314E.
class LaserUpdateModuleData { public: __declspec(noinline) virtual ~LaserUpdateModuleData(); };
// ??1LaserUpdateModuleData@@UAE@XZ present-unmatched
LaserUpdateModuleData::~LaserUpdateModuleData() {}
void LaserUpdateModuleData_Delete(LaserUpdateModuleData *p) { delete p; }

// ??_GArrowStormUpdateModuleData@@UAEPAXI@Z @0x00490679 28B: slot 0 of vtable 0x00C4D5A0; calls ??1 at 0x00490695.
// Owner evidence (audited 2026-09-26): retail registration ArrowStormUpdate -> data factory RVA 0x0024D601 -> ctor RVA 0x00490639; primary vptr store RVA 0x00490647.
class ArrowStormUpdateModuleData { public: __declspec(noinline) virtual ~ArrowStormUpdateModuleData(); };
// ??1ArrowStormUpdateModuleData@@UAE@XZ present-unmatched
ArrowStormUpdateModuleData::~ArrowStormUpdateModuleData() {}
void ArrowStormUpdateModuleData_Delete(ArrowStormUpdateModuleData *p) { delete p; }

// ??_GAutoPickUpUpdateModuleData@@UAEPAXI@Z @0x00496460 28B: slot 0 of vtable 0x00C4F108; calls ??1 at 0x0049647C.
// Owner evidence (audited 2026-09-26): retail registration AutoPickUpUpdate -> data factory RVA 0x0024E099 -> ctor RVA 0x00496308; primary vptr store RVA 0x00496321.
class AutoPickUpUpdateModuleData { public: __declspec(noinline) virtual ~AutoPickUpUpdateModuleData(); };
// ??1AutoPickUpUpdateModuleData@@UAE@XZ present-unmatched
AutoPickUpUpdateModuleData::~AutoPickUpUpdateModuleData() {}
void AutoPickUpUpdateModuleData_Delete(AutoPickUpUpdateModuleData *p) { delete p; }

// ??_GBannerCarrierUpdateModuleData@@UAEPAXI@Z @0x004976AE 28B: slot 0 of vtable 0x00C4F870; calls ??1 at 0x00497056.
// Owner evidence (audited 2026-09-26): retail registration BannerCarrierUpdate -> data factory RVA 0x0024E1AB -> ctor RVA 0x00496FA5; primary vptr store RVA 0x00496FB7.
class BannerCarrierUpdateModuleData { public: __declspec(noinline) virtual ~BannerCarrierUpdateModuleData(); };
// ??1BannerCarrierUpdateModuleData@@UAE@XZ present-unmatched
BannerCarrierUpdateModuleData::~BannerCarrierUpdateModuleData() {}
void BannerCarrierUpdateModuleData_Delete(BannerCarrierUpdateModuleData *p) { delete p; }

// ??_GOneRingPenaltyUpdateModuleData@@UAEPAXI@Z @0x00499C19 28B: slot 0 of vtable 0x00C50298; calls ??1 at 0x00499A16.
// Owner evidence (audited 2026-09-26): retail registration OneRingPenaltyUpdate -> data factory RVA 0x0024E42C -> ctor RVA 0x004999F1; primary vptr store RVA 0x004999F8.
class OneRingPenaltyUpdateModuleData { public: __declspec(noinline) virtual ~OneRingPenaltyUpdateModuleData(); };
// ??1OneRingPenaltyUpdateModuleData@@UAE@XZ present-unmatched
OneRingPenaltyUpdateModuleData::~OneRingPenaltyUpdateModuleData() {}
void OneRingPenaltyUpdateModuleData_Delete(OneRingPenaltyUpdateModuleData *p) { delete p; }

// ??_GReplaceObjectUpdateModuleData@@UAEPAXI@Z @0x004B2E5D 28B: slot 0 of vtable 0x00C56C78; calls ??1 at 0x004B2C9A.
// Owner evidence (audited 2026-09-26): retail registration ReplaceObjectUpdate -> data factory RVA 0x0024FCEA -> ctor RVA 0x004B2AC4; primary vptr store RVA 0x004B2AD8.
class ReplaceObjectUpdateModuleData { public: __declspec(noinline) virtual ~ReplaceObjectUpdateModuleData(); };
// ??1ReplaceObjectUpdateModuleData@@UAE@XZ present-unmatched
ReplaceObjectUpdateModuleData::~ReplaceObjectUpdateModuleData() {}
void ReplaceObjectUpdateModuleData_Delete(ReplaceObjectUpdateModuleData *p) { delete p; }

// ??_GCritterEmitterUpdateModuleData@@UAEPAXI@Z @0x004C8F2D 28B: slot 0 of vtable 0x00C5E988; calls ??1 at 0x004C8F49.
// Owner evidence (audited 2026-09-26): retail registration CritterEmitterUpdate -> data factory RVA 0x00252906 -> ctor RVA 0x004C8EFF; primary vptr store RVA 0x004C8F0D.
class CritterEmitterUpdateModuleData { public: __declspec(noinline) virtual ~CritterEmitterUpdateModuleData(); };
// ??1CritterEmitterUpdateModuleData@@UAE@XZ present-unmatched
CritterEmitterUpdateModuleData::~CritterEmitterUpdateModuleData() {}
void CritterEmitterUpdateModuleData_Delete(CritterEmitterUpdateModuleData *p) { delete p; }
