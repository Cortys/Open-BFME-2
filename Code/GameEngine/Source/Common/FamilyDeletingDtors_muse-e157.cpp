// cl: /O1 /MD
// ??_GRva00345CAB@@UAEPAXI@Z @0x00349FF5, 28B.
// Scalar deleting dtor slot 0 of vtable 0x00813548; calls rowed ??1 at
// 0x00345CAB plus rowed delete at 0x0002FD60.

// ??_GRva00345CAB@@UAEPAXI@Z @0x00349FF5
class Rva00345CAB { public: __declspec(noinline) virtual ~Rva00345CAB(); private: int m_famgen;
  friend void famgenDelete(Rva00345CAB *p); };
Rva00345CAB::~Rva00345CAB() { m_famgen = 0; }
void famgenDelete(Rva00345CAB *p) { delete p; }

// ??_GRva0033FF2B@@UAEPAXI@Z @0x0034280A, 28B.
// Scalar deleting dtor slot 0 of vtable 0x00810DE8; calls rowed ??1 at
// 0x0033FF2B plus rowed delete at 0x0002FD60.

// ??_GRva0033FF2B@@UAEPAXI@Z @0x0034280A
class Rva0033FF2B { public: __declspec(noinline) virtual ~Rva0033FF2B(); private: int m_famgen;
  friend void famgenDelete(Rva0033FF2B *p); };
Rva0033FF2B::~Rva0033FF2B() { m_famgen = 0; }
void famgenDelete(Rva0033FF2B *p) { delete p; }

// ??_GRva00340BDC@@UAEPAXI@Z @0x00342B6B, 28B.
// Scalar deleting dtor slot 0 of vtable 0x00812150; calls rowed ??1 at
// 0x00340BDC plus rowed delete at 0x0002FD60.

// ??_GRva00340BDC@@UAEPAXI@Z @0x00342B6B
class Rva00340BDC { public: __declspec(noinline) virtual ~Rva00340BDC(); private: int m_famgen;
  friend void famgenDelete(Rva00340BDC *p); };
Rva00340BDC::~Rva00340BDC() { m_famgen = 0; }
void famgenDelete(Rva00340BDC *p) { delete p; }
