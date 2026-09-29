// cl: /O1 /MD
// ??_GRva004D64F5@@UAEPAXI@Z @0x004D6AF1 28B calls rowed ??1Rva004D64F5@@UAE@XZ at 0x004D65A6 then delete.
// Chain from just-landed 0x004D65A6 same 28B scalar-deleting shape as Rva004D62A9 precedent.
class Rva004D64F5 { public: __declspec(noinline) virtual ~Rva004D64F5(); private: int m_famgen; };
// ??1Rva004D64F5@@UAE@XZ present-unmatched
Rva004D64F5::~Rva004D64F5() { m_famgen = 0; }
void famgenDelete(Rva004D64F5 *p) { delete p; }
