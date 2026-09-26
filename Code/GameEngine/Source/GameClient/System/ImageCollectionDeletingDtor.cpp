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

// ??_GImageCollection@@UAEPAXI@Z @0x002D9362 28B: slot 0 of vtable 0x00C03878; calls ??1 at 0x002D9283.
// Owner evidence (audited 2026-09-26): ctor RVA 0x002D932B stores primary vptr at RVA 0x002D9348; caller RVA 0x0023A1BB stores result at VA 0x00DFF078; donor findImageByName/addImage bodies corroborate image-map ownership.
class ImageCollection { public: __declspec(noinline) virtual ~ImageCollection(); };
// ??1ImageCollection@@UAE@XZ present-unmatched
ImageCollection::~ImageCollection() {}
void ImageCollection_Delete(ImageCollection *p) { delete p; }
