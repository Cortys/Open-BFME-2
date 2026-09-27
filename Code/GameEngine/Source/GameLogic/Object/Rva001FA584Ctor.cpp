// cl: /O1 /MD
// ??0Rva001FA584@@QAE@XZ @0x001FA584 19B
// Unnamed ctor initializing int at +4 to 0 and inline ObjectCreationList at +8.
// Evidence: ret with no stack args; callee ObjectCreationList ctor 0x001F81BF rowed;
// callers 0x001FA94B and 0x001FB93D and 0x001FBAD8 become ready; honest Rva name.
class ObjectCreationList
{
public:
    ObjectCreationList();
};

class Rva001FA584
{
public:
    int m_00;
    int m_04;
    ObjectCreationList m_08;
    Rva001FA584();
};

Rva001FA584::Rva001FA584() : m_04(0)
{
}
