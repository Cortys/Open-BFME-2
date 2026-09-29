// cl: /O1 /MD
// ??_GRva004D6208@@MAEPAXI@Z @0x004D6AB9 28B
// Deleting dtor slot 0 of vtable 0x00860484; calls rowed ??1Rva004D6208@@MAE@XZ at 0x004D6208 then rowed operator delete at 0x0002FD60.
class Rva004D6208 { protected: __declspec(noinline) virtual ~Rva004D6208(); private: int m_famgen;
  friend void famgenDelete(Rva004D6208 *p); };
// ??1Rva004D6208@@MAE@XZ present-unmatched
Rva004D6208::~Rva004D6208() { m_famgen = 0; }
void famgenDelete(Rva004D6208 *p) { delete p; }
