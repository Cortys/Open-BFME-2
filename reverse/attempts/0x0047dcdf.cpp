// ?rva0047DCDF@Rva0047DCDF@@QAEXP6AXPAX0@Z0I@Z
// partial score=0.94 date=2026-09-29
// ?rva0047DCDF@Rva0047DCDF@@QAEXP6AXPAX0@Z0I@Z
// partial score=0.94 date=2026-09-29
// cl: /O1 /MD
// ?rva0047DCDF@Rva0047DCDF@@QAEXP6AXPAX0@Z0I@Z @0x0047DCDF 48B.
// Forwards to the Rva004F553F visitor with the controlling player's list.
// Evidence: chain lane packet; same arg forwarding; Contain neighbours.
// ?rva0047DCDF@Rva0047DCDF@@QAEXP6AXPAX0@Z0I@Z present-unmatched
typedef void (__cdecl *Rva004F553FCb)(void *data, void *user);
class Rva004F553F
{
public:
    void rva004F553F(Rva004F553FCb cb, void *user, bool flag);
};
class Player;
class Object
{
public:
    Player *getControllingPlayer() const;
};
class Rva0047DCDF
{
public:
    void rva0047DCDF(Rva004F553FCb cb, void *user, unsigned int flags);
};
void Rva0047DCDF::rva0047DCDF(Rva004F553FCb cb, void *user, unsigned int flags)
{
    if (!(flags & 1))
        return;
    Object *obj = *(Object **)((char *)this - 0x18);
    Player *player = obj->getControllingPlayer();
    Rva004F553F *owner = *(Rva004F553F **)((char *)player + 0x2e8);
    unsigned char f = (unsigned char)(flags >> 3);
    f &= 1;
    owner->rva004F553F(cb, user, f);
}
