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

// ??_GActiveBody@@UAEPAXI@Z @0x004BF9D1 28B: slot 0 of vtable 0x00C5B038; calls ??1 at 0x004BF951.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x004BF848 uses class-name string "ActiveBody".
class ActiveBody { public: __declspec(noinline) virtual ~ActiveBody(); };
// ??1ActiveBody@@UAE@XZ present-unmatched
ActiveBody::~ActiveBody() {}
void ActiveBody_Delete(ActiveBody *p) { delete p; }
