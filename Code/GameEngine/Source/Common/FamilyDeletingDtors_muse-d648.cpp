// cl: /O1 /MD
// ??_GRva004E3184@@UAEPAXI@Z @0x004E3797 28B
// Deleting dtor slot 0 of vtable 0x00861F28; calls rowed ??1 at 0x004E3184 then rowed operator delete at 0x0002FD60.
class Rva004E3184 { public: __declspec(noinline) virtual ~Rva004E3184(); private: int m_famgen; };
Rva004E3184::~Rva004E3184() { m_famgen = 0; }
void famgenDelete(Rva004E3184 *p) { delete p; }
