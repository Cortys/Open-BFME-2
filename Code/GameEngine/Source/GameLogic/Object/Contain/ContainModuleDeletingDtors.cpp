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

// ??_GCaveContainModuleData@@UAEPAXI@Z @0x002576F3 28B: slot 0 of vtable 0x00C43F40; calls ??1 at 0x0025770F.
// Owner evidence (audited 2026-09-26): retail registration CaveContain -> data factory RVA 0x00257714 -> ctor RVA 0x00466D37; primary vptr store RVA 0x00466D46; constructor also used by HealContain (no exclusive owner claim).
class CaveContainModuleData { public: __declspec(noinline) virtual ~CaveContainModuleData(); };
// ??1CaveContainModuleData@@UAE@XZ present-unmatched
CaveContainModuleData::~CaveContainModuleData() {}
void CaveContainModuleData_Delete(CaveContainModuleData *p) { delete p; }

// ??_GHordeGarrisonContainModuleData@@UAEPAXI@Z @0x002579E9 28B: slot 0 of vtable 0x00BF4328; calls ??1 at 0x00257A05.
// Owner evidence: vtable 0x00BF4328 installed by ctor 0x0047A251; ctor factory 0x0024BAD1 news 0xD4; dtor 0x00257A05 is 5B jmp to Garrison dtor 0x00257507 (rowed); HordeTransport 5B-jmp precedent.
class HordeGarrisonContainModuleData { public: __declspec(noinline) virtual ~HordeGarrisonContainModuleData(); };
// ??1HordeGarrisonContainModuleData@@UAE@XZ present-unmatched
HordeGarrisonContainModuleData::~HordeGarrisonContainModuleData() {}
void HordeGarrisonContainModuleData_Delete(HordeGarrisonContainModuleData *p) { delete p; }

// ??_GOpenContain@@UAEPAXI@Z @0x00464B7A 28B: slot 0 of vtable 0x00C435E8; calls ??1 at 0x00464692.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x00464775 uses class-name string "OpenContain".
class OpenContain { public: __declspec(noinline) virtual ~OpenContain(); };
// ??1OpenContain@@UAE@XZ present-unmatched
OpenContain::~OpenContain() {}
void OpenContain_Delete(OpenContain *p) { delete p; }

// ??_GTransportContain@@UAEPAXI@Z @0x00468029 28B: slot 0 of vtable 0x00C44278; calls ??1 at 0x00467E61.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x00467EE1 uses class-name string "TransportContain".
class TransportContain { public: __declspec(noinline) virtual ~TransportContain(); };
// ??1TransportContain@@UAE@XZ present-unmatched
TransportContain::~TransportContain() {}
void TransportContain_Delete(TransportContain *p) { delete p; }

// ??_GTransportContainModuleData@@UAEPAXI@Z @0x004684D5 28B: slot 0 of vtable 0x00C442F8; calls ??1 at 0x004684F1.
// Owner evidence (audited 2026-09-26): vtable 0x00C442F8 installed by ctor 0x00468301; ModuleFactory pairs TransportContain with data factory 0x0024B89C; HordeTransport dtor 0x00477D8F jmps to ??1 here.
class TransportContainModuleData { public: __declspec(noinline) virtual ~TransportContainModuleData(); };
// ??1TransportContainModuleData@@UAE@XZ present-unmatched
TransportContainModuleData::~TransportContainModuleData() {}
void TransportContainModuleData_Delete(TransportContainModuleData *p) { delete p; }

// ??_GHordeContain@@UAEPAXI@Z @0x004704C8 28B: slot 0 of vtable 0x00C45050; calls ??1 at 0x0046F901.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x0046F860 uses class-name string "HordeContain".
class HordeContain { public: __declspec(noinline) virtual ~HordeContain(); };
// ??1HordeContain@@UAE@XZ present-unmatched
HordeContain::~HordeContain() {}
void HordeContain_Delete(HordeContain *p) { delete p; }

// ??_GHorseHordeContain@@UAEPAXI@Z @0x0047672D 28B: slot 0 of vtable 0x00C45C38; calls ??1 at 0x00476653.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x004766E8 uses class-name string "HorseHordeContain".
class HorseHordeContain { public: __declspec(noinline) virtual ~HorseHordeContain(); };
// ??1HorseHordeContain@@UAE@XZ present-unmatched
HorseHordeContain::~HorseHordeContain() {}
void HorseHordeContain_Delete(HorseHordeContain *p) { delete p; }

