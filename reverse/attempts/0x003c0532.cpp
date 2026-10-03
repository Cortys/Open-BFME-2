// ?Rva003C0532Do@@YGX_N@Z
// partial score=0.93 date=2026-10-04
// ?Rva003C0532Do@@YGX_N@Z
// partial score=0.93 date=2026-10-02
// cl: /Ireference/shims/bfme2_ascii /DNDEBUG /MD /EHsc /O1
// ?Rva003C0532Do@@YGX_N@Z @0x003C0532 88B. Audio slot 0x98 with (arg==0) then AsciiString "/___MusicScript_Init" temp to ScriptEngine slot then set byte. Evidence: callees rowed, string literal in packet, externs TheAudio g_Va009FE16C, caller 0x003CC10A.
#include "ascii_string.h"
extern class AudioManager *TheAudio;
class AudioManager
{
public:
	virtual void a00(); virtual void a01(); virtual void a02(); virtual void a03();
	virtual void a04(); virtual void a05(); virtual void a06(); virtual void a07();
	virtual void a08(); virtual void a09(); virtual void a10(); virtual void a11();
	virtual void a12(); virtual void a13(); virtual void a14(); virtual void a15();
	virtual void a16(); virtual void a17(); virtual void a18(); virtual void a19();
	virtual void a20(); virtual void a21(); virtual void a22(); virtual void a23();
	virtual void a24(); virtual void a25(); virtual void a26(); virtual void a27();
	virtual void a28(); virtual void a29(); virtual void a30(); virtual void a31();
	virtual void a32(); virtual void a33(); virtual void a34(); virtual void a35();
	virtual void a36(); virtual void a37(); 	virtual void a38(int x, int y, int b);
};
extern class ScriptEngine *g_Va009FE16C;
class ScriptEngine
{
public:
	void *rva0020881A(AsciiString s);
};
// ?Rva003C0532Do@@YGX_N@Z present-unmatched
void __stdcall Rva003C0532Do(bool flag)
{
	TheAudio->a38(0, 0, !flag);
	char buf[] = "/___MusicScript_Init";
	void *p = g_Va009FE16C->rva0020881A(AsciiString(buf));
	if (p != 0)
		*(unsigned char *)p = 1;
}
