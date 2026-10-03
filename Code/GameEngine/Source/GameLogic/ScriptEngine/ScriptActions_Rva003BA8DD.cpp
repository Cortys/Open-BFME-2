// cl: /O1 /DNDEBUG /MD /EHsc /arch:SSE
//
// ScriptActions float setter over the GameLogic singleton, retail 0x003BA8DD
// (22 bytes, ret 4): movss the argument into [TheGameLogic+0x950]. Boundary
// by ret-scan; no E8 caller image-wide (likely vtable-reached or dead), so
// the true identity stays open and the row carries an address token
// (opaque-holder precedent). The /arch:SSE flag reproduces the movss pair
// (ScriptActions_Rva003BC37C precedent).

struct GameLogicMirror
{
	unsigned char pad[0x950];
	float float0950;
};

extern GameLogicMirror *TheGameLogic;

struct Rva003BA8DDHolder
{
	void set(float value);
};

// ?set@Rva003BA8DDHolder@@QAEXM@Z
void Rva003BA8DDHolder::set(float value)
{
	TheGameLogic->float0950 = value;
}
// ?TheGameLogic@@3PAUGameLogicMirror@@A: the global at VA 0xdfe758 is ?TheGlobalData@@3PAVGlobalData@@A.
#pragma comment(linker, "/alternatename:?TheGameLogic@@3PAUGameLogicMirror@@A=?TheGlobalData@@3PAVGlobalData@@A")
