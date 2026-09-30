// cl: /O1 /MD
// ??_GRva005DB100@@UAEPAXI@Z @0x005DB1E8 28B
// Scalar deleting dtor slot 0 of vtable 0x008766A4; calls rowed ??1Rva005DB100@@UAE@XZ @0x005DB100 plus rowed delete @0x0002FD60.
class Rva005DB100 { public: __declspec(noinline) virtual ~Rva005DB100(); private: int m_famgen;
  friend void famgenDelete(Rva005DB100 *p); };
Rva005DB100::~Rva005DB100() { m_famgen = 0; }
void famgenDelete(Rva005DB100 *p) { delete p; }
