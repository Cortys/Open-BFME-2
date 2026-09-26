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

// ??_GTerrainResourceClientBehavior@@UAEPAXI@Z @0x00252E56 28B: slot 0 of vtable 0x00BEFF20; calls ??1 at 0x004CC5AA.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x00252E0B uses class-name string "TerrainResourceClientBehavior".
class TerrainResourceClientBehavior { public: __declspec(noinline) virtual ~TerrainResourceClientBehavior(); };
// ??1TerrainResourceClientBehavior@@UAE@XZ present-unmatched
TerrainResourceClientBehavior::~TerrainResourceClientBehavior() {}
void TerrainResourceClientBehavior_Delete(TerrainResourceClientBehavior *p) { delete p; }

// ??_GGateProxyBehaviorModuleData@@UAEPAXI@Z @0x00254029 28B: slot 0 of vtable 0x00BEF380; calls ??1 at 0x00254045.
// Owner evidence (audited 2026-09-26): retail registration GateProxyBehavior -> data factory RVA 0x00253FB1; inlined construction stores this vtable at RVA 0x00253FD9.
class GateProxyBehaviorModuleData { public: __declspec(noinline) virtual ~GateProxyBehaviorModuleData(); };
// ??1GateProxyBehaviorModuleData@@UAE@XZ present-unmatched
GateProxyBehaviorModuleData::~GateProxyBehaviorModuleData() {}
void GateProxyBehaviorModuleData_Delete(GateProxyBehaviorModuleData *p) { delete p; }

// ??_GCastleMemberBehaviorModuleData@@UAEPAXI@Z @0x00396007 28B: slot 0 of vtable 0x00C1A380; calls ??1 at 0x00395B2C.
// Owner evidence (audited 2026-09-26): retail registration CastleMemberBehavior -> data factory RVA 0x0024AB26 -> ctor RVA 0x00395B03; primary vptr store RVA 0x00395B07.
class CastleMemberBehaviorModuleData { public: __declspec(noinline) virtual ~CastleMemberBehaviorModuleData(); };
// ??1CastleMemberBehaviorModuleData@@UAE@XZ present-unmatched
CastleMemberBehaviorModuleData::~CastleMemberBehaviorModuleData() {}
void CastleMemberBehaviorModuleData_Delete(CastleMemberBehaviorModuleData *p) { delete p; }

// ??_GCastleBehavior@@UAEPAXI@Z @0x00399354 28B: slot 0 of vtable 0x00C1A780; calls ??1 at 0x0039857D.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x00398538 uses class-name string "CastleBehavior".
class CastleBehavior { public: __declspec(noinline) virtual ~CastleBehavior(); };
// ??1CastleBehavior@@UAE@XZ present-unmatched
CastleBehavior::~CastleBehavior() {}
void CastleBehavior_Delete(CastleBehavior *p) { delete p; }

// ??_GGettingBuiltBehavior@@UAEPAXI@Z @0x0045477E 28B: slot 0 of vtable 0x00C404FC; calls ??1 at 0x0045448F.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x004543EB uses class-name string "GettingBuiltBehavior".
class GettingBuiltBehavior { public: __declspec(noinline) virtual ~GettingBuiltBehavior(); };
// ??1GettingBuiltBehavior@@UAE@XZ present-unmatched
GettingBuiltBehavior::~GettingBuiltBehavior() {}
void GettingBuiltBehavior_Delete(GettingBuiltBehavior *p) { delete p; }

// ??_GBridgeBehavior@@UAEPAXI@Z @0x00457536 28B: slot 0 of vtable 0x00C409DC; calls ??1 at 0x00457113.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x004571A9 uses class-name string "BridgeBehavior".
class BridgeBehavior { public: __declspec(noinline) virtual ~BridgeBehavior(); };
// ??1BridgeBehavior@@UAE@XZ present-unmatched
BridgeBehavior::~BridgeBehavior() {}
void BridgeBehavior_Delete(BridgeBehavior *p) { delete p; }

// ??_GSiegeDockingBehavior@@UAEPAXI@Z @0x0045A17D 28B: slot 0 of vtable 0x00C414DC; calls ??1 at 0x00459DAA.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x004599E5 uses class-name string "SiegeDockingBehavior".
class SiegeDockingBehavior { public: __declspec(noinline) virtual ~SiegeDockingBehavior(); };
// ??1SiegeDockingBehavior@@UAE@XZ present-unmatched
SiegeDockingBehavior::~SiegeDockingBehavior() {}
void SiegeDockingBehavior_Delete(SiegeDockingBehavior *p) { delete p; }

// ??_GAutoAbilityBehavior@@UAEPAXI@Z @0x0045A560 28B: slot 0 of vtable 0x00C4175C; calls ??1 at 0x0045A37F.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x0045A3CE uses class-name string "AutoAbilityBehavior".
class AutoAbilityBehavior { public: __declspec(noinline) virtual ~AutoAbilityBehavior(); };
// ??1AutoAbilityBehavior@@UAE@XZ present-unmatched
AutoAbilityBehavior::~AutoAbilityBehavior() {}
void AutoAbilityBehavior_Delete(AutoAbilityBehavior *p) { delete p; }

// ??_GBezierProjectileBehavior@@UAEPAXI@Z @0x0045C959 28B: slot 0 of vtable 0x00C41E04; calls ??1 at 0x0045BF6E.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x0045BFD9 uses class-name string "BezierProjectileBehavior".
class BezierProjectileBehavior { public: __declspec(noinline) virtual ~BezierProjectileBehavior(); };
// ??1BezierProjectileBehavior@@UAE@XZ present-unmatched
BezierProjectileBehavior::~BezierProjectileBehavior() {}
void BezierProjectileBehavior_Delete(BezierProjectileBehavior *p) { delete p; }

