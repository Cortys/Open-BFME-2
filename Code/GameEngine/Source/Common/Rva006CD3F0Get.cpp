// cl: /O2 /MD
// ?Rva006CD3F0Get@@YAHPAX@Z @0x006CD3F0 75B evidence Apt.cpp eType assert plus get row plus byte table g_00CE8B70 plus type 0x25 field
// Apt.cpp's assert hook and break-on-assert flag, which every Apt unit's
// asserts read. Matched DIR32 references across 44 units place the hook at
// VA 0x00E17734 (zero-filled: installed at run time) and the flag at VA
// 0x00DDC01C, whose retail initial value is 1. This unit carries Apt.cpp code
// (the assert names it), so it defines both.
void (__cdecl *g_bfmeAptAssertAtE17734)(const char *, const char *, int) = 0;
int g_bfmeAptBreakOnAssertAtDDC01C = 1;
extern unsigned char g_00CE8B70[];
class Rva006DBB30SarDwordField
{
public:
    int get() const;
};
int __cdecl Rva006CD3F0Get(void *p)
{
    int eType = ((const Rva006DBB30SarDwordField *)p)->get();
    if (!(eType < 47)) {
        g_bfmeAptAssertAtE17734("eType < AptVFT_NumVFTs", "C:\\projects\\bfme2patch103\\bfme2\\Code\\Libraries\\Source\\Apt\\Apt.cpp", 0x880);
        if (g_bfmeAptBreakOnAssertAtDDC01C)
            __asm int 3
    }
    if (eType == 0x25)
        return *(int *)((char *)p + 0xc);
    return (int)g_00CE8B70[eType];
}
