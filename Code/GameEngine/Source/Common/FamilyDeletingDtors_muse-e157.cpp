// cl: /O1 /MD
// ??_GRva00345CAB@@UAEPAXI@Z @0x00349FF5, 28B.
// Scalar deleting dtor slot 0 of vtable 0x00813548; calls rowed ??1 at
// 0x00345CAB plus rowed delete at 0x0002FD60.

// ??_GRva00345CAB@@UAEPAXI@Z @0x00349FF5
class Rva00345CAB { public: __declspec(noinline) virtual ~Rva00345CAB(); private: int m_famgen;
  friend void famgenDelete(Rva00345CAB *p); };
Rva00345CAB::~Rva00345CAB() { m_famgen = 0; }
void famgenDelete(Rva00345CAB *p) { delete p; }
