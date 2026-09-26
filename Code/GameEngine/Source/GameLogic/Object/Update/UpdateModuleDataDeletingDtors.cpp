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

// ??_GDeployStyleAIUpdateModuleData@@UAEPAXI@Z @0x00255F54 28B: slot 0 of vtable 0x00BF3440; calls ??1 at 0x00255F70.
// Owner evidence: sole named installer ??0DeployStyleAIUpdateModuleData@@QAE@XZ.
class DeployStyleAIUpdateModuleData { public: __declspec(noinline) virtual ~DeployStyleAIUpdateModuleData(); };
// ??1DeployStyleAIUpdateModuleData@@UAE@XZ present-unmatched
DeployStyleAIUpdateModuleData::~DeployStyleAIUpdateModuleData() {}
void DeployStyleAIUpdateModuleData_Delete(DeployStyleAIUpdateModuleData *p) { delete p; }

// ??_GSlavedUpdateModuleData@@UAEPAXI@Z @0x00255FA5 28B: slot 0 of vtable 0x00BF34C0; calls ??1 at 0x00255FC1.
// Owner evidence: sole named installer ??0SlavedUpdateModuleData@@QAE@XZ.
class SlavedUpdateModuleData { public: __declspec(noinline) virtual ~SlavedUpdateModuleData(); };
// ??1SlavedUpdateModuleData@@UAE@XZ present-unmatched
SlavedUpdateModuleData::~SlavedUpdateModuleData() {}
void SlavedUpdateModuleData_Delete(SlavedUpdateModuleData *p) { delete p; }

// ??_GTransportAIUpdateModuleData@@UAEPAXI@Z @0x0026E67D 28B: slot 0 of vtable 0x00BFA288; calls ??1 at 0x0026E1FC.
// Owner evidence: sole named installer ??0TransportAIUpdateModuleData@@QAE@XZ.
class TransportAIUpdateModuleData { public: __declspec(noinline) virtual ~TransportAIUpdateModuleData(); };
// ??1TransportAIUpdateModuleData@@UAE@XZ present-unmatched
TransportAIUpdateModuleData::~TransportAIUpdateModuleData() {}
void TransportAIUpdateModuleData_Delete(TransportAIUpdateModuleData *p) { delete p; }

// ??_GLaserUpdateModuleData@@UAEPAXI@Z @0x003631CC 28B: slot 0 of vtable 0x00C17120; calls ??1 at 0x003631E8.
// Owner evidence: sole named installer ??0LaserUpdateModuleData@@QAE@XZ.
class LaserUpdateModuleData { public: __declspec(noinline) virtual ~LaserUpdateModuleData(); };
// ??1LaserUpdateModuleData@@UAE@XZ present-unmatched
LaserUpdateModuleData::~LaserUpdateModuleData() {}
void LaserUpdateModuleData_Delete(LaserUpdateModuleData *p) { delete p; }

// ??_GArrowStormUpdateModuleData@@UAEPAXI@Z @0x00490679 28B: slot 0 of vtable 0x00C4D5A0; calls ??1 at 0x00490695.
// Owner evidence: sole named installer ??0ArrowStormUpdateModuleData@@QAE@XZ.
class ArrowStormUpdateModuleData { public: __declspec(noinline) virtual ~ArrowStormUpdateModuleData(); };
// ??1ArrowStormUpdateModuleData@@UAE@XZ present-unmatched
ArrowStormUpdateModuleData::~ArrowStormUpdateModuleData() {}
void ArrowStormUpdateModuleData_Delete(ArrowStormUpdateModuleData *p) { delete p; }

// ??_GAutoPickUpUpdateModuleData@@UAEPAXI@Z @0x00496460 28B: slot 0 of vtable 0x00C4F108; calls ??1 at 0x0049647C.
// Owner evidence: sole named installer ??0AutoPickUpUpdateModuleData@@QAE@XZ.
class AutoPickUpUpdateModuleData { public: __declspec(noinline) virtual ~AutoPickUpUpdateModuleData(); };
// ??1AutoPickUpUpdateModuleData@@UAE@XZ present-unmatched
AutoPickUpUpdateModuleData::~AutoPickUpUpdateModuleData() {}
void AutoPickUpUpdateModuleData_Delete(AutoPickUpUpdateModuleData *p) { delete p; }

// ??_GBannerCarrierUpdateModuleData@@UAEPAXI@Z @0x004976AE 28B: slot 0 of vtable 0x00C4F870; calls ??1 at 0x00497056.
// Owner evidence: sole named installer ??0BannerCarrierUpdateModuleData@@QAE@XZ.
class BannerCarrierUpdateModuleData { public: __declspec(noinline) virtual ~BannerCarrierUpdateModuleData(); };
// ??1BannerCarrierUpdateModuleData@@UAE@XZ present-unmatched
BannerCarrierUpdateModuleData::~BannerCarrierUpdateModuleData() {}
void BannerCarrierUpdateModuleData_Delete(BannerCarrierUpdateModuleData *p) { delete p; }

// ??_GOneRingPenaltyUpdateModuleData@@UAEPAXI@Z @0x00499C19 28B: slot 0 of vtable 0x00C50298; calls ??1 at 0x00499A16.
// Owner evidence: sole named installer ??0OneRingPenaltyUpdateModuleData@@QAE@XZ.
class OneRingPenaltyUpdateModuleData { public: __declspec(noinline) virtual ~OneRingPenaltyUpdateModuleData(); };
// ??1OneRingPenaltyUpdateModuleData@@UAE@XZ present-unmatched
OneRingPenaltyUpdateModuleData::~OneRingPenaltyUpdateModuleData() {}
void OneRingPenaltyUpdateModuleData_Delete(OneRingPenaltyUpdateModuleData *p) { delete p; }

// ??_GReplaceObjectUpdateModuleData@@UAEPAXI@Z @0x004B2E5D 28B: slot 0 of vtable 0x00C56C78; calls ??1 at 0x004B2C9A.
// Owner evidence: sole named installer ??0ReplaceObjectUpdateModuleData@@QAE@XZ.
class ReplaceObjectUpdateModuleData { public: __declspec(noinline) virtual ~ReplaceObjectUpdateModuleData(); };
// ??1ReplaceObjectUpdateModuleData@@UAE@XZ present-unmatched
ReplaceObjectUpdateModuleData::~ReplaceObjectUpdateModuleData() {}
void ReplaceObjectUpdateModuleData_Delete(ReplaceObjectUpdateModuleData *p) { delete p; }

// ??_GCritterEmitterUpdateModuleData@@UAEPAXI@Z @0x004C8F2D 28B: slot 0 of vtable 0x00C5E988; calls ??1 at 0x004C8F49.
// Owner evidence: sole named installer ??0CritterEmitterUpdateModuleData@@QAE@XZ.
class CritterEmitterUpdateModuleData { public: __declspec(noinline) virtual ~CritterEmitterUpdateModuleData(); };
// ??1CritterEmitterUpdateModuleData@@UAE@XZ present-unmatched
CritterEmitterUpdateModuleData::~CritterEmitterUpdateModuleData() {}
void CritterEmitterUpdateModuleData_Delete(CritterEmitterUpdateModuleData *p) { delete p; }
