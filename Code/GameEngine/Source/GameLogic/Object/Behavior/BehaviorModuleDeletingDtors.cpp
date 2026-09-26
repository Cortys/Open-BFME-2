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

// ??_GTerrainResourceClientBehavior@@UAEPAXI@Z @0x00252E56 28B: slot 0 of vtable 0x00BEFF20; calls ??1 at 0x004CC5AA.
// Owner evidence: installed by ??0TerrainResourceClientBehavior@@QAE@PAVThing@@PBVModuleData@@@Z; class-unique slots 4 ?rva000252E0B@TerrainResourceClientBehavior@@SA?AW4NameKeyType@@XZ.
class TerrainResourceClientBehavior { public: __declspec(noinline) virtual ~TerrainResourceClientBehavior(); };
// ??1TerrainResourceClientBehavior@@UAE@XZ present-unmatched
TerrainResourceClientBehavior::~TerrainResourceClientBehavior() {}
void TerrainResourceClientBehavior_Delete(TerrainResourceClientBehavior *p) { delete p; }

// ??_GGateProxyBehaviorModuleData@@UAEPAXI@Z @0x00254029 28B: slot 0 of vtable 0x00BEF380; calls ??1 at 0x00254045.
// Owner evidence: sole named installer ??0GateProxyBehaviorModuleData@@QAE@XZ.
class GateProxyBehaviorModuleData { public: __declspec(noinline) virtual ~GateProxyBehaviorModuleData(); };
// ??1GateProxyBehaviorModuleData@@UAE@XZ present-unmatched
GateProxyBehaviorModuleData::~GateProxyBehaviorModuleData() {}
void GateProxyBehaviorModuleData_Delete(GateProxyBehaviorModuleData *p) { delete p; }

// ??_GCastleMemberBehaviorModuleData@@UAEPAXI@Z @0x00396007 28B: slot 0 of vtable 0x00C1A380; calls ??1 at 0x00395B2C.
// Owner evidence: sole named installer ??0CastleMemberBehaviorModuleData@@QAE@XZ.
class CastleMemberBehaviorModuleData { public: __declspec(noinline) virtual ~CastleMemberBehaviorModuleData(); };
// ??1CastleMemberBehaviorModuleData@@UAE@XZ present-unmatched
CastleMemberBehaviorModuleData::~CastleMemberBehaviorModuleData() {}
void CastleMemberBehaviorModuleData_Delete(CastleMemberBehaviorModuleData *p) { delete p; }

// ??_GCastleBehavior@@UAEPAXI@Z @0x00399354 28B: slot 0 of vtable 0x00C1A780; calls ??1 at 0x0039857D.
// Owner evidence: class-unique slots 4 ?rva000398538@CastleBehavior@@SA?AW4NameKeyType@@XZ.
class CastleBehavior { public: __declspec(noinline) virtual ~CastleBehavior(); };
// ??1CastleBehavior@@UAE@XZ present-unmatched
CastleBehavior::~CastleBehavior() {}
void CastleBehavior_Delete(CastleBehavior *p) { delete p; }

// ??_GGettingBuiltBehavior@@UAEPAXI@Z @0x0045477E 28B: slot 0 of vtable 0x00C404FC; calls ??1 at 0x0045448F.
// Owner evidence: installed by ??0GettingBuiltBehavior@@QAE@PAVThing@@PBVModuleData@@@Z; class-unique slots 4 ?rva0004543EB@GettingBuiltBehavior@@SA?AW4NameKeyType@@XZ.
class GettingBuiltBehavior { public: __declspec(noinline) virtual ~GettingBuiltBehavior(); };
// ??1GettingBuiltBehavior@@UAE@XZ present-unmatched
GettingBuiltBehavior::~GettingBuiltBehavior() {}
void GettingBuiltBehavior_Delete(GettingBuiltBehavior *p) { delete p; }

// ??_GBridgeBehavior@@UAEPAXI@Z @0x00457536 28B: slot 0 of vtable 0x00C409DC; calls ??1 at 0x00457113.
// Owner evidence: class-unique slots 4 ?rva004571A9@BridgeBehavior@@SA?AW4NameKeyType@@XZ.
class BridgeBehavior { public: __declspec(noinline) virtual ~BridgeBehavior(); };
// ??1BridgeBehavior@@UAE@XZ present-unmatched
BridgeBehavior::~BridgeBehavior() {}
void BridgeBehavior_Delete(BridgeBehavior *p) { delete p; }

