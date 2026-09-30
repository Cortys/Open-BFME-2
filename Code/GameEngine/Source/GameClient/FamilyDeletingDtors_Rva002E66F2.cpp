// cl: /O1 /MD
// ??_GRva002E66F2@@UAEPAXI@Z @0x002E67CE, 28B.
// Scalar deleting dtor slot 0 of vtable 0x00804FA8; calls rowed
// ??1Rva002E66F2@@UAE@XZ at 0x002E66F2 plus rowed delete at 0x0002FD60.

class Rva002E66F2 { public: __declspec(noinline) virtual ~Rva002E66F2(); private: int m_famgen;
  friend void famgenDelete(Rva002E66F2 *p); };
Rva002E66F2::~Rva002E66F2() { m_famgen = 0; }
void famgenDelete(Rva002E66F2 *p) { delete p; }
