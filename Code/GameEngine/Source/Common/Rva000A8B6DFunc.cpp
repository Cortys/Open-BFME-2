// cl: /O1 /MD
// ?rva000A8B6D@Rva000A8B6D@@QAEXXZ @0x000A8B6D 12B.
// Null-guarded forward to rowed ?rva0010F110@Rva0010F110@@QAEXXZ at 0x0010F110.
// Evidence: jmp to 0x0010F110 when [ecx]!=0 else ret; caller at 0x000A8B9B does
// mov ecx,esi with no pushes (thiscall void no args); sibling caller 0x000A8B79
// dereferences [esi] as Rva0010F110 with +0x08 stream and +0x1C loops matching
// Rva0010F110 layout; neighbours share Common dir with /O1 /MD.
// Honest address name: owner unknown so Rva000A8B6D class.
class Rva0010F110
{
public:
    void rva0010F110();
};

class Rva000A8B6D
{
public:
    void rva000A8B6D();
private:
    Rva0010F110 *m_ptr;
};

void Rva000A8B6D::rva000A8B6D()
{
    if (m_ptr != 0)
        m_ptr->rva0010F110();
}
