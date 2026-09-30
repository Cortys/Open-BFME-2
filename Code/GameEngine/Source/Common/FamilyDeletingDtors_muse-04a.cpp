// cl: /O1 /MD
// ??_GRva005CCC69@@UAEPAXI@Z @0x005CCC98 28B calls rowed ??1Rva005CCC69@@UAE@XZ at 0x005CCC69 then delete.
// Chain from 0x005CCC69 same 28B scalar-deleting shape as FamilyDeletingDtors_muse-11 precedent.
class Rva005CCC69 { public: __declspec(noinline) virtual ~Rva005CCC69(); private: int m_famgen; };
Rva005CCC69::~Rva005CCC69() { m_famgen = 0; }
void famgenDelete(Rva005CCC69 *p) { delete p; }
