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

// ?rva006d4280@@YAPBDPBDPAH@Z @0x006D4280 (856B, unrowed). The cursor decoder
// both workers below call: it returns the pointer past one UTF-8 sequence and
// stores the decoded codepoint through the out parameter.
const char *__cdecl rva006d4280(const char *pBuffer, int *pUnicode);

// ?rva006d4d40@@YAPAXPAXH@Z @0x006D4D40 (51B). Advances a UTF-8 cursor by
// `count` codepoints and returns the new cursor, or null at the terminator.
// Called by EAStringC::rva006d5e70 0x006D5E70 with the payload and an index.
void *__cdecl rva006d4d40(void *pBuffer, int count)
{
	const char *p = (const char *)pBuffer;
	int i = 0;
	if (count <= 0)
		return (void *)p;
	do
	{
		int value;
		p = rva006d4280(p, &value);
		if (value == 0)
			return 0;
		++i;
	} while (i < count);
	return (void *)p;
}

// ?rva006d4d80@@YAHPBD@Z @0x006D4D80 (59B). Counts the codepoints in a UTF-8
// byte string, stopping at the terminator, via the same cursor decoder.
int __cdecl rva006d4d80(const char *pBuffer)
{
	const char *p = pBuffer;
	int count = 0;
	for (;;)
	{
		int value;
		p = rva006d4280(p, &value);
		if (value == 0)
			return count;
		++count;
	}
}
