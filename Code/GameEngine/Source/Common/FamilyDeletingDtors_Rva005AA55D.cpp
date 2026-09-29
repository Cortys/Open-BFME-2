// cl: /O1 /MD
// ??_GRva005AA55D@@UAEPAXI@Z @0x005AA62B 28B: scalar deleting dtor, slot 0 of
// vtable 0x00871EB0; calls rowed ??1Rva005AA55D@@UAE@XZ at 0x005AA55D plus
// rowed operator delete at 0x0002FD60. Chain from just-landed 0x005AA55D.

// ??_GRva005AA55D@@UAEPAXI@Z @0x005AA62B present-unmatched
class Rva005AA55D { public: __declspec(noinline) virtual ~Rva005AA55D(); private: int m_famgen;
  friend void famgenDelete(Rva005AA55D *p); };
Rva005AA55D::~Rva005AA55D() { m_famgen = 0; }
void famgenDelete(Rva005AA55D *p) { delete p; }
