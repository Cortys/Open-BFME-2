// ?rva002B2E31@GameMessage@@QAE_NPAHHPAVRva003F4DCA@@HH@Z
// partial score=0.9 date=2026-09-28
// ?rva002B2E31@GameMessage@@QAE_NPAHHPAVRva003F4DCA@@HH@Z
// partial score=0.90 date=2026-09-28
// cl: /O1 /DNDEBUG /MD
//
// ?rva002B2E31@GameMessage@@QAE_NPAHHPAVRva003F4DCA@@HH@Z retail 0x002B2E31 70 bytes.
// GameMessage index validator (chain from 0x003F4DCA landing): checks index
// in [0 m_argCount) via byte at +0x18 then getArgument row 0x0030F4EA then
// stores integer to *out then checks [0 innerSize) via rva003F4DCA row.
// Callers 0x002B41BB 0x002B41D4 pass out plus 3 plus 4 plus container
// plus edi plus esi with add esp 0x14 (caller-clean plain ret). Current
// body 70B same size with correct offsets but thiscall ret 0x14 vs retail
// plain ret plus setl vs xor-inc branches.
typedef unsigned char UnsignedByte;
union GameMessageArgumentType { int integer; float real; int boolean; };
class Rva003F4DCA { public: int rva003F4DCA(int i, int j); };
class GameMessage {
    char m_pad[0x18];
    UnsignedByte m_argCount;
    char m_padB[3];
    void *m_argList;
    void *m_argTail;
public:
    const GameMessageArgumentType *getArgument(int index) const;
    bool rva002B2E31(int *out, int index, Rva003F4DCA *c, int i, int j);
};
bool GameMessage::rva002B2E31(int *out, int index, Rva003F4DCA *c, int i, int j)
{
    if (index < 0)
        return false;
    if (index >= m_argCount)
        return false;
    const GameMessageArgumentType *arg = getArgument(index);
    int v = arg->integer;
    *out = v;
    if (v < 0)
        return false;
    int n = c->rva003F4DCA(i, j);
    if (v >= n)
        return false;
    return true;
}
