// cl: /O1 /MD
// ??_GRva005C3549@@UAEPAXI@Z @0x005C367B, 28B.
// Scalar deleting dtor slot 0 of vtable 0x00874478; calls rowed ??1 at
// 0x005C3549 plus rowed delete at 0x0002FD60.

// ??_GRva005C3549@@UAEPAXI@Z @0x005C367B present-unmatched
class Rva005C3549 { public: __declspec(noinline) virtual ~Rva005C3549(); private: int m_famgen;
  friend void famgenDelete(Rva005C3549 *p); };
Rva005C3549::~Rva005C3549() { m_famgen = 0; }
void famgenDelete(Rva005C3549 *p) { delete p; }
