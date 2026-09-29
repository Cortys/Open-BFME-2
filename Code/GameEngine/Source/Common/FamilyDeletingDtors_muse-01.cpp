// cl: /O1 /MD
// ??_GRva00131BE5@@UAEPAXI@Z @0x001320B4 (28B): scalar deleting dtor over ??1Rva00131BE5@@UAE@XZ @0x00131BE5; vtable slot 9 of 0x007D25D8 proves virtual public (UAE); rowed operator delete @0x0002FD60.
class Rva00131BE5 { public: __declspec(noinline) virtual ~Rva00131BE5(); private: int m_famgen; };
Rva00131BE5::~Rva00131BE5() { m_famgen = 0; }
void famgenDelete(Rva00131BE5 *p) { delete p; }