// ??_GInstantDeathBehaviorModuleData@@UAEPAXI@Z @0x0045D271 28B: slot 0 of vtable 0x00C41F28; calls ??1 at 0x0045D28D.
// Owner evidence (audited 2026-09-26): retail registration InstantDeathBehavior -> data factory RVA 0x0024B213 -> ctor RVA 0x0045D176; primary vptr store RVA 0x0045D189.
class InstantDeathBehaviorModuleData { public: __declspec(noinline) virtual ~InstantDeathBehaviorModuleData(); };
// ??1InstantDeathBehaviorModuleData@@UAE@XZ present-unmatched
InstantDeathBehaviorModuleData::~InstantDeathBehaviorModuleData() {}
void InstantDeathBehaviorModuleData_Delete(InstantDeathBehaviorModuleData *p) { delete p; }

// ??_GStancesBehavior@@UAEPAXI@Z @0x0045F068 28B: slot 0 of vtable 0x00C424DC; calls ??1 at 0x0045F001.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x0045EFBC uses class-name string "StancesBehavior".
class StancesBehavior { public: __declspec(noinline) virtual ~StancesBehavior(); };
// ??1StancesBehavior@@UAE@XZ present-unmatched
StancesBehavior::~StancesBehavior() {}
void StancesBehavior_Delete(StancesBehavior *p) { delete p; }

// ??_GSpawnBehavior@@UAEPAXI@Z @0x004602D8 28B: slot 0 of vtable 0x00C426AC; calls ??1 at 0x0045F6D3.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x0045F688 uses class-name string "SpawnBehavior".
class SpawnBehavior { public: __declspec(noinline) virtual ~SpawnBehavior(); };
// ??1SpawnBehavior@@UAE@XZ present-unmatched
SpawnBehavior::~SpawnBehavior() {}
void SpawnBehavior_Delete(SpawnBehavior *p) { delete p; }

// ??_GFakePathfindPortalBehaviour@@UAEPAXI@Z @0x00461C03 28B: slot 0 of vtable 0x00C42C1C; calls ??1 at 0x004619F2.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x004619AD uses class-name string "FakePathfindPortalBehaviour".
class FakePathfindPortalBehaviour { public: __declspec(noinline) virtual ~FakePathfindPortalBehaviour(); };
// ??1FakePathfindPortalBehaviour@@UAE@XZ present-unmatched
FakePathfindPortalBehaviour::~FakePathfindPortalBehaviour() {}
void FakePathfindPortalBehaviour_Delete(FakePathfindPortalBehaviour *p) { delete p; }

// ??_GPropagandaTowerBehaviorModuleData@@UAEPAXI@Z @0x00481BB2 28B: slot 0 of vtable 0x00C49288; calls ??1 at 0x00481BCE.
// Owner evidence (audited 2026-09-26): retail registration PropagandaTowerBehavior -> data factory RVA 0x0024C21B -> ctor RVA 0x0048197C; primary vptr store RVA 0x00481988.
class PropagandaTowerBehaviorModuleData { public: __declspec(noinline) virtual ~PropagandaTowerBehaviorModuleData(); };
// ??1PropagandaTowerBehaviorModuleData@@UAE@XZ present-unmatched
PropagandaTowerBehaviorModuleData::~PropagandaTowerBehaviorModuleData() {}
void PropagandaTowerBehaviorModuleData_Delete(PropagandaTowerBehaviorModuleData *p) { delete p; }

// ??_GRebuildHoleBehaviorModuleData@@UAEPAXI@Z @0x0048332E 28B: slot 0 of vtable 0x00C49950; calls ??1 at 0x0048334A.
// Owner evidence (audited 2026-09-26): retail registration RebuildHoleBehavior -> data factory RVA 0x0024C433 -> ctor RVA 0x0048323E; primary vptr store RVA 0x00483250.
class RebuildHoleBehaviorModuleData { public: __declspec(noinline) virtual ~RebuildHoleBehaviorModuleData(); };
// ??1RebuildHoleBehaviorModuleData@@UAE@XZ present-unmatched
RebuildHoleBehaviorModuleData::~RebuildHoleBehaviorModuleData() {}
void RebuildHoleBehaviorModuleData_Delete(RebuildHoleBehaviorModuleData *p) { delete p; }

// ??_GReplenishUnitsBehavior@@UAEPAXI@Z @0x004842C1 28B: slot 0 of vtable 0x00C4A034; calls ??1 at 0x00484161.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x00484187 uses class-name string "ReplenishUnitsBehavior".
class ReplenishUnitsBehavior { public: __declspec(noinline) virtual ~ReplenishUnitsBehavior(); };
// ??1ReplenishUnitsBehavior@@UAE@XZ present-unmatched
ReplenishUnitsBehavior::~ReplenishUnitsBehavior() {}
void ReplenishUnitsBehavior_Delete(ReplenishUnitsBehavior *p) { delete p; }

// ??_GSlaveWatcherBehaviorModuleData@@UAEPAXI@Z @0x004846DE 28B: slot 0 of vtable 0x00C4A298; calls ??1 at 0x004846FA.
// Owner evidence (audited 2026-09-26): retail registration SlaveWatcherBehavior -> data factory RVA 0x0024C660 -> ctor RVA 0x004846C7; primary vptr store RVA 0x004846CB.
class SlaveWatcherBehaviorModuleData { public: __declspec(noinline) virtual ~SlaveWatcherBehaviorModuleData(); };
// ??1SlaveWatcherBehaviorModuleData@@UAE@XZ present-unmatched
SlaveWatcherBehaviorModuleData::~SlaveWatcherBehaviorModuleData() {}
void SlaveWatcherBehaviorModuleData_Delete(SlaveWatcherBehaviorModuleData *p) { delete p; }
