// cl: /O1 /MD
// ??_GRva0036783F@@UAEPAXI@Z @0x003689A8 28B: scalar deleting dtor calling the
// rowed ??1Rva0036783F@@UAE@XZ at 0x0036783F then operator delete 0x0002FD60.
// Vtable slot 0 of 0x00817548 proves virtual public dtor (UAE). Family block
// per §4.3 (public for UAE); precedent FamilyDeletingDtors_Rva00205224.cpp.

// ??_GRva0036783F@@UAEPAXI@Z @0x003689A8 present-unmatched
class Rva0036783F { public: __declspec(noinline) virtual ~Rva0036783F(); private: int m_famgen;
  friend void famgenDelete(Rva0036783F *p); };
Rva0036783F::~Rva0036783F() { m_famgen = 0; }
void famgenDelete(Rva0036783F *p) { delete p; }
