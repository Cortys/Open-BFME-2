// cl: /O1 /MD /arch:SSE
// ??0Rva00546C26@@QAE@PAVRva0036E346@@H@Z @0x00546C26 49B evidence: stores vtable 0x00C6A3C4; base holder ctor rowed 0x00548A25; ObjectID at +0x18 from int arg then 3 floats at +0x1c +0x20 +0x24 via xorps-movss; caller 0x00355A32 news 0x28; abuts 0x00546C57.
// Honest-address ctor: vtable 0x00C6A3C4 is not tied to a known class, so Rva name (neighbor Rva00546CAD stores 0x0086A3C4).
enum ObjectID
{
	OBJECTID_0 = 0
};

class Rva0036E346;

class SpecialPowerModuleData
{
public:
	SpecialPowerModuleData(Rva0036E346 *holder);

protected:
	void *m_vtable; // +0
private:
	unsigned char m_pad04[0x18 - 4];
};

extern const void *const g_00C6A3C4[];

class Rva00546C26 : public SpecialPowerModuleData
{
public:
	Rva00546C26(Rva0036E346 *holder, int val);
private:
	enum ObjectID m_18;
	float m_1c[3];
};

Rva00546C26::Rva00546C26(Rva0036E346 *holder, int val)
	: SpecialPowerModuleData(holder)
{
	m_18 = (enum ObjectID)val;
	*(const void **)this = g_00C6A3C4;
	m_1c[0] = 0.0f;
	m_1c[1] = 0.0f;
	m_1c[2] = 0.0f;
}
