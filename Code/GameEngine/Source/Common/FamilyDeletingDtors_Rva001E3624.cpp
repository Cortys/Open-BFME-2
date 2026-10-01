// cl: /O1 /MD
// ??_GRva001E3624@@UAEPAXI@Z @0x001E4445 28B: scalar deleting dtor calling ??1Rva001E3624 at 0x001E3624.
// Same-shape sibling of ??_GRva00414932; needs ??1 row to exist.
class Rva001E3624 { public: __declspec(noinline) virtual ~Rva001E3624(); private: int m_famgen; };
Rva001E3624::~Rva001E3624() { m_famgen = 0; }
void famgenDelete(Rva001E3624 *p) { delete p; }
