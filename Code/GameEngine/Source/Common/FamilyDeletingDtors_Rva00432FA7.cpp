// cl: /O1 /MD
// ??_GRva00432FA7@@UAEPAXI@Z @0x0043312E 28B: scalar deleting dtor calling rowed ??1Rva00432FA7 at 0x00432FEF then delete.
// Evidence: chain lane from 0x00432FEF; vtable slot 0 of 0x0083CA30; delete row 0x0002FD60; precedent FamilyDeletingDtors_muse-04b.cpp.
class Rva00432FA7 { public: __declspec(noinline) virtual ~Rva00432FA7(); private: int m_famgen; };
Rva00432FA7::~Rva00432FA7() { m_famgen = 0; }
void famgenDelete(Rva00432FA7 *p) { delete p; }
