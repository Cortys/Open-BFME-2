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

// ??_GCaveContainModuleData@@UAEPAXI@Z @0x002576F3 28B: slot 0 of vtable 0x00C43F40; calls ??1 at 0x0025770F.
// Owner evidence: sole named installer ??0CaveContainModuleData@@QAE@XZ.
class CaveContainModuleData { public: __declspec(noinline) virtual ~CaveContainModuleData(); };
// ??1CaveContainModuleData@@UAE@XZ present-unmatched
CaveContainModuleData::~CaveContainModuleData() {}
void CaveContainModuleData_Delete(CaveContainModuleData *p) { delete p; }

// ??_GOpenContain@@UAEPAXI@Z @0x00464B7A 28B: slot 0 of vtable 0x00C435E8; calls ??1 at 0x00464692.
// Owner evidence: installed by ??0OpenContain@@QAE@PAVThing@@PBVModuleData@@@Z; class-unique slots 4 ?rva00464775@OpenContain@@SA?AW4NameKeyType@@XZ.
class OpenContain { public: __declspec(noinline) virtual ~OpenContain(); };
// ??1OpenContain@@UAE@XZ present-unmatched
OpenContain::~OpenContain() {}
void OpenContain_Delete(OpenContain *p) { delete p; }

// ??_GTransportContain@@UAEPAXI@Z @0x00468029 28B: slot 0 of vtable 0x00C44278; calls ??1 at 0x00467E61.
// Owner evidence: class-unique slots 4 ?rva000467EE1@TransportContain@@SA?AW4NameKeyType@@XZ.
class TransportContain { public: __declspec(noinline) virtual ~TransportContain(); };
// ??1TransportContain@@UAE@XZ present-unmatched
TransportContain::~TransportContain() {}
void TransportContain_Delete(TransportContain *p) { delete p; }

// ??_GHordeContain@@UAEPAXI@Z @0x004704C8 28B: slot 0 of vtable 0x00C45050; calls ??1 at 0x0046F901.
// Owner evidence: class-unique slots 4 ?rva00046F860@HordeContain@@SA?AW4NameKeyType@@XZ.
class HordeContain { public: __declspec(noinline) virtual ~HordeContain(); };
// ??1HordeContain@@UAE@XZ present-unmatched
HordeContain::~HordeContain() {}
void HordeContain_Delete(HordeContain *p) { delete p; }

// ??_GHorseHordeContain@@UAEPAXI@Z @0x0047672D 28B: slot 0 of vtable 0x00C45C38; calls ??1 at 0x00476653.
// Owner evidence: installed by ??0HorseHordeContain@@QAE@PAVThing@@PBVModuleData@@@Z; class-unique slots 4 ?rva0004766E8@HorseHordeContain@@SA?AW4NameKeyType@@XZ.
class HorseHordeContain { public: __declspec(noinline) virtual ~HorseHordeContain(); };
// ??1HorseHordeContain@@UAE@XZ present-unmatched
HorseHordeContain::~HorseHordeContain() {}
void HorseHordeContain_Delete(HorseHordeContain *p) { delete p; }

// ??_GHordeTransportContain@@UAEPAXI@Z @0x004771CA 28B: slot 0 of vtable 0x00C45EB8; calls ??1 at 0x004771E6.
// Owner evidence: installed by ??0HordeTransportContain@@QAE@PAVThing@@PBVModuleData@@@Z; class-unique slots 4 ?rva000477185@HordeTransportContain@@SA?AW4NameKeyType@@XZ.
class HordeTransportContain { public: __declspec(noinline) virtual ~HordeTransportContain(); };
// ??1HordeTransportContain@@UAE@XZ present-unmatched
HordeTransportContain::~HordeTransportContain() {}
void HordeTransportContain_Delete(HordeTransportContain *p) { delete p; }

// ??_GHordeTransportContainModuleData@@UAEPAXI@Z @0x00477D73 28B: slot 0 of vtable 0x00C45FB0; calls ??1 at 0x00477D8F.
// Owner evidence: sole named installer ??0HordeTransportContainModuleData@@QAE@XZ.
class HordeTransportContainModuleData { public: __declspec(noinline) virtual ~HordeTransportContainModuleData(); };
// ??1HordeTransportContainModuleData@@UAE@XZ present-unmatched
HordeTransportContainModuleData::~HordeTransportContainModuleData() {}
void HordeTransportContainModuleData_Delete(HordeTransportContainModuleData *p) { delete p; }

// ??_GGarrisonContain@@UAEPAXI@Z @0x0047860D 28B: slot 0 of vtable 0x00C461F8; calls ??1 at 0x00478067.
// Owner evidence: class-unique slots 4 ?rva0047801C@GarrisonContain@@SA?AW4NameKeyType@@XZ.
class GarrisonContain { public: __declspec(noinline) virtual ~GarrisonContain(); };
// ??1GarrisonContain@@UAE@XZ present-unmatched
GarrisonContain::~GarrisonContain() {}
void GarrisonContain_Delete(GarrisonContain *p) { delete p; }

