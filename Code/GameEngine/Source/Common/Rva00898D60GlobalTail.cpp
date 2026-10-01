// Open-BFME: two-global virtual tail chain reconstructed from retail RVA 0x00898D60.

class Rva00898D60Target
{
public:
    virtual void slot0(void) = 0;
    virtual void slot1(void) = 0;
    virtual void invoke(void) = 0;
};

extern Rva00898D60Target *g_Rva013379BC;
extern Rva00898D60Target *g_Rva01337A20;
// g_Rva01337A20: matched references place it at VA 0xe180dc (zero-filled .bss).
Rva00898D60Target * g_Rva01337A20;

void Rva00898D60Invoke(void)
{
    g_Rva013379BC->invoke();
    g_Rva01337A20->invoke();
}
// ?g_Rva013379BC@@3PAVRva00898D60Target@@A: the global at VA 0xe18078 is ?g_aptUndefinedAtE18078@@3PAVBfmeAptValue006DCD20@@A.
#pragma comment(linker, "/alternatename:?g_Rva013379BC@@3PAVRva00898D60Target@@A=?g_aptUndefinedAtE18078@@3PAVBfmeAptValue006DCD20@@A")
