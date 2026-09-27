// cl: /O1 /MD
// ??0Rva001FA584@@QAE@XZ @0x001FA584 19B
// ??0Rva001FA94B@@QAE@XZ @0x001FA94B 15B
// Unnamed ctor initializing int at +4 to 0 and inline ObjectCreationList at +8.
// Evidence: ret with no stack args; callee ObjectCreationList ctor 0x001F81BF rowed;
// callers 0x001FA94B and 0x001FB93D and 0x001FBAD8 become ready; honest Rva name.
// Rva001FA94B wraps Rva001FA584 at +4; chain lane after landing 0x001FA584.
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

class Rva001FA94B
{
public:
    int m_00;
    Rva001FA584 m_04;
    Rva001FA94B();
};

Rva001FA94B::Rva001FA94B() : m_04()
{
}
