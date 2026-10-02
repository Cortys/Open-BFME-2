// cl: /O1 /Oy- /DNDEBUG /MD /EHsc
// ?Rva00542B61Parse@@YAXPAVINI@@PAX11@Z, retail 0x00542B61, 64 bytes.
// INI field parser: initFromINI(instance) via rowed 0x0002DE78 with table
// g_00C69638, then if first dword of instance is 0 throw INIException code 8
// with retail literal "AutoResolveArmor entry in Object block: Armor name MUST
// be specified" (string_xrefs.tsv). Sibling weapon parser at 0x00542997 uses
// the same shape with its own table. Evidence: packet disassembly, caller
// 0x00542BA1 (4 __cdecl args, caller cleans 0x10), prev/next flags.
struct FieldParse;

class INI
{
public:
	void initFromINI(void *what, const FieldParse *table);
};

extern const FieldParse g_00C69638;

struct INIException
{
	char *mFailureMessage;
	int mErrorCode;
};

extern "C" void rva002f681_fill(void *e, int argCount, const char *format, ...);

extern "C" void __stdcall _CxxThrowException(void *pExceptionObject, const _s__ThrowInfo *pThrowInfo);
struct Rva00542B61ThrowInfoAnchor { int a; int b; int c; int d; };
static const Rva00542B61ThrowInfoAnchor rva00542B61ThrowInfoAnchor = { 0, 0, 0, 0 };

void __cdecl Rva00542B61Parse(INI *ini, void *a2, void *instance, void *a4)
{
	INIException e;
	ini->initFromINI(instance, &g_00C69638);
	if (*(void **)instance == 0)
	{
		rva002f681_fill(&e, 8, "AutoResolveArmor entry in Object block: Armor name MUST be specified");
		_CxxThrowException(&e, (const _s__ThrowInfo *)&rva00542B61ThrowInfoAnchor);
	}
}
