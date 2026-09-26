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

// ??_GSubObjectsUpgradeModuleData@@UAEPAXI@Z @0x002577F0 28B: slot 0 of vtable 0x00BF41A8; calls ??1 at 0x004B5214.
// Owner evidence: sole named installer ??0SubObjectsUpgradeModuleData@@QAE@XZ.
class SubObjectsUpgradeModuleData { public: __declspec(noinline) virtual ~SubObjectsUpgradeModuleData(); };
// ??1SubObjectsUpgradeModuleData@@UAE@XZ present-unmatched
SubObjectsUpgradeModuleData::~SubObjectsUpgradeModuleData() {}
void SubObjectsUpgradeModuleData_Delete(SubObjectsUpgradeModuleData *p) { delete p; }

// ??_GLocomotorSetUpgrade@@UAEPAXI@Z @0x004B3F3C 28B: slot 0 of vtable 0x00C57530; calls ??1 at 0x004B3EA0.
// Owner evidence: installed by ??0LocomotorSetUpgrade@@QAE@PAVThing@@PBVModuleData@@@Z; class-unique slots 4 ?rva0004B3EC6@LocomotorSetUpgrade@@SA?AW4NameKeyType@@XZ.
class LocomotorSetUpgrade { public: __declspec(noinline) virtual ~LocomotorSetUpgrade(); };
// ??1LocomotorSetUpgrade@@UAE@XZ present-unmatched
LocomotorSetUpgrade::~LocomotorSetUpgrade() {}
void LocomotorSetUpgrade_Delete(LocomotorSetUpgrade *p) { delete p; }

// ??_GObjectCreationUpgradeModuleData@@UAEPAXI@Z @0x004B45CC 28B: slot 0 of vtable 0x00C577C8; calls ??1 at 0x004B45E8.
// Owner evidence: sole named installer ??0ObjectCreationUpgradeModuleData@@QAE@XZ.
class ObjectCreationUpgradeModuleData { public: __declspec(noinline) virtual ~ObjectCreationUpgradeModuleData(); };
// ??1ObjectCreationUpgradeModuleData@@UAE@XZ present-unmatched
ObjectCreationUpgradeModuleData::~ObjectCreationUpgradeModuleData() {}
void ObjectCreationUpgradeModuleData_Delete(ObjectCreationUpgradeModuleData *p) { delete p; }

// ??_GStatusBitsUpgradeIfEldestKindof@@UAEPAXI@Z @0x004B4ADE 28B: slot 0 of vtable 0x00C57ADC; calls ??1 at 0x004B4AFA.
// Owner evidence: installed by ??0StatusBitsUpgradeIfEldestKindof@@QAE@PAVThing@@PBVModuleData@@@Z; class-unique slots 4 ?rva0004B4A99@StatusBitsUpgradeIfEldestKindof@@SA?AW4NameKeyType@@XZ.
class StatusBitsUpgradeIfEldestKindof { public: __declspec(noinline) virtual ~StatusBitsUpgradeIfEldestKindof(); };
// ??1StatusBitsUpgradeIfEldestKindof@@UAE@XZ present-unmatched
StatusBitsUpgradeIfEldestKindof::~StatusBitsUpgradeIfEldestKindof() {}
void StatusBitsUpgradeIfEldestKindof_Delete(StatusBitsUpgradeIfEldestKindof *p) { delete p; }

// ??_GCostModifierUpgradeModuleData@@UAEPAXI@Z @0x004B5C64 28B: slot 0 of vtable 0x00C58210; calls ??1 at 0x004B5C80.
// Owner evidence: sole named installer ??0CostModifierUpgradeModuleData@@QAE@XZ.
class CostModifierUpgradeModuleData { public: __declspec(noinline) virtual ~CostModifierUpgradeModuleData(); };
// ??1CostModifierUpgradeModuleData@@UAE@XZ present-unmatched
CostModifierUpgradeModuleData::~CostModifierUpgradeModuleData() {}
void CostModifierUpgradeModuleData_Delete(CostModifierUpgradeModuleData *p) { delete p; }

// ??_GAllowBannerSpawnUpgrade@@UAEPAXI@Z @0x004B85B8 28B: slot 0 of vtable 0x00C59030; calls ??1 at 0x004B84EA.
// Owner evidence: installed by ??0AllowBannerSpawnUpgrade@@QAE@PAVThing@@PBVModuleData@@@Z; class-unique slots 4 ?rva004B8520@AllowBannerSpawnUpgrade@@SA?AW4NameKeyType@@XZ.
class AllowBannerSpawnUpgrade { public: __declspec(noinline) virtual ~AllowBannerSpawnUpgrade(); };
// ??1AllowBannerSpawnUpgrade@@UAE@XZ present-unmatched
AllowBannerSpawnUpgrade::~AllowBannerSpawnUpgrade() {}
void AllowBannerSpawnUpgrade_Delete(AllowBannerSpawnUpgrade *p) { delete p; }
