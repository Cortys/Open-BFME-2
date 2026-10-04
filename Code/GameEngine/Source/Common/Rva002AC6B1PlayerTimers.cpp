// cl: /O1 /G7 /GX- /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc /Ireference/shims/bfmelist /ICode/GameEngine/Source/Common
// stlport
// Semantic donor: reference/GeneralsMD/Code/GameEngine/Source/Common/RTS/Player.cpp
// addNewSharedSpecialPowerTimer/getOrStartSpecialPowerReadyFrame. Native2AC6B1/48 and
//2AC7A0/70 independently prove list+704, ID from finaloverride+14 and frame40.
// Receiver is an ABI prefix, not a recovered complete Player definition.
#include <list>
#include "BfmeSpecialPowerTimer8.h"
namespace _STL {
template<> void list<BfmeSpecialPowerTimer8,allocator<BfmeSpecialPowerTimer8> >::push_back(const BfmeSpecialPowerTimer8 &);
}
class Overridable { public:const Overridable *friend_getFinalOverride()const; };
class SpecialPowerTemplate;
struct Rva002AC6B1TemplateView { unsigned char prefix[0x14];unsigned id; };
class GameLogic;extern GameLogic *TheGameLogic;
struct Rva002AC6B1FrameView { unsigned char prefix[0x40];unsigned frame; };
class Rva002AC6B1PlayerTimers {
public:
 void addTimer(const SpecialPowerTemplate *,unsigned);
 unsigned getOrStart(const SpecialPowerTemplate *);
 unsigned char prefix[0x704];
 _STL::list<BfmeSpecialPowerTimer8> timers;
};
void Rva002AC6B1PlayerTimers::addTimer(const SpecialPowerTemplate *temp,unsigned frame) {
 BfmeSpecialPowerTimer8 timer;
 timer.m_templateID=((const Rva002AC6B1TemplateView*)((const Overridable*)temp)->friend_getFinalOverride())->id;
 timer.m_readyFrame=frame;
 timers.push_back(timer);
}
// ?getOrStart@Rva002AC6B1PlayerTimers present-unmatched
unsigned Rva002AC6B1PlayerTimers::getOrStart(const SpecialPowerTemplate *temp) {
 unsigned lookupID=((const Rva002AC6B1TemplateView*)((const Overridable*)temp)->friend_getFinalOverride())->id;
 unsigned now=((Rva002AC6B1FrameView*)TheGameLogic)->frame;
 for(_STL::list<BfmeSpecialPowerTimer8>::iterator it=timers.begin();it!=timers.end();++it)
  if(it->m_templateID==lookupID)return it->m_readyFrame;
 addTimer(temp,now);
 return now;
}
