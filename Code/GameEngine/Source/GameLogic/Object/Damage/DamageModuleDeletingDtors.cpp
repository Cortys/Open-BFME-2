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

// ??_GDamageModuleBase@@UAEPAXI@Z @0x0044EF42 28B: slot 0 of vtable 0x00C3F2A8; calls ??1 at 0x0044ECCE.
// Owner evidence: dtor already named ??1DamageModuleBase@@UAE@XZ.
class DamageModuleBase { public: __declspec(noinline) virtual ~DamageModuleBase(); };
// ??1DamageModuleBase@@UAE@XZ present-unmatched
DamageModuleBase::~DamageModuleBase() {}
void DamageModuleBase_Delete(DamageModuleBase *p) { delete p; }

// ??_GCallHelpOnDamage@@UAEPAXI@Z @0x004BB4B5 28B: slot 0 of vtable 0x00C59FDC; calls ??1 at 0x004BB4D1.
// Owner evidence: installed by ??0CallHelpOnDamage@@QAE@PAVThing@@PBVModuleData@@@Z; class-unique slots 4 ?rva0004BB470@CallHelpOnDamage@@SA?AW4NameKeyType@@XZ.
class CallHelpOnDamage { public: __declspec(noinline) virtual ~CallHelpOnDamage(); };
// ??1CallHelpOnDamage@@UAE@XZ present-unmatched
CallHelpOnDamage::~CallHelpOnDamage() {}
void CallHelpOnDamage_Delete(CallHelpOnDamage *p) { delete p; }
