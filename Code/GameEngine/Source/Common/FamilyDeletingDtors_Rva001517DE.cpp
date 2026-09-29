// cl: /O1 /MD
//
// ??_GRva001517DE@@UAEPAXI@Z, retail 0x00151896, 28 bytes. Deleting dtor for
// Rva001517DE (vtable 0x007D3AA8 slot 0): calls rowed ??1Rva001517DE 136B at
// 0x001517DE then operator delete 0x0002FD60 on flag. Chain from 0x001517DE.
// Public virtual (UAE) like Rva00151632 twin at 0x00151717.

// ??_GRva001517DE@@UAEPAXI@Z @0x151896
class Rva001517DE { public: __declspec(noinline) virtual ~Rva001517DE(); private: int m_famgen; };
Rva001517DE::~Rva001517DE() { m_famgen = 0; }
void famgenDelete(Rva001517DE *p) { delete p; }