// ??_GHordeTransportContain@@UAEPAXI@Z @0x004771CA 28B: slot 0 of vtable 0x00C45EB8; calls ??1 at 0x004771E6.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x00477185 uses class-name string "HordeTransportContain".
class HordeTransportContain { public: __declspec(noinline) virtual ~HordeTransportContain(); };
// ??1HordeTransportContain@@UAE@XZ present-unmatched
HordeTransportContain::~HordeTransportContain() {}
void HordeTransportContain_Delete(HordeTransportContain *p) { delete p; }

// ??_GHordeTransportContainModuleData@@UAEPAXI@Z @0x00477D73 28B: slot 0 of vtable 0x00C45FB0; calls ??1 at 0x00477D8F.
// Owner evidence (audited 2026-09-26): retail registration HordeTransportContain -> data factory RVA 0x0024BA07 -> ctor RVA 0x00477D61; primary vptr store RVA 0x00477D69.
class HordeTransportContainModuleData { public: __declspec(noinline) virtual ~HordeTransportContainModuleData(); };
// ??1HordeTransportContainModuleData@@UAE@XZ present-unmatched
HordeTransportContainModuleData::~HordeTransportContainModuleData() {}
void HordeTransportContainModuleData_Delete(HordeTransportContainModuleData *p) { delete p; }

// ??_GGarrisonContain@@UAEPAXI@Z @0x0047860D 28B: slot 0 of vtable 0x00C461F8; calls ??1 at 0x00478067.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x0047801C uses class-name string "GarrisonContain".
class GarrisonContain { public: __declspec(noinline) virtual ~GarrisonContain(); };
// ??1GarrisonContain@@UAE@XZ present-unmatched
GarrisonContain::~GarrisonContain() {}
void GarrisonContain_Delete(GarrisonContain *p) { delete p; }

// ??_GHordeGarrisonContain@@UAEPAXI@Z @0x0047A12B 28B: slot 0 of vtable 0x00C46570; calls ??1 at 0x0047A147.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x0047A0E6 uses class-name string "HordeGarrisonContain".
class HordeGarrisonContain { public: __declspec(noinline) virtual ~HordeGarrisonContain(); };
// ??1HordeGarrisonContain@@UAE@XZ present-unmatched
HordeGarrisonContain::~HordeGarrisonContain() {}
void HordeGarrisonContain_Delete(HordeGarrisonContain *p) { delete p; }

// ??_GAODHordeContain@@UAEPAXI@Z @0x0047B674 28B: slot 0 of vtable 0x00C46D28; calls ??1 at 0x0047B563.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x0047B51E uses class-name string "AODHordeContain".
class AODHordeContain { public: __declspec(noinline) virtual ~AODHordeContain(); };
// ??1AODHordeContain@@UAE@XZ present-unmatched
AODHordeContain::~AODHordeContain() {}
void AODHordeContain_Delete(AODHordeContain *p) { delete p; }

// ??_GSiegeEngineContain@@UAEPAXI@Z @0x0047C2D6 28B: slot 0 of vtable 0x00C470F8; calls ??1 at 0x0047BF43.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x0047C03A uses class-name string "SiegeEngineContain".
class SiegeEngineContain { public: __declspec(noinline) virtual ~SiegeEngineContain(); };
// ??1SiegeEngineContain@@UAE@XZ present-unmatched
SiegeEngineContain::~SiegeEngineContain() {}
void SiegeEngineContain_Delete(SiegeEngineContain *p) { delete p; }

// ??_GSiegeEngineContainModuleData@@UAEPAXI@Z @0x0047C9AF 28B: slot 0 of vtable 0x00C47180; calls ??1 at 0x0047C9CB.
// Owner evidence (audited 2026-09-26): retail registration SiegeEngineContain -> data factory RVA 0x0024BBEF -> ctor RVA 0x0047C927; primary vptr store RVA 0x0047C94A.
class SiegeEngineContainModuleData { public: __declspec(noinline) virtual ~SiegeEngineContainModuleData(); };
// ??1SiegeEngineContainModuleData@@UAE@XZ present-unmatched
SiegeEngineContainModuleData::~SiegeEngineContainModuleData() {}
void SiegeEngineContainModuleData_Delete(SiegeEngineContainModuleData *p) { delete p; }

