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

// ??_GCreateCrateDieModuleData@@UAEPAXI@Z @0x00257339 28B: slot 0 of vtable 0x00BF40A8; calls ??1 at 0x00257355.
// Owner evidence: sole named installer ??0CreateCrateDieModuleData@@QAE@XZ.
class CreateCrateDieModuleData { public: __declspec(noinline) virtual ~CreateCrateDieModuleData(); };
// ??1CreateCrateDieModuleData@@UAE@XZ present-unmatched
CreateCrateDieModuleData::~CreateCrateDieModuleData() {}
void CreateCrateDieModuleData_Delete(CreateCrateDieModuleData *p) { delete p; }

// ??_GDamageFilteredCreateObjectDie@@UAEPAXI@Z @0x00485FC7 28B: slot 0 of vtable 0x00C4AB54; calls ??1 at 0x00485EC3.
// Owner evidence: installed by ??0DamageFilteredCreateObjectDie@@QAE@PAVThing@@PBVModuleData@@@Z; class-unique slots 4 ?rva000485EFD@DamageFilteredCreateObjectDie@@SA?AW4NameKeyType@@XZ.
class DamageFilteredCreateObjectDie { public: __declspec(noinline) virtual ~DamageFilteredCreateObjectDie(); };
// ??1DamageFilteredCreateObjectDie@@UAE@XZ present-unmatched
DamageFilteredCreateObjectDie::~DamageFilteredCreateObjectDie() {}
void DamageFilteredCreateObjectDie_Delete(DamageFilteredCreateObjectDie *p) { delete p; }

// ??_GRebuildHoleExposeDie@@UAEPAXI@Z @0x004867DD 28B: slot 0 of vtable 0x00C4AE54; calls ??1 at 0x004867F9.
// Owner evidence: installed by ??0RebuildHoleExposeDie@@QAE@PAVThing@@PBVModuleData@@@Z; class-unique slots 4 ?rva000486792@RebuildHoleExposeDie@@SA?AW4NameKeyType@@XZ.
class RebuildHoleExposeDie { public: __declspec(noinline) virtual ~RebuildHoleExposeDie(); };
// ??1RebuildHoleExposeDie@@UAE@XZ present-unmatched
RebuildHoleExposeDie::~RebuildHoleExposeDie() {}
void RebuildHoleExposeDie_Delete(RebuildHoleExposeDie *p) { delete p; }
