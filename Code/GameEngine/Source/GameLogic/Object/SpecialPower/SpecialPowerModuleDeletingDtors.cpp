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

// ??_GActivateModuleSpecialPowerModuleData@@UAEPAXI@Z @0x0025712E 28B: slot 0 of vtable 0x00BF3F60; calls ??1 at 0x0025714A.
// Owner evidence: sole named installer ??0ActivateModuleSpecialPowerModuleData@@QAE@XZ.
class ActivateModuleSpecialPowerModuleData { public: __declspec(noinline) virtual ~ActivateModuleSpecialPowerModuleData(); };
// ??1ActivateModuleSpecialPowerModuleData@@UAE@XZ present-unmatched
ActivateModuleSpecialPowerModuleData::~ActivateModuleSpecialPowerModuleData() {}
void ActivateModuleSpecialPowerModuleData_Delete(ActivateModuleSpecialPowerModuleData *p) { delete p; }

// ??_GWeaponFireSpecialAbilityUpdateModuleData@@UAEPAXI@Z @0x004927EA 28B: slot 0 of vtable 0x00C4E108; calls ??1 at 0x00492806.
// Owner evidence: sole named installer ??0WeaponFireSpecialAbilityUpdateModuleData@@QAE@XZ.
class WeaponFireSpecialAbilityUpdateModuleData { public: __declspec(noinline) virtual ~WeaponFireSpecialAbilityUpdateModuleData(); };
// ??1WeaponFireSpecialAbilityUpdateModuleData@@UAE@XZ present-unmatched
WeaponFireSpecialAbilityUpdateModuleData::~WeaponFireSpecialAbilityUpdateModuleData() {}
void WeaponFireSpecialAbilityUpdateModuleData_Delete(WeaponFireSpecialAbilityUpdateModuleData *p) { delete p; }

// ??_GSpecialPowerModule@@UAEPAXI@Z @0x004941D7 28B: slot 0 of vtable 0x00C4E868; calls ??1 at 0x00493DEF.
// Owner evidence: class-unique slots 4 ?rva000493DAA@SpecialPowerModule@@SA?AW4NameKeyType@@XZ.
class SpecialPowerModule { public: __declspec(noinline) virtual ~SpecialPowerModule(); };
// ??1SpecialPowerModule@@UAE@XZ present-unmatched
SpecialPowerModule::~SpecialPowerModule() {}
void SpecialPowerModule_Delete(SpecialPowerModule *p) { delete p; }

// ??_GAISpecialPowerUpdateModuleData@@UAEPAXI@Z @0x004B2FF3 28B: slot 0 of vtable 0x00C56F48; calls ??1 at 0x004B300F.
// Owner evidence: sole named installer ??0AISpecialPowerUpdateModuleData@@QAE@XZ.
class AISpecialPowerUpdateModuleData { public: __declspec(noinline) virtual ~AISpecialPowerUpdateModuleData(); };
// ??1AISpecialPowerUpdateModuleData@@UAE@XZ present-unmatched
AISpecialPowerUpdateModuleData::~AISpecialPowerUpdateModuleData() {}
void AISpecialPowerUpdateModuleData_Delete(AISpecialPowerUpdateModuleData *p) { delete p; }

// ??_GInvisibilitySpecialPowerModuleData@@UAEPAXI@Z @0x004C24C3 28B: slot 0 of vtable 0x00C5C558; calls ??1 at 0x004C24DF.
// Owner evidence: sole named installer ??0InvisibilitySpecialPowerModuleData@@QAE@XZ.
class InvisibilitySpecialPowerModuleData { public: __declspec(noinline) virtual ~InvisibilitySpecialPowerModuleData(); };
// ??1InvisibilitySpecialPowerModuleData@@UAE@XZ present-unmatched
InvisibilitySpecialPowerModuleData::~InvisibilitySpecialPowerModuleData() {}
void InvisibilitySpecialPowerModuleData_Delete(InvisibilitySpecialPowerModuleData *p) { delete p; }

