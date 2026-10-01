// cl: /O1 /MD
// ??_GRva00497DD6@@UAEPAXI@Z @0x00497DBA 28B
// Deleting dtor calls rowed ??1Rva00497DD6@@UAE@XZ at 0x00497DD6 then rowed operator delete at 0x0002FD60.
// Evidence: chain lane after landing 0x00497DD6; retail push esi call ??1 test flag delete ret 4.
class Rva00497DD6 { public: __declspec(noinline) virtual ~Rva00497DD6(); private: int m_famgen;
  friend void famgenDelete(Rva00497DD6 *p); };
// ??1Rva00497DD6@@UAE@XZ present-unmatched
Rva00497DD6::~Rva00497DD6() { m_famgen = 0; }
void famgenDelete(Rva00497DD6 *p) { delete p; }
