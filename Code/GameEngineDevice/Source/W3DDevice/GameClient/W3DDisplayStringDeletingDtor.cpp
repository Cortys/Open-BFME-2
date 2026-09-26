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

// ??_GW3DDisplayString@@UAEPAXI@Z @0x0010625B 28B: slot 0 of vtable 0x00BCF900; calls ??1 at 0x00106162.
// Owner evidence (audited 2026-09-26): donor slots 9/16 at RVAs 0x00105FC6/0x0010657E, corroborated by ctor RVA 0x00106088 and dtor RVA 0x00106162 constructing/destructing two render-sentence members at +0x14/+0xD8; donor class attribution.
class W3DDisplayString { public: __declspec(noinline) virtual ~W3DDisplayString(); };
// ??1W3DDisplayString@@UAE@XZ present-unmatched
W3DDisplayString::~W3DDisplayString() {}
void W3DDisplayString_Delete(W3DDisplayString *p) { delete p; }
