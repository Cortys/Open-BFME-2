// cl: /Ireference/shims/bfme2_ascii /O1
// ?rva0030D4F2@Rva0030D4F2@@QAEHXZ, retail 0x0030D4F2, 26B.
// Dict getter twin of Rva0030D773 setter: Dict at +0x24 via rowed getInt
// 0x003131CA with key from rowed NameKey cache get 0x00148F5E on g_00DBDC84,
// exists null. Caller 0x004E9C4A.
// Evidence: packet disasm; same Dict offset and key as Rva0030D773Method.
#include "ascii_string.h"

enum NameKeyType
{
	NAMEKEY_INVALID = 0
};

class Rva00148F5ECache
{
public:
	NameKeyType get();
private:
	NameKeyType m_key;
	const char *m_name;
};

extern Rva00148F5ECache g_00DBDC84;

class Dict
{
public:
	int getInt(int key, bool *exists) const;
private:
	void *m_data;
};

class Rva0030D4F2
{
public:
	int rva0030D4F2();
private:
	char m_pad0[0x24];
	Dict m_dict;
};

int Rva0030D4F2::rva0030D4F2()
{
	return m_dict.getInt(g_00DBDC84.get(), 0);
}
