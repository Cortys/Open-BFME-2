// cl: /O1 /MD
// ??_GWatchdog@@UAEPAXI@Z @0x002257CD 28B
// Deleting dtor slot 0 of vtable 0x007E6FD8; calls rowed ??1 at 0x0022576A then rowed operator delete at 0x0002FD60.
class Watchdog { public: __declspec(noinline) virtual ~Watchdog(); private: int m_famgen; };
// ??1Watchdog@@UAE@XZ present-unmatched
Watchdog::~Watchdog() { m_famgen = 0; }
void famgenDelete(Watchdog *p) { delete p; }
