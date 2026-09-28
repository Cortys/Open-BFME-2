// cl: /O1 /MD
// ?Rva0060173ACopy@@YAXPAVCoord3D@@ABUCoord3DBase@@@Z @0x0060173A 18B: null-checked Coord3D assign helper.
// Callee rowed ?4Coord3D@@QAEAAV0@ABUCoord3DBase@@@Z @0x004216D3 in coord3d.cpp; callers 0x0060174C 0x00601772 0x0060197D 0x00601A3A copy 0x0C-stride Coord3D ranges.
struct Coord3DBase
{
    float x;
    float y;
    float z;
};
class Coord3D : public Coord3DBase
{
public:
    Coord3D &operator=(const Coord3DBase &that);
};
void __cdecl Rva0060173ACopy(Coord3D *dst, const Coord3DBase &src)
{
    if (dst)
        *dst = src;
}
Coord3D *__cdecl Rva00601772Fill(Coord3D *first, unsigned int count, const Coord3DBase &value)
{
    Coord3D *dst = first;
    unsigned int n = count;
    for (; n > 0; --n, ++dst)
        Rva0060173ACopy(dst, value);
    return dst;
}
Coord3D *__cdecl Rva0060174CCopy(const Coord3D *first, const Coord3D *last, Coord3D *result)
{
    Coord3D *dst = result;
    const Coord3D *src = first;
    for (; src != last; ++src, ++dst)
        Rva0060173ACopy(dst, *(const Coord3DBase *)src);
    return dst;
}
