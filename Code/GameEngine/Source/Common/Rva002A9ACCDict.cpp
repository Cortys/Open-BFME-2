// cl: /O1 /MD
//
// ?rva002A9ACC@Rva002A9ACC@@QAEXPBVDict@@@Z retail 0x002A9ACC 105B
// Two Dict color reads via rowed NameKey caches at 0x00DBDE64 and 0x00DBDE6C
// plus rowed Dict getInt at 0x003131CA. First hit writes +0x280 and +0x284
// second hit overwrites +0x284 with alpha 0xFF000000 ORed. Caller 0x002AFCDF.
// Evidence: retail calls rowed get 0x00148F5E twice and rowed getInt twice.
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

extern Rva00148F5ECache g_00DBDE64;
extern Rva00148F5ECache g_00DBDE6C;

class Dict
{
public:
	int getInt(int key, bool *exists) const;
private:
	void *m_data;
};

class Rva002A9ACC
{
public:
	void rva002A9ACC(const Dict *dict);
private:
	unsigned char m_pad[0x280];
	int m_color1;
	int m_color2;
};

void Rva002A9ACC::rva002A9ACC(const Dict *dict)
{
	if (!dict)
		return;
	bool exists;
	int v = dict->getInt(g_00DBDE64.get(), &exists);
	if (exists)
	{
		v |= 0xFF000000;
		m_color1 = v;
		m_color2 = v;
	}
	int v2 = dict->getInt(g_00DBDE6C.get(), &exists);
	if (exists)
	{
		v2 |= 0xFF000000;
		m_color2 = v2;
	}
}
