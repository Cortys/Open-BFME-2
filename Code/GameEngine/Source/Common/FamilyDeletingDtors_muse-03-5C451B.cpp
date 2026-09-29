// cl: /O1 /MD
// ??_GRva005C436E@@UAEPAXI@Z @0x005C451B 28B chain deleting dtor via rowed ??1 0x005C4423 plus delete 0x0002FD60; vslot 0 of 0x008745A8.
// ?rva005C436E@Rva005C436E@@QAEXH@Z dispatch plus ??1 plus vslot6 already landed in Rva005C436EDispatch.cpp; callers none.

class Rva005C436E { public: __declspec(noinline) virtual ~Rva005C436E(); private: int m_famgen; };
Rva005C436E::~Rva005C436E() { m_famgen = 0; }
void famgenDelete(Rva005C436E *p) { delete p; }
