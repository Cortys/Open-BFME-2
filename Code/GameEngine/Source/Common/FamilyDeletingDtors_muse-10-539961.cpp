// cl: /O1 /MD
// ??_GRva00539926@@UAEPAXI@Z @0x00539961 28B
// Deleting dtor slot 0 of vtable 0x00869268; calls rowed ??1 at 0x00539926
// then rowed operator delete at 0x0002FD60.

class Rva00539926 { public: __declspec(noinline) virtual ~Rva00539926(); private: int m_famgen; };
// ??1Rva00539926@@UAE@XZ present-unmatched
Rva00539926::~Rva00539926() { m_famgen = 0; }
void famgenDelete(Rva00539926 *p) { delete p; }
