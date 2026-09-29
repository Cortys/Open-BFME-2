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

// ?Rva003BD412Set@@YGXE@Z @0x003BD412 13B: free forwarder to rowed Rva004E432ASet.
// Evidence: push dword [esp+4] call 0x004E432A pop ecx ret 4; callee is
// void(unsigned char) in Rva0050E9D3Enable.cpp; caller 0x003CEC92 in huge
// dispatch; Rva0050E9D3Enable.cpp names 0x003BD412 as dword forwarder.
void Rva004E432ASet(unsigned char value);
void __stdcall Rva003BD412Set(unsigned char value)
{
	Rva004E432ASet(value);
}
