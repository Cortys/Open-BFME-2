// cl: /O1 /MD
//
// Scalar deleting destructors (28B flag-test ??_G shape) whose owning class
// the image names:
// push esi / mov esi,ecx / call <dtor> / test [esp+8],1 / je / push esi /
// call ??3 (0x2FD60) / pop ecx / mov eax,esi / pop esi / ret 4.
//
// Target facts, per class below: the ??_G bytes; the destructor it calls; the
// vtable holding the ??_G in slot 0; and the evidence tying that vtable to the
// class -- the class's own constructor installs it, and/or other slots of it
// that no other vtable shares already carry the class's name in the ledger.
// Carried from those ledger rows: the class names themselves.
// Not established: each class's layout, bases and destructor body. Every class
// is declared with only the virtual destructor the ??_G needs;
// __declspec(noinline) keeps it out of line so the ??_G calls it through the
// pin, and the empty body is a placeholder, not a claim.

// ??_GW3DScriptedModelDraw@@UAEPAXI@Z @0x000C8617 28B: slot 0 of vtable 0x00BCA090; calls ??1 at 0x000C79C9.
// Owner evidence: class-unique slots 4 ?rva0000C1201@W3DScriptedModelDraw@@SA?AW4NameKeyType@@XZ.
class W3DScriptedModelDraw { public: __declspec(noinline) virtual ~W3DScriptedModelDraw(); };
// ??1W3DScriptedModelDraw@@UAE@XZ present-unmatched
W3DScriptedModelDraw::~W3DScriptedModelDraw() {}
void W3DScriptedModelDraw_Delete(W3DScriptedModelDraw *p) { delete p; }

// ??_GW3DModelDrawModuleData@@UAEPAXI@Z @0x000C8DC3 28B: slot 0 of vtable 0x00BCADE8; calls ??1 at 0x000C8BE0.
// Owner evidence: dtor already named ??1W3DModelDrawModuleData@@UAE@XZ.
class W3DModelDrawModuleData { public: __declspec(noinline) virtual ~W3DModelDrawModuleData(); };
// ??1W3DModelDrawModuleData@@UAE@XZ present-unmatched
W3DModelDrawModuleData::~W3DModelDrawModuleData() {}
void W3DModelDrawModuleData_Delete(W3DModelDrawModuleData *p) { delete p; }

// ??_GW3DRopeDraw@@UAEPAXI@Z @0x000CA9D5 28B: slot 0 of vtable 0x00BCBD60; calls ??1 at 0x000CA8BC.
// Owner evidence: class-unique slots 4 ?rva000CA7F6@W3DRopeDraw@@SA?AW4NameKeyType@@XZ.
class W3DRopeDraw { public: __declspec(noinline) virtual ~W3DRopeDraw(); };
// ??1W3DRopeDraw@@UAE@XZ present-unmatched
W3DRopeDraw::~W3DRopeDraw() {}
void W3DRopeDraw_Delete(W3DRopeDraw *p) { delete p; }

// ??_GW3DTruckDraw@@UAEPAXI@Z @0x000CDF34 28B: slot 0 of vtable 0x00BCC650; calls ??1 at 0x000CDE73.
// Owner evidence: class-unique slots 4 ?rva0000CB578@W3DTruckDraw@@SA?AW4NameKeyType@@XZ.
class W3DTruckDraw { public: __declspec(noinline) virtual ~W3DTruckDraw(); };
// ??1W3DTruckDraw@@UAE@XZ present-unmatched
W3DTruckDraw::~W3DTruckDraw() {}
void W3DTruckDraw_Delete(W3DTruckDraw *p) { delete p; }

// ??_GW3DTankDraw@@UAEPAXI@Z @0x000CEB2C 28B: slot 0 of vtable 0x00BCCBE8; calls ??1 at 0x000CE960.
// Owner evidence: class-unique slots 4 ?rva000CE9EE@W3DTankDraw@@SA?AW4NameKeyType@@XZ.
class W3DTankDraw { public: __declspec(noinline) virtual ~W3DTankDraw(); };
// ??1W3DTankDraw@@UAE@XZ present-unmatched
W3DTankDraw::~W3DTankDraw() {}
void W3DTankDraw_Delete(W3DTankDraw *p) { delete p; }

// ??_GW3DFloorDraw@@UAEPAXI@Z @0x000CF492 28B: slot 0 of vtable 0x00BCD4E0; calls ??1 at 0x000CF1A6.
// Owner evidence: installed by ??0W3DFloorDraw@@QAE@PAVThing@@PBVModuleData@@@Z; class-unique slots 4 ?rva000CF161@W3DFloorDraw@@SA?AW4NameKeyType@@XZ.
class W3DFloorDraw { public: __declspec(noinline) virtual ~W3DFloorDraw(); };
// ??1W3DFloorDraw@@UAE@XZ present-unmatched
W3DFloorDraw::~W3DFloorDraw() {}
void W3DFloorDraw_Delete(W3DFloorDraw *p) { delete p; }

