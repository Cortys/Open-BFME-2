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

// ??_GActivateModuleSpecialPowerModuleData@@UAEPAXI@Z @0x0025712E 28B: slot 0 of vtable 0x00BF3F60; calls ??1 at 0x0025714A.
// Owner evidence (audited 2026-09-26): retail registration ActivateModuleSpecialPower -> data factory RVA 0x00256DC5 -> ctor RVA 0x00256DA1; primary vptr store RVA 0x00256DB5.
class ActivateModuleSpecialPowerModuleData { public: __declspec(noinline) virtual ~ActivateModuleSpecialPowerModuleData(); };
// ??1ActivateModuleSpecialPowerModuleData@@UAE@XZ present-unmatched
ActivateModuleSpecialPowerModuleData::~ActivateModuleSpecialPowerModuleData() {}
void ActivateModuleSpecialPowerModuleData_Delete(ActivateModuleSpecialPowerModuleData *p) { delete p; }

// ??_GWeaponFireSpecialAbilityUpdateModuleData@@UAEPAXI@Z @0x004927EA 28B: slot 0 of vtable 0x00C4E108; calls ??1 at 0x00492806.
// Owner evidence (audited 2026-09-26): retail registration WeaponFireSpecialAbilityUpdate -> data factory RVA 0x0024DB56 -> ctor RVA 0x004926CA; primary vptr store RVA 0x004926D4.
class WeaponFireSpecialAbilityUpdateModuleData { public: __declspec(noinline) virtual ~WeaponFireSpecialAbilityUpdateModuleData(); };
// ??1WeaponFireSpecialAbilityUpdateModuleData@@UAE@XZ present-unmatched
WeaponFireSpecialAbilityUpdateModuleData::~WeaponFireSpecialAbilityUpdateModuleData() {}
void WeaponFireSpecialAbilityUpdateModuleData_Delete(WeaponFireSpecialAbilityUpdateModuleData *p) { delete p; }

// ??_GSpecialPowerModule@@UAEPAXI@Z @0x004941D7 28B: slot 0 of vtable 0x00C4E868; calls ??1 at 0x00493DEF.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x00493DAA uses class-name string "SpecialPowerModule".
class SpecialPowerModule { public: __declspec(noinline) virtual ~SpecialPowerModule(); };
// ??1SpecialPowerModule@@UAE@XZ present-unmatched
SpecialPowerModule::~SpecialPowerModule() {}
void SpecialPowerModule_Delete(SpecialPowerModule *p) { delete p; }

// ??_GAISpecialPowerUpdateModuleData@@UAEPAXI@Z @0x004B2FF3 28B: slot 0 of vtable 0x00C56F48; calls ??1 at 0x004B300F.
// Owner evidence (audited 2026-09-26): retail registration AISpecialPowerUpdate -> data factory RVA 0x0024FD76 -> ctor RVA 0x004B2FCD; primary vptr store RVA 0x004B2FD9.
class AISpecialPowerUpdateModuleData { public: __declspec(noinline) virtual ~AISpecialPowerUpdateModuleData(); };
// ??1AISpecialPowerUpdateModuleData@@UAE@XZ present-unmatched
AISpecialPowerUpdateModuleData::~AISpecialPowerUpdateModuleData() {}
void AISpecialPowerUpdateModuleData_Delete(AISpecialPowerUpdateModuleData *p) { delete p; }

// ??_GInvisibilitySpecialPowerModuleData@@UAEPAXI@Z @0x004C24C3 28B: slot 0 of vtable 0x00C5C558; calls ??1 at 0x004C24DF.
// Owner evidence (audited 2026-09-26): retail registration InvisibilitySpecialPower -> data factory RVA 0x002518CB -> ctor RVA 0x004C244D; primary vptr store RVA 0x004C246C.
class InvisibilitySpecialPowerModuleData { public: __declspec(noinline) virtual ~InvisibilitySpecialPowerModuleData(); };
// ??1InvisibilitySpecialPowerModuleData@@UAE@XZ present-unmatched
InvisibilitySpecialPowerModuleData::~InvisibilitySpecialPowerModuleData() {}
void InvisibilitySpecialPowerModuleData_Delete(InvisibilitySpecialPowerModuleData *p) { delete p; }

