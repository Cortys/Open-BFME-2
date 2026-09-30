// ?rva000578B3@Rva000578B3@@QAEXW4NameKeyType@@@Z
// partial score=0.9 date=2026-09-30
// ?rva000578B3@Rva000578B3@@QAEXW4NameKeyType@@@Z
// partial score=0.90 date=2026-09-30
// cl: /MD /O1 /GX /DNDEBUG /DWIN32 /D_WINDOWS /D_STLP_USE_STATIC_LIB /D_CRTIMP= /D_STLP_USE_MALLOC /D_STLP_NO_EXCEPTIONS
// stlport
#include <hash_map>
#include <cstddef>
enum NameKeyType
{
    NAMEKEY_INVALID = 0,
    NAMEKEY_MAX = 1 << 23,
    FORCE_NAMEKEYTYPE_LONG = 0x7fffffff
};
namespace rts
{
template <typename T> struct hash
{
    size_t operator()(const T &value) const;
};
}
class ArmorTemplate
{
public:
    float m_damageCoefficient[38];
};
typedef std::hash_map<
    NameKeyType,
    ArmorTemplate,
    rts::hash<NameKeyType>,
    std::equal_to<NameKeyType> > ArmorTemplateMap;
class Rva000578B3
{
public:
    void rva000578B3(NameKeyType key);
private:
    char _pad0[0x104];
    ArmorTemplateMap m_map104;
    ArmorTemplateMap m_map118;
};
// ?rva000578B3@Rva000578B3@@QAEXW4NameKeyType@@@Z present-unmatched
void Rva000578B3::rva000578B3(NameKeyType key)
{
    if ((unsigned)key < 5)
        return;
    ArmorTemplateMap::iterator it1 = m_map118.find(key);
    if (it1 == m_map118.end())
        return;
    int key2 = *(int *)&it1->second;
    m_map118.erase(it1);
    ArmorTemplateMap::iterator it2 = m_map104.find((NameKeyType)key2);
    if (it2 == m_map104.end())
        return;
    for (; it2 != m_map104.end(); ++it2) {
        if (*(int *)&it2->second == (int)key)
            break;
        if ((int)it2->first != key2)
            break;
    }
    if (it2 == m_map104.end())
        return;
    if ((int)it2->first != key2)
        return;
    m_map104.erase(it2);
}
