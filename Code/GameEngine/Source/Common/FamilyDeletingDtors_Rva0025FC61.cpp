// cl: /O1 /MD
// ??_GRva0025FC61@@MAEPAXI@Z @0x0025FF73: scalar deleting dtor for SubtitleEntry-derived Rva0025FC61.
// Evidence: vtable 0x007F63F8 slot 0 calls rowed ??1Rva0025FC61@@MAE@XZ at 0x0025FC61 plus delete 0x0002FD60. Protected to match MAE.

// ??_GRva0025FC61@@MAEPAXI@Z @0x25ff73
class Rva0025FC61 { protected: __declspec(noinline) virtual ~Rva0025FC61(); private: int m_famgen;
  friend void famgenDelete(Rva0025FC61 *p); };
Rva0025FC61::~Rva0025FC61() { m_famgen = 0; }
void famgenDelete(Rva0025FC61 *p) { delete p; }
