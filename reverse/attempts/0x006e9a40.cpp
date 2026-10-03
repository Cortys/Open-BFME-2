// ?rva006E9A40@Rva006E0DE0@@QAEXPAVAptValue@@@Z
// partial score=0.96 date=2026-10-03
// ?rva006E9A40@Rva006E0DE0@@QAEXPAVAptValue@@@Z
// partial score=0.94 date=2026-10-01
// ?rva006E9A40@Rva006E0DE0@@QAEXPAVAptValue@@@Z
// partial score=0.94 date=2026-10-01
// cl: /O2 /MD
// ?rva006E9A40@Rva006E0DE0@@QAEXPAVAptValue@@@Z @0x006E9A40 163B unlock lane AptSet add with duplicate and full guards.
// Evidence: same _AptSet.h mnElements/mnMaxElements/maElements asserts as Rva006E0DE0Remove; layout +0/+2/+4; AddRef slot0; callers 12x.
extern void (__cdecl *g_bfmeAptAssertAtE17734)(const char *, const char *, int);
extern int g_bfmeAptBreakOnAssertAtDDC01C;
void __debugbreak();
#pragma intrinsic(__debugbreak)

class AptValue {
public:
	virtual void AddRef();
	virtual void Release();
};

class Rva006E0DE0 {
	union {
		struct {
			unsigned short m_nElements;
			unsigned short m_nMaxElements;
		};
		int m_0;
	};
	AptValue **m_ppElements;
	int m_8;
	int m_C;
public:
	void rva006E9A40(AptValue *p);
};

// ?rva006E9A40@Rva006E0DE0@@QAEXPAVAptValue@@@Z present-unmatched
void Rva006E0DE0::rva006E9A40(AptValue *p)
{
	if (m_nElements >= m_nMaxElements) {
		g_bfmeAptAssertAtE17734("mnElements < mnMaxElements", "c:\\projects\\bfme2patch103\\bfme2\\code\\libraries\\source\\apt\\_AptSet.h", 0x27);
		if (g_bfmeAptBreakOnAssertAtDDC01C)
			__debugbreak();
	}
	for (int i = 0; i < m_nMaxElements; ++i) {
		if (m_ppElements[i] == p) {
			g_bfmeAptAssertAtE17734("maElements[i] != element", "c:\\projects\\bfme2patch103\\bfme2\\code\\libraries\\source\\apt\\_AptSet.h", 0x2D);
			if (g_bfmeAptBreakOnAssertAtDDC01C)
				__debugbreak();
		}
	}
	int nMax = m_nMaxElements;
	AptValue **tab = m_ppElements;
	++m_nElements;
	int idx = m_nElements;
	if (tab[idx] != 0) {
		for (;;) {
			if (idx >= nMax)
				idx = 0;
			AptValue *e = tab[idx + 1];
			++idx;
			if (e == 0)
				break;
		}
	}
	tab[idx] = p;
	p->AddRef();
}