// ??_GCashHackSpecialPowerModuleData@@UAEPAXI@Z @0x004C28C1 28B: slot 0 of vtable 0x00C5C688; calls ??1 at 0x004C28DD.
// Owner evidence (audited 2026-09-26): retail registration CashHackSpecialPower -> data factory RVA 0x00251957 -> ctor RVA 0x004C2889; primary vptr store RVA 0x004C289D.
class CashHackSpecialPowerModuleData { public: __declspec(noinline) virtual ~CashHackSpecialPowerModuleData(); };
// ??1CashHackSpecialPowerModuleData@@UAE@XZ present-unmatched
CashHackSpecialPowerModuleData::~CashHackSpecialPowerModuleData() {}
void CashHackSpecialPowerModuleData_Delete(CashHackSpecialPowerModuleData *p) { delete p; }

// ??_GLevelGrantSpecialPower@@UAEPAXI@Z @0x004C2C5A 28B: slot 0 of vtable 0x00C5C920; calls ??1 at 0x004C2C76.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x004C2BC1 uses class-name string "LevelGrantSpecialPower".
class LevelGrantSpecialPower { public: __declspec(noinline) virtual ~LevelGrantSpecialPower(); };
// ??1LevelGrantSpecialPower@@UAE@XZ present-unmatched
LevelGrantSpecialPower::~LevelGrantSpecialPower() {}
void LevelGrantSpecialPower_Delete(LevelGrantSpecialPower *p) { delete p; }

// ??_GProductionSpeedBonusModuleData@@UAEPAXI@Z @0x004C3048 28B: slot 0 of vtable 0x00C5CA80; calls ??1 at 0x004C3064.
// Owner evidence (audited 2026-09-26): retail registration ProductionSpeedBonus -> data factory RVA 0x00251AFE -> ctor RVA 0x004C2FE6; primary vptr store RVA 0x004C300E.
class ProductionSpeedBonusModuleData { public: __declspec(noinline) virtual ~ProductionSpeedBonusModuleData(); };
// ??1ProductionSpeedBonusModuleData@@UAE@XZ present-unmatched
ProductionSpeedBonusModuleData::~ProductionSpeedBonusModuleData() {}
void ProductionSpeedBonusModuleData_Delete(ProductionSpeedBonusModuleData *p) { delete p; }

// ??_GOCLSpecialPowerModuleData@@UAEPAXI@Z @0x004C37A4 28B: slot 0 of vtable 0x00C5CCB0; calls ??1 at 0x004C37C0.
// Owner evidence (audited 2026-09-26): retail registration OCLSpecialPower -> data factory RVA 0x00251B8A -> ctor RVA 0x004C32BC; primary vptr store RVA 0x004C32E3.
class OCLSpecialPowerModuleData { public: __declspec(noinline) virtual ~OCLSpecialPowerModuleData(); };
// ??1OCLSpecialPowerModuleData@@UAE@XZ present-unmatched
OCLSpecialPowerModuleData::~OCLSpecialPowerModuleData() {}
void OCLSpecialPowerModuleData_Delete(OCLSpecialPowerModuleData *p) { delete p; }

// ??_GElvenWoodSpecialPowerModuleData@@UAEPAXI@Z @0x004C3EA6 28B: slot 0 of vtable 0x00C5CF38; calls ??1 at 0x004C3EC2.
// Owner evidence (audited 2026-09-26): retail registration ElvenWoodSpecialPower -> data factory RVA 0x00251CB4 -> ctor RVA 0x004C3DA9; primary vptr store RVA 0x004C3DBA.
class ElvenWoodSpecialPowerModuleData { public: __declspec(noinline) virtual ~ElvenWoodSpecialPowerModuleData(); };
// ??1ElvenWoodSpecialPowerModuleData@@UAE@XZ present-unmatched
ElvenWoodSpecialPowerModuleData::~ElvenWoodSpecialPowerModuleData() {}
void ElvenWoodSpecialPowerModuleData_Delete(ElvenWoodSpecialPowerModuleData *p) { delete p; }

// ??_GWeaponChangeSpecialPowerModuleData@@UAEPAXI@Z @0x004C42D2 28B: slot 0 of vtable 0x00C5D1F0; calls ??1 at 0x004C42EE.
// Owner evidence (audited 2026-09-26): retail registration WeaponChangeSpecialPowerModule -> data factory RVA 0x00251D40 -> ctor RVA 0x004C4257; primary vptr store RVA 0x004C4277.
class WeaponChangeSpecialPowerModuleData { public: __declspec(noinline) virtual ~WeaponChangeSpecialPowerModuleData(); };
// ??1WeaponChangeSpecialPowerModuleData@@UAE@XZ present-unmatched
WeaponChangeSpecialPowerModuleData::~WeaponChangeSpecialPowerModuleData() {}
void WeaponChangeSpecialPowerModuleData_Delete(WeaponChangeSpecialPowerModuleData *p) { delete p; }

