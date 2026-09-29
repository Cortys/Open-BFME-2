// cl: /O1 /MD
// ??_GRva0029B816@@UAEPAXI@Z @0x0029E1EF 28B
// Deleting dtor slot 0 of vtable 0x007FD028; calls rowed ??1 at 0x0029B816 then rowed operator delete at 0x0002FD60.
class Rva0029B816 { public: __declspec(noinline) virtual ~Rva0029B816(); private: int m_famgen; };
Rva0029B816::~Rva0029B816() { m_famgen = 0; }
void famgenDelete(Rva0029B816 *p) { delete p; }
