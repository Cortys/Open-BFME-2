// cl: /O1 /MD
// ??_GRva002E1F42@@UAEPAXI@Z @0x002E21B5 28B calls rowed ??1Rva002E1F42@@UAE@XZ at 0x002E1F42 then delete.
// Chain from 0x002E1F42 same 28B scalar-deleting shape as muse-11 precedent.
class Rva002E1F42 { public: __declspec(noinline) virtual ~Rva002E1F42(); private: int m_famgen;
  friend void famgenDelete(Rva002E1F42 *p); };
Rva002E1F42::~Rva002E1F42() { m_famgen = 0; }
void famgenDelete(Rva002E1F42 *p) { delete p; }
