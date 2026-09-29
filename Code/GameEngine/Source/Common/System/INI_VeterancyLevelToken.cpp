// cl: /O1 /Oy- /DNDEBUG /MD /GX- /Oi-
//
// ?rva0033AFBB@Rva0033AFBB@@QAE_NPBDPA_N1@Z @0x0033AFBB 308B
// Single-token VeterancyLevel bitstring worker. Evidence: the pinned
// BitFlags<21> name table VeterancyLevelNames at 0x00DBAA40 is baked in as an
// immediate, the "you may not mix normal and +- ops in bitstring lists"
// INIException filler-throw matches INI_parseBitString32, and the two call
// sites in 0x0033B84E drive it per token (false return = NONE break).

#define NULL 0

typedef int Int;
typedef unsigned int UnsignedInt;
typedef bool Bool;
typedef const char *ConstCharPtr;
typedef const ConstCharPtr *ConstCharPtrArray;

extern const char *VeterancyLevelNames[21]; ///< retail [0x00DBAA40]

struct INIException
{
	char *mFailureMessage;
	int mErrorCode;
};

class Rva0033AFBB
{
public:
	Bool rva0033AFBB(const char *token, Bool *foundNormal, Bool *foundAddOrSub);

private:
	unsigned m_words[1];
};

extern "C" void rva002f681_fill(void *dst, int code, const char *fmt, ...);
__declspec(noreturn) void __stdcall _CxxThrowException(void *pExc, void *pInfo);
extern "C" __declspec(dllimport) int __cdecl _strcmpi(const char *a, const char *b);
extern "C" int rva002bcab_scanIndex(const char *token, ConstCharPtrArray nameList, Bool *found, Bool doThrow);
extern "C" void *memset(void *dst, Int val, unsigned n);

// Address anchor only: the throw site pushes this object's address as an
// immediate (DIR32, copied from retail's throwinfo at 0xCFE2FC). Content is
// never compared; the real chain lives in the retail image.
struct Rva0033AFBBThrowInfoAnchor { int a; int b; int c; int d; };
static const Rva0033AFBBThrowInfoAnchor rva0033AFBBThrowInfoAnchor = { 0, 0, 0, 0 };

Bool Rva0033AFBB::rva0033AFBB(const char *token, Bool *foundNormal, Bool *foundAddOrSub)
{
	Bool found;

	if (_strcmpi(token, "NONE") == 0) {
		if (*foundNormal || *foundAddOrSub) {
			INIException e;
			rva002f681_fill(&e, 2, "you may not mix normal and +- ops in bitstring lists");
			_CxxThrowException(&e, (void *)&rva0033AFBBThrowInfoAnchor);
		}
		memset(m_words, 0, sizeof(m_words));
		return false;
	}

	if (token[0] == '+') {
		if (*foundNormal) {
			INIException e;
			rva002f681_fill(&e, 2, "you may not mix normal and +- ops in bitstring lists");
			_CxxThrowException(&e, (void *)&rva0033AFBBThrowInfoAnchor);
		}
		UnsignedInt bitIndex = rva002bcab_scanIndex(token + 1, VeterancyLevelNames, &found, true);
		m_words[bitIndex >> 5] |= (1u << (bitIndex & 31));
		*foundAddOrSub = true;
	} else if (token[0] == '-') {
		if (*foundNormal) {
			INIException e;
			rva002f681_fill(&e, 2, "you may not mix normal and +- ops in bitstring lists");
			_CxxThrowException(&e, (void *)&rva0033AFBBThrowInfoAnchor);
		}
		UnsignedInt bitIndex = rva002bcab_scanIndex(token + 1, VeterancyLevelNames, &found, true);
		m_words[bitIndex >> 5] &= ~(1u << (bitIndex & 31));
		*foundAddOrSub = true;
	} else {
		if (*foundAddOrSub) {
			INIException e;
			rva002f681_fill(&e, 2, "you may not mix normal and +- ops in bitstring lists");
			_CxxThrowException(&e, (void *)&rva0033AFBBThrowInfoAnchor);
		}

		if (!*foundNormal)
			memset(m_words, 0, sizeof(m_words));

		UnsignedInt bitIndex = rva002bcab_scanIndex(token, VeterancyLevelNames, &found, true);
		m_words[bitIndex >> 5] |= (1u << (bitIndex & 31));
		*foundNormal = true;
	}
	return true;
}
