// cl: /O1 /MD
// ??_GMissileUpdate@@MAEPAXI@Z @0x004A789C 28B: deleting dtor calls rowed ??1 0x4A76DE then delete; vtable slot 0 of 0x85362C
class MissileUpdate { protected: __declspec(noinline) virtual ~MissileUpdate(); private: int m_famgen;
  friend void famgenDelete(MissileUpdate *p); };
MissileUpdate::~MissileUpdate() { m_famgen = 0; }
void famgenDelete(MissileUpdate *p) { delete p; }
