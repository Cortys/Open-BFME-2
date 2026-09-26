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

// ??_GCreateCrateDieModuleData@@UAEPAXI@Z @0x00257339 28B: slot 0 of vtable 0x00BF40A8; calls ??1 at 0x00257355.
// Owner evidence (audited 2026-09-26): retail registration CreateCrateDie -> data factory RVA 0x0025739D -> ctor RVA 0x002572EE; primary vptr store RVA 0x00257313.
class CreateCrateDieModuleData { public: __declspec(noinline) virtual ~CreateCrateDieModuleData(); };
// ??1CreateCrateDieModuleData@@UAE@XZ present-unmatched
CreateCrateDieModuleData::~CreateCrateDieModuleData() {}
void CreateCrateDieModuleData_Delete(CreateCrateDieModuleData *p) { delete p; }

// ??_GDamageFilteredCreateObjectDie@@UAEPAXI@Z @0x00485FC7 28B: slot 0 of vtable 0x00C4AB54; calls ??1 at 0x00485EC3.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x00485EFD uses class-name string "DamageFilteredCreateObjectDie".
class DamageFilteredCreateObjectDie { public: __declspec(noinline) virtual ~DamageFilteredCreateObjectDie(); };
// ??1DamageFilteredCreateObjectDie@@UAE@XZ present-unmatched
DamageFilteredCreateObjectDie::~DamageFilteredCreateObjectDie() {}
void DamageFilteredCreateObjectDie_Delete(DamageFilteredCreateObjectDie *p) { delete p; }

// ??_GRebuildHoleExposeDie@@UAEPAXI@Z @0x004867DD 28B: slot 0 of vtable 0x00C4AE54; calls ??1 at 0x004867F9.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x00486792 uses class-name string "RebuildHoleExposeDie".
class RebuildHoleExposeDie { public: __declspec(noinline) virtual ~RebuildHoleExposeDie(); };
// ??1RebuildHoleExposeDie@@UAE@XZ present-unmatched
RebuildHoleExposeDie::~RebuildHoleExposeDie() {}
void RebuildHoleExposeDie_Delete(RebuildHoleExposeDie *p) { delete p; }