// ??_GSiegeDockingBehavior@@UAEPAXI@Z @0x0045A17D 28B: slot 0 of vtable 0x00C414DC; calls ??1 at 0x00459DAA.
// Owner evidence: installed by ??0SiegeDockingBehavior@@QAE@PAVThing@@PBVModuleData@@@Z; class-unique slots 4 ?rva0004599E5@SiegeDockingBehavior@@SA?AW4NameKeyType@@XZ.
class SiegeDockingBehavior { public: __declspec(noinline) virtual ~SiegeDockingBehavior(); };
// ??1SiegeDockingBehavior@@UAE@XZ present-unmatched
SiegeDockingBehavior::~SiegeDockingBehavior() {}
void SiegeDockingBehavior_Delete(SiegeDockingBehavior *p) { delete p; }

// ??_GAutoAbilityBehavior@@UAEPAXI@Z @0x0045A560 28B: slot 0 of vtable 0x00C4175C; calls ??1 at 0x0045A37F.
// Owner evidence: class-unique slots 4 ?rva00045A3CE@AutoAbilityBehavior@@SA?AW4NameKeyType@@XZ.
class AutoAbilityBehavior { public: __declspec(noinline) virtual ~AutoAbilityBehavior(); };
// ??1AutoAbilityBehavior@@UAE@XZ present-unmatched
AutoAbilityBehavior::~AutoAbilityBehavior() {}
void AutoAbilityBehavior_Delete(AutoAbilityBehavior *p) { delete p; }

// ??_GBezierProjectileBehavior@@UAEPAXI@Z @0x0045C959 28B: slot 0 of vtable 0x00C41E04; calls ??1 at 0x0045BF6E.
// Owner evidence: class-unique slots 4 ?rva00045BFD9@BezierProjectileBehavior@@SA?AW4NameKeyType@@XZ.
class BezierProjectileBehavior { public: __declspec(noinline) virtual ~BezierProjectileBehavior(); };
// ??1BezierProjectileBehavior@@UAE@XZ present-unmatched
BezierProjectileBehavior::~BezierProjectileBehavior() {}
void BezierProjectileBehavior_Delete(BezierProjectileBehavior *p) { delete p; }

// ??_GInstantDeathBehaviorModuleData@@UAEPAXI@Z @0x0045D271 28B: slot 0 of vtable 0x00C41F28; calls ??1 at 0x0045D28D.
// Owner evidence: sole named installer ??0InstantDeathBehaviorModuleData@@QAE@XZ.
class InstantDeathBehaviorModuleData { public: __declspec(noinline) virtual ~InstantDeathBehaviorModuleData(); };
// ??1InstantDeathBehaviorModuleData@@UAE@XZ present-unmatched
InstantDeathBehaviorModuleData::~InstantDeathBehaviorModuleData() {}
void InstantDeathBehaviorModuleData_Delete(InstantDeathBehaviorModuleData *p) { delete p; }

// ??_GStancesBehavior@@UAEPAXI@Z @0x0045F068 28B: slot 0 of vtable 0x00C424DC; calls ??1 at 0x0045F001.
// Owner evidence: installed by ??0StancesBehavior@@QAE@PAVThing@@PBVModuleData@@@Z; class-unique slots 3 ?xfer@StancesBehavior@@MAEXPAVXfer@@@Z and 4 ?rva00045EFBC@StancesBehavior@@SA?AW4NameKeyType@@XZ.
class StancesBehavior { public: __declspec(noinline) virtual ~StancesBehavior(); };
// ??1StancesBehavior@@UAE@XZ present-unmatched
StancesBehavior::~StancesBehavior() {}
void StancesBehavior_Delete(StancesBehavior *p) { delete p; }

// ??_GSpawnBehavior@@UAEPAXI@Z @0x004602D8 28B: slot 0 of vtable 0x00C426AC; calls ??1 at 0x0045F6D3.
// Owner evidence: class-unique slots 4 ?rva00045F688@SpawnBehavior@@SA?AW4NameKeyType@@XZ.
class SpawnBehavior { public: __declspec(noinline) virtual ~SpawnBehavior(); };
// ??1SpawnBehavior@@UAE@XZ present-unmatched
SpawnBehavior::~SpawnBehavior() {}
void SpawnBehavior_Delete(SpawnBehavior *p) { delete p; }

