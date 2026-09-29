// ?rva00200A01@Rva00200A01@@QAEXXZ
// partial score=0.9 date=2026-09-29
// ?rva00200A01@Rva00200A01@@QAEXXZ
// partial score=0.90 date=2026-09-29
// cl: /O1 /G7 /MD
// ?rva00200A01@Rva00200A01@@QAEXXZ @0x00200A01 100B.
// Array debug logger via sprintf plus OutputDebugStringA. Evidence: thiscall
// via caller 0x00200B95; offsets +0 +8 +0xC step 4 elem +8; data 0x007E2B00
// format 0x007BAC1C default; IAT sprintf 0x00BBA6BC OutputDebugStringA
// 0x00BBA19C; neighbours ConstIntGetters give no flags so TU default.
extern "C" __declspec(dllimport) int __cdecl sprintf(char *buf, const char *fmt, ...);
extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char *s);

#define Fmt00200A01 ((const char *)0x007E2B00)
#define Def00200A01 ((const char *)0x007BAC1C)

class Rva00200A01
{
public:
	void rva00200A01();
private:
	void *m_0;
	char m_pad4[4];
	void **m_8;
	void **m_C;
};

void Rva00200A01::rva00200A01()
{
	void **p = m_8;
	if (p == m_C)
		return;
	do
	{
		void *e = *p;
		const char *s1 = e != 0 ? (const char *)((char *)e + 8) : Def00200A01;
		const char *s0 = m_0 != 0 ? (const char *)((char *)m_0 + 8) : Def00200A01;
		char buf[0x100];
		sprintf(buf, Fmt00200A01, s0, s1);
		OutputDebugStringA(buf);
		++p;
	} while (p != m_C);
}
