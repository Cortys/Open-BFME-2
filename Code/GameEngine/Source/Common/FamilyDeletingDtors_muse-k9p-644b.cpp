// cl: /O1 /MD
// ??_GWeapon@@MAEPAXI@Z @0x002CCE37
// Deleting dtor slot 0 of vtable 0x0080214C; calls the rowed ??1 at 0x002CC39E.
class Weapon { protected: __declspec(noinline) virtual ~Weapon(); private: int m_famgen;
  friend void famgenDelete(Weapon *p); };
Weapon::~Weapon() { m_famgen = 0; }
void famgenDelete(Weapon *p) { delete p; }
