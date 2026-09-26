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

// ??_GXferSave@@UAEPAXI@Z @0x0060D24D 28B: slot 0 of vtable 0x00C7B010; calls ??1 at 0x0060D0B3.
// Owner evidence (audited 2026-09-26): BFME1 reconstructed donor slots 6/38 at RVAs 0x0060CA26/0x0060C935 implement save-side block finalization and stream writes; ctor/dtor RVAs 0x0060D1F7/0x0060D0B3 share this primary vptr; class spelling remains donor-derived.
class XferSave { public: __declspec(noinline) virtual ~XferSave(); };
// ??1XferSave@@UAE@XZ present-unmatched
XferSave::~XferSave() {}
void XferSave_Delete(XferSave *p) { delete p; }
