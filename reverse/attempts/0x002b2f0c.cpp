// ?rva002B2F0C@Rva004F6093Holder@@QAEXPAURva004F6093Ref@@@Z
// partial score=0.9 date=2026-09-28
// ?rva002B2F0C@Rva004F6093Holder@@QAEXPAURva004F6093Ref@@@Z
// partial score=0.90 date=2026-09-28
struct Rva004F6093Ref { char m_pad[0xB0]; int m_refCount; };
class Rva004F6093Holder {
public: void rva002B2F0C(Rva004F6093Ref *p);
private: Rva004F6093Ref *m_ptr;
};
void Rva004F6093Holder::rva002B2F0C(Rva004F6093Ref *p)
{
  m_ptr = p;
  if (p == 0)
    return;
  ++p->m_refCount;
}
