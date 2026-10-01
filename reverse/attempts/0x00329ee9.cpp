// ?rva00329EE9@Rva00329EE9@@QAE_NXZ
// partial score=0.9 date=2026-10-01
// ?rva00329EE9@Rva00329EE9@@QAE_NXZ
// partial score=0.90 date=2026-10-01
// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD /GX-
//
// ?rva00329EE9@Rva00329EE9@@QAE_NXZ, retail 0x00329EE9, 86 bytes.
// Dict-backed non-empty check via NameKeyCache; callers 0x0032E02B 0x0032FD8E.
// ?rva00329EE9@Rva00329EE9@@QAE_NXZ present-unmatched
#include "ascii_string.h"

enum NameKeyType
{
	NAMEKEY_INVALID = 0
};

class Rva00148F5ECache
{
public:
	NameKeyType get() throw();
};

extern Rva00148F5ECache g_00DBDE24;

class Dict
{
public:
	AsciiString getAsciiString(int key, bool *flag) const throw();
};

class Rva00329EE9
{
public:
	bool rva00329EE9();
private:
	char m_pad[4];
	Dict m_dict;
};

bool Rva00329EE9::rva00329EE9()
{
	Dict *d = &m_dict;
	if (d == 0)
		return false;
	bool flag = false;
	NameKeyType key = g_00DBDE24.get();
	AsciiString s = d->getAsciiString(key, &flag);
	if (((const StringBase<char> *)&s)->isEmpty())
		return true;
	return false;
}
