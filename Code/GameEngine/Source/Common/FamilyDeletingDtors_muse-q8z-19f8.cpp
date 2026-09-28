// cl: /O1 /MD
// ??_GRva00355D66@@UAEPAXI@Z @0x00355FDD, 28B.
// Scalar deleting dtor slot 0 of vtable 0x00814E5C; calls rowed ??1 at
// 0x00355D66 plus rowed delete at 0x0002FD60.
// ??_GRva00355DC5@@UAEPAXI@Z @0x00356066, 28B.
// Scalar deleting dtor slot 0 of vtable 0x00814E74; calls rowed ??1 at
// 0x00355DC5 plus rowed delete at 0x0002FD60.
// ??_GRva00355F3E@@UAEPAXI@Z @0x003563F7, 28B.
// Scalar deleting dtor slot 0 of vtable 0x00814E8C; calls rowed ??1 at
// 0x00355F3E plus rowed delete at 0x0002FD60.
// ??_GRva003563A7@@UAEPAXI@Z @0x00356AFA, 28B.
// Scalar deleting dtor slot 0 of vtable 0x00814ED4; calls rowed ??1 at
// 0x003563A7 plus rowed delete at 0x0002FD60.

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

// ??_GRva00355F3E@@UAEPAXI@Z @0x003563F7
class Rva00355F3E { public: __declspec(noinline) virtual ~Rva00355F3E(); private: int m_famgen;
  friend void famgenDelete(Rva00355F3E *p); };
Rva00355F3E::~Rva00355F3E() { m_famgen = 0; }
void famgenDelete(Rva00355F3E *p) { delete p; }

// ??_GRva003563A7@@UAEPAXI@Z @0x00356AFA
class Rva003563A7 { public: __declspec(noinline) virtual ~Rva003563A7(); private: int m_famgen;
  friend void famgenDelete(Rva003563A7 *p); };
Rva003563A7::~Rva003563A7() { m_famgen = 0; }
void famgenDelete(Rva003563A7 *p) { delete p; }