// ??_GCashHackSpecialPowerModuleData@@UAEPAXI@Z @0x004C28C1 28B: slot 0 of vtable 0x00C5C688; calls ??1 at 0x004C28DD.
// Owner evidence: sole named installer ??0CashHackSpecialPowerModuleData@@QAE@XZ.
class CashHackSpecialPowerModuleData { public: __declspec(noinline) virtual ~CashHackSpecialPowerModuleData(); };
// ??1CashHackSpecialPowerModuleData@@UAE@XZ present-unmatched
CashHackSpecialPowerModuleData::~CashHackSpecialPowerModuleData() {}
void CashHackSpecialPowerModuleData_Delete(CashHackSpecialPowerModuleData *p) { delete p; }

// ??_GLevelGrantSpecialPower@@UAEPAXI@Z @0x004C2C5A 28B: slot 0 of vtable 0x00C5C920; calls ??1 at 0x004C2C76.
// Owner evidence: installed by ??0LevelGrantSpecialPower@@QAE@PAVThing@@PBVModuleData@@@Z; class-unique slots 4 ?rva0004C2BC1@LevelGrantSpecialPower@@SA?AW4NameKeyType@@XZ.
class LevelGrantSpecialPower { public: __declspec(noinline) virtual ~LevelGrantSpecialPower(); };
// ??1LevelGrantSpecialPower@@UAE@XZ present-unmatched
LevelGrantSpecialPower::~LevelGrantSpecialPower() {}
void LevelGrantSpecialPower_Delete(LevelGrantSpecialPower *p) { delete p; }

// ??_GProductionSpeedBonusModuleData@@UAEPAXI@Z @0x004C3048 28B: slot 0 of vtable 0x00C5CA80; calls ??1 at 0x004C3064.
// Owner evidence: sole named installer ??0ProductionSpeedBonusModuleData@@QAE@XZ.
class ProductionSpeedBonusModuleData { public: __declspec(noinline) virtual ~ProductionSpeedBonusModuleData(); };
// ??1ProductionSpeedBonusModuleData@@UAE@XZ present-unmatched
ProductionSpeedBonusModuleData::~ProductionSpeedBonusModuleData() {}
void ProductionSpeedBonusModuleData_Delete(ProductionSpeedBonusModuleData *p) { delete p; }

// ??_GOCLSpecialPowerModuleData@@UAEPAXI@Z @0x004C37A4 28B: slot 0 of vtable 0x00C5CCB0; calls ??1 at 0x004C37C0.
// Owner evidence: sole named installer ??0OCLSpecialPowerModuleData@@QAE@XZ.
class OCLSpecialPowerModuleData { public: __declspec(noinline) virtual ~OCLSpecialPowerModuleData(); };
// ??1OCLSpecialPowerModuleData@@UAE@XZ present-unmatched
OCLSpecialPowerModuleData::~OCLSpecialPowerModuleData() {}
void OCLSpecialPowerModuleData_Delete(OCLSpecialPowerModuleData *p) { delete p; }

// ??_GElvenWoodSpecialPowerModuleData@@UAEPAXI@Z @0x004C3EA6 28B: slot 0 of vtable 0x00C5CF38; calls ??1 at 0x004C3EC2.
// Owner evidence: sole named installer ??0ElvenWoodSpecialPowerModuleData@@QAE@XZ.
class ElvenWoodSpecialPowerModuleData { public: __declspec(noinline) virtual ~ElvenWoodSpecialPowerModuleData(); };
// ??1ElvenWoodSpecialPowerModuleData@@UAE@XZ present-unmatched
ElvenWoodSpecialPowerModuleData::~ElvenWoodSpecialPowerModuleData() {}
void ElvenWoodSpecialPowerModuleData_Delete(ElvenWoodSpecialPowerModuleData *p) { delete p; }

// ??_GWeaponChangeSpecialPowerModuleData@@UAEPAXI@Z @0x004C42D2 28B: slot 0 of vtable 0x00C5D1F0; calls ??1 at 0x004C42EE.
// Owner evidence: sole named installer ??0WeaponChangeSpecialPowerModuleData@@QAE@XZ.
class WeaponChangeSpecialPowerModuleData { public: __declspec(noinline) virtual ~WeaponChangeSpecialPowerModuleData(); };
// ??1WeaponChangeSpecialPowerModuleData@@UAE@XZ present-unmatched
WeaponChangeSpecialPowerModuleData::~WeaponChangeSpecialPowerModuleData() {}
void WeaponChangeSpecialPowerModuleData_Delete(WeaponChangeSpecialPowerModuleData *p) { delete p; }

