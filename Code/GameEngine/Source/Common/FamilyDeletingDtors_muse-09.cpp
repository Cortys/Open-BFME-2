// cl: /O1 /MD
// ??_GRva005DE9E3@@UAEPAXI@Z, RVA 0x005DF144, 28B. Chain lane: deleting dtor
// calling rowed ??1Rva005DE9E3@@UAE@XZ at 0x005DE9E3 then rowed operator
// delete 0x0002FD60; test flags, ret 4. Vtable slot 0 of 0x00876AFC proves
// virtual public dtor (UAE). Follows FamilyDeletingDtors_0021C7e.cpp pattern.

class Rva005DE9E3 { public: __declspec(noinline) virtual ~Rva005DE9E3(); private: int m_famgen;
  friend void famgenDelete(Rva005DE9E3 *p); };
Rva005DE9E3::~Rva005DE9E3() { m_famgen = 0; }
void famgenDelete(Rva005DE9E3 *p) { delete p; }

// ??_GRva005DD1EA@@UAEPAXI@Z, RVA 0x005DD5ED, 28B. Chain lane: deleting dtor
// calling rowed ??1Rva005DD1EA@@UAE@XZ at 0x005DD1EA then rowed operator
// delete 0x0002FD60; test flags, ret 4. Vtable slot 0 of 0x008769B0 proves
// virtual public dtor (UAE). Same pattern as above.

class Rva005DD1EA { public: __declspec(noinline) virtual ~Rva005DD1EA(); private: int m_famgen;
  friend void famgenDelete(Rva005DD1EA *p); };
Rva005DD1EA::~Rva005DD1EA() { m_famgen = 0; }
void famgenDelete(Rva005DD1EA *p) { delete p; }

// ??_GRva005C1A36@@UAEPAXI@Z, RVA 0x005C1A9E, 28B. Chain lane: deleting dtor
// calling rowed ??1Rva005C1A36@@UAE@XZ at 0x005C1A36 then rowed operator
// delete 0x0002FD60; test flags, ret 4. Vtable slot 0 of 0x008743DC proves
// virtual public dtor (UAE). Same pattern as above.

class Rva005C1A36 { public: __declspec(noinline) virtual ~Rva005C1A36(); private: int m_famgen;
  friend void famgenDelete(Rva005C1A36 *p); };
Rva005C1A36::~Rva005C1A36() { m_famgen = 0; }
void famgenDelete(Rva005C1A36 *p) { delete p; }

// ??_GRva005C18F0@@UAEPAXI@Z, RVA 0x005C18D4, 28B. Chain lane: deleting dtor
// calling rowed ??1Rva005C18F0@@UAE@XZ at 0x005C18F0 then rowed operator
// delete 0x0002FD60; test flags, ret 4. Vtable slot 0 of 0x008743C4 proves
// virtual public dtor (UAE). Same pattern as above.

class Rva005C18F0 { public: __declspec(noinline) virtual ~Rva005C18F0(); private: int m_famgen;
  friend void famgenDelete(Rva005C18F0 *p); };
Rva005C18F0::~Rva005C18F0() { m_famgen = 0; }
void famgenDelete(Rva005C18F0 *p) { delete p; }
