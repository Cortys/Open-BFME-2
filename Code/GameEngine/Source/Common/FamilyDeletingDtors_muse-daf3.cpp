// cl: /O1 /MD
// ??_GNetCommandWrapperList@@MAEPAXI@Z @0x0058C268, 28B.
// Scalar deleting dtor slot 0 of vtable 0x00870A24; calls rowed ??1 at
// 0x0058C0BB plus rowed delete at 0x0002FD60.

// ??_GNetCommandWrapperList@@MAEPAXI@Z @0x0058C268
class NetCommandWrapperList { protected: __declspec(noinline) virtual ~NetCommandWrapperList(); private: int m_famgen;
  friend void famgenDelete(NetCommandWrapperList *p); };
NetCommandWrapperList::~NetCommandWrapperList() { m_famgen = 0; }
void famgenDelete(NetCommandWrapperList *p) { delete p; }
