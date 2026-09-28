// cl: /O1
//
// ?Rva003BCFC9Set@@YGX_N@Z @0x003BCFC9 11B: free forwarder to PartitionManager::rva007397A0.
// Evidence: mov ecx,[0x00DFE74C] jmp 0x007397A0; callee is PartitionManager
// shroud thunk void(bool); slot 0xDFE74C is TheShroudManager (PartitionManager*
// view per W3DPropBuffer); caller 0x003CE614 in ScriptActions dispatch.

class PartitionManager
{
public:
	void rva007397A0(bool value);
};

#define TheShroudManager (*(PartitionManager **)0x00DFE74C)

void __stdcall Rva003BCFC9Set(bool value)
{
	TheShroudManager->rva007397A0(value);
}
