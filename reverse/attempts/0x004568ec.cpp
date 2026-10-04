// ?rva004568EC@Rva004568EC@@QAEXPAVThing@@PAMPAUCoord3D@@22PBU3@@Z
// partial score=0.93 date=2026-10-04
// cl: /Ireference/shims/bfme2_ascii /Ireference/shims/sweep /G7 /arch:SSE /MD /GX /DNDEBUG /DWIN32 /D_WINDOWS /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_STLP_NO_EXCEPTIONS /Ivendor/stlport /Ireference/shims/asciistring_outofline /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Include /O1
// ?rva004568EC@Rva004568EC@@QAEX... @0x004568EC 338B
// Bridge scaffold placement: getBridgeScaffold 0x4582F3, setPosition 0x30AA80,
// setOrientation 0x30AB9D, Coord3D length 0x3571 twice, MAX_LINE_TILING_FACTOR,
// ret 0x18 with ecx+4 member. Member proven by mov eax,[ecx+4]; honest Rva owner.
class Object;
struct Coord3D {
  float x;
  float y;
  float z;
  float length() const;
};
class Thing {
public:
  void setPosition(const Coord3D *pos);
  void setOrientation(float ang);
};
class BridgeScaffoldBehaviorInterface {
public:
  virtual void v0(const Coord3D *a, const Coord3D *b, const Coord3D *c);
  virtual void v1(int x);
  virtual void v2();
  virtual void v3();
  virtual void v4(float f);
  virtual void v5(float f);
};
class BridgeScaffoldBehavior {
public:
  static BridgeScaffoldBehaviorInterface *getBridgeScaffoldBehaviorInterfaceFromObject(Object *obj);
};
struct BridgeData {
  float f0;
  float f1;
  float f2;
  float f3;
};
class Rva004568EC {
public:
  void *pad;
  BridgeData *data;
  void rva004568EC(Thing *thing, float *ang, Coord3D *a, Coord3D *b, Coord3D *c, const Coord3D *d);
};
extern const float g_00BC2A10;

// ?rva004568EC@Rva004568EC@@QAEX... present-unmatched
void Rva004568EC::rva004568EC(Thing *thing, float *ang, Coord3D *a, Coord3D *b, Coord3D *c, const Coord3D *d)
{
  if (!thing)
    return;
  if (!ang)
    return;
  if (!b)
    return;
  if (!c)
    return;
  BridgeData *p = data;
  BridgeScaffoldBehaviorInterface *iface = BridgeScaffoldBehavior::getBridgeScaffoldBehaviorInterfaceFromObject((Object *)thing);
  Coord3D tmp;
  tmp.x = b->x;
  tmp.y = b->y;
  tmp.z = b->z - a->x - g_00BC2A10;
  thing->setPosition(&tmp);
  iface->v0(&tmp, b, c);
  iface->v1(1);
  thing->setOrientation(*ang);
  Coord3D v1;
  v1.x = c->x - b->x;
  v1.y = c->y - b->y;
  v1.z = c->z - b->z;
  Coord3D v2;
  v2.x = d->x - b->x;
  v2.y = d->y - b->y;
  v2.z = d->z - b->z;
  float len1 = v1.length();
  float len2 = v2.length();
  iface->v4(len1 / len2 * p->f2);
  iface->v5(p->f3);
}
