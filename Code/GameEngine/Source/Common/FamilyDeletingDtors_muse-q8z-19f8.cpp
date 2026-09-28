// cl: /O1 /MD
// ??_GRva00355D66@@UAEPAXI@Z @0x00355FDD, 28B.
// Scalar deleting dtor slot 0 of vtable 0x00814E5C; calls rowed ??1 at
// 0x00355D66 plus rowed delete at 0x0002FD60.
// ??_GRva00355DC5@@UAEPAXI@Z @0x00356066, 28B.
// Scalar deleting dtor slot 0 of vtable 0x00814E74; calls rowed ??1 at
// 0x00355DC5 plus rowed delete at 0x0002FD60.

// ??_GRva00355D66@@UAEPAXI@Z @0x00355FDD
class Rva00355D66 { public: __declspec(noinline) virtual ~Rva00355D66(); private: int m_famgen;
  friend void famgenDelete(Rva00355D66 *p); };
Rva00355D66::~Rva00355D66() { m_famgen = 0; }
void famgenDelete(Rva00355D66 *p) { delete p; }

// ??_GRva00355DC5@@UAEPAXI@Z @0x00356066
class Rva00355DC5 { public: __declspec(noinline) virtual ~Rva00355DC5(); private: int m_famgen;
  friend void famgenDelete(Rva00355DC5 *p); };
Rva00355DC5::~Rva00355DC5() { m_famgen = 0; }
void famgenDelete(Rva00355DC5 *p) { delete p; }
