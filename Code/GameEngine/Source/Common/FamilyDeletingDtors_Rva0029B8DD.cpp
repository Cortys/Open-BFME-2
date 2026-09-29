// cl: /O1 /MD
// ??_GRva0029B8DD@@UAEPAXI@Z @0x0029B8C1 28B
// Deleting dtor slot 0 of vtable 0x007FD02C; calls rowed ??1 at 0x0029B8DD then rowed operator delete at 0x0002FD60.
class Rva0029B8DD { public: __declspec(noinline) virtual ~Rva0029B8DD(); private: int m_famgen; };
Rva0029B8DD::~Rva0029B8DD() { m_famgen = 0; }
void famgenDelete(Rva0029B8DD *p) { delete p; }
