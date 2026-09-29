// cl: /O1 /MD
// ??_GRva004D62A9@@UAEPAXI@Z @0x004D6AD5 28B calls rowed ??1Rva004D62A9@@UAE@XZ at 0x004D62F7 then delete.
// Chain from just-landed 0x004D62F7 same 28B scalar-deleting shape as Rva00509D4C precedent.
class Rva004D62A9 { public: __declspec(noinline) virtual ~Rva004D62A9(); private: int m_famgen; };
// ??1Rva004D62A9@@UAE@XZ present-unmatched
Rva004D62A9::~Rva004D62A9() { m_famgen = 0; }
void famgenDelete(Rva004D62A9 *p) { delete p; }
