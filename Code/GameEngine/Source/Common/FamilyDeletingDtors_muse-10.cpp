// cl: /O1 /MD
// ??_GRva002AC340@@MAEPAXI@Z @0x002AC3A2 28B
// Deleting dtor slot 0 of vtable 0x007FDD6C; calls rowed ??1Rva002AC340@@MAE@XZ at 0x002AC366 then rowed operator delete at 0x0002FD60.
class Rva002AC340 { protected: __declspec(noinline) virtual ~Rva002AC340(); private: int m_famgen;
  friend void famgenDelete(Rva002AC340 *p); };
Rva002AC340::~Rva002AC340() { m_famgen = 0; }
void famgenDelete(Rva002AC340 *p) { delete p; }

// ??_GRva00517397@@UAEPAXI@Z @0x0051737B 28B
// Deleting dtor calls rowed ??1Rva00517397@@UAE@XZ at 0x00517397 then rowed operator delete at 0x0002FD60.
class Rva00517397 { public: __declspec(noinline) virtual ~Rva00517397(); private: int m_famgen;
  friend void famgenDelete(Rva00517397 *p); };
Rva00517397::~Rva00517397() { m_famgen = 0; }
void famgenDelete(Rva00517397 *p) { delete p; }

// ??_GRva00220CD4@@UAEPAXI@Z @0x00220F71 28B
// Deleting dtor slot 0 of vtable 0x007E6A84; calls rowed ??1Rva00220CD4@@UAE@XZ at 0x00220CD4 then rowed operator delete at 0x0002FD60.
class Rva00220CD4 { public: __declspec(noinline) virtual ~Rva00220CD4(); private: int m_famgen;
  friend void famgenDelete(Rva00220CD4 *p); };
Rva00220CD4::~Rva00220CD4() { m_famgen = 0; }
void famgenDelete(Rva00220CD4 *p) { delete p; }
