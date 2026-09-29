// cl: /O1 /MD
// ??_GRva003FD4DA@@UAEPAXI@Z @0x002B5972 28B
// Deleting dtor slot 0 of vtable 0x007FE1B0; calls rowed ??1Rva003FD4DA@@UAE@XZ at 0x003FD4DA then rowed operator delete at 0x0002FD60.
class Rva003FD4DA { public: __declspec(noinline) virtual ~Rva003FD4DA(); private: int m_famgen; };
Rva003FD4DA::~Rva003FD4DA() { m_famgen = 0; }
void famgenDelete(Rva003FD4DA *p) { delete p; }
