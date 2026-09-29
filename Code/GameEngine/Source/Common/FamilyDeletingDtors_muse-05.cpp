// cl: /O1 /MD
// ??_GRva00329D0E@@QAEPAXI@Z @0x00329D98
// Deleting dtor for Rva00329D0E whose ??1 is rowed at 0x00329D0E.
// Evidence: retail push esi mov esi ecx call ??1 test flag delete ret 4;
// chain lane after landing ??1Rva00329D0E.
class Rva00329D0E { public: ~Rva00329D0E(); };
void famgenDelete(Rva00329D0E *p) { delete p; }
// ??_GRva00596CDF@@UAEPAXI@Z @0x00596D7D 28B
// Deleting dtor slot 0 of vtable 0x00870AF0; calls rowed ??1Rva00596CDF@@UAE@XZ at 0x00596CDF then rowed operator delete at 0x0002FD60.
class Rva00596CDF { public: __declspec(noinline) virtual ~Rva00596CDF(); private: int m_famgen;
  friend void famgenDelete(Rva00596CDF *p); };
Rva00596CDF::~Rva00596CDF() { m_famgen = 0; }
void famgenDelete(Rva00596CDF *p) { delete p; }
// ??_GRva0059675A@@UAEPAXI@Z @0x00596AE9 28B
// Deleting dtor slot 0 of vtable 0x00870A70; calls rowed ??1Rva0059675A@@UAE@XZ at 0x0059675A then rowed operator delete at 0x0002FD60.
class Rva0059675A { public: __declspec(noinline) virtual ~Rva0059675A(); private: int m_famgen;
  friend void famgenDelete(Rva0059675A *p); };
Rva0059675A::~Rva0059675A() { m_famgen = 0; }
void famgenDelete(Rva0059675A *p) { delete p; }
