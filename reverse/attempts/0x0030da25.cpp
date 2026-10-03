// ??0Rva0030DA25@@QAE@UVec3@@ABVAsciiString@@MHPBVDict@@PAX@Z
// partial score=0.9 date=2026-10-03
// cl: /Ireference/shims/bfme2_ascii /O1 /EHsc
// ??0Rva0030DA25@@QAE@VVec3@@ABVAsciiString@@MHHHPAX@Z, retail 0x0030DA25, 432B.
// Ctor: vtable 0x00808A2C, Dict at +0x24 via rowed ctor, pos copy to +8,
// name via rowed Rva0030D5EEConstruct plus StringBase set, angle via rowed
// normalizeAngle, Dict defaults via rowed NameKey get plus setInt/setBool,
// tail zeroing. Callers 0x00302A3B 0x0030DDB7 0x0030E352.
// Evidence: packet disasm; siblings Rva0030D773Method Dict at +0x24.
#include "ascii_string.h"

struct Vec3
{
	float x;
	float y;
	float z;
};

class Dict
{
public:
	Dict(int numPairsToPreAllocate);
	~Dict();
	Dict &operator=(const Dict &src);
	int getInt(int key, bool *exists) const;
	void setInt(int key, int value);
	void setBool(int key, bool value);
private:
	void *m_data;
};

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
extern Rva00148F5ECache g_00DBDCD4;
extern Rva00148F5ECache g_00DBDCEC;
extern Rva00148F5ECache g_00DBDCF4;
extern Rva00148F5ECache g_00DBDCFC;
extern Rva00148F5ECache g_00DBDD1C;
extern Rva00148F5ECache g_00DBDD54;
extern Rva00148F5ECache g_00DBDD04;
extern Rva00148F5ECache g_00DBDD84;
extern Rva00148F5ECache g_00DBDD8C;

extern const void *const g_00C08A2C[];

float normalizeAngle(float angle);
AsciiString Rva0030D5EEConstruct(const AsciiString &src);

class Rva0030D773
{
public:
	void rva0030D773(int val);
};

class Rva0030DA25
{
public:
	Rva0030DA25(Vec3 pos, const AsciiString &name, float angle, int a, const Dict *dictSrc, void *thing);
private:
	const void *m_vtable;
	int m_4;
	Vec3 m_pos;
	AsciiString m_name;
	void *m_thing;
	float m_angleN;
	int m_20;
	Dict m_dict;
	int m_28;
	int m_2c;
	int m_30;
	int m_34[4];
	int m_44;
	char m_pad48[12];
	int m_54;
	void *m_58;
};

// ?rva0030DA25@Rva0030DA25@@QAE@VVec3@@ABVAsciiString@@MHHHPAX@Z present-unmatched
Rva0030DA25::Rva0030DA25(Vec3 pos, const AsciiString &name, float angle, int a, const Dict *dictSrc, void *thing)
	: m_vtable(g_00C08A2C), m_4(0), m_dict(0)
{
	m_58 = 0;
	m_pos = pos;
	m_name = Rva0030D5EEConstruct(name);
	m_thing = thing;
	m_angleN = normalizeAngle(angle);
	m_20 = a;
	m_54 = 1;
	if (dictSrc != 0)
	{
		m_dict = *dictSrc;
		bool exists = false;
		int v = m_dict.getInt(g_00DBDC84.get(), &exists);
		if (exists)
			((Rva0030D773 *)this)->rva0030D773(v);
	}
	else
	{
		m_dict.setInt(g_00DBDCD4.get(), 100);
		m_dict.setBool(g_00DBDCEC.get(), true);
		m_dict.setBool(g_00DBDCF4.get(), false);
		m_dict.setBool(g_00DBDCFC.get(), false);
		m_dict.setBool(g_00DBDD1C.get(), true);
		m_dict.setBool(g_00DBDD54.get(), true);
		m_dict.setBool(g_00DBDD04.get(), false);
		m_dict.setInt(g_00DBDD84.get(), 40);
		m_dict.setInt(g_00DBDD8C.get(), 1);
	}
	m_2c = 0;
	m_30 = 0;
	m_28 = 0xff00;
	m_34[0] = 0;
	m_34[1] = 0;
	m_34[2] = 0;
	m_34[3] = 0;
	m_44 = 0;
}
