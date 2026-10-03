// ?rva006D9780@BfmeAptValue006DCD20@@QAE_NPAV1@PAVEAStringC@@0@Z
// partial score=0.95 date=2026-10-03
// cl: /O2 /MD
// Banked near miss: ?rva006D9780@BfmeAptValue006DCD20@@QAE_NPAV1@PAVEAStringC@@0@Z
// @0x006D9780 (145B). Only the condition block layout differs from retail: retail
// sinks the `return false` block to the end of the function (`cmp [edi],'0';
// jne fail` with the body as fallthrough), while VC7.1 /O2 emits it inline
// (`cmp; je body; <fail>; body`). isArray assert, both atoi calls, the double
// data() eval, value selection and checked store all match byte-for-byte.
// Tried: direct &&, nested if, || with/without else, empty-then/else, gotos,
// static/inline atoiOrZero helper (emits sete), /O1, /EHsc.
extern void (__cdecl *g_bfmeAptAssertAtE17734)(const char *, const char *, int);
extern int g_bfmeAptBreakOnAssertAtDDC01C;
extern "C" int __cdecl atoi(const char *);

class EAStringC
{
public:
	const char *rva00620090() const;
};

class BfmeAptValue006DCD20
{
public:
	virtual void slot0();
	virtual void slot1();

	int isArray() const;
	BfmeAptValue006DCD20 *rva006DCFA0();
	void rva006D9500(int nCapacity);
	void rva006D8AD0(int nIndex, BfmeAptValue006DCD20 *pNewValue);
	void rva006D95E0(int nIndex, BfmeAptValue006DCD20 *pValue);
	bool rva006D9780(BfmeAptValue006DCD20 *pContext, EAStringC *pKey, BfmeAptValue006DCD20 *pValue);

	unsigned int m_flags;
	char m_pad[0x18];
	BfmeAptValue006DCD20 **m_data;
	int mnCapacity;
	int mnLength;
};

extern BfmeAptValue006DCD20 *g_aptUndefinedAtE18078;

bool BfmeAptValue006DCD20::rva006D9780(BfmeAptValue006DCD20 *pContext, EAStringC *pKey, BfmeAptValue006DCD20 *pValue)
{
	if (!static_cast<unsigned char>(pContext->isArray()))
	{
		g_bfmeAptAssertAtE17734("pContext->isArray()", "C:\\projects\\bfme2patch103\\bfme2\\Code\\Libraries\\Source\\Apt\\AptArray.cpp", 0x217);
		if (g_bfmeAptBreakOnAssertAtDDC01C)
			__asm int 3
	}

	const char *text = pKey->rva00620090();
	if (atoi(text) != 0 || *text == '0')
	{
		int index = atoi(pKey->rva00620090());
		pContext->rva006DCFA0()->rva006D95E0(index, pValue ? pValue : g_aptUndefinedAtE18078);
		return true;
	}
	return false;
}