// ??_GHordeSiegeEngineContain@@UAEPAXI@Z @0x0047D31E 28B: slot 0 of vtable 0x00C474A0; calls ??1 at 0x0047CFB2.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x0047D0A2 uses class-name string "HordeSiegeEngineContain".
class HordeSiegeEngineContain { public: __declspec(noinline) virtual ~HordeSiegeEngineContain(); };
// ??1HordeSiegeEngineContain@@UAE@XZ present-unmatched
HordeSiegeEngineContain::~HordeSiegeEngineContain() {}
void HordeSiegeEngineContain_Delete(HordeSiegeEngineContain *p) { delete p; }

// ??_GHordeSiegeEngineContainModuleData@@UAEPAXI@Z @0x0047DA7D 28B: slot 0 of vtable 0x00C47520; calls ??1 at 0x0047DA99.
// Owner evidence (audited 2026-09-26): retail registration HordeSiegeEngineContain -> data factory RVA 0x0024BC7E -> ctor RVA 0x0047DA08; primary vptr store RVA 0x0047DA2A.
class HordeSiegeEngineContainModuleData { public: __declspec(noinline) virtual ~HordeSiegeEngineContainModuleData(); };
// ??1HordeSiegeEngineContainModuleData@@UAE@XZ present-unmatched
HordeSiegeEngineContainModuleData::~HordeSiegeEngineContainModuleData() {}
void HordeSiegeEngineContainModuleData_Delete(HordeSiegeEngineContainModuleData *p) { delete p; }

// ??_GTunnelContain@@UAEPAXI@Z @0x0047DC59 28B: slot 0 of vtable 0x00C47740; calls ??1 at 0x0047DB00.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x0047DB43 uses class-name string "TunnelContain".
class TunnelContain { public: __declspec(noinline) virtual ~TunnelContain(); };
// ??1TunnelContain@@UAE@XZ present-unmatched
TunnelContain::~TunnelContain() {}
void TunnelContain_Delete(TunnelContain *p) { delete p; }

// ??_GRiderChangeContain@@UAEPAXI@Z @0x0047E4FF 28B: slot 0 of vtable 0x00C47A00; calls ??1 at 0x0047E51B.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x0047E2E0 uses class-name string "RiderChangeContain".
class RiderChangeContain { public: __declspec(noinline) virtual ~RiderChangeContain(); };
// ??1RiderChangeContain@@UAE@XZ present-unmatched
RiderChangeContain::~RiderChangeContain() {}
void RiderChangeContain_Delete(RiderChangeContain *p) { delete p; }

// ??_GRiderChangeContainModuleData@@UAEPAXI@Z @0x0047EB1A 28B: slot 0 of vtable 0x00C47B00; calls ??1 at 0x0047EB36.
// Owner evidence (audited 2026-09-26): retail registration RiderChangeContain -> data factory RVA 0x0024BD63 -> ctor RVA 0x0047EABC; primary vptr store RVA 0x0047EAEB.
class RiderChangeContainModuleData { public: __declspec(noinline) virtual ~RiderChangeContainModuleData(); };
// ??1RiderChangeContainModuleData@@UAE@XZ present-unmatched
RiderChangeContainModuleData::~RiderChangeContainModuleData() {}
void RiderChangeContainModuleData_Delete(RiderChangeContainModuleData *p) { delete p; }

// ??_GSlaughterHordeContain@@UAEPAXI@Z @0x00480645 28B: slot 0 of vtable 0x00C48AA0; calls ??1 at 0x004803FB.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x004803B6 uses class-name string "SlaughterHordeContain".
class SlaughterHordeContain { public: __declspec(noinline) virtual ~SlaughterHordeContain(); };
// ??1SlaughterHordeContain@@UAE@XZ present-unmatched
SlaughterHordeContain::~SlaughterHordeContain() {}
void SlaughterHordeContain_Delete(SlaughterHordeContain *p) { delete p; }

// ??_GCitadelSlaughterHordeContain@@UAEPAXI@Z @0x004806FC 28B: slot 0 of vtable 0x00C48CC0; calls ??1 at 0x00480718.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x00480600 uses class-name string "CitadelSlaughterHordeContain".
class CitadelSlaughterHordeContain { public: __declspec(noinline) virtual ~CitadelSlaughterHordeContain(); };
// ??1CitadelSlaughterHordeContain@@UAE@XZ present-unmatched
CitadelSlaughterHordeContain::~CitadelSlaughterHordeContain() {}
void CitadelSlaughterHordeContain_Delete(CitadelSlaughterHordeContain *p) { delete p; }

