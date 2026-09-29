// cl: /O1 /MD
// ??_GRva0040DB52@@UAEPAXI@Z @0x0040E09B
class Rva0040DB52 { public: __declspec(noinline) virtual ~Rva0040DB52(); private: int m_famgen;
  friend void famgenDelete(Rva0040DB52 *p); };
Rva0040DB52::~Rva0040DB52() { m_famgen = 0; }
void famgenDelete(Rva0040DB52 *p) { delete p; }
