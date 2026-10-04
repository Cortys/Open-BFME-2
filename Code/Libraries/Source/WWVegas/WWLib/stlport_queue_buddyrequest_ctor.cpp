// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ??0?$queue@VBuddyRequest@@V?$deque@VBuddyRequest@@V?$allocator@VBuddyRequest@@@_STL@@@_STL@@@_STL@@QAE@XZ 0x00551A06 21B retail queue<BuddyRequest> default ctor; caller GameSpyBuddyMessageQueue ctor at 0x00551ACE; callee _Deque_base ctor rowed in stlport_pod_large_bodies
#include <queue>
class BuddyRequest { char m_bfmeBody[0x2B8]; };
template _STL::queue<BuddyRequest>::queue();
