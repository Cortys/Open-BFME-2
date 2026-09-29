// ?rva006E1090@AptCIH@@QAEPAXXZ
// partial score=0.93 date=2026-09-29
// ?rva006E1090@AptCIH@@QAEPAXXZ
// partial score=0.93 date=2026-09-29
// cl: /O2 /MD
// ?rva006E1090@AptCIH@@QAEPAXXZ @0x006E1090 103B.
// Button-instance data accessor requiring type 14 and defined value.
// Evidence: unlock lane, AptCIH.h asserts this/0xB5 and isButtonInst/0x92,
// SarDword get != 0xE or isUndefined triggers second assert, returns +0x4C,
// neighbours AptIntervalTimerParams/AptCIHLevel006E0B80 share /O2 /MD.
extern void (__cdecl *g_bfmeAptAssertAtE17734)(const char *, const char *, int);
extern int g_bfmeAptBreakOnAssertAtDDC01C;
void __debugbreak();
#pragma intrinsic(__debugbreak)
class Rva006DBB30SarDwordField {
public:
	int get() const;
};
class BfmeAptValue006DCD20 {
public:
	bool isUndefined() const;
};
class AptCIH {
	virtual void vtableSlot0();
	char _pad[72];
public:
	void *rva006E1090();
	void *m_buttonData;
};
void *AptCIH::rva006E1090()
{
	if (!this) {
		g_bfmeAptAssertAtE17734("this", "c:\\projects\\bfme2patch103\\bfme2\\code\\libraries\\source\\apt\\AptCIH.h", 0xB5);
		if (g_bfmeAptBreakOnAssertAtDDC01C)
			__debugbreak();
	}
	if (((const Rva006DBB30SarDwordField *)this)->get() != 0xE
		|| ((const BfmeAptValue006DCD20 *)this)->isUndefined()) {
		g_bfmeAptAssertAtE17734("isButtonInst()", "c:\\projects\\bfme2patch103\\bfme2\\code\\libraries\\source\\apt\\AptCIH.h", 0x92);
		if (g_bfmeAptBreakOnAssertAtDDC01C)
			__debugbreak();
	}
	return m_buttonData;
}
