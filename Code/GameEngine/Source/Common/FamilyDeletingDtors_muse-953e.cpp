// cl: /O1 /MD
// ??_GRva00342157@@UAEPAXI@Z @0x00342F95 28B
// Deleting dtor slot 0 of vtable 0x008118B0; calls rowed ??1 at 0x00342157 then rowed operator delete at 0x0002FD60.
class Rva00342157 { public: __declspec(noinline) virtual ~Rva00342157(); private: int m_famgen; };
Rva00342157::~Rva00342157() { m_famgen = 0; }
void famgenDelete(Rva00342157 *p) { delete p; }
