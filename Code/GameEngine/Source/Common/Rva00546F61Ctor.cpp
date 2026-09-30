// cl: /O1 /MD /arch:SSE
// ??0Rva00546F61@@QAE@XZ @0x00546F03 44B evidence: stores vtable 0x0086A420; base ctor rowed 0x005488C5; clears dword at +0x18 then byte at +0x1c then 3 floats at +0x20 +0x24 +0x28 via xorps-movss; caller 0x00354FCC; returns this.
// Ctor of Rva00546F61 via vtable store (naming rule).
enum ObjectID
{
	OBJECTID_0 = 0
};

class Rva0036E346;

class SpecialPowerModuleData
{
public:
	SpecialPowerModuleData();
	SpecialPowerModuleData(Rva0036E346 *holder);

protected:
	void *m_vtable; // +0
private:
	unsigned char m_pad04[0x18 - 4];
};

extern const void *const g_0086A420[];
extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)

class Rva00546F61 : public SpecialPowerModuleData
{
public:
	Rva00546F61();
	Rva00546F61(Rva0036E346 *holder, int val);
private:
	enum ObjectID m_18;
	bool m_1c;
	float m_20[3];
};

Rva00546F61::Rva00546F61()
{
	m_18 = OBJECTID_0;
	_ReadWriteBarrier();
	*(const void **)this = g_0086A420;
	m_1c = false;
	m_20[0] = 0.0f;
	m_20[1] = 0.0f;
	m_20[2] = 0.0f;
}

Rva00546F61::Rva00546F61(Rva0036E346 *holder, int val)
	: SpecialPowerModuleData(holder)
{
	m_18 = (enum ObjectID)val;
	*(const void **)this = g_0086A420;
	m_1c = false;
	m_20[0] = 0.0f;
	m_20[1] = 0.0f;
	m_20[2] = 0.0f;
}
