// cl: /O1 /MD
// ??_GRva0050B6ED@@UAEPAXI@Z @0x0050B6D1 28B
// Deleting dtor slot 0 of vtable 0x00864D80; calls rowed ??1 at 0x0050B6ED then rowed operator delete at 0x0002FD60.
class Rva0050B6ED { public: __declspec(noinline) virtual ~Rva0050B6ED(); private: int m_famgen; };
Rva0050B6ED::~Rva0050B6ED() { m_famgen = 0; }
void famgenDelete(Rva0050B6ED *p) { delete p; }
