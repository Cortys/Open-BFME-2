// cl: /O1 /MD
//
// ??_GRva002D3573@@UAEPAXI@Z retail 0x002D40D8 28B. Scalar deleting dtor for
// Rva002D3573 whose ??1 is rowed at 0x002D3573 with vtable 0x00802AA8.
// Evidence: vtable slot 0 of 0x00802AA8 plus call to ??1Rva002D3573 plus
// operator delete 0x0002FD60 with test-je shape per §4.3.

// ??_GRva002D3573@@UAEPAXI@Z @0x002D40D8
class Rva002D3573 { public: __declspec(noinline) virtual ~Rva002D3573(); private: int m_famgen;
  friend void famgenDelete(Rva002D3573 *p); };
Rva002D3573::~Rva002D3573() { m_famgen = 0; }
void famgenDelete(Rva002D3573 *p) { delete p; }
