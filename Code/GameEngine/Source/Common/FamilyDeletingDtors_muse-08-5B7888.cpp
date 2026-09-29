// cl: /O1 /MD
// ??_GRva005B77F1@@UAEPAXI@Z @0x005B7888 28B; calls rowed ??1Rva005B77F1@@UAE@XZ @0x005B77F1 then delete 0x0002FD60.
// Evidence: vtable slot 0 of 0x00873918; retail push esi mov esi ecx call test flag delete ret 4; UAE virtual so UAEPAXI; chain from 0x005B77F1 landing.
class Rva005B77F1 { public: __declspec(noinline) virtual ~Rva005B77F1(); private: int m_famgen; };
Rva005B77F1::~Rva005B77F1() { m_famgen = 0; }
void famgenDelete(Rva005B77F1 *p) { delete p; }
