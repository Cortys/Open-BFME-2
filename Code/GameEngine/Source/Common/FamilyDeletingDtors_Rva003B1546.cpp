// cl: /O1 /MD
// ??_GRva003B1546@@UAEPAXI@Z @0x003B17F3 (28B):
// Deleting dtor for Rva003B1546 whose ??1 was landed at 0x003B1546.
// Public virtual (UAE) matching the rowed ??1. Chain lane after ??1.
// Evidence: vtable slot 0 of 0x0081ED1C, all callees rowed.
class Rva003B1546 { public: __declspec(noinline) virtual ~Rva003B1546(); private: int m_famgen;
  friend void famgenDelete(Rva003B1546 *p); };
Rva003B1546::~Rva003B1546() { m_famgen = 0; }
void famgenDelete(Rva003B1546 *p) { delete p; }
