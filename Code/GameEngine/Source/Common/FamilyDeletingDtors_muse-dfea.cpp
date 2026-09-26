// cl: /O1 /MD
// ??_GInvisibilitySpecialPowerModuleData@@UAEPAXI@Z @0x004C24C3 28B
// Deleting dtor slot 0 of vtable 0x00C5C558; calls rowed ??1 at 0x004C24DF then rowed operator delete at 0x0002FD60.
class InvisibilitySpecialPowerModuleData { public: __declspec(noinline) virtual ~InvisibilitySpecialPowerModuleData(); private: int m_famgen; };
// ??1InvisibilitySpecialPowerModuleData@@UAE@XZ present-unmatched
InvisibilitySpecialPowerModuleData::~InvisibilitySpecialPowerModuleData() { m_famgen = 0; }
void famgenDelete(InvisibilitySpecialPowerModuleData *p) { delete p; }
// ??_GCashHackSpecialPowerModuleData@@UAEPAXI@Z @0x004C28C1 28B
// Deleting dtor slot 0 of vtable 0x00C5C688; calls rowed ??1 at 0x004C28DD then rowed operator delete at 0x0002FD60.
class CashHackSpecialPowerModuleData { public: __declspec(noinline) virtual ~CashHackSpecialPowerModuleData(); private: int m_famgen; };
// ??1CashHackSpecialPowerModuleData@@UAE@XZ present-unmatched
CashHackSpecialPowerModuleData::~CashHackSpecialPowerModuleData() { m_famgen = 0; }
void famgenDelete(CashHackSpecialPowerModuleData *p) { delete p; }
