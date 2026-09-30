// cl: /O1 /MD
// ??_GRva0020D583@@UAEPAXI@Z @0x0020D567 28B: scalar deleting dtor calling the
// rowed ??1Rva0020D583 0x0020D583 then operator delete. Family block
// per §4.3 (public for UAE). Evidence: vtable slot 0 of 0x007E3F98; chain from landed 0x0020D583.

// ??_GRva0020D583@@UAEPAXI@Z @0x0020d567
class Rva0020D583 { public: __declspec(noinline) virtual ~Rva0020D583(); private: int m_famgen;
  friend void famgenDelete(Rva0020D583 *p); };
Rva0020D583::~Rva0020D583() { m_famgen = 0; }
void famgenDelete(Rva0020D583 *p) { delete p; }
