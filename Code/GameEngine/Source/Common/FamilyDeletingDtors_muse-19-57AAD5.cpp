// cl: /O1 /MD
// ??_GRva0057A4E7@@QAEPAXI@Z @0x0057AAD5 28B; calls rowed ??1Rva0057A4E7@@QAE@XZ @0x0057A4E7 then delete 0x0002FD60.
// Evidence: retail push esi mov esi ecx call test flag delete ret 4 shape; QAE non-virtual so QAEPAXI; chain from 0x0057A4E7 landing.
class Rva0057A4E7 { public: ~Rva0057A4E7(); };
// ?famgenDelete0057AAD5@@YAXPAVRva0057A4E7@@@Z present-unmatched
void famgenDelete0057AAD5(Rva0057A4E7 *p) { delete p; }
