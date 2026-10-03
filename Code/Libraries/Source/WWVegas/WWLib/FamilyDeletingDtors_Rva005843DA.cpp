// cl: /O1 /MD
// ??_GRva005843DA@@UAEPAXI@Z retail 0x005844E6 28B.
// Deleting dtor slot0 of vtable 0x0086FC80 for Rva005843DA whose ??1 is at
// 0x00584502 rowed as dup alias; placeholder ~ is duplicate.
class Rva005843DA { public: __declspec(noinline) virtual ~Rva005843DA(); private: int m_famgen; friend void famgenDelete(Rva005843DA *p); };
// ??1Rva005843DA@@UAE@XZ present-unmatched
Rva005843DA::~Rva005843DA() { m_famgen = 0; }
void famgenDelete(Rva005843DA *p) { delete p; }
