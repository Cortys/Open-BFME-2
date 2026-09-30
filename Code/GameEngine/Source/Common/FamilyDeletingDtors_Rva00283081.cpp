// cl: /O1 /MD
// ??_GRva00283081@@UAEPAXI@Z @0x00283246 28B: scalar deleting dtor calling the
// rowed ??1Rva00283081 0x00283081 then operator delete. Family block
// per §4.3 (public for UAE).

class Rva00283081 { public: __declspec(noinline) virtual ~Rva00283081(); private: int m_famgen;
  friend void famgenDelete(Rva00283081 *p); };
Rva00283081::~Rva00283081() { m_famgen = 0; }
void famgenDelete(Rva00283081 *p) { delete p; }
