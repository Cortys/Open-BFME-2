// cl: /O1 /DNDEBUG /MD
// ?Rva0031455ELink@Rva0031455E@@QAEXPAV1@@Z @ 0x0031455E (35B).
// Honest address-derived list link: virtual slot 2 then insert this into list headed at arg plus 0x1DC with next at plus 0x04 and owner at plus 0x08.
// Evidence: neighbors 0x0031450A plus 0x003145F0 plus twin unlink 0x00314581 sharing plus 0x04 plus 0x08 plus 0x1DC layout.
class Rva0031455E
{
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    void Rva0031455ELink(Rva0031455E *arg);
private:
    void *m_04;
    void *m_08;
    char m_pad[0x1DC - 0x0C];
    void *m_1DC;
};
void Rva0031455E::Rva0031455ELink(Rva0031455E *arg)
{
    v2();
    if (arg) {
        m_08 = arg;
        m_04 = arg->m_1DC;
        arg->m_1DC = this;
    }
}
