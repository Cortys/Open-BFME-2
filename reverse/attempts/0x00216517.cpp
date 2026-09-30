// ?Rva00216517Fire@@YAXPAVRva00222A8BTarget@@PAXPBDPBIPBM@Z
// partial score=0.92 date=2026-09-30
// ?Rva00216517Fire@@YAXPAVRva00222A8BTarget@@PAXPBDPBIPBM@Z
// partial score=0.92 date=2026-09-30
// cl: /O1 /EHsc
// stlport
// Retail RVA 0x00216517, 153 bytes.
// ?Rva00216517Fire@@YAXPAVRva00222A8BTarget@@PAXPBDPAIPA M@Z placeholder - exact mangling from nm.
// Free __cdecl UI firer with (int float) as strings: formats via rowed Rva002228E8Get(float) and
// Rva0022288EGet(uint), substitutes rowed empty string when a buffer is null, invokes with flag 2.
// Evidence: callees Rva002228E8Get 0x002228E8 and Rva0022288EGet 0x0022288E plus invoke pin 0x00222A8B
// and releaseBuffer row 0x00036410; caller 0x00216670 pushes (target owner SetBannerXOffset int* float*).
template <typename T> class StringBase
{
	friend class AsciiString;
	StringBase(const StringBase<T> &other);
	void releaseBuffer();
	T *m_data;
public:
	StringBase() : m_data(0) {}
	~StringBase() { releaseBuffer(); }
};

class AsciiString : public StringBase<char>
{
public:
	AsciiString() {}
	AsciiString(const AsciiString &other) : StringBase<char>(other) {}
	~AsciiString() {}
	void __cdecl format(const char *fmt, ...);
};

AsciiString Rva002228E8Get(float val);
AsciiString Rva0022288EGet(unsigned int val);

class Rva00222A8BTarget
{
public:
	void invoke(void *owner, const char *name, int flag, const char *value, void *a4, void *a5, void *a6, void *a7);
};

extern const char g_Rva0107301CEmptyString[];

// ?Rva00216517Fire@Rva00216517@@YAXPAVRva00222A8BTarget@@PAXPBDPAIPAM@Z present-unmatched
void __cdecl Rva00216517Fire(Rva00222A8BTarget *target, void *owner, const char *name, const unsigned int *pInt, const float *pFloat)
{
	AsciiString sFloat = Rva002228E8Get(*pFloat);
	AsciiString *pF = &sFloat;
	AsciiString sInt = Rva0022288EGet(*pInt);
	void *q1 = *(void **)pF;
	const char *c1;
	if (q1)
		c1 = (const char *)q1 + 8;
	else
		c1 = g_Rva0107301CEmptyString;
	void *q2 = *(void **)&sInt;
	const char *c2;
	if (q2)
		c2 = (const char *)q2 + 8;
	else
		c2 = g_Rva0107301CEmptyString;
	target->invoke(owner, name, 2, c2, (void *)c1, 0, 0, 0);
}
