// cl: /O1 /MD
// ??_GRva0022958D@@UAEPAXI@Z @0x00229571 28B calls rowed ??1Rva0022958D@@UAE@XZ at 0x0022958D then delete.
// Chain from 0x0022958D; vtable slot 0 of 0x007E73E8 proves virtual public dtor.
class Rva0022958D { public: __declspec(noinline) virtual ~Rva0022958D(); private: int m_famgen; };
Rva0022958D::~Rva0022958D() { m_famgen = 0; }
void famgenDelete(Rva0022958D *p) { delete p; }
