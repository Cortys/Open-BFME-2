// ?rva0035B1C3@Rva0035B1C3@@QAEHH@Z
// partial score=0.9 date=2026-10-02
// cl: /O1 /MD
//
// ?rva0035B1C3@Rva0035B1C3@@QAEHH@Z @0x0035B1C3 38B
// Bounds-checked int list getter over vector<int> at +0xec: negative or
// past-end index returns 0 else m_begin[index].
// Evidence: ecx-first thiscall ret 4; sar-2 count shape like twin
// Rva0035B232Getter; caller 0x005679C9; prev/next donor TUs in Common.
struct Rva0035B1C3Vec {
    int *begin;
    int *end;
    int *cap;
    unsigned int size() const { return end - begin; }
    int &operator[](unsigned int i) { return begin[i]; }
};
class Rva0035B1C3 {
    char m_pad[0xec];
    Rva0035B1C3Vec m_vec;
public:
    int rva0035B1C3(int index);
};
// ?rva0035B1C3@Rva0035B1C3@@QAEHH@Z present-unmatched
int Rva0035B1C3::rva0035B1C3(int index)
{
    if (index < 0)
        return 0;
    Rva0035B1C3Vec *v = &m_vec;
    unsigned int count = v->size();
    if ((unsigned int)index >= count)
        return 0;
    return (*v)[(unsigned int)index];
}
