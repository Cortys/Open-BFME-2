// cl: /O1 /MD
// ??_GRva005E16DA@@UAEPAXI@Z @0x005E184E 28B; calls rowed ??1Rva005E16DA@@UAE@XZ @0x005E16FD then delete 0x0002FD60.
// Evidence: retail push esi mov esi ecx call test flag delete ret 4 shape; UAE virtual public so UAEPAXI; chain from 0x005E16FD landing vtable 0x00877A30.
class Rva005E16DA { public: __declspec(noinline) virtual ~Rva005E16DA(); private: int m_famgen;
  friend void famgenDelete(Rva005E16DA *p); };
Rva005E16DA::~Rva005E16DA() { m_famgen = 0; }
void famgenDelete(Rva005E16DA *p) { delete p; }
