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

// ??_GAttributeModifierAuraUpdate@@UAEPAXI@Z @0x0049B884 28B: slot 0 of vtable 0x00C50D2C; calls ??1 at 0x0049B6DD.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x0049B5DC uses class-name string "AttributeModifierAuraUpdate".
class AttributeModifierAuraUpdate { public: __declspec(noinline) virtual ~AttributeModifierAuraUpdate(); };
// ??1AttributeModifierAuraUpdate@@UAE@XZ present-unmatched
AttributeModifierAuraUpdate::~AttributeModifierAuraUpdate() {}
void AttributeModifierAuraUpdate_Delete(AttributeModifierAuraUpdate *p) { delete p; }

// ??_GProductionUpdate@@UAEPAXI@Z @0x0049E34C 28B: slot 0 of vtable 0x00C515BC; calls ??1 at 0x0049E1BF.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x0049E15E uses class-name string "ProductionUpdate".
class ProductionUpdate { public: __declspec(noinline) virtual ~ProductionUpdate(); };
// ??1ProductionUpdate@@UAE@XZ present-unmatched
ProductionUpdate::~ProductionUpdate() {}
void ProductionUpdate_Delete(ProductionUpdate *p) { delete p; }

// ??_GEmotionTrackerUpdate@@UAEPAXI@Z @0x004B15CA 28B: slot 0 of vtable 0x00C5667C; calls ??1 at 0x004B1322.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x004B1393 uses class-name string "EmotionTrackerUpdate".
class EmotionTrackerUpdate { public: __declspec(noinline) virtual ~EmotionTrackerUpdate(); };
// ??1EmotionTrackerUpdate@@UAE@XZ present-unmatched
EmotionTrackerUpdate::~EmotionTrackerUpdate() {}
void EmotionTrackerUpdate_Delete(EmotionTrackerUpdate *p) { delete p; }

// ??_GDockUpdate@@UAEPAXI@Z @0x0058A177 28B: slot 0 of vtable 0x00C70378; calls ??1 at 0x0058A0F4.
// Owner evidence (audited 2026-09-26): donor ctor RVA 0x0058A290 stores this primary vptr at RVA 0x0058A2C5 and a separate interface vptr at +0x20; slot-3 xfer RVA 0x0058A410 corroborates the dock fields and member order.
class DockUpdate { public: __declspec(noinline) virtual ~DockUpdate(); };
// ??1DockUpdate@@UAE@XZ present-unmatched
DockUpdate::~DockUpdate() {}
void DockUpdate_Delete(DockUpdate *p) { delete p; }
