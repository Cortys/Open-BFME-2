// cl: /O1 /MD
// ??_GRva0035FD0A@@UAEPAXI@Z @0x0035FF56 28B: scalar deleting dtor calling the
// rowed ??1Rva0035FD0A@@UAE@XZ at 0x0035FD0A then operator delete 0x0002FD60.
// Vtable slot 0 of 0x008166BC proves virtual public dtor (UAE). Family block
// per §4.3 (public for UAE); precedent FamilyDeletingDtors_Rva0036783F.cpp.

class Rva0035FD0A { public: __declspec(noinline) virtual ~Rva0035FD0A(); private: int m_famgen;
  friend void famgenDelete(Rva0035FD0A *p); };
Rva0035FD0A::~Rva0035FD0A() { m_famgen = 0; }
void famgenDelete(Rva0035FD0A *p) { delete p; }