// ??_GSlaughterHordeContainModuleData@@UAEPAXI@Z @0x00481113 28B: slot 0 of vtable 0x00C48DC0; calls ??1 at 0x004810D5.
// Owner evidence: vtable 0x00C48DC0 installed by ctor 0x0048104D (store at 0x0048107A); ctor factory 0x0024C071 news 0xEC; dtor 0x004810D5 rowed in SlaughterHordeContainModuleDataDtor.cpp.
class SlaughterHordeContainModuleData { public: __declspec(noinline) virtual ~SlaughterHordeContainModuleData(); };
// ??1SlaughterHordeContainModuleData@@UAE@XZ present-unmatched
SlaughterHordeContainModuleData::~SlaughterHordeContainModuleData() {}
void SlaughterHordeContainModuleData_Delete(SlaughterHordeContainModuleData *p) { delete p; }

// ??_GCitadelSlaughterHordeContainModuleData@@UAEPAXI@Z @0x004811CA 28B: slot 0 of vtable 0x00C48E40; calls ??1 at 0x004811E6.
// Owner evidence (audited 2026-09-26): retail registration CitadelSlaughterHordeContain -> data factory RVA 0x0024C100 -> ctor RVA 0x0048112F; primary vptr store RVA 0x00481155.
class CitadelSlaughterHordeContainModuleData { public: __declspec(noinline) virtual ~CitadelSlaughterHordeContainModuleData(); };
// ??1CitadelSlaughterHordeContainModuleData@@UAE@XZ present-unmatched
CitadelSlaughterHordeContainModuleData::~CitadelSlaughterHordeContainModuleData() {}
void CitadelSlaughterHordeContainModuleData_Delete(CitadelSlaughterHordeContainModuleData *p) { delete p; }

// ??_GProductionQueueHordeContain@@UAEPAXI@Z @0x00481397 28B: slot 0 of vtable 0x00C49040; calls ??1 at 0x00481230.
// Owner evidence (audited 2026-09-26): retail slot 4 -> RVA 0x004812B9 uses class-name string "ProductionQueueHordeContain".
class ProductionQueueHordeContain { public: __declspec(noinline) virtual ~ProductionQueueHordeContain(); };
// ??1ProductionQueueHordeContain@@UAE@XZ present-unmatched
ProductionQueueHordeContain::~ProductionQueueHordeContain() {}
void ProductionQueueHordeContain_Delete(ProductionQueueHordeContain *p) { delete p; }

// ??_GProductionQueueHordeContainModuleData@@UAEPAXI@Z @0x0048179A 28B: slot 0 of vtable 0x00C490F8; calls ??1 at 0x004817B6.
// Owner evidence (audited 2026-09-26): retail registration ProductionQueueHordeContain -> data factory RVA 0x0024C18F -> ctor RVA 0x00481776; primary vptr store RVA 0x0048178A.
class ProductionQueueHordeContainModuleData { public: __declspec(noinline) virtual ~ProductionQueueHordeContainModuleData(); };
// ??1ProductionQueueHordeContainModuleData@@UAE@XZ present-unmatched
ProductionQueueHordeContainModuleData::~ProductionQueueHordeContainModuleData() {}
void ProductionQueueHordeContainModuleData_Delete(ProductionQueueHordeContainModuleData *p) { delete p; }

// ??_GGarrisonContainModuleData@@UAEPAXI@Z @0x0047981E 28B: calls ??1 at 0x00257507.
// Owner evidence: retail ctor 0x0047978F installs vtable 0x00C462D8; rowed dtor 0x00257507 is ??1GarrisonContainModuleData@@UAE@XZ; 28B flag-test wrapper calls dtor plus delete 0x0002FD60.
class GarrisonContainModuleData { public: __declspec(noinline) virtual ~GarrisonContainModuleData(); };
// ??1GarrisonContainModuleData@@UAE@XZ present-unmatched
GarrisonContainModuleData::~GarrisonContainModuleData() {}
void GarrisonContainModuleData_Delete(GarrisonContainModuleData *p) { delete p; }
