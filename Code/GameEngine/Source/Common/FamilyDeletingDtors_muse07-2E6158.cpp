// cl: /O1 /MD
// ??_GRva002E6158@@QAEPAXI@Z @0x002E6415 28B; calls rowed ??1Rva002E6158@@QAE@XZ @0x002E6158 then delete 0x0002FD60.
// Evidence: retail push esi mov esi ecx call test flag delete ret 4 shape; QAE non-virtual so QAEPAXI; chain from 0x002E6158 landing.
class Rva002E6158 { public: ~Rva002E6158(); };
// ?famgenDelete002E6158@@YAXPAVRva002E6158@@@Z present-unmatched
void famgenDelete002E6158(Rva002E6158 *p) { delete p; }
