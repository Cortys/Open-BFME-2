// cl: /O1 /MD /arch:SSE
// ??0Rva00546CAD@@QAE@XZ @0x00546C57 40B evidence: stores vtable 0x0086A3C4; base ctor rowed 0x005488C5; clears ObjectID at +0x18 then 3 floats at +0x1c +0x20 +0x24 via xorps-movss; caller 0x00354FFA; returns this.
// Ctor of Rva00546CAD via vtable store (naming rule).
enum ObjectID
{
	OBJECTID_0 = 0
};

class SpecialPowerModuleData
{
public:
	SpecialPowerModuleData();
	SpecialPowerModuleData(const SpecialPowerModuleData &other);

protected:
	void *m_vtable; // +0
private:
	unsigned char m_pad04[0x18 - 4];
};

extern const void *const g_0086A3C4[];
extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)

class Rva00546CAD : public SpecialPowerModuleData
{
public:
	Rva00546CAD();
	Rva00546CAD(const Rva00546CAD &other);
private:
	enum ObjectID m_18;
	float m_1c[3];
};

Rva00546CAD::Rva00546CAD()
{
	m_18 = OBJECTID_0;
	_ReadWriteBarrier();
	*(const void **)this = g_0086A3C4;
	m_1c[0] = 0.0f;
	m_1c[1] = 0.0f;
	m_1c[2] = 0.0f;
}

Rva00546CAD::Rva00546CAD(const Rva00546CAD &other)
	: SpecialPowerModuleData(other)
{
	m_18 = OBJECTID_0;
	_ReadWriteBarrier();
	*(const void **)this = g_0086A3C4;
	m_1c[0] = 0.0f;
	m_1c[1] = 0.0f;
	m_1c[2] = 0.0f;
}
