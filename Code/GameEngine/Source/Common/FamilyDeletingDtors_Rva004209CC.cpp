// cl: /O1 /MD
// ??_GRva004209CC@@UAEPAXI@Z, RVA 0x00420A0D, 28B. Chain lane: deleting dtor
// calling rowed ??1Rva004209CC@@UAE@XZ at 0x004209CC then rowed operator
// delete 0x0002FD60; test flags, ret 4. Vtable slot 0 of 0x0083BD40 proves
// virtual public dtor (UAE). Follows FamilyDeletingDtors_muse-09.cpp pattern.

class Rva004209CC { public: __declspec(noinline) virtual ~Rva004209CC(); private: int m_famgen;
  friend void famgenDelete(Rva004209CC *p); };
Rva004209CC::~Rva004209CC() { m_famgen = 0; }
void famgenDelete(Rva004209CC *p) { delete p; }
