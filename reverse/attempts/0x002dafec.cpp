// ?Rva002DAFECParse@@YAXPAVINI@@PAX@Z
// partial score=0.95 date=2026-10-04
// cl: /O1 /MD /EHs /G7
// class-gate: allow AsciiString retail 0x002DAFEC needs private StringBase inheritance for mov ecx esp plus mov ebp-8 esp saved-esp shape per shape-lever 23, shared ascii_string.h gives transposed/missing saved-esp t=8 model=muse-10
// ?Rva002DAFECParse@@YAXPAVINI@@PAX@Z retail 0x002DAFEC 238 bytes.
// Free INI parser for Transition Damage/Repair ToState EffectNum OCL,
// calls 0x002DAEED (Damage) and 0x002DAF6C (Repair). Chain lane: calls
// 0x002DAF6C just landed, all callees rowed/pinned.
// Evidence: string literals Transition Damage Repair ToState EffectNum OCL,
// scanIndexList g_00DBCF30, throws g_00C03DC8 g_00C03D9C, TI1 INIException.
template <typename T> struct StringInlineData
{
	int m_refCount;
	int m_length;
	T m_text[1];
};
template <typename T> class StringBase
{
	friend class AsciiString;
private:
	StringBase();
	StringBase(const T *text);
	StringBase(const StringBase<T> &other);
	~StringBase();
	StringInlineData<T> *m_data;
};
class AsciiString : private StringBase<char>
{
public:
	AsciiString() : StringBase<char>() {}
	AsciiString(const char *text) : StringBase<char>(text) {}
	AsciiString(const AsciiString &other) : StringBase<char>(other) {}
	~AsciiString() {}
};

class INI
{
public:
	const char *getNextSubToken(const char *expected);
	int scanIndexList(const char *token, const char *const *list);
	int scanInt(const char *token);
};

class INIException
{
public:
	INIException(int argCount, const char *format, ...);
	char *mFailureMessage;
	int mErrorCode;
	INIException(const INIException &that);
	~INIException();
};

extern "C" __declspec(dllimport) int __cdecl _strcmpi(const char *a, const char *b);

class Rva002DACF4
{
public:
	void rva002DAEED(int a, int b, AsciiString s);
};

class Rva002DAF6C
{
public:
	void rva002DAF6C(int a, int b, AsciiString s);
};

extern const char *const g_00DBCF30[];
extern const char g_00C03DC8;
extern const char g_00C03D9C;

// ?Rva002DAFECParse@@YAXPAVINI@@PAX@Z present-unmatched
void __cdecl Rva002DAFECParse(INI *ini, void *obj)
{
	const char *tok = ini->getNextSubToken("Transition");
	bool isDamage;
	if (_strcmpi(tok, "Damage") == 0) {
		isDamage = true;
	} else {
		int cmpRepair = _strcmpi(tok, "Repair");
		if (cmpRepair != 0) {
			throw INIException(3, &g_00C03D9C);
		}
		isDamage = (unsigned char)cmpRepair;
	}
	const char *toState = ini->getNextSubToken("ToState");
	int stateIdx = ini->scanIndexList(toState, g_00DBCF30);
	const char *effectTok = ini->getNextSubToken("EffectNum");
	int effect = ini->scanInt(effectTok);
	int idx = effect;
	--idx;
	if (idx < 0 || idx >= 3) {
		throw INIException(3, &g_00C03DC8, 3);
	}
	const char *oclTok = ini->getNextSubToken("OCL");
	if (isDamage) {
		((Rva002DACF4 *)obj)->rva002DAEED(stateIdx, idx, AsciiString(oclTok));
	} else {
		((Rva002DAF6C *)obj)->rva002DAF6C(stateIdx, idx, AsciiString(oclTok));
	}
}
