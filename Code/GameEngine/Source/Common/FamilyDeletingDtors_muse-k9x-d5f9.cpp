// cl: /O1 /MD
// ??_GRva0033FC42@@UAEPAXI@Z @0x00343CBA 28B
// Deleting dtor slot 0 of vtable 0x00811DB0; calls rowed ??1 at 0x0033FC42 then rowed operator delete at 0x0002FD60.
class Rva0033FC42 { public: __declspec(noinline) virtual ~Rva0033FC42(); private: int m_famgen; };
Rva0033FC42::~Rva0033FC42() { m_famgen = 0; }
void famgenDelete(Rva0033FC42 *p) { delete p; }
// ??_GRva0033FB20@@UAEPAXI@Z @0x003435DF 28B
// Deleting dtor slot 0 of vtable 0x00811B18; calls rowed ??1 at 0x0033FB20 then rowed operator delete at 0x0002FD60.
class Rva0033FB20 { public: __declspec(noinline) virtual ~Rva0033FB20(); private: int m_famgen; };
Rva0033FB20::~Rva0033FB20() { m_famgen = 0; }
void famgenDelete(Rva0033FB20 *p) { delete p; }
// ??_GRva0033FBB7@@UAEPAXI@Z @0x00343BAD 28B
// Deleting dtor slot 0 of vtable 0x00811CF0; calls rowed ??1 at 0x0033FBB7 then rowed operator delete at 0x0002FD60.
class Rva0033FBB7 { public: __declspec(noinline) virtual ~Rva0033FBB7(); private: int m_famgen; };
Rva0033FBB7::~Rva0033FBB7() { m_famgen = 0; }
void famgenDelete(Rva0033FBB7 *p) { delete p; }
