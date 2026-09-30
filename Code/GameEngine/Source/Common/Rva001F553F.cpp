// cl: /O1 /MD /arch:SSE
// ?rva001F553F@Rva001F553F@@QAEPAUCoord3D@@PAU2@II@Z @0x001F553F 105B
// Evidence: chain lane; calls rowed 0x003AFB2A Rva003AFB2A::rva003AFB2A; SSE scale via TheWritableGlobalData+0x9ec g_Va00BBB8D8 g_Va007C26F0; null member at +0x1c0 zeroes Coord3D out; ret 0xc with out in eax on both paths so returns Coord3D*.

struct Coord3D
{
	float x;
	float y;
	float z;
};

class GlobalData
{
public:
	char m_pad[0x9EC];
	volatile float m_09EC;
};

extern GlobalData *TheWritableGlobalData;
extern float g_Va00BBB8D8;
extern float g_Va007C26F0;

class Rva003AFB2A
{
public:
	void rva003AFB2A(Coord3D *out, float a, float b, unsigned int c, unsigned int d);
};

class Rva001F553F
{
public:
	Coord3D *rva001F553F(Coord3D *out, unsigned int a, unsigned int b);

private:
	char m_pad00[0x17C];
	float m_17C;
	char m_pad180[0x40];
	Rva003AFB2A *m_1C0;
};

Coord3D *Rva001F553F::rva001F553F(Coord3D *out, unsigned int a, unsigned int b)
{
	Rva003AFB2A *p = m_1C0;
	if (p != 0)
	{
		p->rva003AFB2A(out, m_17C, (TheWritableGlobalData->m_09EC + g_Va00BBB8D8) * g_Va007C26F0, a, b);
		return out;
	}
	else
	{
		out->x = 0.0f;
		out->y = 0.0f;
		out->z = 0.0f;
		return out;
	}
}