// ??_GCloudBreakSpecialPowerModuleData@@UAEPAXI@Z @0x004C47D7 28B: slot 0 of vtable 0x00C5D468; calls ??1 at 0x004C47F3.
// Owner evidence: sole named installer ??0CloudBreakSpecialPowerModuleData@@QAE@XZ.
class CloudBreakSpecialPowerModuleData { public: __declspec(noinline) virtual ~CloudBreakSpecialPowerModuleData(); };
// ??1CloudBreakSpecialPowerModuleData@@UAE@XZ present-unmatched
CloudBreakSpecialPowerModuleData::~CloudBreakSpecialPowerModuleData() {}
void CloudBreakSpecialPowerModuleData_Delete(CloudBreakSpecialPowerModuleData *p) { delete p; }

// ??_GTaintSpecialPowerModuleData@@UAEPAXI@Z @0x004C4AEB 28B: slot 0 of vtable 0x00C5D608; calls ??1 at 0x004C4B07.
// Owner evidence: sole named installer ??0TaintSpecialPowerModuleData@@QAE@XZ.
class TaintSpecialPowerModuleData { public: __declspec(noinline) virtual ~TaintSpecialPowerModuleData(); };
// ??1TaintSpecialPowerModuleData@@UAE@XZ present-unmatched
TaintSpecialPowerModuleData::~TaintSpecialPowerModuleData() {}
void TaintSpecialPowerModuleData_Delete(TaintSpecialPowerModuleData *p) { delete p; }

// ??_GSiegeDeploySpecialPower@@UAEPAXI@Z @0x004C585B 28B: slot 0 of vtable 0x00C5DCFC; calls ??1 at 0x004C57C1.
// Owner evidence: installed by ??0SiegeDeploySpecialPower@@QAE@PAVThing@@PBVModuleData@@@Z; class-unique slots 3 ?xfer@SiegeDeploySpecialPower@@MAEXPAVXfer@@@Z and 4 ?rva0004C577C@SiegeDeploySpecialPower@@SA?AW4NameKeyType@@XZ.
class SiegeDeploySpecialPower { public: __declspec(noinline) virtual ~SiegeDeploySpecialPower(); };
// ??1SiegeDeploySpecialPower@@UAE@XZ present-unmatched
SiegeDeploySpecialPower::~SiegeDeploySpecialPower() {}
void SiegeDeploySpecialPower_Delete(SiegeDeploySpecialPower *p) { delete p; }

// ??_GPlayerUpgradeSpecialPowerModuleData@@UAEPAXI@Z @0x004C7DB8 28B: slot 0 of vtable 0x00C5E1C0; calls ??1 at 0x004C7DD4.
// Owner evidence: sole named installer ??0PlayerUpgradeSpecialPowerModuleData@@QAE@XZ.
class PlayerUpgradeSpecialPowerModuleData { public: __declspec(noinline) virtual ~PlayerUpgradeSpecialPowerModuleData(); };
// ??1PlayerUpgradeSpecialPowerModuleData@@UAE@XZ present-unmatched
PlayerUpgradeSpecialPowerModuleData::~PlayerUpgradeSpecialPowerModuleData() {}
void PlayerUpgradeSpecialPowerModuleData_Delete(PlayerUpgradeSpecialPowerModuleData *p) { delete p; }

// ??_GDevastateSpecialPowerModuleData@@UAEPAXI@Z @0x004C851B 28B: slot 0 of vtable 0x00C5E518; calls ??1 at 0x004C8537.
// Owner evidence: sole named installer ??0DevastateSpecialPowerModuleData@@QAE@XZ.
class DevastateSpecialPowerModuleData { public: __declspec(noinline) virtual ~DevastateSpecialPowerModuleData(); };
// ??1DevastateSpecialPowerModuleData@@UAE@XZ present-unmatched
DevastateSpecialPowerModuleData::~DevastateSpecialPowerModuleData() {}
void DevastateSpecialPowerModuleData_Delete(DevastateSpecialPowerModuleData *p) { delete p; }
