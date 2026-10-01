// cl: /O1 /Ob1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB
// stlport
// ?findIndex@Rva0040A3F9@@QBEHPAVCreateAHeroData@@@Z @0x0040A3F9 43B
// Evidence: unlock lane; vector-like +0/+4 of CreateAHeroData* searched via
// rowed _STL::find 0x20E873; null returns count else index of value (count if
// absent); callers 0x441599 0x522067 0x5220AD unclaimed; LINK BONUS none.
#include <vector>
#include <algorithm>

class CreateAHeroData;

class Rva0040A3F9
{
public:
    int findIndex(CreateAHeroData *value) const;
private:
    CreateAHeroData **m_begin;
    CreateAHeroData **m_end;
};

int Rva0040A3F9::findIndex(CreateAHeroData *value) const
{
    if (value == 0)
        return m_end - m_begin;
    return _STL::find(m_begin, m_end, value) - m_begin;
}
