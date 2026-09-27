// cl: /O1 /DNDEBUG /MD
//
// Object::findModule, retail 0x0028B6D6, 43 bytes.
// Dedicated TU. Walks the null-terminated module pointer list at +0x244
// and compares virtual name-key slot 0x10.

enum NameKeyType
{
	NAMEKEY_INVALID = 0
};

class Module
{
public:
	virtual void _dtor() = 0;
	virtual void _r1() = 0;
	virtual void _r2() = 0;
	virtual void _r3() = 0;
	virtual NameKeyType getModuleNameKey() const = 0;
};

class BodyFwd
{
public:
	virtual void s00();
	virtual void s01();
	virtual void s02();
	virtual void s03();
	virtual void s04();
	virtual void s05();
	virtual void s06();
	virtual void s07();
	virtual void s08();
	virtual void s09();
	virtual void s10();
	virtual void s11();
	virtual void slot12(int v);
};

class Object
{
	char pad[0x244];
	Module **m_modules; // +0x244
	char pad248[0x254 - 0x248];
	BodyFwd *m_body; // +0x254, proven by Object_attemptHealing precedent

protected:
	Module *findModule(NameKeyType key) const;
public:
	void rva0028B78A(int v);
};

Module *Object::findModule(NameKeyType key) const
{
	Module *found = 0;
	for (Module **at = m_modules; *at; ++at)
	{
		if ((*at)->getModuleNameKey() == key)
		{
			found = *at;
			break;
		}
	}
	return found;
}

// ?rva0028B78A@Object@@QAEXH@Z, retail 0x0028B78A, 18 bytes.
// Object body forwarder: if the body at +0x254 is present tail-jumps to its
// slot 0x30 with the caller's int arg, else returns void. Evidence: body at
// +0x254 per Object_attemptHealing, slot 0x30 from retail jmp, callers pass
// 6/9 with Object this at 0x0049930F 0x004AE07B 0x004B0527 0x00499514.
void Object::rva0028B78A(int v)
{
	BodyFwd *b = m_body;
	if (b != 0)
		b->slot12(v);
}
