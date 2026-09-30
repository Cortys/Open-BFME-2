// cl: /O2 /DNDEBUG /MD
// ?rva006F7600@Rva006F7600@@QAEXH@Z @0x006F7600 95B evidence AptDisplayList assert i-range plus array shift with count at +0x80; caller 0x006F7885
extern void (__cdecl *g_bfmeAptAssertAtE17734)(const char *, const char *, int);
extern int g_bfmeAptBreakOnAssertAtDDC01C;
void __debugbreak();
#pragma intrinsic(__debugbreak)
class Rva006F7600
{
public:
    void rva006F7600(int i);
private:
    void *m_items[32];
    int m_nElements;
};
void Rva006F7600::rva006F7600(int i)
{
    if (i < 0 || i >= m_nElements) {
        g_bfmeAptAssertAtE17734("i >= 0 && i < nElements", "C:\\projects\\bfme2patch103\\bfme2\\Code\\Libraries\\Source\\Apt\\AptDisplayList.cpp", 0x54A);
        if (g_bfmeAptBreakOnAssertAtDDC01C)
            __debugbreak();
    }
    int last = m_nElements - 1;
    if (i < last) {
        do {
            m_items[i] = m_items[i + 1];
            ++i;
        } while (i < m_nElements - 1);
    }
    --m_nElements;
}
