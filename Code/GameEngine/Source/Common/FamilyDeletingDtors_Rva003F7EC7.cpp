// cl: /O1 /MD
// ??_GRva003F7EC7@@UAEPAXI@Z, RVA 0x003F845C, 28B. Chain lane: deleting dtor
// calling rowed ??1Rva003F7EC7@@UAE@XZ at 0x003F7EC7 then rowed operator
// delete 0x0002FD60; test flags, ret 4. Vtable slot 0 of 0x008372D4 proves
// virtual public dtor (UAE). Follows FamilyDeletingDtors_Rva004209CC.cpp pattern.
class Rva003F7EC7 { public: __declspec(noinline) virtual ~Rva003F7EC7(); private: int m_famgen;
  friend void famgenDelete(Rva003F7EC7 *p); };
Rva003F7EC7::~Rva003F7EC7() { m_famgen = 0; }
void famgenDelete(Rva003F7EC7 *p) { delete p; }
