// cl: /O1 /MD
// ??_GRva00507823@@UAEPAXI@Z @0x00507807 28B calls rowed ??1Rva00507823@@UAE@XZ at 0x00507823 then delete.
// Slot 0 of vtable 0x00864010 per tf.py show chain lane. Same 28B scalar-deleting
// shape as FamilyDeletingDtors_muse-8fbc precedent with public virtual UAE.
class Rva00507823 { public: __declspec(noinline) virtual ~Rva00507823(); private: int m_famgen; };
Rva00507823::~Rva00507823() { m_famgen = 0; }
void famgenDelete(Rva00507823 *p) { delete p; }

// ??_GRva00508CF7@@UAEPAXI@Z @0x00508CDB 28B calls rowed ??1Rva00508CF7@@UAE@XZ at 0x00508CF7 then delete.
// Chain from 0x00508CF7 same 28B scalar-deleting shape.
class Rva00508CF7 { public: __declspec(noinline) virtual ~Rva00508CF7(); private: int m_famgen; };
Rva00508CF7::~Rva00508CF7() { m_famgen = 0; }
void famgenDelete(Rva00508CF7 *p) { delete p; }
