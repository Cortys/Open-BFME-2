// cl: /O1 /MD
// ??_GRva0033F33D@@UAEPAXI@Z @0x003428F1 28B
// Deleting dtor slot 0 of vtable 0x00810EE0; calls rowed ??1 at 0x003401E4 then rowed operator delete at 0x0002FD60.
class Rva0033F33D { public: __declspec(noinline) virtual ~Rva0033F33D(); private: int m_famgen; };
Rva0033F33D::~Rva0033F33D() { m_famgen = 0; }
void famgenDelete(Rva0033F33D *p) { delete p; }
// ??_GNetKeepAliveCommandMsg@@MAEPAXI@Z @0x004D5B30 28B
// Deleting dtor slot 0 of vtable 0x00860244; calls rowed apply at 0x004CEE78 as ICF twin of ??1 then rowed operator delete at 0x0002FD60.
class NetKeepAliveCommandMsg { protected: __declspec(noinline) virtual ~NetKeepAliveCommandMsg(); private: int m_famgen; friend void famgenDelete(NetKeepAliveCommandMsg *p); };
// ??1NetKeepAliveCommandMsg@@MAE@XZ present-unmatched
NetKeepAliveCommandMsg::~NetKeepAliveCommandMsg() { m_famgen = 0; }
void famgenDelete(NetKeepAliveCommandMsg *p) { delete p; }
