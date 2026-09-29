// ?rva0002DFE2@INI@@QAEPBDPBDPA_N@Z
// partial score=0.95 date=2026-09-29
// ?rva0002DFE2@INI@@QAEPBDPBDPA_N@Z
// partial score=0.95 date=2026-09-29
// cl: /O1 /Oy- /DNDEBUG /MD /GX- /Oi-
//
// ?rva0002DFE2@INI@@QAEPBDPBDPA_N@Z, retail 0x0002DFE2, 91 bytes.
// INI next-token with macro expansion and changed flag: getNextTokenOrNull
// via rowed 0x002DEED, throw INIException(3) via rowed 0x002F681 plus pinned
// _CxxThrowException when null and no out ptr, else preprocessMacro via
// pinned 0x002D0A9 and set *out = (expanded != token). Same flags/TU shape
// as INI_getNextToken siblings. Unblocks 8 234B parsers.
//
// NEAR MISS (87B vs 91B, 35/37 insns, single structural diff): retail keeps
// a jmp-plus-xor-eax-eax tail before the shared epilogue, ours folds the
// null-token return-0 into the epilogue since eax is provably 0 there.
// Tried: if/else with throw in then (xor lands early after throw); late
// shared return via if-changed-store-return-expanded plus trailing return 0
// (reaches 91B with only the flagtest je displacement off, but that shape
// returns 0 for null changed where retail returns expanded, so its
// semantics are wrong); dead return 0 after return expanded (eliminated).
// Next: find a spelling that keeps the redundant xor late without changing
// the flagtest je target (END) or the null-path semantics.

class INI
{
public:
	const char *getNextTokenOrNull(const char *seps);
	const char *rva0002DFE2(const char *seps, bool *changed);
	static const char *preprocessMacro(const char *token);

private:
	char _pad[0x418];
	const char *m_seps;
};

struct INIException
{
	char *mFailureMessage;
	int mErrorCode;
};

extern "C" void rva002f681_fill(void *dst, int code, const char *fmt, ...);
__declspec(noreturn) void __stdcall _CxxThrowException(void *pExc, void *pInfo);

// Address anchor only: the throw site pushes this object's address as an
// immediate (DIR32, copied from retail's INIException throwinfo at
// 0x8FE2FC — the same chain the INI_getNextToken TU throws through). Its
// content is never compared; the real chain lives in the retail image.
struct GetNextTokenBoolThrowInfoAnchor { int a; int b; int c; int d; };
static const GetNextTokenBoolThrowInfoAnchor gntbThrowInfoAnchor = { 0, 0, 0, 0 };

// ?rva0002DFE2@INI@@QAEPBDPBDPA_N@Z present-unmatched
const char *INI::rva0002DFE2(const char *seps, bool *changed)
{
	const char *token = getNextTokenOrNull(seps);
	if (token == 0) {
		if (changed != 0)
			return 0;
		INIException e;
		rva002f681_fill(&e, 3, "Expected additional data after '%s'", seps);
		_CxxThrowException(&e, (void *)&gntbThrowInfoAnchor);
	}
	const char *expanded = preprocessMacro(token);
	if (changed != 0)
		*changed = (expanded != token);
	return expanded;
}
