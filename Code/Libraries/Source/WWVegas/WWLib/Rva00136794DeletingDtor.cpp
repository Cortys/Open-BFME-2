// cl: /O1 /MD
// ??_GRva00136794@@UAEPAXI@Z @0x00136F3F 28B
// Scalar deleting dtor, vtable slot 9 class (vtable 0x007D2970, same class as
// rowed ??1Rva00136794@@UAE@XZ at 0x00136AA5); calls that rowed dtor plus
// operator delete ??3@YAXPAX@Z at 0x0002FD60. Evidence: retail call bytes plus
// ??1 row plus vtable slot, pattern follows Rva004E16D9RecordDeletingDtor.cpp.
class Rva00136794 { public: __declspec(noinline) virtual ~Rva00136794(); private: int m_famgen;
  friend void famgenDelete(Rva00136794 *p); };
Rva00136794::~Rva00136794() { m_famgen = 0; }
void famgenDelete(Rva00136794 *p) { delete p; }
