// cl: /O1 /MD
// ??_GRva004978A3@@UAEPAXI@Z @0x00497FD7 28B
// Deleting dtor slot 0 of vtable 0x0084FBAC; calls rowed ??1Rva004978A3@@UAE@XZ at 0x004978A3 then rowed operator delete at 0x0002FD60.
// Evidence: chain lane after landing 0x004978A3; retail push esi call ??1 test flag delete ret 4.
class Rva004978A3 { public: __declspec(noinline) virtual ~Rva004978A3(); private: int m_famgen;
  friend void famgenDelete(Rva004978A3 *p); };
// ??1Rva004978A3@@UAE@XZ present-unmatched
Rva004978A3::~Rva004978A3() { m_famgen = 0; }
void famgenDelete(Rva004978A3 *p) { delete p; }
