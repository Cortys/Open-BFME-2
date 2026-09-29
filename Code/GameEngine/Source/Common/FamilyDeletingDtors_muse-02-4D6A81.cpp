// cl: /O1 /MD
// ??_GRva004D60CA@@MAEPAXI@Z @0x004D6A81 28B
// Deleting dtor slot 0 of vtable 0x00860464; calls rowed ??1Rva004D60CA@@MAE@XZ at 0x004D60E3 then rowed operator delete at 0x0002FD60.
class Rva004D60CA { protected: __declspec(noinline) virtual ~Rva004D60CA(); private: int m_famgen;
  friend void famgenDelete(Rva004D60CA *p); };
// ??1Rva004D60CA@@MAE@XZ present-unmatched
Rva004D60CA::~Rva004D60CA() { m_famgen = 0; }
void famgenDelete(Rva004D60CA *p) { delete p; }
