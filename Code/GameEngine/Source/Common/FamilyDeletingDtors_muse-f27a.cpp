// cl: /O1 /MD
// ??_GFloodUpdateModuleData@@UAEPAXI@Z @0x0048E13F 28B
// Deleting dtor slot 0 of vtable 0x0084C8C0; calls rowed ??1 at 0x0048DFB1 then rowed operator delete at 0x0002FD60.
class FloodUpdateModuleData { public: __declspec(noinline) virtual ~FloodUpdateModuleData(); private: int m_famgen; };
FloodUpdateModuleData::~FloodUpdateModuleData() { m_famgen = 0; }
void famgenDelete(FloodUpdateModuleData *p) { delete p; }
