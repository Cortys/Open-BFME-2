// cl: /O1 /MD

// ??_GRva004104C9@@QAEPAXI@Z @0x004105A8
class Rva004104C9 { public: __declspec(noinline) ~Rva004104C9(); private: int m_famgen;
  friend void famgenDelete(Rva004104C9 *p); };
Rva004104C9::~Rva004104C9() { m_famgen = 0; }
void famgenDelete(Rva004104C9 *p) { delete p; }

// ??_GRva004444D2@@UAEPAXI@Z @0x00444509
// Deleting dtor slot 0 of vtable 0x0083E020; calls rowed ??1Rva004444D2@@UAE@XZ at 0x004444D2 then rowed operator delete at 0x0002FD60.
class Rva004444D2 { public: __declspec(noinline) virtual ~Rva004444D2(); private: int m_famgen;
  friend void famgenDelete(Rva004444D2 *p); };
Rva004444D2::~Rva004444D2() { m_famgen = 0; }
void famgenDelete(Rva004444D2 *p) { delete p; }
