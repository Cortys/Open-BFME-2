// ?rva00496B48@Rva00496B48@@QAE_NXZ
// partial score=0.95 date=2026-10-02
// cl: /O1 /EHs /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc /Ireference/shims/moduledata
// ?rva00496B48@Rva00496B48@@QAE_NXZ, retail 0x00496B48 138B. Unlock: landing
// makes 0x00496BD2 ready. Walks +0x274 chain from this+8, checks [[+4]+0x116]
// &0x40, cached AllowBannerSpawnUpgrade key via static, findModule, virtual
// at module+0x10 slot0 bool. False only if module vetoes, else true.
// Evidence: callees __EH_prolog 0x00629188 nameToKey 0x00148E1A findModule
// 0x0028B6D6, string AllowBannerSpawnUpgrade, caller 0x00496C29.

enum NameKeyType
{
	NAMEKEY_INVALID = 0
};

class NameKeyGenerator
{
public:
	NameKeyType nameToKey(const char *s);
};
extern NameKeyGenerator *TheNameKeyGenerator;

class ModuleInner
{
public:
	virtual bool allow();
};

class Module
{
public:
	char m_pad00[0x10];
	ModuleInner m_10;
};

struct ObjectInner04
{
	char m_pad00[0x116];
	unsigned char m_116;
};

class Object
{
public:
	char m_pad00[4];
	ObjectInner04 *m_04;
	char m_pad08[0x274 - 8];
	Object *m_next274;
protected:
	Module *findModule(NameKeyType key) const;
};

struct ObjectHack : public Object
{
// ?find@ObjectHack@@SAPAVModule@@PBVObject@@W4NameKeyType@@@Z present-unmatched
	static Module *find(const Object *o, NameKeyType k) { return ((ObjectHack *)o)->findModule(k); }
};

class Rva00496B48
{
public:
	bool rva00496B48();
private:
	char m_pad00[8];
	Object *m_obj08;
};

// ?rva00496B48@Rva00496B48@@QAE_NXZ present-unmatched
bool Rva00496B48::rva00496B48()
{
	Object *o = m_obj08;
	if (o == 0)
		return true;
	do {
		Object *next = o->m_next274;
		if (next == 0)
			break;
		o = next;
	} while (o != 0);
	if (o == 0)
		return true;
	ObjectInner04 *inner = o->m_04;
	if ((inner->m_116 & 0x40) == 0)
		return true;
	static NameKeyType s_key = TheNameKeyGenerator->nameToKey("AllowBannerSpawnUpgrade");
	Module *m = ObjectHack::find(o, s_key);
	if (m == 0)
		return true;
	bool ok = true;
	if (!(&m->m_10)->allow())
		ok = false;
	if (!ok)
		return false;
	return true;
}
