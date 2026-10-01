// cl: /Ireference/shims/bfme2_ascii /O1 /G7 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// ?rva0040ADFA@Rva0040ADFA@@QBE_NPBX@Z @0x0040ADFA 50B
// Evidence: unlock lane; +4/+8 int sorted array searched via rowed
// binary_search int 0x40AD75 for key from rowed NameKeyGenerator::nameToKey
// 0x9FA65 via TheNameKeyGenerator on AsciiString at arg+0x64; caller 0x40B143;
// LINK BONUS none.
#include "ascii_string.h"

enum NameKeyType
{
    NAMEKEY_INVALID = 0
};

class NameKeyGenerator
{
public:
    NameKeyType nameToKey(const AsciiString &name);
};

extern class NameKeyGenerator *TheNameKeyGenerator;

namespace _STL
{
    template <class _ForwardIter, class _Tp>
    bool binary_search(_ForwardIter __first, _ForwardIter __last, const _Tp &__val);
}

class Rva0040ADFA
{
public:
    bool rva0040ADFA(const void *arg) const;
private:
    char m_pad[4];
    int *m_first;
    int *m_last;
};

bool Rva0040ADFA::rva0040ADFA(const void *arg) const
{
    NameKeyType key = TheNameKeyGenerator->nameToKey(*(const AsciiString *)((const char *)arg + 0x64));
    return _STL::binary_search(m_first, m_last, (int)key);
}
