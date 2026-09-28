// cl: /O1 /DNDEBUG /MD /EHsc
// ?rva0028B265@Object@@QBEXXZ @0x0028B265 45B
// Object module scan through the +0x244 array: asks each module's +0x0C
// sub-object for slot 8 (+0x20); when non-null calls its slot 15 (+0x3C)
// with 1.0f. Evidence: same +0x244 array and +0x0C lea as rowed
// getSpawnBehaviorInterface at 0x0028BCD4 and siblings rva0028C4ED (slot 26)
// rva0028BA85 (slot 46); retail lea ecx [eax+0x0C] plus call [eax+0x20] plus
// fld1/push/fstp plus call [edx+0x3C] prove slots and float arg;
// null-terminated scan with plain ret proves 0 args void; caller at
// 0x0037F1D4; name stays address-derived (Object owner proven by +0x244).

class Rva0028B265Result
{
public:
	virtual void slot00(); virtual void slot01(); virtual void slot02(); virtual void slot03();
	virtual void slot04(); virtual void slot05(); virtual void slot06(); virtual void slot07();
	virtual void slot08(); virtual void slot09(int v); virtual void slot10(); virtual void slot11();
	virtual void slot12(); virtual void slot13(); virtual void slot14();
	virtual void slot15(float v);
};

class BehaviorModuleInterface
{
public:
	virtual void slot00(); virtual void slot01(); virtual void slot02(); virtual void slot03();
	virtual void slot04(); virtual void slot05(); virtual void slot06(); virtual void slot07();
	virtual Rva0028B265Result *slot08();
};

class BfmeObjectModule
{
public:
	virtual void slot0();

private:
	unsigned int m_data[2];
};

class BehaviorModule : public BfmeObjectModule, public BehaviorModuleInterface
{
};

class Object
{
	char m_pad[0x244];
	BehaviorModule **m_modules244;

public:
	void rva0028B265() const;
	void rva0028B292(int v) const;
};

void Object::rva0028B265() const
{
	for (BehaviorModule **m = m_modules244; *m; ++m)
	{
		Rva0028B265Result *r = (*m)->slot08();
		if (r != 0)
			r->slot15(1.0f);
	}
}

void Object::rva0028B292(int v) const
{
	for (BehaviorModule **m = m_modules244; *m; ++m)
	{
		Rva0028B265Result *r = (*m)->slot08();
		if (r != 0)
			r->slot09(v);
	}
}
