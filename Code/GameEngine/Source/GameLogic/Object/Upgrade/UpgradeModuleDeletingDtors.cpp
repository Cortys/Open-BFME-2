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

// ??_GSubObjectsUpgradeModuleData@@UAEPAXI@Z @0x002577F0 28B: slot 0 of vtable 0x00BF41A8; calls ??1 at 0x004B5214.
// Owner evidence (audited 2026-09-26): retail registration SubObjectsUpgrade -> data factory RVA 0x0025780C -> ctor RVA 0x00257768; primary vptr store RVA 0x0025777E.
class SubObjectsUpgradeModuleData { public: __declspec(noinline) virtual ~SubObjectsUpgradeModuleData(); };
// ??1SubObjectsUpgradeModuleData@@UAE@XZ present-unmatched
SubObjectsUpgradeModuleData::~SubObjectsUpgradeModuleData() {}
void SubObjectsUpgradeModuleData_Delete(SubObjectsUpgradeModuleData *p) { delete p; }

// ??_GLocomotorSetUpgrade@@UAEPAXI@Z @0x004B3F3C 28B: slot 0 of vtable 0x00C57530; calls ??1 at 0x004B3EA0.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x004B3EC6 uses class-name string "LocomotorSetUpgrade".
class LocomotorSetUpgrade { public: __declspec(noinline) virtual ~LocomotorSetUpgrade(); };
// ??1LocomotorSetUpgrade@@UAE@XZ present-unmatched
LocomotorSetUpgrade::~LocomotorSetUpgrade() {}
void LocomotorSetUpgrade_Delete(LocomotorSetUpgrade *p) { delete p; }

// ??_GObjectCreationUpgradeModuleData@@UAEPAXI@Z @0x004B45CC 28B: slot 0 of vtable 0x00C577C8; calls ??1 at 0x004B45E8.
// Owner evidence (audited 2026-09-26): retail registration ObjectCreationUpgrade -> data factory RVA 0x0024FFAC -> ctor RVA 0x004B425B; primary vptr store RVA 0x004B4264.
class ObjectCreationUpgradeModuleData { public: __declspec(noinline) virtual ~ObjectCreationUpgradeModuleData(); };
// ??1ObjectCreationUpgradeModuleData@@UAE@XZ present-unmatched
ObjectCreationUpgradeModuleData::~ObjectCreationUpgradeModuleData() {}
void ObjectCreationUpgradeModuleData_Delete(ObjectCreationUpgradeModuleData *p) { delete p; }

// ??_GStatusBitsUpgradeIfEldestKindof@@UAEPAXI@Z @0x004B4ADE 28B: slot 0 of vtable 0x00C57ADC; calls ??1 at 0x004B4AFA.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x004B4A99 uses class-name string "StatusBitsUpgradeIfEldestKindof".
class StatusBitsUpgradeIfEldestKindof { public: __declspec(noinline) virtual ~StatusBitsUpgradeIfEldestKindof(); };
// ??1StatusBitsUpgradeIfEldestKindof@@UAE@XZ present-unmatched
StatusBitsUpgradeIfEldestKindof::~StatusBitsUpgradeIfEldestKindof() {}
void StatusBitsUpgradeIfEldestKindof_Delete(StatusBitsUpgradeIfEldestKindof *p) { delete p; }

// ??_GCostModifierUpgradeModuleData@@UAEPAXI@Z @0x004B5C64 28B: slot 0 of vtable 0x00C58210; calls ??1 at 0x004B5C80.
// Owner evidence (audited 2026-09-26): retail registration CostModifierUpgrade -> data factory RVA 0x00250316 -> ctor RVA 0x004B5BAC; primary vptr store RVA 0x004B5BD0.
class CostModifierUpgradeModuleData { public: __declspec(noinline) virtual ~CostModifierUpgradeModuleData(); };
// ??1CostModifierUpgradeModuleData@@UAE@XZ present-unmatched
CostModifierUpgradeModuleData::~CostModifierUpgradeModuleData() {}
void CostModifierUpgradeModuleData_Delete(CostModifierUpgradeModuleData *p) { delete p; }

// ??_GAllowBannerSpawnUpgrade@@UAEPAXI@Z @0x004B85B8 28B: slot 0 of vtable 0x00C59030; calls ??1 at 0x004B84EA.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x004B8520 uses class-name string "AllowBannerSpawnUpgrade".
class AllowBannerSpawnUpgrade { public: __declspec(noinline) virtual ~AllowBannerSpawnUpgrade(); };
// ??1AllowBannerSpawnUpgrade@@UAE@XZ present-unmatched
AllowBannerSpawnUpgrade::~AllowBannerSpawnUpgrade() {}
void AllowBannerSpawnUpgrade_Delete(AllowBannerSpawnUpgrade *p) { delete p; }
