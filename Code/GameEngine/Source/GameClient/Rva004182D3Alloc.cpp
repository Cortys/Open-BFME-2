// cl: /O1 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
// ?Rva004182D3Alloc@@YGPAXPBVRva004181F5@@@Z @0x004182D3 37B
// Allocates 0x20 via byte allocator 0x000307F0, zeroes first dword, constructs
// Rva004181F5 at +4 via rowed Construct 0x0041826B, returns new wrapper.
// __stdcall (ret 4, 1 arg). /O1 gives and-zero plus direct push.
// Evidence: chain lane after landing 0x0041826B; unblocks 0x004182F8.
#include <memory>
class Rva004181F5 {
public:
    Rva004181F5(const Rva004181F5 &other);
private:
    char m_pad[0x1c];
};
void __cdecl Rva0041826BConstruct(Rva004181F5 *dst, const Rva004181F5 *src);
struct Wrapper004182D3 {
    int m_0;
    Rva004181F5 m_4;
};
void *__stdcall Rva004182D3Alloc(const Rva004181F5 *src)
{
    char *buf = _STL::allocator<char>::allocate(0x20, 0);
    Wrapper004182D3 *w = (Wrapper004182D3 *)buf;
    w->m_0 = 0;
    Rva0041826BConstruct(&w->m_4, src);
    return w;
}
