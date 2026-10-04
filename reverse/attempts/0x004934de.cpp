// ?isReady@SpecialPowerModule@@UBE_NXZ
// partial score=1.0 date=2026-10-04
// cl: /O1 /G7 /Oa /GX- /MD
// ZH isReady semantic lead, target4934DE/128 adds blocked+28 and status70.
// MI receiver is the SpecialPowerModuleInterface subobject at primary+10.
// Layout/access evidence independently agrees with rowed getPowerName4934B8.
class Overridable { public: const Overridable *friend_getFinalOverride()const; char pad[0x10]; };
class SpecialPowerTemplate:public Overridable { public: unsigned unknown10;unsigned id;char pad18[0x59-0x18];bool shared; bool isSharedNSync()const { return ((const SpecialPowerTemplate*)friend_getFinalOverride())->shared; } };
class Player { public: unsigned getOrStartSpecialPowerReadyFrame(const SpecialPowerTemplate *); };
enum ObjectStatusTypes { Status70=70 };
class Object { public: bool testStatus(ObjectStatusTypes)const;Player *getControllingPlayer()const; };
class GameLogic;extern GameLogic *TheGameLogic;
struct SpecialReadyFrameView { char pad[0x40];unsigned frame; };
static unsigned frame(){return ((SpecialReadyFrameView*)TheGameLogic)->frame;}
class ModuleData { public: virtual ~ModuleData(); };
class SpecialPowerModuleData:public ModuleData { public: int unknown4;const SpecialPowerTemplate *power; };
class ObjectModule { protected:virtual ~ObjectModule();const ModuleData *data;Object *object; };
class BehaviorModuleInterface { public:virtual void anchor(); };
class BehaviorModule:public ObjectModule,public BehaviorModuleInterface { protected:virtual ~BehaviorModule(); };
class SpecialPowerModuleInterface { public:virtual bool isReady()const=0; };
class SpecialPowerModule:public BehaviorModule,public SpecialPowerModuleInterface {
public:virtual bool isReady()const;
 int unknown14;unsigned available;int paused;unsigned pausedOnFrame;float pausedPercent;bool blocked;
};
bool SpecialPowerModule::isReady()const {
 if(blocked)return false;
 const Object *obj=object;
 if(obj->testStatus(Status70))return false;
 const SpecialPowerModuleData *modData=(const SpecialPowerModuleData*)data;
 if(obj&&modData) {
  Player *player=obj->getControllingPlayer();
  if(player&&modData->power->isSharedNSync())
   return frame()>=player->getOrStartSpecialPowerReadyFrame(modData->power);
 }
 return paused==0&&frame()>=available;
}