// ??_GW3DLightDraw@@UAEPAXI@Z @0x000CFBF0 28B: slot 0 of vtable 0x00BCD728; calls ??1 at 0x000CFA42.
// Owner evidence: class-unique slots 4 ?rva0000CFAF9@W3DLightDraw@@SA?AW4NameKeyType@@XZ.
class W3DLightDraw { public: __declspec(noinline) virtual ~W3DLightDraw(); };
// ??1W3DLightDraw@@UAE@XZ present-unmatched
W3DLightDraw::~W3DLightDraw() {}
void W3DLightDraw_Delete(W3DLightDraw *p) { delete p; }

// ??_GW3DSailModelDraw@@UAEPAXI@Z @0x000D08A2 28B: slot 0 of vtable 0x00BCDC60; calls ??1 at 0x000D08BE.
// Owner evidence: installed by ??0W3DSailModelDraw@@QAE@PAVThing@@PBVModuleData@@@Z; class-unique slots 4 ?rva0000D07CB@W3DSailModelDraw@@SA?AW4NameKeyType@@XZ.
class W3DSailModelDraw { public: __declspec(noinline) virtual ~W3DSailModelDraw(); };
// ??1W3DSailModelDraw@@UAE@XZ present-unmatched
W3DSailModelDraw::~W3DSailModelDraw() {}
void W3DSailModelDraw_Delete(W3DSailModelDraw *p) { delete p; }

// ??_GW3DBoatWakeModelDraw@@UAEPAXI@Z @0x000D0D08 28B: slot 0 of vtable 0x00BCDD70; calls ??1 at 0x000D0B69.
// Owner evidence: installed by ??0W3DBoatWakeModelDraw@@QAE@PAVThing@@PBVModuleData@@@Z; class-unique slots 4 ?rva0000D0C93@W3DBoatWakeModelDraw@@SA?AW4NameKeyType@@XZ.
class W3DBoatWakeModelDraw { public: __declspec(noinline) virtual ~W3DBoatWakeModelDraw(); };
// ??1W3DBoatWakeModelDraw@@UAE@XZ present-unmatched
W3DBoatWakeModelDraw::~W3DBoatWakeModelDraw() {}
void W3DBoatWakeModelDraw_Delete(W3DBoatWakeModelDraw *p) { delete p; }

// ??_GW3DProjectileStreamDraw@@UAEPAXI@Z @0x000D144F 28B: slot 0 of vtable 0x00BCE010; calls ??1 at 0x000D146B.
// Owner evidence: installed by ??0W3DProjectileStreamDraw@@QAE@PAVThing@@PBVModuleData@@@Z; class-unique slots 4 ?rva0000D140A@W3DProjectileStreamDraw@@SA?AW4NameKeyType@@XZ and 35 ?setFullyObscuredByShroud@W3DProjectileStreamDraw@@UAEX_N@Z.
class W3DProjectileStreamDraw { public: __declspec(noinline) virtual ~W3DProjectileStreamDraw(); };
// ??1W3DProjectileStreamDraw@@UAE@XZ present-unmatched
W3DProjectileStreamDraw::~W3DProjectileStreamDraw() {}
void W3DProjectileStreamDraw_Delete(W3DProjectileStreamDraw *p) { delete p; }

// ??_GW3DTornadoDrawModuleData@@UAEPAXI@Z @0x000D16F7 28B: slot 0 of vtable 0x00BCE198; calls ??1 at 0x000D1713.
// Owner evidence: sole named installer ??0W3DTornadoDrawModuleData@@QAE@XZ.
class W3DTornadoDrawModuleData { public: __declspec(noinline) virtual ~W3DTornadoDrawModuleData(); };
// ??1W3DTornadoDrawModuleData@@UAE@XZ present-unmatched
W3DTornadoDrawModuleData::~W3DTornadoDrawModuleData() {}
void W3DTornadoDrawModuleData_Delete(W3DTornadoDrawModuleData *p) { delete p; }

// ??_GW3DTornadoDraw@@UAEPAXI@Z @0x000D19DD 28B: slot 0 of vtable 0x00BCE218; calls ??1 at 0x000D18AB.
// Owner evidence: installed by ??0W3DTornadoDraw@@QAE@PAVThing@@PBVModuleData@@@Z; class-unique slots 4 ?rva000D1866@W3DTornadoDraw@@SA?AW4NameKeyType@@XZ.
class W3DTornadoDraw { public: __declspec(noinline) virtual ~W3DTornadoDraw(); };
// ??1W3DTornadoDraw@@UAE@XZ present-unmatched
W3DTornadoDraw::~W3DTornadoDraw() {}
void W3DTornadoDraw_Delete(W3DTornadoDraw *p) { delete p; }
