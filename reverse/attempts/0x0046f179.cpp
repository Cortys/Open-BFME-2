// ?parseBannerCarrierPosition@@YAXPAVINI@@PAX1PBX@Z
// partial score=0.985 date=2026-09-30
// ?parseBannerCarrierPosition@@YAXPAVINI@@PAX1PBX@Z
// partial score=0.985 date=2026-09-30
// cl: /O1 /Oy- /MD /EHs /Oi- /D_STLP_USE_STATIC_LIB
// stlport
// ?parseBannerCarrierPosition@@YAXPAVINI@@PAX1PBX@Z @0x0046F179 270B
// Evidence: PC table C45530 BannerCarrierPosition; INI colon seps +420; rowed getNextTokenOrNull plus StringBase set plus parseCoord2D plus vector push_back.
// Semantic donor: BFME1 reverse/attempts/0x0023e280.cpp. PC table C45530.
#include <vector>
extern "C" int __cdecl strcmp(const char *, const char *);
template<class T> class StringBase {
    void *data;
public:
    void set(const T *);
};
struct Coord2D { float x,y; };
class INI {
public:
    char unknown[0x420];
    const char *sepsColon;
    const char *getNextToken(const char *);
    const char *getNextTokenOrNull(const char *);
    static void parseCoord2D(INI *,void *,void *,const void *);
};
class HordeContainUnitSlot {
public:
    StringBase<char> unitType;
    Coord2D pos;
    HordeContainUnitSlot();
};
struct HordeBannerSlot { HordeContainUnitSlot *value; };
namespace _STL {
template <> void vector<HordeBannerSlot>::push_back(const HordeBannerSlot &);
}
struct INIException { char *message; int code; };
extern "C" void rva002f681_fill(void *, int, const char *, ...);
__declspec(noreturn) void __stdcall _CxxThrowException(void *, void *);
struct BannerThrowInfoAnchor { int a,b,c,d; };
static const BannerThrowInfoAnchor bannerThrowInfoAnchor = {0,0,0,0};
// ?parseBannerCarrierPosition@@YAXPAVINI@@PAX1PBX@Z present-unmatched
void parseBannerCarrierPosition(INI *ini, void *instance, void *store, const void *userData)
{
  {
    HordeContainUnitSlot *slot = new HordeContainUnitSlot;
    HordeBannerSlot value;
    value.value = slot;
    const char *token = ini->getNextTokenOrNull(ini->sepsColon);
    if (!token || strcmp(token,"UnitType") != 0) goto badUnit;
    slot->unitType.set(ini->getNextToken(ini->sepsColon));
    token = ini->getNextTokenOrNull(ini->sepsColon);
    if (!token || strcmp(token,"Pos") != 0) goto badPos;
    Coord2D pos;
    INI::parseCoord2D(ini,0,&pos,0);
    slot->pos.x = pos.x;
    slot->pos.y = pos.y;
    ((_STL::vector<HordeBannerSlot> *)store)->push_back(value);
    return;
  }
badPos:
  {
    INIException e;
    rva002f681_fill(&e,3,"'Pos' expected");
    _CxxThrowException(&e,(void *)&bannerThrowInfoAnchor);
  }
badUnit:
  {
    INIException e;
    rva002f681_fill(&e,3,"UnitType expected");
    _CxxThrowException(&e,(void *)&bannerThrowInfoAnchor);
  }
}
