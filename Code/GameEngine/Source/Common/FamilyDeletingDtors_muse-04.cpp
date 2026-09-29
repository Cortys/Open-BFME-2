// cl: /O1 /MD
// ??_GRva00573F03@@UAEPAXI@Z @0x00574013 28B
// Deleting dtor slot 0 of vtable 0x0086E2C8; calls rowed ??1Rva00573F03@@UAE@XZ at 0x00573F03 then rowed operator delete at 0x0002FD60.
class Rva00573F03 { public: __declspec(noinline) virtual ~Rva00573F03(); private: int m_famgen;
  friend void famgenDelete(Rva00573F03 *p); };
Rva00573F03::~Rva00573F03() { m_famgen = 0; }
void famgenDelete(Rva00573F03 *p) { delete p; }
// ??_GRva0034149B@@UAEPAXI@Z @0x00342E58 28B
// Deleting dtor slot 0 of vtable 0x008112C0; calls rowed ??1Rva0034149B@@UAE@XZ at 0x0034149B then rowed operator delete at 0x0002FD60.
class Rva0034149B { public: __declspec(noinline) virtual ~Rva0034149B(); private: int m_famgen;
  friend void famgenDelete(Rva0034149B *p); };
Rva0034149B::~Rva0034149B() { m_famgen = 0; }
void famgenDelete(Rva0034149B *p) { delete p; }
// ??_GRva00341796@@UAEPAXI@Z @0x00342E90 28B
// Deleting dtor slot 0 of vtable 0x008113B8; calls rowed ??1Rva00341796@@UAE@XZ at 0x00341796 then rowed operator delete at 0x0002FD60.
class Rva00341796 { public: __declspec(noinline) virtual ~Rva00341796(); private: int m_famgen;
  friend void famgenDelete(Rva00341796 *p); };
Rva00341796::~Rva00341796() { m_famgen = 0; }
void famgenDelete(Rva00341796 *p) { delete p; }
// ??_GRva00341F99@@UAEPAXI@Z @0x00342F79 28B
// Deleting dtor slot 0 of vtable 0x00811850; calls rowed ??1Rva00341F99@@UAE@XZ at 0x00341F99 then rowed operator delete at 0x0002FD60.
class Rva00341F99 { public: __declspec(noinline) virtual ~Rva00341F99(); private: int m_famgen;
  friend void famgenDelete(Rva00341F99 *p); };
Rva00341F99::~Rva00341F99() { m_famgen = 0; }
void famgenDelete(Rva00341F99 *p) { delete p; }
