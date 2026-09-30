// cl: /O1 /MD
// ??_GRva002FED8D@@UAEPAXI@Z @0x002FFCE7 28B calls rowed ??1Rva002FED8D@@UAE@XZ at 0x002FEDEC then delete.
// Chain from 0x002FEDEC same 28B scalar-deleting shape as Rva003FAFB9 precedent.
// Evidence: vtable 0x00807408 slot 0; rowed dtor Rva002FED8DDtor; rowed delete 0x0002FD60.
class Rva002FED8D { public: __declspec(noinline) virtual ~Rva002FED8D(); private: int m_famgen; };
Rva002FED8D::~Rva002FED8D() { m_famgen = 0; }
void famgenDelete(Rva002FED8D *p) { delete p; }
