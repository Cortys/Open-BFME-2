// cl: /O1 /MD
// ??_GShell@@UAEPAXI@Z @0x0035C54A 28B
// Deleting dtor slot 0 of vtable 0x00816208; calls rowed ??1Shell@@UAE@XZ at 0x0035C087 then rowed operator delete ??3@YAXPAX@Z at 0x0002FD60.
class Shell { public: __declspec(noinline) virtual ~Shell(); private: int m_famgen; };
// ??1Shell@@UAE@XZ present-unmatched
Shell::~Shell() { m_famgen = 0; }
void famgenDeleteShell(Shell *p) { delete p; }