// ??_GHordeGarrisonContain@@UAEPAXI@Z @0x0047A12B 28B: slot 0 of vtable 0x00C46570; calls ??1 at 0x0047A147.
// Owner evidence: class-unique slots 4 ?rva00047A0E6@HordeGarrisonContain@@SA?AW4NameKeyType@@XZ.
class HordeGarrisonContain { public: __declspec(noinline) virtual ~HordeGarrisonContain(); };
// ??1HordeGarrisonContain@@UAE@XZ present-unmatched
HordeGarrisonContain::~HordeGarrisonContain() {}
void HordeGarrisonContain_Delete(HordeGarrisonContain *p) { delete p; }

// ??_GAODHordeContain@@UAEPAXI@Z @0x0047B674 28B: slot 0 of vtable 0x00C46D28; calls ??1 at 0x0047B563.
// Owner evidence: installed by ??0AODHordeContain@@QAE@PAVThing@@PBVModuleData@@@Z; class-unique slots 4 ?rva00047B51E@AODHordeContain@@SA?AW4NameKeyType@@XZ.
class AODHordeContain { public: __declspec(noinline) virtual ~AODHordeContain(); };
// ??1AODHordeContain@@UAE@XZ present-unmatched
AODHordeContain::~AODHordeContain() {}
void AODHordeContain_Delete(AODHordeContain *p) { delete p; }

// ??_GSiegeEngineContain@@UAEPAXI@Z @0x0047C2D6 28B: slot 0 of vtable 0x00C470F8; calls ??1 at 0x0047BF43.
// Owner evidence: installed by ??0SiegeEngineContain@@QAE@PAVThing@@PBVModuleData@@@Z; class-unique slots 4 ?rva00047C03A@SiegeEngineContain@@SA?AW4NameKeyType@@XZ.
class SiegeEngineContain { public: __declspec(noinline) virtual ~SiegeEngineContain(); };
// ??1SiegeEngineContain@@UAE@XZ present-unmatched
SiegeEngineContain::~SiegeEngineContain() {}
void SiegeEngineContain_Delete(SiegeEngineContain *p) { delete p; }

// ??_GSiegeEngineContainModuleData@@UAEPAXI@Z @0x0047C9AF 28B: slot 0 of vtable 0x00C47180; calls ??1 at 0x0047C9CB.
// Owner evidence: sole named installer ??0SiegeEngineContainModuleData@@QAE@XZ.
class SiegeEngineContainModuleData { public: __declspec(noinline) virtual ~SiegeEngineContainModuleData(); };
// ??1SiegeEngineContainModuleData@@UAE@XZ present-unmatched
SiegeEngineContainModuleData::~SiegeEngineContainModuleData() {}
void SiegeEngineContainModuleData_Delete(SiegeEngineContainModuleData *p) { delete p; }

// ??_GHordeSiegeEngineContain@@UAEPAXI@Z @0x0047D31E 28B: slot 0 of vtable 0x00C474A0; calls ??1 at 0x0047CFB2.
// Owner evidence: class-unique slots 4 ?rva00047D0A2@HordeSiegeEngineContain@@SA?AW4NameKeyType@@XZ.
class HordeSiegeEngineContain { public: __declspec(noinline) virtual ~HordeSiegeEngineContain(); };
// ??1HordeSiegeEngineContain@@UAE@XZ present-unmatched
HordeSiegeEngineContain::~HordeSiegeEngineContain() {}
void HordeSiegeEngineContain_Delete(HordeSiegeEngineContain *p) { delete p; }

// ??_GHordeSiegeEngineContainModuleData@@UAEPAXI@Z @0x0047DA7D 28B: slot 0 of vtable 0x00C47520; calls ??1 at 0x0047DA99.
// Owner evidence: sole named installer ??0HordeSiegeEngineContainModuleData@@QAE@XZ.
class HordeSiegeEngineContainModuleData { public: __declspec(noinline) virtual ~HordeSiegeEngineContainModuleData(); };
// ??1HordeSiegeEngineContainModuleData@@UAE@XZ present-unmatched
HordeSiegeEngineContainModuleData::~HordeSiegeEngineContainModuleData() {}
void HordeSiegeEngineContainModuleData_Delete(HordeSiegeEngineContainModuleData *p) { delete p; }

// ??_GTunnelContain@@UAEPAXI@Z @0x0047DC59 28B: slot 0 of vtable 0x00C47740; calls ??1 at 0x0047DB00.
// Owner evidence: installed by ??0TunnelContain@@QAE@PAVThing@@PBVModuleData@@@Z; class-unique slots 4 ?rva00047DB43@TunnelContain@@SA?AW4NameKeyType@@XZ.
class TunnelContain { public: __declspec(noinline) virtual ~TunnelContain(); };
// ??1TunnelContain@@UAE@XZ present-unmatched
TunnelContain::~TunnelContain() {}
void TunnelContain_Delete(TunnelContain *p) { delete p; }

