// cl: /O1 /DNDEBUG /MD /arch:SSE
// ?parseCommonStuff@@YAXPAVINI@@PBQBDAAH222@Z, retail 0x00360613, 118 bytes.
// DamageFX parseCommonStuff: BFME1 Code/GameEngine/Source/Common/DamageFX.cpp
// parseCommonStuff shape verbatim (vet pair via scanIndexList or 0/3, damage via
// Default->0/29 else scanIndexList). BFME2 deltas retail-measured: damageLast
// Default is 29 (30 types, 0x1d) not 15, second list is retail array at 0x9BFFF0.
// Evidence: 4 callers 0x360689/702/774/7E6 are DamageFX::parseAmount (scanReal),
// parseMajorFXList/parseMinorFXList (parseFXList) and parseTime (parseDuration);
// callees rowed getNextToken 0x2DF97 scanIndexList 0x2BD39 plus strcmpi IAT.
// Static with 4 callers in this TU: /O1 outlines custom eax/ebx/edi convention.

typedef const char *ConstCharPtr;
typedef const ConstCharPtr *ConstCharPtrArray;
typedef int Int;
typedef float Real;
typedef unsigned int UnsignedInt;

class INI
{
public:
	const char *getNextToken(const char *seps);
	int scanIndexList(const char *token, ConstCharPtrArray nameList);
	float scanReal(const char *token);
	static void parseFXList(INI *ini, void *instance, void *store, const void *userData);
	static void parseDurationUnsignedInt(INI *ini, void *instance, void *store, const void *userData);
};

extern "C" __declspec(dllimport) int __cdecl _strcmpi(const char *a, const char *b);

// Descriptive alias of the retail damage-name pointer array at VA 0xDBFFF0
// (RVA 0x9BFFF0); the push is DIR32-masked so only the reference matters.
extern const char * const DamageFXDamageTypeNames[];

#define DAMAGE_NUM_TYPES 30
#define LEVEL_FIRST 0
#define LEVEL_LAST 3

struct DamageDFX
{
	Real m_amountForMajorFX;
	void *m_majorDamageFXList;
	void *m_minorDamageFXList;
	UnsignedInt m_damageFXThrottleTime;
};

class DamageFX
{
public:
	static void parseAmount(INI *ini, void *instance, void *store, const void *userData);
	static void parseMajorFXList(INI *ini, void *instance, void *store, const void *userData);
	static void parseMinorFXList(INI *ini, void *instance, void *store, const void *userData);
	static void parseTime(INI *ini, void *instance, void *store, const void *userData);
	DamageDFX m_dfx[DAMAGE_NUM_TYPES][4];
};

static void parseCommonStuff(INI *ini, ConstCharPtrArray names, int &vetFirst, int &vetLast, int &damageFirst, int &damageLast)
{
	if (names)
	{
		vetFirst = ini->scanIndexList(ini->getNextToken(0), names);
		vetLast = vetFirst;
	}
	else
	{
		vetFirst = LEVEL_FIRST;
		vetLast = LEVEL_LAST;
	}

	const char *damageName = ini->getNextToken(0);
	if (_strcmpi(damageName, "Default") == 0)
	{
		damageFirst = 0;
		damageLast = DAMAGE_NUM_TYPES - 1;
	}
	else
	{
		damageFirst = ini->scanIndexList(damageName, DamageFXDamageTypeNames);
		damageLast = damageFirst;
	}
}

void DamageFX::parseAmount(INI *ini, void *instance, void *store, const void *userData)
{
	DamageFX *self = (DamageFX *)instance;
	ConstCharPtrArray names = (ConstCharPtrArray)userData;
	int vetFirst, vetLast, damageFirst, damageLast;
	parseCommonStuff(ini, names, vetFirst, vetLast, damageFirst, damageLast);
	Real amt = ini->scanReal(ini->getNextToken(0));
	for (Int dt = damageFirst; dt <= damageLast; ++dt)
	{
		for (Int v = vetFirst; v <= vetLast; ++v)
		{
			self->m_dfx[dt][v].m_amountForMajorFX = amt;
		}
	}
}

void DamageFX::parseMajorFXList(INI *ini, void *instance, void *store, const void *userData)
{
	DamageFX *self = (DamageFX *)instance;
	ConstCharPtrArray names = (ConstCharPtrArray)userData;
	int vetFirst, vetLast, damageFirst, damageLast;
	parseCommonStuff(ini, names, vetFirst, vetLast, damageFirst, damageLast);
	void *fx;
	INI::parseFXList(ini, 0, &fx, 0);
	for (Int dt = damageFirst; dt <= damageLast; ++dt)
	{
		for (Int v = vetFirst; v <= vetLast; ++v)
		{
			self->m_dfx[dt][v].m_majorDamageFXList = fx;
		}
	}
}

void DamageFX::parseMinorFXList(INI *ini, void *instance, void *store, const void *userData)
{
	DamageFX *self = (DamageFX *)instance;
	ConstCharPtrArray names = (ConstCharPtrArray)userData;
	int vetFirst, vetLast, damageFirst, damageLast;
	parseCommonStuff(ini, names, vetFirst, vetLast, damageFirst, damageLast);
	void *fx;
	INI::parseFXList(ini, 0, &fx, 0);
	for (Int dt = damageFirst; dt <= damageLast; ++dt)
	{
		for (Int v = vetFirst; v <= vetLast; ++v)
		{
			self->m_dfx[dt][v].m_minorDamageFXList = fx;
		}
	}
}

void DamageFX::parseTime(INI *ini, void *instance, void *store, const void *userData)
{
	DamageFX *self = (DamageFX *)instance;
	ConstCharPtrArray names = (ConstCharPtrArray)userData;
	int vetFirst, vetLast, damageFirst, damageLast;
	parseCommonStuff(ini, names, vetFirst, vetLast, damageFirst, damageLast);
	UnsignedInt t;
	INI::parseDurationUnsignedInt(ini, 0, &t, 0);
	for (Int dt = damageFirst; dt <= damageLast; ++dt)
	{
		for (Int v = vetFirst; v <= vetLast; ++v)
		{
			self->m_dfx[dt][v].m_damageFXThrottleTime = t;
		}
	}
}
