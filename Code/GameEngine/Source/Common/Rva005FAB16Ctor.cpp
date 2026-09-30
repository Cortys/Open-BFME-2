// cl: /O1 /MD
// ??0Rva005FAB16@@QAE@ABUPayload005FAB16@@@Z, RVA 0x005FAB16, 30 bytes.
// Ctor storing vtable 0x00879EB4 at +0, zeroing +4, copying 16 bytes from
// arg+0 to this+8 via 4x movsd. Evidence: caller 0x005FAC76; vtable DIR32
// filled by gate; neighbours use /O1 /MD.
struct Payload005FAB16 {
    int v[4];
};
struct Rva005FAB16 {
    virtual void _vf();
    int m4;
    Payload005FAB16 m8;
    Rva005FAB16(const Payload005FAB16 &o);
};
Rva005FAB16::Rva005FAB16(const Payload005FAB16 &o) : m4(0), m8(o) {}
