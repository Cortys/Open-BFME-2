// cl: /O1 /MD
// ??_GRva00367F8D@@UAEPAXI@Z @0x00368B35 28B; calls rowed ??1Rva00367F8D@@UAE@XZ @0x00367F8D then operator delete 0x0002FD60.
// Evidence: retail push esi/mov esi,ecx/call/test [esp+8],1 pop-ecx shape; UAE public virtual dtor so UAEPAXI; rowed dtor in Rva00367F8DDtor.cpp; vtable 0x00817768 slot0.
// ??_GRva00367F8D@@UAEPAXI@Z @0x00368B35
class Rva00367F8D { public: __declspec(noinline) virtual ~Rva00367F8D(); private: int m_famgen; };
// ??1Rva00367F8D@@UAE@XZ present-unmatched
Rva00367F8D::~Rva00367F8D() { m_famgen = 0; }
void famgenDelete(Rva00367F8D *p) { delete p; }
