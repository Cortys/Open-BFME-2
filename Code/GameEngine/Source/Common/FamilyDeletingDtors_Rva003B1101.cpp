// cl: /O1 /MD
// ??_GRva003B1101@@UAEPAXI@Z @0x003B152A (28B):
// Deleting dtor for Rva003B1101 whose ??1 was landed at 0x003B1101.
// Public virtual (UAE) matching the rowed ??1. Chain lane after ??1.
// Evidence: vtable slot 0 of 0x0081ED18, all callees rowed.
class Rva003B1101 { public: __declspec(noinline) virtual ~Rva003B1101(); private: int m_famgen;
  friend void famgenDelete(Rva003B1101 *p); };
Rva003B1101::~Rva003B1101() { m_famgen = 0; }
void famgenDelete(Rva003B1101 *p) { delete p; }
