// cl: /O1 /MD
// ??_GRva00420E67@@UAEPAXI@Z @0x00421084 deleting dtor calls rowed ??1Rva00420E67@@UAE@XZ then operator delete
class Rva00420E67 { public: __declspec(noinline) virtual ~Rva00420E67(); private: int m_famgen;
  friend void famgenDelete(Rva00420E67 *p); };
Rva00420E67::~Rva00420E67() { m_famgen = 0; }
void famgenDelete(Rva00420E67 *p) { delete p; }
