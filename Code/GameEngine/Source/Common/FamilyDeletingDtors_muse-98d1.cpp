// cl: /O1 /MD

// ??_GRva0045EF90Object@@UAEPAXI@Z @0x41048f
class Rva0045EF90Object { public: __declspec(noinline) virtual ~Rva0045EF90Object(); private: int m_famgen;
  friend void famgenDelete(Rva0045EF90Object *p); };
Rva0045EF90Object::~Rva0045EF90Object() { m_famgen = 0; }
void famgenDelete(Rva0045EF90Object *p) { delete p; }
