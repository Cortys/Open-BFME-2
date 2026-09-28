// ?rva00272945@Drawable@@QAEXH@Z
// partial score=0.91 date=2026-09-28
// ?rva00272945@Drawable@@QAEXH@Z
// partial score=0.91 date=2026-09-28
// cl: /O1 /DNDEBUG /MD /EHsc /G7
class DrawModule
{
public:
    virtual void slot00() = 0; virtual void slot04() = 0;
    virtual void slot08() = 0; virtual void slot0C() = 0;
    virtual void slot10() = 0; virtual void slot14() = 0;
    virtual void slot18() = 0; virtual void slot1C() = 0;
    virtual void slot20() = 0; virtual void slot24() = 0;
    virtual void slot28() = 0; virtual void slot2C() = 0;
    virtual void slot30() = 0; virtual void slot34() = 0;
    virtual void slot38() = 0; virtual void slot3C() = 0;
    virtual void slot40() = 0; virtual void slot44() = 0;
    virtual void slot48() = 0; virtual void slot4C() = 0;
    virtual void slot50() = 0; virtual void slot54() = 0;
    virtual void slot58() = 0; virtual void slot5C() = 0;
    virtual void slot60(int a) = 0;
};
class Drawable
{
public:
    void rva00272945(int a);
private:
    char m_pad[0x14C];
    DrawModule **m_drawModules;
};
// ?rva00272945@Drawable@@QAEXH@Z present-unmatched
void Drawable::rva00272945(int a)
{
    DrawModule *first = *m_drawModules;
    if (first == 0)
        return;
    first->slot60(a);
}
