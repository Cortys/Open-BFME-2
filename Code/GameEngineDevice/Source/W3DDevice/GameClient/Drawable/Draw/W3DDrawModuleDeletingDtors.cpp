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

// ??_GW3DScriptedModelDraw@@UAEPAXI@Z @0x000C8617 28B: slot 0 of vtable 0x00BCA090; calls ??1 at 0x000C79C9.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x000C1201 uses class-name string "W3DScriptedModelDraw".
class W3DScriptedModelDraw { public: __declspec(noinline) virtual ~W3DScriptedModelDraw(); };
// ??1W3DScriptedModelDraw@@UAE@XZ present-unmatched
W3DScriptedModelDraw::~W3DScriptedModelDraw() {}
void W3DScriptedModelDraw_Delete(W3DScriptedModelDraw *p) { delete p; }

// ??_GW3DModelDrawModuleData@@UAEPAXI@Z @0x000C8DC3 28B: slot 0 of vtable 0x00BCADE8; calls ??1 at 0x000C8BE0.
// Owner evidence (audited 2026-09-26): retail W3DScriptedModelDraw registration -> shared data factory RVA 0x000648D6 -> ctor RVA 0x000C8EEF; primary vptr store RVA 0x000C8F13; field parser RVA 0x000C9240 agrees with donor W3DModelDraw data.
class W3DModelDrawModuleData { public: __declspec(noinline) virtual ~W3DModelDrawModuleData(); };
// ??1W3DModelDrawModuleData@@UAE@XZ present-unmatched
W3DModelDrawModuleData::~W3DModelDrawModuleData() {}
void W3DModelDrawModuleData_Delete(W3DModelDrawModuleData *p) { delete p; }

// ??_GW3DRopeDraw@@UAEPAXI@Z @0x000CA9D5 28B: slot 0 of vtable 0x00BCBD60; calls ??1 at 0x000CA8BC.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x000CA7F6 uses class-name string "W3DRopeDraw".
class W3DRopeDraw { public: __declspec(noinline) virtual ~W3DRopeDraw(); };
// ??1W3DRopeDraw@@UAE@XZ present-unmatched
W3DRopeDraw::~W3DRopeDraw() {}
void W3DRopeDraw_Delete(W3DRopeDraw *p) { delete p; }

// ??_GW3DTruckDraw@@UAEPAXI@Z @0x000CDF34 28B: slot 0 of vtable 0x00BCC650; calls ??1 at 0x000CDE73.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x000CB578 uses class-name string "W3DTruckDraw".
class W3DTruckDraw { public: __declspec(noinline) virtual ~W3DTruckDraw(); };
// ??1W3DTruckDraw@@UAE@XZ present-unmatched
W3DTruckDraw::~W3DTruckDraw() {}
void W3DTruckDraw_Delete(W3DTruckDraw *p) { delete p; }

// ??_GW3DTankDraw@@UAEPAXI@Z @0x000CEB2C 28B: slot 0 of vtable 0x00BCCBE8; calls ??1 at 0x000CE960.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x000CE9EE uses class-name string "W3DTankDraw".
class W3DTankDraw { public: __declspec(noinline) virtual ~W3DTankDraw(); };
// ??1W3DTankDraw@@UAE@XZ present-unmatched
W3DTankDraw::~W3DTankDraw() {}
void W3DTankDraw_Delete(W3DTankDraw *p) { delete p; }

// ??_GW3DFloorDraw@@UAEPAXI@Z @0x000CF492 28B: slot 0 of vtable 0x00BCD4E0; calls ??1 at 0x000CF1A6.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x000CF161 uses class-name string "W3DFloorDraw".
class W3DFloorDraw { public: __declspec(noinline) virtual ~W3DFloorDraw(); };
// ??1W3DFloorDraw@@UAE@XZ present-unmatched
W3DFloorDraw::~W3DFloorDraw() {}
void W3DFloorDraw_Delete(W3DFloorDraw *p) { delete p; }

