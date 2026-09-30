// cl: /O1 /MD
// ??_GRva0054080A@@UAEPAXI@Z @0x00540A6C 28B deleting dtor.
// Retail calls ??1Rva0054080A@@UAE@XZ then operator delete on flag.
// Evidence: chain lane; slot 6 of 0x008694F8; needs ??1 rowed.

// ??_GRva0054080A@@UAEPAXI@Z @0x00540a6c
class Rva0054080A { public: __declspec(noinline) virtual ~Rva0054080A(); private: int m_famgen;
  friend void famgenDelete(Rva0054080A *p); };
Rva0054080A::~Rva0054080A() { m_famgen = 0; }
void famgenDelete(Rva0054080A *p) { delete p; }