// ??_GCloudBreakSpecialPowerModuleData@@UAEPAXI@Z @0x004C47D7 28B: slot 0 of vtable 0x00C5D468; calls ??1 at 0x004C47F3.
// Owner evidence (audited 2026-09-26): retail registration CloudBreakSpecialPower -> data factory RVA 0x00251E58 -> ctor RVA 0x004C479A; primary vptr store RVA 0x004C47AA.
class CloudBreakSpecialPowerModuleData { public: __declspec(noinline) virtual ~CloudBreakSpecialPowerModuleData(); };
// ??1CloudBreakSpecialPowerModuleData@@UAE@XZ present-unmatched
CloudBreakSpecialPowerModuleData::~CloudBreakSpecialPowerModuleData() {}
void CloudBreakSpecialPowerModuleData_Delete(CloudBreakSpecialPowerModuleData *p) { delete p; }

// ??_GTaintSpecialPowerModuleData@@UAEPAXI@Z @0x004C4AEB 28B: slot 0 of vtable 0x00C5D608; calls ??1 at 0x004C4B07.
// Owner evidence (audited 2026-09-26): retail registration TaintSpecialPower -> data factory RVA 0x00251EE4 -> ctor RVA 0x004C4AB8; primary vptr store RVA 0x004C4ACA.
class TaintSpecialPowerModuleData { public: __declspec(noinline) virtual ~TaintSpecialPowerModuleData(); };
// ??1TaintSpecialPowerModuleData@@UAE@XZ present-unmatched
TaintSpecialPowerModuleData::~TaintSpecialPowerModuleData() {}
void TaintSpecialPowerModuleData_Delete(TaintSpecialPowerModuleData *p) { delete p; }

// ??_GSiegeDeploySpecialPower@@UAEPAXI@Z @0x004C585B 28B: slot 0 of vtable 0x00C5DCFC; calls ??1 at 0x004C57C1.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x004C577C uses class-name string "SiegeDeploySpecialPower".
class SiegeDeploySpecialPower { public: __declspec(noinline) virtual ~SiegeDeploySpecialPower(); };
// ??1SiegeDeploySpecialPower@@UAE@XZ present-unmatched
SiegeDeploySpecialPower::~SiegeDeploySpecialPower() {}
void SiegeDeploySpecialPower_Delete(SiegeDeploySpecialPower *p) { delete p; }

// ??_GPlayerUpgradeSpecialPowerModuleData@@UAEPAXI@Z @0x004C7DB8 28B: slot 0 of vtable 0x00C5E1C0; calls ??1 at 0x004C7DD4.
// Owner evidence (audited 2026-09-26): retail registration PlayerUpgradeSpecialPower -> data factory RVA 0x0025253B -> ctor RVA 0x004C7D68; primary vptr store RVA 0x004C7D8D.
class PlayerUpgradeSpecialPowerModuleData { public: __declspec(noinline) virtual ~PlayerUpgradeSpecialPowerModuleData(); };
// ??1PlayerUpgradeSpecialPowerModuleData@@UAE@XZ present-unmatched
PlayerUpgradeSpecialPowerModuleData::~PlayerUpgradeSpecialPowerModuleData() {}
void PlayerUpgradeSpecialPowerModuleData_Delete(PlayerUpgradeSpecialPowerModuleData *p) { delete p; }

// ??_GDevastateSpecialPowerModuleData@@UAEPAXI@Z @0x004C851B 28B: slot 0 of vtable 0x00C5E518; calls ??1 at 0x004C8537.
// Owner evidence (audited 2026-09-26): retail registration DevastateSpecialPower -> data factory RVA 0x00252653 -> ctor RVA 0x004C84BD; primary vptr store RVA 0x004C84EC.
class DevastateSpecialPowerModuleData { public: __declspec(noinline) virtual ~DevastateSpecialPowerModuleData(); };
// ??1DevastateSpecialPowerModuleData@@UAE@XZ present-unmatched
DevastateSpecialPowerModuleData::~DevastateSpecialPowerModuleData() {}
void DevastateSpecialPowerModuleData_Delete(DevastateSpecialPowerModuleData *p) { delete p; }
