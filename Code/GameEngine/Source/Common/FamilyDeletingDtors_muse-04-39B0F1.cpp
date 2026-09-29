// cl: /O1 /MD
// ??_GRva0039ADF3@@UAEPAXI@Z @0x0039B0F1, 28B.
// Scalar deleting dtor slot 0 of vtable 0x0081AD34; calls rowed ??1 at
// 0x0039ADF3 plus rowed delete at 0x0002FD60.

// ??_GRva0039ADF3@@UAEPAXI@Z @0x0039B0F1 present-unmatched
class Rva0039ADF3 { public: __declspec(noinline) virtual ~Rva0039ADF3(); private: int m_famgen;
  friend void famgenDelete(Rva0039ADF3 *p); };
Rva0039ADF3::~Rva0039ADF3() { m_famgen = 0; }
void famgenDelete(Rva0039ADF3 *p) { delete p; }
