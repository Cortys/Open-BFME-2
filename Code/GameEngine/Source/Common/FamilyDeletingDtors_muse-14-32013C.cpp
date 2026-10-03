// cl: /O1 /MD
// ??_GRva0031FAF0@@QAEPAXI@Z, retail 0x0032013C, 28 bytes. Deleting dtor calls rowed ??1Rva0031FAF0@@QAE@XZ @0x0032002C then operator delete 0x0002FD60.
// Evidence: retail push esi mov esi ecx call test flag delete ret 4 shape; QAE non-virtual so QAEPAXI; chain from 0x0032002C landing.
class Rva0031FAF0 { public: ~Rva0031FAF0(); };
// ?famgenDelete0032013C@@YAXPAVRva0031FAF0@@@Z present-unmatched
void famgenDelete0032013C(Rva0031FAF0 *p) { delete p; }
