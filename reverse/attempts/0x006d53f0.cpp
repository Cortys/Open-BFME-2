// ?rva006D53F0@EAStringC@@QAEXPBDPAD@Z
// partial score=0.91 date=2026-09-30
// ?rva006D53F0@EAStringC@@QAEXPBDPAD@Z
// partial score=0.91 date=2026-09-30
// cl: /O2 /DNDEBUG /MD
// ?rva006D53F0@EAStringC@@QAEXPBDPAD@Z @0x006D53F0 188B
// EAStringC format-v with vsnprintf growth loop.
// Evidence: asserts pStrFormat 0x24E via g_bfmeAptAssertAtE17734 row; callees ChangeBuffer 0x006D4AA0 row EAStringCChangeBuffer.cpp SetSize 0x006D3BC0 row EAStringCSetSize.cpp vsnprintf thunk 0x00629898 row imports_000.cpp; callers 0x006CBB17 0x006D62F8; layout rep+4 maxSize rep+6 hash per ChangeBuffer precedent.
extern void (__cdecl *g_bfmeAptAssertAtE17734)(const char *, const char *, int);
extern int g_bfmeAptBreakOnAssertAtDDC01C;
void __debugbreak();
#pragma intrinsic(__debugbreak)
extern "C" int __cdecl _vsnprintf(char *buffer, unsigned int count, const char *format, char *args);
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
	enum CBPushZero
	{
		CB_NO_PUSH_ZERO,
		CB_PUSH_ZERO
	};
	void SetSize(int size);
private:
	StringDataC *m_pData;
	void ChangeBuffer(unsigned int uSizeToReserve, unsigned int uOffsetCopy, unsigned int uSizeCopy, CBPushZero ePushZero, unsigned int uInternalSize);
public:
	void rva006D53F0(const char *pStrFormat, char *args);
};
// ?rva006D53F0@EAStringC@@QAEXPBDPAD@Z present-unmatched
void EAStringC::rva006D53F0(const char *pStrFormat, char *args)
{
	if (pStrFormat == 0)
	{
		g_bfmeAptAssertAtE17734("pStrFormat != NULL", "C:\\projects\\bfme2patch103\\bfme2\\Code\\Libraries\\Source\\Apt\\string\\EAString.cpp", 0x24E);
		if (g_bfmeAptBreakOnAssertAtDDC01C)
			__debugbreak();
	}
	const char *eos = pStrFormat;
	const char *base = eos + 1;
	while (*eos++ != 0)
		;
	unsigned int reserve = ((unsigned int)(eos - base)) * 4;
	ChangeBuffer(reserve, 0, 0, CB_NO_PUSH_ZERO, 0);
	char *buf;
	buf = (char *)m_pData + 8;
	int ret = _vsnprintf(buf, m_pData->m_uMaxSize, pStrFormat, args);
	while (ret < 0)
	{
		reserve += reserve;
		ChangeBuffer(reserve, 0, 0, CB_NO_PUSH_ZERO, 0);
		buf = (char *)m_pData + 8;
		ret = _vsnprintf(buf, m_pData->m_uMaxSize, pStrFormat, args);
	}
	buf[ret] = 0;
	SetSize(ret);
	m_pData->m_uHash = 0;
}
