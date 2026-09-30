// cl: /O1 /Oy- /DNDEBUG /MD /GX-
// ?rva004135CD@Rva004135CD@@QAEXPAVINI@@@Z @0x004135CD 65B
// INI parse validator: initFromINI(this) through table 0x00839A78 (rowed
// 0x0002DE78), then throw INIException code 3 with the retail message when
// the int at +0 is negative. Throw idiom (filler 0x0002F681 plus CxxThrow
// 0x00629094 plus throwinfo anchor 0x00CFE2FC) from RankInfoParse. Evidence:
// unlock lane; caller 0x004138C7 (Duplicate message sibling in string_xrefs);
// string_xrefs full message; prev/next Common TUs.
struct FieldParse;
class INI
{
public:
	void initFromINI(void *what, const FieldParse *table);
};
extern const FieldParse g_00839A78;
extern "C" void rva002f681_fill(void *dst, int code, const char *fmt, ...);
__declspec(noreturn) void __stdcall _CxxThrowException(void *pExc, void *pInfo);
struct Rva004135CDThrowInfoAnchor { int a; int b; int c; int d; };
static const Rva004135CDThrowInfoAnchor rva004135CDThrowInfoAnchor = { 0, 0, 0, 0 };
class Rva004135CD
{
public:
	void rva004135CD(INI *ini);
private:
	int m_value00;
};
// ?rva004135CD@Rva004135CD@@QAEXPAVINI@@@Z
void Rva004135CD::rva004135CD(INI *ini)
{
	ini->initFromINI(this, &g_00839A78);
	if (m_value00 < 0)
	{
		char exc[8];
		rva002f681_fill(exc, 3, "Must provide a MinSciencePurchasePointsForBonus, and it must be >= 0");
		_CxxThrowException(exc, (void *)&rva004135CDThrowInfoAnchor);
	}
}
