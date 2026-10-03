// cl: /O1 /MD
// ??_GRva005ED152@@MAEPAXI@Z @0x005ED136 28B: deleting dtor calls rowed dtor 0x005ED152 then operator delete 0x0002FD60 on flag. Evidence: vtable slot 0 of 0x008785B8; chain from 0x005ED152.
// placeholder ??1 duplicates owner for codegen only.
class Rva005ED152 { protected: __declspec(noinline) virtual ~Rva005ED152(); private: int m_famgen;
  friend void famgenDelete(Rva005ED152 *p); };
// ??1Rva005ED152@@MAE@XZ present-unmatched
Rva005ED152::~Rva005ED152() { m_famgen = 0; }
void famgenDelete(Rva005ED152 *p) { delete p; }
