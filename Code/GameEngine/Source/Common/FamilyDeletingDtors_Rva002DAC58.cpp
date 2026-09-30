// cl: /O1 /MD
// ??_GRva002DAC58@@UAEPAXI@Z @0x002DACD8 28B: scalar deleting dtor calling rowed ??1Rva002DAC58 at 0x002DAC58.
// Evidence: chain lane, vtable slot 0 of 0x00803D64, ??1 rowed in Rva002DAC58Dtor.cpp, delete row 0x2FD60, precedent FamilyDeletingDtors_Rva001805E0.cpp.

class Rva002DAC58 { public: __declspec(noinline) virtual ~Rva002DAC58(); private: int m_famgen;
  friend void famgenDelete(Rva002DAC58 *p); };
Rva002DAC58::~Rva002DAC58() { m_famgen = 0; }
void famgenDelete(Rva002DAC58 *p) { delete p; }
