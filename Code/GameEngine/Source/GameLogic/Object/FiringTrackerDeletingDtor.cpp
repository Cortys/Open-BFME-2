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

// ??_GFiringTracker@@UAEPAXI@Z @0x004DEBA5 28B: slot 0 of vtable 0x00C61530; calls ??1 at 0x004DEA0C.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x004DEACB uses class-name string "FiringTracker".
class FiringTracker { public: __declspec(noinline) virtual ~FiringTracker(); };
// ??1FiringTracker@@UAE@XZ present-unmatched
FiringTracker::~FiringTracker() {}
void FiringTracker_Delete(FiringTracker *p) { delete p; }
