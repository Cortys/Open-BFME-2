// cl: /O1 /MD
// ?rva00222BCD@Rva00222A8BTarget@@QAEHPAXPBDH10000@Z @0x00222BCD 69B
// Forward 8 args to invoke then fire slot 0x28 once when +0x312 is 0.
// Evidence: invoke pin 0x00222A8B plus +0x312 +0x328 in Rva00222A53 TU range plus caller 0x00528C25; same class as prev Rva00222A53.
class Rva00222A8BTarget
{
public:
    int invoke(void *owner, const char *name, int flag, const char *value, void *a4, void *a5, void *a6, void *a7);
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    int rva00222BCD(void *owner, const char *name, int flag, const char *value, void *a4, void *a5, void *a6, void *a7);
private:
    char m_pad00[0x312 - 4];
    unsigned char m_312;
    char m_pad01[0x328 - 0x313];
    unsigned char m_328;
};
int Rva00222A8BTarget::rva00222BCD(void *owner, const char *name, int flag, const char *value, void *a4, void *a5, void *a6, void *a7)
{
    int r = invoke(owner, name, flag, value, a4, a5, a6, a7);
    if (!m_312) {
        m_328 = 1;
        v10();
    }
    return r;
}
