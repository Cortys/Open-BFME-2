// cl: /O1 /MD
// ??_GRva001EE3DE@@UAEPAXI@Z @0x001EEFB6 28B
// Deleting dtor slot 0 of vtable 0x00BE0358; calls pinned ??1Rva001EE3DE@@UAE@XZ at 0x001EE3DE then rowed operator delete at 0x0002FD60.
class Rva001EE3DE { public: __declspec(noinline) virtual ~Rva001EE3DE(); private: int m_famgen; };
// ??1Rva001EE3DE@@UAE@XZ present-unmatched
Rva001EE3DE::~Rva001EE3DE() { m_famgen = 0; }
void famgenDelete(Rva001EE3DE *p) { delete p; }
