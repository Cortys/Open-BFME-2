// cl: /O1 /MD
// ??_GRva003FD789@@UAEPAXI@Z @0x003FD82D 28B
// Deleting dtor slot 0 of vtable 0x00837D78; calls rowed ??1Rva003FD789@@UAE@XZ at 0x003FD789 then rowed operator delete at 0x0002FD60.
class Rva003FD789 { public: __declspec(noinline) virtual ~Rva003FD789(); private: int m_famgen; };
Rva003FD789::~Rva003FD789() { m_famgen = 0; }
void famgenDelete(Rva003FD789 *p) { delete p; }
