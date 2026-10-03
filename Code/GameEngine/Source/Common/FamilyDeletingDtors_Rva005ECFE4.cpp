// cl: /O1 /MD
// ??_GRva005ECFE4@@MAEPAXI@Z @0x005ECFC8 28B: deleting dtor calls rowed dtor 0x005ECFE4 then operator delete 0x0002FD60 on flag. Evidence: vtable slot 0 of 0x008785B4; chain from 0x005ECFE4.
// placeholder ??1 duplicates owner for codegen only.
class Rva005ECFE4 { protected: __declspec(noinline) virtual ~Rva005ECFE4(); private: int m_famgen;
  friend void famgenDelete(Rva005ECFE4 *p); };
// ??1Rva005ECFE4@@MAE@XZ present-unmatched
Rva005ECFE4::~Rva005ECFE4() { m_famgen = 0; }
void famgenDelete(Rva005ECFE4 *p) { delete p; }
