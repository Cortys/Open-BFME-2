// cl: /O2 /DNDEBUG /MD
//
// ?rva006d4ca0@@YAHPBD@Z @0x006D4CA0 (151B). UTF-8 lead-byte sequence-size
// worker: retail first runs the lead-byte codepoint decoder (rva006d3e40
// 0x006D3E40) for its assertions, then derives 1/2/3/4 from pBuffer[0] with
// the EAString.inl assertions at lines 0x5D9/0x5E0. Assert strings and the
// /O2 /DNDEBUG /MD flags are shared with Utf8EncodedLength.cpp and
// EAStringCUtf8Encode.cpp in this directory.

extern void (__cdecl *g_bfmeAptAssertAtE17734)(const char *, const char *, int);
extern int g_bfmeAptBreakOnAssertAtDDC01C;

int __cdecl rva006d3e40(const char *pBuffer);

int __cdecl rva006d4ca0(const char *pBuffer)
{
	rva006d3e40(pBuffer);
	unsigned char cChar0 = (unsigned char)pBuffer[0];
	if ((cChar0 == 0xFE) || (cChar0 == 0xFF))
	{
		g_bfmeAptAssertAtE17734("(cChar0 != 0xFE) && (cChar0 != 0xFF)", ".\\string\\EAString.inl", 0x5D9);
		if (g_bfmeAptBreakOnAssertAtDDC01C)
			__debugbreak();
	}
	if (cChar0 <= 0x7F)
		return 1;
	if ((cChar0 & 0xC0) != 0xC0)
	{
		g_bfmeAptAssertAtE17734("(cChar0 & 0xC0) == 0xC0", ".\\string\\EAString.inl", 0x5E0);
		if (g_bfmeAptBreakOnAssertAtDDC01C)
			__debugbreak();
	}
	if ((cChar0 & 0xE0) == 0xC0)
		return 2;
	return ((cChar0 & 0xF0) != 0xE0) ? 4 : 3;
}
