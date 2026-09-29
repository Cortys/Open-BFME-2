// cl: /O1 /MD
// ??_GRva0039AD56@@UAEPAXI@Z @0x0039AF5A, 28B.
// Scalar deleting dtor slot 0 of vtable 0x0081AD20; calls rowed ??1 at
// 0x0039AD56 plus rowed delete at 0x0002FD60.

// ??_GRva0039AD56@@UAEPAXI@Z @0x0039AF5A present-unmatched
class Rva0039AD56 { public: __declspec(noinline) virtual ~Rva0039AD56(); private: int m_famgen;
  friend void famgenDelete(Rva0039AD56 *p); };
Rva0039AD56::~Rva0039AD56() { m_famgen = 0; }
void famgenDelete(Rva0039AD56 *p) { delete p; }
