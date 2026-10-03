// ?rva006FD700@@YGPBDPBDPAVEAStringC@@1@Z
// partial score=0.85 date=2026-10-03
// cl: /O2 /DNDEBUG /MD
//
// ?rva006FD700@@YGPBDPBDPAVEAStringC@@1@Z @0x006FD700 (133B) -- banked near
// miss. Splits an ampersand-separated name=value pair: releases both output
// strings, assigns the name and value through the bounded append
// (bfmeAppendVKG 0x006D52A0), URL-decodes both through rva006FD630, and
// returns the cursor past the pair (or null when there is no '=').
//
// This body reproduces the retail prologue, both release-to-empty calls, the
// null check and the register roles (p in EBX, cursor in ESI, '=' in EDI)
// exactly, but MSVC 7.1 peels the first loop read through EBX instead of ESI,
// making the body 145 bytes against 133. The tail is otherwise identical.

class EAStringC
{
	void *m_pData;

public:
	EAStringC();
	~EAStringC();
	EAStringC &clear();
	unsigned int rva006D3750() const;
	const char *rva00620090() const;
	EAStringC &Rva006D50A0Append(const char *text);
	EAStringC &operator=(const EAStringC &other);
	void rva006D3470();
};

class BfmeBufVKG
{
public:
	BfmeBufVKG *bfmeAppendVKG(const char *source, unsigned int limit);
};

void __cdecl rva006FD630(EAStringC *pString);

const char *__stdcall rva006FD700(const char *p, EAStringC *outName, EAStringC *outValue)
{
	const char *q = p;
	const char *eq = 0;
	outName->rva006D3470();
	outValue->rva006D3470();
	if (p == 0)
		return 0;
	for (; *q != 0 && *q != '&'; ++q)
	{
		if (*q == '=')
			eq = q;
	}
	if (eq == 0)
		return 0;
	((BfmeBufVKG *)outName)->bfmeAppendVKG(p, (unsigned int)(eq - p));
	rva006FD630(outName);
	((BfmeBufVKG *)outValue)->bfmeAppendVKG(eq + 1, (unsigned int)(q - (eq + 1)));
	rva006FD630(outValue);
	if (*q == '&')
		++q;
	return q;
}
