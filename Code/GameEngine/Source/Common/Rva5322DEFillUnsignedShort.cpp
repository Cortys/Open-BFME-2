// cl: /O1 /MD
// ?rva_5322de_fill_unsigned_short@@YAPAGPAGI0@Z @ 0x005322DE 37B
// Counted 4-byte splat: dst advances, src fixed, returns end pointer.
// Evidence: chain caller of rowed 0x0053229D (declared only so the gate
// resolves the call), jbe unsigned count check, pop/add/dec/pop
// interleaving, caller 0x00532F44.
void rva_53229d_copy_unsigned_short(unsigned short *dst, unsigned short *src);

unsigned short *rva_5322de_fill_unsigned_short(unsigned short *dst, unsigned int count, unsigned short *src)
{
    unsigned short *d = dst;
    while (count > 0) {
        rva_53229d_copy_unsigned_short(d, src);
        d += 2;
        --count;
    }
    return d;
}
