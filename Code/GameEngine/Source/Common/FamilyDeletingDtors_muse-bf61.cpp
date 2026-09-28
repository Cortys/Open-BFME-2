// cl: /O1 /MD
// ??_GTracerFXNugget@@MAEPAXI@Z @0x004E1B45, 28B.
// Scalar deleting dtor slot 0 of vtable 0x00861DB4; calls rowed ??1 at
// 0x004E1B00 plus rowed delete at 0x0002FD60.

// ??_GTracerFXNugget@@MAEPAXI@Z @0x004E1B45
class TracerFXNugget { protected: __declspec(noinline) virtual ~TracerFXNugget(); private: int m_famgen;
  friend void famgenDelete(TracerFXNugget *p); };
TracerFXNugget::~TracerFXNugget() { m_famgen = 0; }
void famgenDelete(TracerFXNugget *p) { delete p; }
