// cl: /O1 /MD
// ??_GRva004E2382@@QAEPAXI@Z @ 0x004E2CB9 (28B).
// Deleting dtor of Rva004E2382 whose dtor is 0x004E2941: calls ??1 then
// rowed operator delete 0x0002FD60 when flag bit set. Caller chain from
// 0x004E2941 landing.
class Rva004E2382 {
public:
    ~Rva004E2382();
};

void famgenDelete(Rva004E2382 *p) { delete p; }
