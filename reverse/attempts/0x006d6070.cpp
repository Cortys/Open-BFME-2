// ?rva006d6070@EAStringC@@QAEHPBDH@Z
// partial score=0.9 date=2026-10-03
// cl: /O2 /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc
//
// ?rva006d6070@EAStringC@@QAEHPBDH@Z @0x006D6070 (143B) -- banked near miss.
// Codepoint index of a substring: advance `count` codepoints with the rowed
// cursor worker 0x006D4D40, convert that cursor to a byte offset, Find the
// substring from there (rowed 0x006D3870) and walk the buffer forward to the
// hit, counting codepoints with rva006d4ca0 before the EAString.cpp 0x75E
// "i == iFoundASCII" assert. This body is 143 bytes and byte-identical to
// retail EXCEPT that MSVC 7.1 colors `this` into EBX (retail EDI) and the
// scanned-offset local into EDI (retail EBX); every instruction, including the
// shared loop-exit/assert test, matches otherwise. 13 source shapes tried.

extern void (__cdecl *g_bfmeAptAssertAtE17734)(const char *, const char *, int);
extern int g_bfmeAptBreakOnAssertAtDDC01C;
void __debugbreak();
#pragma intrinsic(__debugbreak)
void *__cdecl rva006d4d40(void *pBuffer, int count);
int __cdecl rva006d4ca0(const char *pBuffer);

class EAStringC
{
public:
	class StringDataC
	{
	public:
		unsigned short m_uRefCount;
		unsigned short m_uSize;
		unsigned short m_uMaxSize;
		unsigned short m_uHash;
	};
	StringDataC *m_pData;
public:
	static void FreeData(StringDataC *data);
	EAStringC()
	{
		extern StringDataC g_eaEmptyStringData;
		m_pData = &g_eaEmptyStringData;
		++g_eaEmptyStringData.m_uRefCount;
	}
	EAStringC(const EAStringC &other);
	~EAStringC() { FreeData(m_pData); }
	int Find(const char *s, int start);
	int rva006d6070(const char *pStr, int count);
};
extern EAStringC::StringDataC g_eaEmptyStringData;

int EAStringC::rva006d6070(const char *pStr, int count)
{
	const unsigned char *buffer = reinterpret_cast<const unsigned char *>(m_pData) + 8;
	const unsigned char *found = (const unsigned char *)rva006d4d40((void *)buffer, count);
	if (found == 0)
		return -1;
	int i = (int)(found - buffer);
	int iFoundASCII = Find(pStr, i);
	if (iFoundASCII < 0)
		return -1;
	while (i < iFoundASCII)
	{
		int size = rva006d4ca0((const char *)buffer);
		buffer += size;
		i += size;
		++count;
	}
	if (i != iFoundASCII)
	{
		g_bfmeAptAssertAtE17734("i == iFoundASCII", "C:\\projects\\bfme2patch103\\bfme2\\Code\\Libraries\\Source\\Apt\\string\\EAString.cpp", 0x75E);
		if (g_bfmeAptBreakOnAssertAtDDC01C)
			__debugbreak();
	}
	return count;
}
