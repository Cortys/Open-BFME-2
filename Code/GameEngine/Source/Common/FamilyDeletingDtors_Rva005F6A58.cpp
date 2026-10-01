// cl: /O1 /MD
// ??_GRva005F6A58@@UAEPAXI@Z, RVA 0x005F6B3C, 28B. Chain lane: deleting dtor
// calling rowed ??1Rva005F6A58@@UAE@XZ at 0x005F6A58 then rowed operator
// delete 0x0002FD60; test flags, ret 4. Virtual public dtor (UAE).
// Follows FamilyDeletingDtors_Rva005F6AB0.cpp pattern.
class Rva005F6A58 { public: __declspec(noinline) virtual ~Rva005F6A58(); private: int m_famgen;
  friend void famgenDelete(Rva005F6A58 *p); };
Rva005F6A58::~Rva005F6A58() { m_famgen = 0; }
void famgenDelete(Rva005F6A58 *p) { delete p; }
