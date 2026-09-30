// cl: /O1 /MD
// ??_GRva001805E0@@UAEPAXI@Z @0x0018062D, 28B.
// Scalar deleting dtor slot 9 of vtable 0x007D4FD0; calls rowed
// ??1Rva001805E0@@UAE@XZ at 0x00180527 plus rowed delete at 0x0002FD60.

class Rva001805E0 { public: __declspec(noinline) virtual ~Rva001805E0(); private: int m_famgen;
  friend void famgenDelete(Rva001805E0 *p); };
Rva001805E0::~Rva001805E0() { m_famgen = 0; }
void famgenDelete(Rva001805E0 *p) { delete p; }
