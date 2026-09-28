// ?Rva00263569Xfer@@YAPAVXfer@@PAV1@PAH@Z
// partial score=0.93 date=2026-09-28
// ?Rva00263569Xfer@@YAPAVXfer@@PAV1@PAH@Z
// partial score=0.93 date=2026-09-28
// cl: /O1 /DNDEBUG /MD
// probe for 0x00263569 89B: Xfer GuardTargetType[2] with version 2 check.
// Ours 87B vs retail 89B. Diffs are register allocation only: xfer in edi
// vs ebx, count in esi vs edi, values on stack vs esi, plus vtable reg
// edx vs eax for the version call. Logic (version check via slot30,
// throw via bfmeFormatText plus _CxxThrow, loop 2 via XferGuardTargetType)
// matches. Needs ebx/esi/edi allocation to match retail push/pop shape.

class Xfer;

void __cdecl XferGuardTargetType(Xfer *xfer, int *value);

struct BfmeFormattedText
{
	char *text;
	int tag;
};

extern "C" BfmeFormattedText *__cdecl bfmeFormatText(BfmeFormattedText *result, int tag, const char *format, ...);
void __stdcall _CxxThrowException(void *obj, void *info);

extern int g_throwInfo00CFFD18;

class Xfer
{
public:
	virtual void s00() = 0;
	virtual void s01() = 0;
	virtual void s02() = 0;
	virtual void s03() = 0;
	virtual void s04() = 0;
	virtual void s05() = 0;
	virtual void s06() = 0;
	virtual void s07() = 0;
	virtual void s08() = 0;
	virtual void s09() = 0;
	virtual void s10() = 0;
	virtual void s11() = 0;
	virtual void s12() = 0;
	virtual void s13() = 0;
	virtual void s14() = 0;
	virtual void s15() = 0;
	virtual void s16() = 0;
	virtual void s17() = 0;
	virtual void s18() = 0;
	virtual void s19() = 0;
	virtual void s20() = 0;
	virtual void s21() = 0;
	virtual void s22() = 0;
	virtual void s23() = 0;
	virtual void s24() = 0;
	virtual void s25() = 0;
	virtual void s26() = 0;
	virtual void s27() = 0;
	virtual void s28() = 0;
	virtual void s29() = 0;
	virtual void xferVersion(int *version) = 0;
};

// ?Rva00263569Xfer@@YAPAVXfer@@PAV1@PAH@Z present-unmatched
Xfer *__cdecl Rva00263569Xfer(Xfer *xfer, int *values)
{
	int version = 2;
	xfer->xferVersion(&version);
	if (version != 2) {
		BfmeFormattedText tmp;
		bfmeFormatText(&tmp, 0, 0);
		_CxxThrowException(&tmp, &g_throwInfo00CFFD18);
	}
	int count = 2;
	do {
		XferGuardTargetType(xfer, values);
		++values;
		--count;
	} while (count != 0);
	return xfer;
}
