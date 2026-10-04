// cl: /DNDEBUG /DWIN32 /D_WINDOWS /MD /O1 /G7
// ?rva00595A9F@Rva00595A9F@@QAE_NXZ @0x00595A9F 248B evidence: calls rowed 0x00594E07 0x0059534A 0x0059517F plus IAT timeGetTime; offsets 0x54 0x68 0x6a 0x78 0x88 0x17c 0x180 0x184 match Rva00594E07 layout; caller 0x00595D2D
extern "C" __declspec(dllimport) unsigned long __stdcall timeGetTime();

class Rva00594E07
{
public:
    unsigned short rva00594E07(unsigned short a, int b);
};

class Rva0059534A
{
public:
    void rva0059534A(unsigned short key);
};

class Rva0059517F
{
public:
    bool rva0059517F(unsigned long a1, unsigned short a2, unsigned short a3, unsigned short a4, bool a5);
};

class Rva00595A9F
{
public:
    bool rva00595A9F();
private:
    char m_pad0[0x54];
    unsigned long m_54;
    char m_pad58[0x68 - 0x58];
    unsigned short m_68;
    unsigned short m_6a;
    char m_pad6c[0x78 - 0x6c];
    unsigned short m_78;
    char m_pad7a[0x88 - 0x7a];
    unsigned short m_88;
    char m_pad8a[0x17c - 0x8a];
    unsigned long m_17c;
    unsigned long m_180;
    unsigned long m_184;
};

bool Rva00595A9F::rva00595A9F()
{
    unsigned short r = ((Rva00594E07 *)this)->rva00594E07(m_88, 0);
    m_78 = r;
    if (r == 0) {
        unsigned long now = timeGetTime();
        if (now - m_180 > m_184) {
            ((Rva0059534A *)this)->rva0059534A(m_68);
            ((Rva0059534A *)this)->rva0059534A(m_6a);
            m_17c = 9;
            return true;
        }
        return false;
    } else {
        unsigned long addr = m_54;
        ((Rva0059517F *)this)->rva0059517F(addr, m_68, m_88, 0x10e2, false);
        ((Rva0059517F *)this)->rva0059517F(addr, m_68, m_88, 0x10e2, false);
        ((Rva0059517F *)this)->rva0059517F(addr, m_68, m_88, 0x10e2, false);
        ++m_88;
        m_180 = timeGetTime();
        m_184 = 0xfa0;
        ((Rva0059517F *)this)->rva0059517F(m_54, m_6a, m_88, 0x10e1, false);
        m_17c = 7;
        return false;
    }
}