// ??_GW3DLightDraw@@UAEPAXI@Z @0x000CFBF0 28B: slot 0 of vtable 0x00BCD728; calls ??1 at 0x000CFA42.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x000CFAF9 uses class-name string "W3DLightDraw".
class W3DLightDraw { public: __declspec(noinline) virtual ~W3DLightDraw(); };
// ??1W3DLightDraw@@UAE@XZ present-unmatched
W3DLightDraw::~W3DLightDraw() {}
void W3DLightDraw_Delete(W3DLightDraw *p) { delete p; }

// ??_GW3DSailModelDraw@@UAEPAXI@Z @0x000D08A2 28B: slot 0 of vtable 0x00BCDC60; calls ??1 at 0x000D08BE.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x000D07CB uses class-name string "W3DSailModelDraw".
class W3DSailModelDraw { public: __declspec(noinline) virtual ~W3DSailModelDraw(); };
// ??1W3DSailModelDraw@@UAE@XZ present-unmatched
W3DSailModelDraw::~W3DSailModelDraw() {}
void W3DSailModelDraw_Delete(W3DSailModelDraw *p) { delete p; }

// ??_GW3DBoatWakeModelDraw@@UAEPAXI@Z @0x000D0D08 28B: slot 0 of vtable 0x00BCDD70; calls ??1 at 0x000D0B69.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x000D0C93 uses class-name string "W3DBoatWakeModelDraw".
class W3DBoatWakeModelDraw { public: __declspec(noinline) virtual ~W3DBoatWakeModelDraw(); };
// ??1W3DBoatWakeModelDraw@@UAE@XZ present-unmatched
W3DBoatWakeModelDraw::~W3DBoatWakeModelDraw() {}
void W3DBoatWakeModelDraw_Delete(W3DBoatWakeModelDraw *p) { delete p; }

// ??_GW3DProjectileStreamDraw@@UAEPAXI@Z @0x000D144F 28B: slot 0 of vtable 0x00BCE010; calls ??1 at 0x000D146B.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x000D140A uses class-name string "W3DProjectileStreamDraw".
class W3DProjectileStreamDraw { public: __declspec(noinline) virtual ~W3DProjectileStreamDraw(); };
// ??1W3DProjectileStreamDraw@@UAE@XZ present-unmatched
W3DProjectileStreamDraw::~W3DProjectileStreamDraw() {}
void W3DProjectileStreamDraw_Delete(W3DProjectileStreamDraw *p) { delete p; }

// ??_GW3DTornadoDrawModuleData@@UAEPAXI@Z @0x000D16F7 28B: slot 0 of vtable 0x00BCE198; calls ??1 at 0x000D1713.
// Owner evidence (audited 2026-09-26): retail registration W3DTornadoDraw -> data factory RVA 0x00065171 -> ctor RVA 0x000D16B4; primary vptr store RVA 0x000D16CC.
class W3DTornadoDrawModuleData { public: __declspec(noinline) virtual ~W3DTornadoDrawModuleData(); };
// ??1W3DTornadoDrawModuleData@@UAE@XZ present-unmatched
W3DTornadoDrawModuleData::~W3DTornadoDrawModuleData() {}
void W3DTornadoDrawModuleData_Delete(W3DTornadoDrawModuleData *p) { delete p; }

// ??_GW3DTornadoDraw@@UAEPAXI@Z @0x000D19DD 28B: slot 0 of vtable 0x00BCE218; calls ??1 at 0x000D18AB.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x000D1866 uses class-name string "W3DTornadoDraw".
class W3DTornadoDraw { public: __declspec(noinline) virtual ~W3DTornadoDraw(); };
// ??1W3DTornadoDraw@@UAE@XZ present-unmatched
W3DTornadoDraw::~W3DTornadoDraw() {}
void W3DTornadoDraw_Delete(W3DTornadoDraw *p) { delete p; }
