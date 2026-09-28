// cl: /O1
//
// ?Rva003BC6C7Set@@YGXH@Z @0x003BC6C7 18B: free wrapper forwarding to GameLogic::rva003BA5DD.
// Evidence: mov ecx,[0x00DFE78C] test ecx je ret jmp 0x003BA5DD ret 4; chain
// from just-landed 0x003BA5DD; sole caller 0x003CD546 in ScriptActions dispatch.

class GameLogic
{
public:
	void rva003BA5DD(int value);
};

#define TheGameLogic (*(GameLogic **)0x00DFE78C)

void __stdcall Rva003BC6C7Set(int value)
{
	if (TheGameLogic)
		TheGameLogic->rva003BA5DD(value);
}
