// ?rva000B664E@Rva000B664E@@QAE_NPBDPA_N1@Z
// partial score=0.96 date=2026-10-01
// cl: /Ireference/shims/bfme2_ascii /O1 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// ?rva000B664E@Rva000B664E@@QAE_NPBDPA_N1@Z @0x000B664E 308B
// Bitmask parse over ModelConditionNames via scanIndex worker; 0x4c memset plus set/clear.
// Evidence: callers 0x000B93EB 0x000B9437 0x0033398D; strings NONE plus mix-error; INIException throw.
void *__cdecl ji_006291ae(void *dest, int val, unsigned int count);
#pragma comment(linker, "/alternatename:?ji_006291ae@@YAPAXPAXHI@Z=?ji_006291ae@@YAXXZ")

extern "C" __declspec(dllimport) int __cdecl _strcmpi(const char *a, const char *b);
extern const char *const ModelConditionNames[];
extern "C" int rva002bcab_scanIndex(const char *token, const char *const *nameList, bool *found, bool doThrow);

struct INIException
{
	char *message;
	int code;
	INIException() {}
	INIException(int argCount, const char *format, ...);
};
extern "C" void __stdcall _CxxThrowException(void *pExceptionObject, const _s__ThrowInfo *pThrowInfo);
struct Rva000B664EThrowInfoAnchor { int a; int b; int c; int d; };
static const Rva000B664EThrowInfoAnchor rva000B664EThrowInfoAnchor = { 0, 0, 0, 0 };

class Rva000B664E
{
public:
	bool rva000B664E(const char *token, bool *normalSeen, bool *plusMinusSeen);
private:
	unsigned int m_bits[19];
};

// ?rva000B664E@Rva000B664E@@QAE_NPBDPA_N1@Z present-unmatched
bool Rva000B664E::rva000B664E(const char *token, bool *normalSeen, bool *plusMinusSeen)
{
	bool found;
	if (_strcmpi(token, "NONE") == 0)
	{
		if (*normalSeen != 0)
		{
			INIException e;
			e.INIException::INIException(2, "you may not mix normal and +- ops in bitstring lists");
			_CxxThrowException(&e, (const _s__ThrowInfo *)&rva000B664EThrowInfoAnchor); __assume(0);
		}
		if (*plusMinusSeen != 0)
		{
			INIException e;
			e.INIException::INIException(2, "you may not mix normal and +- ops in bitstring lists");
			_CxxThrowException(&e, (const _s__ThrowInfo *)&rva000B664EThrowInfoAnchor); __assume(0);
		}
		ji_006291ae(this, 0, 0x4c);
		return false;
	}
	if (token[0] == '+')
	{
		if (*normalSeen != 0)
		{
			INIException e;
			e.INIException::INIException(2, "you may not mix normal and +- ops in bitstring lists");
			_CxxThrowException(&e, (const _s__ThrowInfo *)&rva000B664EThrowInfoAnchor); __assume(0);
		}
		int index = rva002bcab_scanIndex(token + 1, ModelConditionNames, &found, true);
		m_bits[(unsigned int)index >> 5] |= (unsigned int)1 << (index & 31);
		*plusMinusSeen = true;
		return true;
	}
	if (token[0] == '-')
	{
		if (*normalSeen != 0)
		{
			INIException e;
			e.INIException::INIException(2, "you may not mix normal and +- ops in bitstring lists");
			_CxxThrowException(&e, (const _s__ThrowInfo *)&rva000B664EThrowInfoAnchor); __assume(0);
		}
		int index = rva002bcab_scanIndex(token + 1, ModelConditionNames, &found, true);
		m_bits[(unsigned int)index >> 5] &= ~((unsigned int)1 << (index & 31));
		*plusMinusSeen = true;
		return true;
	}
	if (*plusMinusSeen != 0)
	{
		INIException e;
		e.INIException::INIException(2, "you may not mix normal and +- ops in bitstring lists");
		_CxxThrowException(&e, (const _s__ThrowInfo *)&rva000B664EThrowInfoAnchor); __assume(0);
	}
	if (*normalSeen == 0)
		ji_006291ae(this, 0, 0x4c);
	int index = rva002bcab_scanIndex(token, ModelConditionNames, &found, true);
	m_bits[(unsigned int)index >> 5] |= (unsigned int)1 << (index & 31);
	*normalSeen = true;
	return true;
}
