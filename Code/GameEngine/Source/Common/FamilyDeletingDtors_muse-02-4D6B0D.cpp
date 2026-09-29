// cl: /O1 /MD
// ??_GRva004D65DC@@MAEPAXI@Z @0x004D6B0D 28B
// Deleting dtor slot 0 of vtable 0x00860530; calls rowed ??1Rva004D65DC@@MAE@XZ at 0x004D6708 then rowed operator delete at 0x0002FD60.
class Rva004D65DC { protected: __declspec(noinline) virtual ~Rva004D65DC(); private: int m_famgen;
  friend void famgenDelete(Rva004D65DC *p); };
// ??1Rva004D65DC@@MAE@XZ present-unmatched
Rva004D65DC::~Rva004D65DC() { m_famgen = 0; }
void famgenDelete(Rva004D65DC *p) { delete p; }
