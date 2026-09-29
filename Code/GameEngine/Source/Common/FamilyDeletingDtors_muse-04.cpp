// cl: /O1 /MD
// ??_GRva00573F03@@UAEPAXI@Z @0x00574013 28B
// Deleting dtor slot 0 of vtable 0x0086E2C8; calls rowed ??1Rva00573F03@@UAE@XZ at 0x00573F03 then rowed operator delete at 0x0002FD60.
class Rva00573F03 { public: __declspec(noinline) virtual ~Rva00573F03(); private: int m_famgen;
  friend void famgenDelete(Rva00573F03 *p); };
Rva00573F03::~Rva00573F03() { m_famgen = 0; }
void famgenDelete(Rva00573F03 *p) { delete p; }
