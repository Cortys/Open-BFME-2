// cl: /O1 /MD
// ??_GRva003FAFB9@@UAEPAXI@Z @0x003FB4EC 28B calls rowed ??1Rva003FAFB9@@UAE@XZ at 0x003FAFB9 then delete.
// Chain from 0x003FAFB9 same 28B scalar-deleting shape.
class Rva003FAFB9 { public: __declspec(noinline) virtual ~Rva003FAFB9(); private: int m_famgen; };
Rva003FAFB9::~Rva003FAFB9() { m_famgen = 0; }
void famgenDelete(Rva003FAFB9 *p) { delete p; }
