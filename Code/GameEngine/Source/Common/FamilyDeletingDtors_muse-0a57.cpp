// cl: /O1 /MD
// ??_GMonsterDockUpdate@@MAEPAXI@Z @0x004A1459, 28B, slot 0 of vtable
// 0x00851D74. Scalar deleting dtor for MonsterDockUpdate whose ??1
// (??1MonsterDockUpdate@@MAE@XZ) is rowed at 0x004A13F4. Protected to match
// the MAE ??1. Calls the rowed ??1 then operator delete 0x2FD60.

class MonsterDockUpdate { protected: __declspec(noinline) virtual ~MonsterDockUpdate(); private: int m_famgen;
  friend void famgenDelete(MonsterDockUpdate *p); };
MonsterDockUpdate::~MonsterDockUpdate() { m_famgen = 0; }
void famgenDelete(MonsterDockUpdate *p) { delete p; }
