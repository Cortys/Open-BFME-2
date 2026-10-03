// cl: /O1
// ?Rva003BC830Clear@@YGXABVAsciiString@@@Z @0x003BC830 62B: free stdcall clearing dword via rowed clearer for each player in mask.
// Evidence: push ebp mov ebp,esp mov ecx,[0xDFE16C]=g_Va009FE16C push 0 push [ebp+8] call rowed rva00357475 0x00357475 test eax mov [ebp+8],eax je end; mov ecx,[0xDFEEE8]=ThePlayerList lea eax,[ebp+8] push eax call rowed getEachPlayerFromMask 0x002A7BC9 test eax je skip mov ecx,eax call rowed clear 0x002A9F0F; cmp [ebp+8],0 jne loop pop ebp ret 4; caller 0x003CDB02; sibling Rva003BB31DClear same mask loop shape.
class AsciiString;
class Player;
class Rva002A9F0FDwordClearer
{
public:
	void clear();
};
class ScriptEngine
{
public:
	int rva00357475(const AsciiString &name, bool *matchedSpecialName);
};
extern ScriptEngine *g_Va009FE16C;
class PlayerList
{
public:
	Player *getEachPlayerFromMask(int &mask);
};
extern PlayerList *ThePlayerList;

void __stdcall Rva003BC830Clear(const AsciiString &name)
{
	int mask = g_Va009FE16C->rva00357475(name, 0);
	if (mask == 0)
		return;
	Player *p;
	do {
		p = ThePlayerList->getEachPlayerFromMask(mask);
		if (p)
			((Rva002A9F0FDwordClearer *)p)->clear();
	} while (mask != 0);
}