// ??_GFakePathfindPortalBehaviour@@UAEPAXI@Z @0x00461C03 28B: slot 0 of vtable 0x00C42C1C; calls ??1 at 0x004619F2.
// Owner evidence: installed by ??0FakePathfindPortalBehaviour@@QAE@PAVThing@@PBVModuleData@@@Z; class-unique slots 4 ?rva0004619AD@FakePathfindPortalBehaviour@@SA?AW4NameKeyType@@XZ.
class FakePathfindPortalBehaviour { public: __declspec(noinline) virtual ~FakePathfindPortalBehaviour(); };
// ??1FakePathfindPortalBehaviour@@UAE@XZ present-unmatched
FakePathfindPortalBehaviour::~FakePathfindPortalBehaviour() {}
void FakePathfindPortalBehaviour_Delete(FakePathfindPortalBehaviour *p) { delete p; }

// ??_GPropagandaTowerBehaviorModuleData@@UAEPAXI@Z @0x00481BB2 28B: slot 0 of vtable 0x00C49288; calls ??1 at 0x00481BCE.
// Owner evidence: sole named installer ??0PropagandaTowerBehaviorModuleData@@QAE@XZ.
class PropagandaTowerBehaviorModuleData { public: __declspec(noinline) virtual ~PropagandaTowerBehaviorModuleData(); };
// ??1PropagandaTowerBehaviorModuleData@@UAE@XZ present-unmatched
PropagandaTowerBehaviorModuleData::~PropagandaTowerBehaviorModuleData() {}
void PropagandaTowerBehaviorModuleData_Delete(PropagandaTowerBehaviorModuleData *p) { delete p; }

// ??_GRebuildHoleBehaviorModuleData@@UAEPAXI@Z @0x0048332E 28B: slot 0 of vtable 0x00C49950; calls ??1 at 0x0048334A.
// Owner evidence: sole named installer ??0RebuildHoleBehaviorModuleData@@QAE@XZ.
class RebuildHoleBehaviorModuleData { public: __declspec(noinline) virtual ~RebuildHoleBehaviorModuleData(); };
// ??1RebuildHoleBehaviorModuleData@@UAE@XZ present-unmatched
RebuildHoleBehaviorModuleData::~RebuildHoleBehaviorModuleData() {}
void RebuildHoleBehaviorModuleData_Delete(RebuildHoleBehaviorModuleData *p) { delete p; }

// ??_GReplenishUnitsBehavior@@UAEPAXI@Z @0x004842C1 28B: slot 0 of vtable 0x00C4A034; calls ??1 at 0x00484161.
// Owner evidence: installed by ??0ReplenishUnitsBehavior@@QAE@PAVThing@@PBVModuleData@@@Z; class-unique slots 4 ?rva000484187@ReplenishUnitsBehavior@@SA?AW4NameKeyType@@XZ.
class ReplenishUnitsBehavior { public: __declspec(noinline) virtual ~ReplenishUnitsBehavior(); };
// ??1ReplenishUnitsBehavior@@UAE@XZ present-unmatched
ReplenishUnitsBehavior::~ReplenishUnitsBehavior() {}
void ReplenishUnitsBehavior_Delete(ReplenishUnitsBehavior *p) { delete p; }

// ??_GSlaveWatcherBehaviorModuleData@@UAEPAXI@Z @0x004846DE 28B: slot 0 of vtable 0x00C4A298; calls ??1 at 0x004846FA.
// Owner evidence: sole named installer ??0SlaveWatcherBehaviorModuleData@@QAE@XZ.
class SlaveWatcherBehaviorModuleData { public: __declspec(noinline) virtual ~SlaveWatcherBehaviorModuleData(); };
// ??1SlaveWatcherBehaviorModuleData@@UAE@XZ present-unmatched
SlaveWatcherBehaviorModuleData::~SlaveWatcherBehaviorModuleData() {}
void SlaveWatcherBehaviorModuleData_Delete(SlaveWatcherBehaviorModuleData *p) { delete p; }
