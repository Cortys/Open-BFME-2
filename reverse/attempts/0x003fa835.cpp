// ?rva003FA835@Rva003FA835@@QAEXPAM@Z
// partial score=0.92 date=2026-09-29
// ?rva003FA835@Rva003FA835@@QAEXPAM@Z
// partial score=0.92 date=2026-09-29
// cl: /O1 /MD /arch:SSE
// ?rva003FA835@Rva003FA835@@QAEXPAM@Z @0x003FA835 67B
// Unlock float triad via inner slot 0x50. Evidence: this+0x10+8 null-gated,
// inner floats at +0x24 +0x34 +0x44 to out[0..2], zero init via xorps.
class Inner003FA835 {
public:
    virtual void s00(); virtual void s01(); virtual void s02(); virtual void s03();
    virtual void s04(); virtual void s05(); virtual void s06(); virtual void s07();
    virtual void s08(); virtual void s09(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void slot20();
public:
    unsigned char pad04[0x20];
    float f24;
    unsigned char pad28[0x0C];
    float f34;
    unsigned char pad38[0x0C];
    float f44;
};
struct Mid003FA835 {
    unsigned char pad[8];
    Inner003FA835 *inner;
};
class Rva003FA835 {
public:
    void rva003FA835(float *out);
private:
    unsigned char pad00[0x10];
    Mid003FA835 *m_10;
};
// ?rva003FA835@Rva003FA835@@QAEXPAM@Z present-unmatched
void Rva003FA835::rva003FA835(float *out)
{
    float c = 0.0f;
    float b = 0.0f;
    float a = 0.0f;
    Inner003FA835 *inner = m_10->inner;
    if (inner != 0) {
        inner->slot20();
        a = inner->f24;
        b = inner->f34;
        c = inner->f44;
    }
    out[0] = a;
    out[1] = b;
    out[2] = c;
}
