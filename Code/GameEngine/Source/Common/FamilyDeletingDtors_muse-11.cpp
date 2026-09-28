// cl: /O1 /MD
// ??_GMade002CCC90@@UAEPAXI@Z @0x0050BD81 28B calls rowed ??1Made002CCC90@@UAE@XZ at 0x0050BD9D then delete.
// Chain from 0x0050BD9D same 28B scalar-deleting shape as Rva00508CF7 precedent.
class Made002CCC90 { public: __declspec(noinline) virtual ~Made002CCC90(); private: int m_famgen; };
Made002CCC90::~Made002CCC90() { m_famgen = 0; }
void famgenDelete(Made002CCC90 *p) { delete p; }

// ??_GMade002CCC2D@@UAEPAXI@Z @0x0050BB66 28B calls rowed ??1Made002CCC2D@@UAE@XZ at 0x0050BB82 then delete.
// Chain from 0x0050BB82 same 28B scalar-deleting shape.
class Made002CCC2D { public: __declspec(noinline) virtual ~Made002CCC2D(); private: int m_famgen; };
Made002CCC2D::~Made002CCC2D() { m_famgen = 0; }
void famgenDelete(Made002CCC2D *p) { delete p; }
