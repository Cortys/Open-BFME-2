// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// ??0?$queue@VBuddyResponse@@V?$deque@VBuddyResponse@@V?$allocator@VBuddyResponse@@@_STL@@@_STL@@@_STL@@QAE@XZ @0x00551A1B 21B retail queue<BuddyResponse> default ctor; caller GameSpyBuddyMessageQueue ctor at 0x00551ADA; callee _Deque_base ctor rowed for same-size BfmeOpaqueOwnedRecord2148 0x00550C06 via ICF. Evidence: pinned name plus sibling queue<BuddyRequest> 0x00551A06 21B same shape plus BuddyResponse 0x864 body from BuddyResponseDequePushBackAux.
#include <queue>
class BuddyResponse { char m_bfmeBody[0x864]; };
template _STL::queue<BuddyResponse>::queue();
