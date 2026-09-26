// cl: /O1 /MD
// ??_GCloudBreakSpecialPowerModuleData@@UAEPAXI@Z @0x004C47D7 28B
// Deleting dtor slot 0 of vtable 0x00C5D468; calls rowed ??1 at 0x004C47F3 then rowed operator delete at 0x0002FD60.
class CloudBreakSpecialPowerModuleData { public: __declspec(noinline) virtual ~CloudBreakSpecialPowerModuleData(); private: int m_famgen; };
// ??1CloudBreakSpecialPowerModuleData@@UAE@XZ present-unmatched
CloudBreakSpecialPowerModuleData::~CloudBreakSpecialPowerModuleData() { m_famgen = 0; }
void famgenDelete(CloudBreakSpecialPowerModuleData *p) { delete p; }

// ??_GTaintSpecialPowerModuleData@@UAEPAXI@Z @0x004C4AEB 28B
// Deleting dtor slot 0 of vtable 0x00C5D608; calls rowed ??1 at 0x004C4B07 then rowed operator delete at 0x0002FD60.
class TaintSpecialPowerModuleData { public: __declspec(noinline) virtual ~TaintSpecialPowerModuleData(); private: int m_famgen; };
// ??1TaintSpecialPowerModuleData@@UAE@XZ present-unmatched
TaintSpecialPowerModuleData::~TaintSpecialPowerModuleData() { m_famgen = 0; }
void famgenDelete(TaintSpecialPowerModuleData *p) { delete p; }
