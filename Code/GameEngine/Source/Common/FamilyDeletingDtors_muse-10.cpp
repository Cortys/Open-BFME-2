// cl: /O1 /MD
// ??_GRva002AC340@@MAEPAXI@Z @0x002AC3A2 28B
// Deleting dtor slot 0 of vtable 0x007FDD6C; calls rowed ??1Rva002AC340@@MAE@XZ at 0x002AC366 then rowed operator delete at 0x0002FD60.
class Rva002AC340 { protected: __declspec(noinline) virtual ~Rva002AC340(); private: int m_famgen;
  friend void famgenDelete(Rva002AC340 *p); };
Rva002AC340::~Rva002AC340() { m_famgen = 0; }
void famgenDelete(Rva002AC340 *p) { delete p; }
