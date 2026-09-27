// cl: /O1 /MD
// ??_GObjectCreationUpgrade@@MAEPAXI@Z @0x004B40EA 28B
// Deleting dtor slot 0 of vtable 0x00857660; calls rowed ??1ObjectCreationUpgrade@@MAE@XZ at 0x004B3F90 then rowed operator delete at 0x0002FD60.
class ObjectCreationUpgrade { protected: __declspec(noinline) virtual ~ObjectCreationUpgrade(); private: int m_famgen;
  friend void famgenDelete(ObjectCreationUpgrade *p); };
ObjectCreationUpgrade::~ObjectCreationUpgrade() { m_famgen = 0; }
void famgenDelete(ObjectCreationUpgrade *p) { delete p; }
