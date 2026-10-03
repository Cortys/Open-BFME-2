// ?Rva000C3AB3Parse@INI@@SAXPAV1@PAX1PBX@Z
// partial score=0.93 date=2026-10-03
// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD /EHsc
// ?Rva000C3AB3Parse@INI@@SAXPAV1@PAX1PBX@Z @0x000C3AB3 187B: INI indexed AsciiString list parse via getNextToken scanIndexList getNextAsciiString plus vector resize and set plus Rva000C2AA4 add. Evidence: caller of landed 0x000C32D9 resize; neighbours 0x000C3824 and 0x000C3B6E give TU flags and SAXPAV1@PAX1PBX@Z shape.
#include "ascii_string.h"

extern const char *g_00DBC284[];
extern const char g_Rva0107301CEmptyString[];

class Rva000C2AA4
{
public:
	void rva000C2AA4(const AsciiString &val);
};

class Rva000C32D9
{
public:
	AsciiString *m_begin;
	AsciiString *m_finish;
	AsciiString *m_end_of_storage;
	void rva000C32D9(unsigned int n, AsciiString x);
};

class INI
{
public:
	const char *getNextToken(const char *seps);
	int scanIndexList(const char *token, const char *const *nameList);
	AsciiString getNextAsciiString();
	static void Rva000C3AB3Parse(INI *ini, void *instance, void *store, const void *userData);
};

// ?Rva000C3AB3Parse@INI@@SAXPAV1@PAX1PBX@Z present-unmatched
void INI::Rva000C3AB3Parse(INI *ini, void *instance, void *store, const void *userData)
{
	unsigned int index = (unsigned int)ini->scanIndexList(ini->getNextToken(0), g_00DBC284);
	AsciiString value = ini->getNextAsciiString();
	value.toLower();
	if (value.isNone())
		value.clear();
	Rva000C32D9 *vec = (Rva000C32D9 *)store;
	unsigned int need = index + 1;
	if ((unsigned int)(vec->m_finish - vec->m_begin) < need)
		vec->rva000C32D9(need, AsciiString(g_Rva0107301CEmptyString));
	vec->m_begin[index].set(value);
	if (instance != 0)
		((Rva000C2AA4 *)instance)->rva000C2AA4(vec->m_begin[index]);
}
