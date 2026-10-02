// ?Rva0051C2E2Update@@YGXPAHHH@Z
// partial score=0.99 date=2026-10-02
// cl: /Ireference/shims/bfme2_ascii /O1 /G7 /EHsc /arch:SSE /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB
// ?Rva0051C2E2Update@@YGXPAHHH@Z @0x0051C2E2 201B: free stdcall ScoreRegionBonus Apt update via Ascii format plus GameText slot40 plus Unicode format plus bfmeSetText; evidence strings APT:ScoreRegionBonus%d plus callers 0x0051E10E 0x0051E140 0x0051E1A0 plus globals TheGameText TheRva00222A8BTarget g_00BC26DC
#include "ascii_string.h"
#include "unicode_string.h"

class GameTextInterface {
public:
	virtual ~GameTextInterface() {}
	virtual void pad01();
	virtual void pad02();
	virtual void pad03();
	virtual void pad04();
	virtual void pad05();
	virtual void pad06();
	virtual void pad07();
	virtual void pad08();
	virtual void pad09();
	virtual void pad10();
	virtual void pad11();
	virtual void pad12();
	virtual void pad13();
	virtual void pad14();
	virtual void pad15();
	virtual const UnicodeString *getBonusText(int a, int b, int c);
};

extern GameTextInterface *TheGameText;

class BfmeAptWindowManager {
public:
	void bfmeSetText(const AsciiString &key, const UnicodeString &val, bool flag);
};

class Rva00222A8BTarget;
extern Rva00222A8BTarget *TheRva00222A8BTarget;

extern unsigned short g_00BC26DC;

// ?Rva0051C2E2Update@@YGXPAHHH@Z present-unmatched
void __stdcall Rva0051C2E2Update(int *counter, int a2, int a3)
{
	AsciiString key;
	key.format("APT:ScoreRegionBonus%d", *counter);
	if (a3 > 0) {
		UnicodeString val;
		val.format(TheGameText->getBonusText(a2, 0, a3));
		((BfmeAptWindowManager *)TheRva00222A8BTarget)->bfmeSetText(key, val, false);
		(*counter)++;
	} else if (a3 < 0) {
		{
			UnicodeString val2((const unsigned short *)&g_00BC26DC);
			((BfmeAptWindowManager *)TheRva00222A8BTarget)->bfmeSetText(key, val2, false);
		}
		(*counter)++;
	}
}
