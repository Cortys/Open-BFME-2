// cl: /O1 /MD
// ??_GRva00342228@@UAEPAXI@Z @0x00342FB1 28B
// Deleting dtor slot 0 of vtable 0x00811900; calls rowed ??1 at 0x00342228 then rowed operator delete at 0x0002FD60.
class Rva00342228 { public: __declspec(noinline) virtual ~Rva00342228(); private: int m_famgen; };
Rva00342228::~Rva00342228() { m_famgen = 0; }
void famgenDelete(Rva00342228 *p) { delete p; }
