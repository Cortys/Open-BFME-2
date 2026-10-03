// cl: /O2 /MD
//
// ?rva007065e0@@YAXHHPAVBfmeAptValue006DCD20@@PAPAV1@@Z retail 0x007065E0,
// 121 bytes.
//
// AptActionInterpreter.cpp helper (the NOT_REACHED assert names that file at
// line 0x7A6): a CIH or a value whose vtable slot +0x10 returns true passes
// straight to the out pointer; otherwise the value must be a string, and the
// string's EAStringC (opaque resolver 0x006DCE50 plus 8) goes through the
// address-derived 0x007064F0 helper. The three predicate slots test AL, so
// the retail declarations return bool; the matched ledger rows spell them int,
// hence the bool alias pins at the same addresses. This body's name is
// address-derived.

class Rva006DCE50Opaque
{
public:
	void *rva006DCE50();
};

class EAStringC;

class BfmeAptValue006DCD20
{
public:
	virtual void s0();
	virtual void s1();
	virtual void s2();
	virtual void s3();
	virtual bool s4();
	bool isCIH(bool) const;
	bool isString() const;
};

BfmeAptValue006DCD20 *rva007064f0(int, int, EAStringC *);

extern void (__cdecl *g_bfmeAptAssertAtE17734)(const char *, const char *, int);
extern int g_bfmeAptBreakOnAssertAtDDC01C;

void rva007065e0(int a1, int a2, BfmeAptValue006DCD20 *value, BfmeAptValue006DCD20 **out)
{
	if (value->isCIH(false) || value->s4()) {
		*out = value;
		return;
	}
	if (value->isString()) {
		void *opaque = ((Rva006DCE50Opaque *)value)->rva006DCE50();
		*out = rva007064f0(a1, a2, (EAStringC *)((char *)opaque + 8));
		return;
	}
	g_bfmeAptAssertAtE17734("NOT_REACHED", "C:\\projects\\bfme2patch103\\bfme2\\Code\\Libraries\\Source\\Apt\\AptActionInterpreter.cpp", 0x7a6);
	if (g_bfmeAptBreakOnAssertAtDDC01C)
		__asm int 3
}
