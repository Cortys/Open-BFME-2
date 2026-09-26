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

// ??_GSmudgeManager@@UAEPAXI@Z @0x002D2A83 28B: slot 0 of vtable 0x00C02A60; calls ??1 at 0x002D29F7.
// Owner evidence (audited 2026-09-26): ctor RVA 0x002D25BA stores primary vptr at RVA 0x002D25BE and distinct list vptrs at +0x08/+0x14; reset RVA 0x002D27CC and dtor RVA 0x002D29F7 agree with donor used/free-list ownership.
class SmudgeManager { public: __declspec(noinline) virtual ~SmudgeManager(); };
// ??1SmudgeManager@@UAE@XZ present-unmatched
SmudgeManager::~SmudgeManager() {}
void SmudgeManager_Delete(SmudgeManager *p) { delete p; }
