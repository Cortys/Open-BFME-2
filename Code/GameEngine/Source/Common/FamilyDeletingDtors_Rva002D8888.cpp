// cl: /O1 /MD
// ??_GRadar@@UAEPAXI@Z @0x002D8888 28B
// Scalar deleting dtor slot 0 of vtable 0x0080363C; calls rowed ??1Radar@@UAE@XZ @0x002D7CED plus rowed delete @0x0002FD60.
class Radar { public: __declspec(noinline) virtual ~Radar(); private: int m_famgen;
  friend void famgenDelete(Radar *p); };
Radar::~Radar() { m_famgen = 0; }
void famgenDelete(Radar *p) { delete p; }
