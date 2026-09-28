// cl: /O1 /MD
// ??_GRva0033FC42@@UAEPAXI@Z @0x00343CBA 28B
// Deleting dtor slot 0 of vtable 0x00811DB0; calls rowed ??1 at 0x0033FC42 then rowed operator delete at 0x0002FD60.
class Rva0033FC42 { public: __declspec(noinline) virtual ~Rva0033FC42(); private: int m_famgen; };
Rva0033FC42::~Rva0033FC42() { m_famgen = 0; }
void famgenDelete(Rva0033FC42 *p) { delete p; }
