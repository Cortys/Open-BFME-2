// cl: /O1 /MD
// ??_GRva0015058E@@UAEPAXI@Z @0x001510A6, 28B.
// Scalar deleting dtor; calls rowed ??1 at 0x0015058E plus rowed delete at 0x0002FD60.
// Evidence: retail calls 0x0015058E (rowed ??1Rva0015058E@@UAE@XZ) and 0x0002FD60 (rowed ??3@YAXPAX@Z); same 28B ??_G shape as family.
class Rva0015058E { public: __declspec(noinline) virtual ~Rva0015058E(); private: int m_famgen;
  friend void famgenDelete(Rva0015058E *p); };
// ??1Rva0015058E@@UAE@XZ present-unmatched
Rva0015058E::~Rva0015058E() { m_famgen = 0; }
// ?famgenDelete@@YAXPAVRva0015058E@@@Z present-unmatched
void famgenDelete(Rva0015058E *p) { delete p; }
