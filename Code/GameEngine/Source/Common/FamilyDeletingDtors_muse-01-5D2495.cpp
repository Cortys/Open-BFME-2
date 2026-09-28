// cl: /O1 /MD
// ??_GRva005D242F@@UAEPAXI@Z @0x005D2495, 28B.
// Scalar deleting dtor slot 0 of vtable 0x008757D8; calls rowed ??1 at
// 0x005D242F plus rowed delete at 0x0002FD60.

// ??_GRva005D242F@@UAEPAXI@Z @0x005D2495
class Rva005D242F { public: __declspec(noinline) virtual ~Rva005D242F(); private: int m_famgen;
  friend void famgenDelete(Rva005D242F *p); };
Rva005D242F::~Rva005D242F() { m_famgen = 0; }
void famgenDelete(Rva005D242F *p) { delete p; }
