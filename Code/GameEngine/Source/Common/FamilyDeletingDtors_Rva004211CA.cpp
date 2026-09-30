// cl: /O1 /MD
// ??_GRva004211CA@@UAEPAXI@Z @ 0x00421226 28B; calls rowed ??1Rva004211CA@@UAE@XZ @0x004211CA then delete 0x0002FD60.
// Evidence: chain from 0x004211CA landing; vtable slot 0 of 0x0083BDFC; retail push esi mov esi ecx call test flag delete ret 4 shape; UAE public virtual.
class Rva004211CA { public: __declspec(noinline) virtual ~Rva004211CA(); private: int m_famgen; };
Rva004211CA::~Rva004211CA() { m_famgen = 0; }
void famgenDelete(Rva004211CA *p) { delete p; }
