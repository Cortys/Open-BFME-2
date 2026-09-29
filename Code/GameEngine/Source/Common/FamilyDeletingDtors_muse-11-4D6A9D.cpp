// cl: /O1 /MD
// ??_GRva004D6134@@MAEPAXI@Z @0x004D6A9D 28B
// Deleting dtor slot 0 of vtable 0x00860474; calls rowed ??1Rva004D6134@@MAE@XZ at 0x004D6151 then rowed operator delete at 0x0002FD60.
class Rva004D6134 { protected: __declspec(noinline) virtual ~Rva004D6134(); private: int m_famgen;
  friend void famgenDelete(Rva004D6134 *p); };
// ??1Rva004D6134@@MAE@XZ present-unmatched
Rva004D6134::~Rva004D6134() { m_famgen = 0; }
void famgenDelete(Rva004D6134 *p) { delete p; }
