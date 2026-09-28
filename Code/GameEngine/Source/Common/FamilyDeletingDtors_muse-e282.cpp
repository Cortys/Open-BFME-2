// cl: /O1 /MD
// ??_GRva007401F6@@UAEPAXI@Z @0x00740226, 28B.
// Scalar deleting dtor calling rowed ??1 at 0x007401F6 plus rowed delete at 0x0002FD60.
// ??_GRva007401F6@@UAEPAXI@Z @0x00740226
class Rva007401F6 { public: __declspec(noinline) virtual ~Rva007401F6(); private: int m_famgen;
  friend void famgenDelete(Rva007401F6 *p); };
Rva007401F6::~Rva007401F6() { m_famgen = 0; }
void famgenDelete(Rva007401F6 *p) { delete p; }
// ??_GRva00740242@@UAEPAXI@Z @0x0074058D, 28B.
// Scalar deleting dtor calling rowed ??1 at 0x00740242 plus rowed delete at 0x0002FD60.
// ??_GRva00740242@@UAEPAXI@Z @0x0074058D
class Rva00740242 { public: __declspec(noinline) virtual ~Rva00740242(); private: int m_famgen;
  friend void famgenDelete(Rva00740242 *p); };
Rva00740242::~Rva00740242() { m_famgen = 0; }
void famgenDelete(Rva00740242 *p) { delete p; }
