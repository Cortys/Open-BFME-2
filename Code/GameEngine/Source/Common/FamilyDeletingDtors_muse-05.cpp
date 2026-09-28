// cl: /O1 /MD
// ??_GRva00329D0E@@QAEPAXI@Z @0x00329D98
// Deleting dtor for Rva00329D0E whose ??1 is rowed at 0x00329D0E.
// Evidence: retail push esi mov esi ecx call ??1 test flag delete ret 4;
// chain lane after landing ??1Rva00329D0E.
class Rva00329D0E { public: ~Rva00329D0E(); };
void famgenDelete(Rva00329D0E *p) { delete p; }
