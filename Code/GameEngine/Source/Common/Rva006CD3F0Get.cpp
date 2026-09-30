// cl: /O2 /MD
// ?Rva006CD3F0Get@@YAHPAX@Z @0x006CD3F0 75B evidence Apt.cpp eType assert plus get row plus byte table g_00CE8B70 plus type 0x25 field
extern void (__cdecl *g_bfmeAptAssertAtE17734)(const char *, const char *, int);
extern int g_bfmeAptBreakOnAssertAtDDC01C;
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
