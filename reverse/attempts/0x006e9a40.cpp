// ?rva006E9A40@Rva006E0DE0@@QAEXPAVAptValue@@@Z
// partial score=0.97 date=2026-10-04
// ?rva006E9A40@Rva006E0DE0@@QAEXPAVAptValue@@@Z
// partial score=0.97 date=2026-10-04
// ?rva006E9A40@Rva006E0DE0@@QAEXPAVAptValue@@@Z
// partial score=0.97 date=2026-10-04
// ?rva006E9A40@Rva006E0DE0@@QAEXPAVAptValue@@@Z
// partial score=0.96 date=2026-10-03
// ?rva006E9A40@Rva006E0DE0@@QAEXPAVAptValue@@@Z
// partial score=0.94 date=2026-10-01
// ?rva006E9A40@Rva006E0DE0@@QAEXPAVAptValue@@@Z
// partial score=0.94 date=2026-10-01
// cl: /O2 /MD
// ?rva006E9A40@Rva006E0DE0@@QAEXPAVAptValue@@@Z @0x006E9A40 163B unlock lane AptSet add with duplicate and full guards.
// Evidence: same _AptSet.h mnElements/mnMaxElements/maElements asserts as Rva006E0DE0Remove; layout +0/+2/+4; AddRef slot0; callers 12x.
//
// 163 bytes emitted; identical to retail through +0x82.  The free-slot scan
// advances the index BEFORE reading the slot it just passed, which is the only
// shape that makes MSVC emit retail's `[ecx+eax*4]` addressing and push the
// first difference from +0x77 out to +0x83 (146 of 163 positional).  Binding
// the array into a local before the duplicate scan moves the difference the
// other way (to +0x01), so the local must be bound after that scan.
//
// Residual (from +0x83): retail copies the array into esi with `mov esi,ecx`
// once, then reads slots through it (`mov edi,[esi+eax*4+4]`), while this build
// keeps the array in ecx and indexes it there.  esi is `this` at that point and
// stays live only because the wrap test still reads m_nMaxElements from
// [esi+2]; hoisting that max into a local frees esi but then costs the reload
// the banked attempt already lost.  Refuted: max/array locals bound before the
// duplicate scan, an explicit slot local `e`, pointer-form scans, do/while,
// post-decrement bound, `idx--` read-back, and an explicit `this` alias.
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
	AptValue **tab;
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
	tab = m_ppElements;
	++m_nElements;
	int idx = m_nElements;
	if (tab[idx] != 0) {
		while (1) {
			if (idx >= m_nMaxElements)
				idx = 0;
			idx++;
			if (tab[idx - 1] == 0)
				break;
			idx--;
		}
	}
	tab[idx] = p;
	p->AddRef();
}