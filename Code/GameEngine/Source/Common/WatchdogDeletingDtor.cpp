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

// ??_GWatchdog@@UAEPAXI@Z @0x002257CD 28B: slot 0 of vtable 0x00BE6FD8; calls ??1 at 0x0022576A.
// Owner evidence (audited 2026-09-26): ctor RVA 0x00225616 stores primary vptr at RVA 0x00225633; slot 3 RVA 0x002255AD formats retail Watchdog diagnostic at VA 0x00BE6F70; thread start/run slots agree with donor.
class Watchdog { public: __declspec(noinline) virtual ~Watchdog(); };
// ??1Watchdog@@UAE@XZ present-unmatched
Watchdog::~Watchdog() {}
void Watchdog_Delete(Watchdog *p) { delete p; }
