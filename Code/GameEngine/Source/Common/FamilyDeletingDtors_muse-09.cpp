// cl: /O1 /MD
// ??_GRva005DE9E3@@UAEPAXI@Z, RVA 0x005DF144, 28B. Chain lane: deleting dtor
// calling rowed ??1Rva005DE9E3@@UAE@XZ at 0x005DE9E3 then rowed operator
// delete 0x0002FD60; test flags, ret 4. Vtable slot 0 of 0x00876AFC proves
// virtual public dtor (UAE). Follows FamilyDeletingDtors_0021C7e.cpp pattern.

class Rva005DE9E3 { public: __declspec(noinline) virtual ~Rva005DE9E3(); private: int m_famgen;
  friend void famgenDelete(Rva005DE9E3 *p); };
Rva005DE9E3::~Rva005DE9E3() { m_famgen = 0; }
void famgenDelete(Rva005DE9E3 *p) { delete p; }
