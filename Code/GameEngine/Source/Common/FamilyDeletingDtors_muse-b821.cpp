// cl: /O1 /MD
// ??_GProductionSpeedBonusModuleData@@UAEPAXI@Z @0x004C3048 28B
// Deleting dtor slot 0 of vtable 0x00C5CA80; calls rowed ??1 at 0x004C3064 then rowed operator delete at 0x0002FD60.
class ProductionSpeedBonusModuleData { public: __declspec(noinline) virtual ~ProductionSpeedBonusModuleData(); private: int m_famgen; };
// ??1ProductionSpeedBonusModuleData@@UAE@XZ present-unmatched
ProductionSpeedBonusModuleData::~ProductionSpeedBonusModuleData() { m_famgen = 0; }
void famgenDelete(ProductionSpeedBonusModuleData *p) { delete p; }
