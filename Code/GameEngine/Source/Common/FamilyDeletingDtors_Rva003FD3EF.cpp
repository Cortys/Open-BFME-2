// cl: /O1 /MD
// ??_GRva003FD3EF@@UAEPAXI@Z @0x002B30AE 28B
// Deleting dtor slot 0 of vtable 0x007FE024; calls rowed ??1Rva003FD3EF@@UAE@XZ at 0x003FD3EF then rowed operator delete at 0x0002FD60.
class Rva003FD3EF { public: __declspec(noinline) virtual ~Rva003FD3EF(); private: int m_famgen; };
Rva003FD3EF::~Rva003FD3EF() { m_famgen = 0; }
void famgenDelete(Rva003FD3EF *p) { delete p; }
