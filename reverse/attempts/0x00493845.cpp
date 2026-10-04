// ?createViewObject@SpecialPowerModule@@IAEXPBUCoord3D@@@Z
// partial score=0.8755 date=2026-10-04
// cl: /O1 /EHsc /arch:SSE2 /MD /Ireference/shims/bfme2_ascii
// ZH SpecialPowerModule::createViewObject semantic lead; target null guard,
// 16-byte pointed creation mask and explicit partition refresh differ.
// Scratch ABI-prefix views only; complete target classes remain unreconciled.
#include "ascii_string.h"
struct Coord3D { float x,y,z; };
class Overridable { public: const Overridable *friend_getFinalOverride()const; };
struct PowerView { unsigned char prefix[0x4c];unsigned duration;float range; };
class SpecialPowerTemplate;
class Team;class Module;
enum NameKeyType { InvalidName=-1 };
class Player;
class Thing { public:void setPosition(const Coord3D *); };
class Object:public Thing { public:Player *getControllingPlayer()const;void setShroudClearingRange(float);void bfmeRefreshPartitionCells();protected:Module *findModule(NameKeyType)const;friend class Rva00493845; };
class DeletionUpdate { public:void setLifetimeRange(unsigned,unsigned); };
class NameKeyGenerator { public:NameKeyType nameToKey(const char *); };extern NameKeyGenerator *TheNameKeyGenerator;
class GlobalData;extern GlobalData *TheGlobalData;
struct GlobalView { unsigned char prefix[0xba4];AsciiString viewObject; };
struct PlayerView { unsigned char prefix[0x2ec];Team *team; };
class ThingFactory;extern ThingFactory *TheThingFactory;
class Rva002D06CA { public:void *rva002D06CA(const AsciiString *); };
struct CreateMask { unsigned int words[4]; };
class FactoryView { public:Object *create(const void *,Team *,const CreateMask *,bool); };
struct ModuleDataView { unsigned char prefix[8];const SpecialPowerTemplate *power; };
class Rva00493845 { public:void createViewObject(const Coord3D *);unsigned unknown0;ModuleDataView *data;Object *owner; };
void Rva00493845::createViewObject(const Coord3D *location) {
 if(!location)return;
 const SpecialPowerTemplate *power=data->power;
 if(!power)return;
 float range=((const PowerView*)((const Overridable*)power)->friend_getFinalOverride())->range;
 unsigned duration=((const PowerView*)((const Overridable*)power)->friend_getFinalOverride())->duration;
 if(range==0.0f||duration==0)return;
 AsciiString name(((GlobalView*)TheGlobalData)->viewObject);
 if(name.isEmpty())return;
 const void *t=((Rva002D06CA*)TheThingFactory)->rva002D06CA(&name);
 if(!t)return;
 CreateMask flags;memset(&flags,0,sizeof(flags));
 Object *obj=((FactoryView*)TheThingFactory)->create(t,((PlayerView*)owner->getControllingPlayer())->team,&flags,false);
 if(obj) {
  obj->setPosition(location);
  obj->setShroudClearingRange(range);
  obj->bfmeRefreshPartitionCells();
  static NameKeyType key=TheNameKeyGenerator->nameToKey("DeletionUpdate");
  DeletionUpdate *del=(DeletionUpdate*)obj->findModule(key);
  if(del)del->setLifetimeRange(duration,duration);
 }
}
