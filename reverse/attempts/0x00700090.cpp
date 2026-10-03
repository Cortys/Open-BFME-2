// ?rva00700090@AptActionInterpreter@@QAEXPAURva00700090Info@@@Z
// partial score=0.3 date=2026-10-03
// cl: /O2 /DNDEBUG /MD
// Apt debug-call-stack push at retail 0x00700090 (222 bytes). The interpreter
// keeps its AptDebugStack<DebugCallStackInfo_t> at +0x34 (count/capacity/array;
// see AptInterpreterDebugStack.cpp), a thrown-value flag at +0x60, and pushes a
// freshly allocated 0x0C-byte DebugCallStackInfo_t (EAStringC at +0, two ints)
// through the Rva006FBDB0 constructor 0x006FBD40. Assert strings name this TU's
// AptActionInterpreter.cpp:0x875 (!hasThrownValue()) and _AptDebugStack.h:0x6A.

extern void (__cdecl *g_bfmeAptAssertAtE17734)(const char *, const char *, int);
extern int g_bfmeAptBreakOnAssertAtDDC01C;
void __debugbreak();
#pragma intrinsic(__debugbreak)

class EAStringC
{
public:
	EAStringC(const char *text);
};

class Rva006DB160
{
public:
	void *allocBlock(int size);
};

extern Rva006DB160 *g_aptPoolAllocator; // VA 0x00E176E8

class Rva006FBDB0
{
public:
	Rva006FBDB0(EAStringC str, int a, int b);

	static void *operator new(unsigned int size)
	{
		return g_aptPoolAllocator->allocBlock((int)size);
	}

	EAStringC m_str;
	int m_4;
	int m_8;
};

struct Rva00700090Info
{
	int m_0;
	int m_4;
	const char *m_8;
	int m_c;
};

class AptScriptFunctionBase
{
public:
	static void *PushStaticData();
};

class AptActionInterpreter
{
public:
	void rva00700090(Rva00700090Info *info);

	int m_stack00[3];
	int m_withStack0C[3];
	int m_setTarget18[3];
	int m_thisStack24[3];
	int m_currentFunction30;
	int m_debugCount34;
	int m_debugCapacity38;
	Rva006FBDB0 **m_debugArray3C;
	int m_gap40[8];
	int m_flag60;
	int m_pad64;
};

void AptActionInterpreter::rva00700090(Rva00700090Info *info)
{
	if (m_flag60 != 0) {
		g_bfmeAptAssertAtE17734("!hasThrownValue()", "C:\\projects\\bfme2patch103\\bfme2\\Code\\Libraries\\Source\\Apt\\AptActionInterpreter.cpp", 0x875);
		if (g_bfmeAptBreakOnAssertAtDDC01C)
			__debugbreak();
	}

	Rva006FBDB0 *pInfo = new Rva006FBDB0(EAStringC(info->m_8), info->m_4, info->m_c);

	if (!(m_debugCount34 < m_debugCapacity38)) {
		g_bfmeAptAssertAtE17734("m_nElements < m_nCapacity", "c:\\projects\\bfme2patch103\\bfme2\\code\\libraries\\source\\apt\\_AptDebugStack.h", 0x6A);
		if (g_bfmeAptBreakOnAssertAtDDC01C)
			__debugbreak();
	}

	m_debugArray3C[m_debugCount34] = pInfo;
	++m_debugCount34;
	AptScriptFunctionBase::PushStaticData();
}
