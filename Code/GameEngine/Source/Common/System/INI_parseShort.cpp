// cl: /O1 /Oy- /DNDEBUG /MD /GX /Oi-
//
// ?parseShort@INI@@SAXPAV1@PAX1PBX@Z, retail 0x002EEB9, 79 bytes.
// Dedicated ebp-frame TU (same INI scanner family as INI_parseByte.cpp).
//
// BFME1 reference (reference/open-bfme-1/Code/GameEngine/Source/Common/INI/ini_parsers.cpp,
// INI::parseShort): range-checked signed-half store. Same BFME2 deltas as
// parseByte (explicit NULL seps, member scanInt, filler plus throw).

class INI
{
public:
	const char *getNextToken(const char *seps);
	int scanInt(const char *token);
	static void parseShort(INI *ini, void *instance, void *store, const void *userData);
};

struct INIException
{
	INIException(int argCount, const char *format, ...);
	char *mFailureMessage;
	int mErrorCode;
};

extern "C" void __stdcall _CxxThrowException(void *pExceptionObject, const _s__ThrowInfo *pThrowInfo);

// Address anchor only: the throw site pushes this object's address as an
// immediate (DIR32, copied from retail's throwinfo at 0xCFE2FC). Content is
// never compared; the real chain lives in the retail image.
struct ParseShortThrowInfoAnchor { int a; int b; int c; int d; };
static const ParseShortThrowInfoAnchor parseShortThrowInfoAnchor = { 0, 0, 0, 0 };

// ?parseShort@INI@@SAXPAV1@PAX1PBX@Z
void INI::parseShort(INI *ini, void *instance, void *store, const void *userData)
{
	int value = ini->scanInt(ini->getNextToken(0));
	if (value < -32768 || value > 32767) {
		INIException e(3, "value out of range, expected -32768..32767");
		_CxxThrowException(&e, (const _s__ThrowInfo *)&parseShortThrowInfoAnchor); __assume(0);
	}
	*(unsigned short *)store = (unsigned short)value;
}
