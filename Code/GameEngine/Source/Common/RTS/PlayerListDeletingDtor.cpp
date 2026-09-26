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

// ??_GPlayerList@@UAEPAXI@Z @0x002A7ED5 28B: slot 0 of vtable 0x00BFD618; calls ??1 at 0x002A79A9.
// Owner evidence (audited 2026-09-26): donor reset at RVA 0x002A7AA0 in slot 9, corroborated by ctor RVA 0x002A7F80 and dtor RVA 0x002A79A9 managing 20 Player pointers at +0x18; donor class attribution.
class PlayerList { public: __declspec(noinline) virtual ~PlayerList(); };
// ??1PlayerList@@UAE@XZ present-unmatched
PlayerList::~PlayerList() {}
void PlayerList_Delete(PlayerList *p) { delete p; }
