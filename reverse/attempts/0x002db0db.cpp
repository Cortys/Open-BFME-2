// ?Rva002DB0DBParse@@YAXPAVINI@@PAX@Z
// partial score=0.99 date=2026-10-04
// cl: /Ireference/shims/bfme2_ascii /O1 /Oy- /DNDEBUG /MD /GX- /Oi- /G7
// ?Rva002DB0DBParse@@YAXPAVINI@@PAX@Z @0x002DB0DB 238B: INI parse Transition Damage/Repair ToState EffectNum FX via rowed setters.
// Evidence: callees getNextSubToken 0x0002E06B scanIndexList 0x0002BD39 scanInt 0x0002ECCF StringBase 0x00037BA0 setters 0x002DAF2B 0x002DAFAC INIException 0x0002F681; data g_00DBCF30 0x009BCF30 g_00C03DC8 0x00803DC8 g_00C03D9C 0x00803D9C TI1 INIException; strings Transition Damage Repair ToState EffectNum FX.
#include "ascii_string.h"

class INI
{
public:
	const char *getNextSubToken(const char *s);
	int scanIndexList(const char *tok, const char * const *list);
	int scanInt(const char *tok);
};

class Rva002DAF2B
{
public:
	void rva002DAF2B(int a, int b, AsciiString c);
};

class Rva002DAFAC
{
public:
	void rva002DAFAC(int a, int b, AsciiString c);
};

class INIException
{
public:
	INIException(int argCount, const char *format, ...);
	INIException(const INIException &that);
	~INIException();
	char *mFailureMessage;
	int mErrorCode;
};

extern "C" __declspec(dllimport) int __cdecl _strcmpi(const char *a, const char *b);
extern const char * const g_00DBCF30[];
extern const char g_00C03DC8[];
extern const char g_00C03D9C[];

void Rva002DB0DBParse(INI *ini, void *obj)
{
	const char *tok = ini->getNextSubToken("Transition");
	bool isDamage;
	if (_strcmpi(tok, "Damage") == 0) {
		isDamage = true;
	} else {
		int rc = _strcmpi(tok, "Repair");
		if (rc == 0)
			isDamage = (char)rc;
		else
			throw INIException(3, g_00C03D9C);
	}
	const char *toTok = ini->getNextSubToken("ToState");
	int toIdx = ini->scanIndexList(toTok, g_00DBCF30);
	const char *effTok = ini->getNextSubToken("EffectNum");
	int eff = ini->scanInt(effTok);
	eff -= 1;
	if (eff < 0 || eff >= 3)
		throw INIException(3, g_00C03DC8, 3);
	const char *fxTok = ini->getNextSubToken("FX");
	if (isDamage)
		((Rva002DAF2B *)obj)->rva002DAF2B(toIdx, eff, AsciiString(fxTok));
	else
		((Rva002DAFAC *)obj)->rva002DAFAC(toIdx, eff, AsciiString(fxTok));
}
