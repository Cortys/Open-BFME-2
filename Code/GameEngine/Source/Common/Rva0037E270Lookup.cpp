// cl: /O1 /DNDEBUG /MD
//
// ?rva0037E270@Rva0037E270@@QAEPAXXZ retail 0x0037E270 25 bytes.
// Null-checked global lookup via 0x00DFF000 plus AsciiString at +0xd4.
// Returns 0 when global null else rowed 0x002D06CA result. Callers
// 0x002E1A25 0x0037E3F6 0x0037E7B4 0x0037E93E 0x0037EB8C 0x0037EFB9
// 0x004067DD. Flags from sibling Rva002D06CAGet without EHsc.
class AsciiString { char *m_text; };
class Rva002D06CA { public: void *rva002D06CA(const AsciiString *key); };
#define TheRva00DFF000 (*(Rva002D06CA **)0x00DFF000)
class Rva0037E270 {
    char m_pad[0xd4];
    AsciiString m_str;
public:
    void *rva0037E270();
};
void *Rva0037E270::rva0037E270()
{
    Rva002D06CA *mgr = TheRva00DFF000;
    if (mgr == 0)
        return 0;
    return mgr->rva002D06CA((const AsciiString *)((char *)this + 0xd4));
}