// ??_GRiderChangeContain@@UAEPAXI@Z @0x0047E4FF 28B: slot 0 of vtable 0x00C47A00; calls ??1 at 0x0047E51B.
// Owner evidence: installed by ??0RiderChangeContain@@QAE@PAVThing@@PBVModuleData@@@Z; class-unique slots 4 ?rva00047E2E0@RiderChangeContain@@SA?AW4NameKeyType@@XZ.
class RiderChangeContain { public: __declspec(noinline) virtual ~RiderChangeContain(); };
// ??1RiderChangeContain@@UAE@XZ present-unmatched
RiderChangeContain::~RiderChangeContain() {}
void RiderChangeContain_Delete(RiderChangeContain *p) { delete p; }

// ??_GRiderChangeContainModuleData@@UAEPAXI@Z @0x0047EB1A 28B: slot 0 of vtable 0x00C47B00; calls ??1 at 0x0047EB36.
// Owner evidence: sole named installer ??0RiderChangeContainModuleData@@QAE@XZ.
class RiderChangeContainModuleData { public: __declspec(noinline) virtual ~RiderChangeContainModuleData(); };
// ??1RiderChangeContainModuleData@@UAE@XZ present-unmatched
RiderChangeContainModuleData::~RiderChangeContainModuleData() {}
void RiderChangeContainModuleData_Delete(RiderChangeContainModuleData *p) { delete p; }

// ??_GSlaughterHordeContain@@UAEPAXI@Z @0x00480645 28B: slot 0 of vtable 0x00C48AA0; calls ??1 at 0x004803FB.
// Owner evidence: installed by ??0SlaughterHordeContain@@QAE@PAVThing@@PBVModuleData@@@Z; class-unique slots 4 ?rva0004803B6@SlaughterHordeContain@@SA?AW4NameKeyType@@XZ.
class SlaughterHordeContain { public: __declspec(noinline) virtual ~SlaughterHordeContain(); };
// ??1SlaughterHordeContain@@UAE@XZ present-unmatched
SlaughterHordeContain::~SlaughterHordeContain() {}
void SlaughterHordeContain_Delete(SlaughterHordeContain *p) { delete p; }

// ??_GCitadelSlaughterHordeContain@@UAEPAXI@Z @0x004806FC 28B: slot 0 of vtable 0x00C48CC0; calls ??1 at 0x00480718.
// Owner evidence: installed by ??0CitadelSlaughterHordeContain@@QAE@PAVThing@@PBVModuleData@@@Z; class-unique slots 4 ?rva000480600@CitadelSlaughterHordeContain@@SA?AW4NameKeyType@@XZ.
class CitadelSlaughterHordeContain { public: __declspec(noinline) virtual ~CitadelSlaughterHordeContain(); };
// ??1CitadelSlaughterHordeContain@@UAE@XZ present-unmatched
CitadelSlaughterHordeContain::~CitadelSlaughterHordeContain() {}
void CitadelSlaughterHordeContain_Delete(CitadelSlaughterHordeContain *p) { delete p; }

// ??_GCitadelSlaughterHordeContainModuleData@@UAEPAXI@Z @0x004811CA 28B: slot 0 of vtable 0x00C48E40; calls ??1 at 0x004811E6.
// Owner evidence: sole named installer ??0CitadelSlaughterHordeContainModuleData@@QAE@XZ.
class CitadelSlaughterHordeContainModuleData { public: __declspec(noinline) virtual ~CitadelSlaughterHordeContainModuleData(); };
// ??1CitadelSlaughterHordeContainModuleData@@UAE@XZ present-unmatched
CitadelSlaughterHordeContainModuleData::~CitadelSlaughterHordeContainModuleData() {}
void CitadelSlaughterHordeContainModuleData_Delete(CitadelSlaughterHordeContainModuleData *p) { delete p; }

// ??_GProductionQueueHordeContain@@UAEPAXI@Z @0x00481397 28B: slot 0 of vtable 0x00C49040; calls ??1 at 0x00481230.
// Owner evidence: installed by ??0ProductionQueueHordeContain@@QAE@PAVThing@@PBVModuleData@@@Z; class-unique slots 4 ?rva0004812B9@ProductionQueueHordeContain@@SA?AW4NameKeyType@@XZ.
class ProductionQueueHordeContain { public: __declspec(noinline) virtual ~ProductionQueueHordeContain(); };
// ??1ProductionQueueHordeContain@@UAE@XZ present-unmatched
ProductionQueueHordeContain::~ProductionQueueHordeContain() {}
void ProductionQueueHordeContain_Delete(ProductionQueueHordeContain *p) { delete p; }

// ??_GProductionQueueHordeContainModuleData@@UAEPAXI@Z @0x0048179A 28B: slot 0 of vtable 0x00C490F8; calls ??1 at 0x004817B6.
// Owner evidence: sole named installer ??0ProductionQueueHordeContainModuleData@@QAE@XZ.
class ProductionQueueHordeContainModuleData { public: __declspec(noinline) virtual ~ProductionQueueHordeContainModuleData(); };
// ??1ProductionQueueHordeContainModuleData@@UAE@XZ present-unmatched
ProductionQueueHordeContainModuleData::~ProductionQueueHordeContainModuleData() {}
void ProductionQueueHordeContainModuleData_Delete(ProductionQueueHordeContainModuleData *p) { delete p; }
