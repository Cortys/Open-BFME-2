// cl: /O1 /DNDEBUG /MD /EHsc
//
// ?rva0028EBDA@Object@@QAEX_N@Z, retail 0x0028EBDA 110B.
// Static NameKey for "EnragedBehavior" via TheNameKeyGenerator, then
// findModule; if module found, call rva004590C5 when flag true else
// rva004590E6. Chain via rowed 0x004590C5. Callers 0x0033593E 0x0048C97C.
enum NameKeyType
{
	NK_UNKNOWN = 0
};

class NameKeyGenerator
{
public:
	NameKeyType nameToKey(const char *name);
};

extern NameKeyGenerator *TheNameKeyGenerator;

class Module
{
};

class Rva004590C5
{
public:
	void rva004590C5();
	void rva004590E6();
};

class Object
{
public:
	void rva0028EBDA(bool flag);
protected:
	Module *findModule(NameKeyType key) const;
};

void Object::rva0028EBDA(bool flag)
{
	static NameKeyType key_EnragedBehavior =
		TheNameKeyGenerator->nameToKey("EnragedBehavior");
	Rva004590C5 *m = (Rva004590C5 *)findModule(key_EnragedBehavior);
	if (m == 0)
		return;
	if (flag)
		m->rva004590C5();
	else
		m->rva004590E6();
}
