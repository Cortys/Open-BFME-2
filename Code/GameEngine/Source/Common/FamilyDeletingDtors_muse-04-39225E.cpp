// cl: /O1 /MD
// ??_GRva0039225E@@UAEPAXI@Z @0x00392DA4, 28B.
// Scalar deleting dtor slot 0 of vtable 0x0081A088; calls rowed ??1 at
// 0x0039225E plus rowed delete at 0x0002FD60.

// ??_GRva0039225E@@UAEPAXI@Z @0x00392DA4 present-unmatched
class Rva0039225E { public: __declspec(noinline) virtual ~Rva0039225E(); private: int m_famgen;
  friend void famgenDelete(Rva0039225E *p); };
Rva0039225E::~Rva0039225E() { m_famgen = 0; }
void famgenDelete(Rva0039225E *p) { delete p; }
