// ?rva00573F3A@Rva00573F03@@QAEXPAUCoord3DBase@@@Z
// partial score=0.91 date=2026-10-03
// cl: /Ireference/shims/bfme2_ascii /O1 /DNDEBUG /MD /EHsc /arch:SSE
// ?rva00573F3A@Rva00573F03@@QAEXPAUCoord3DBase@@@Z @0x00573F3A 101B
// Leaf slot13 of Rva00573F03 (vtable 0x0086E270 family): sums base Coord +0x30 with derived Coord +0x40 into x/y then TerrainLogic getGroundHeight for z into out param.
// Evidence: movss xmm1 [ecx+30] xmm0 [ecx+40] xmm2 [ecx+34] addss store then addss [ecx+44] then call [eax+18] via TheTerrainLogic 0x009FEC50 then stores to [ebp+8]; layout from Rva00573F9FXfer.cpp.
#include "ascii_string.h"

struct Coord3DBase
{
	float x;
	float y;
	float z;
};

class TerrainLogic
{
public:
	virtual void v0();
	virtual void v1();
	virtual void v2();
	virtual void v3();
	virtual void v4();
	virtual void v5();
	virtual float getGroundHeight(float x, float y, int dummy) const;
};

extern TerrainLogic *TheTerrainLogic;

class Rva0055B0CC
{
public:
	virtual ~Rva0055B0CC();
private:
	char m_pad04[0x28];
};

class Rva00573B23 : public Rva0055B0CC
{
protected:
	AsciiString m_2c;
	Coord3DBase m_30;
	float m_3c;
};

class Rva00573F03 : public Rva00573B23
{
public:
	void rva00573F3A(Coord3DBase *out);
private:
	Coord3DBase m_40;
};

// ?rva00573F3A@Rva00573F03@@QAEXPAUCoord3DBase@@@Z present-unmatched
void Rva00573F03::rva00573F3A(Coord3DBase *out)
{
	float v[3];
	v[0] = m_30.x + m_40.x;
	v[1] = m_30.y + m_40.y;
	float z = TheTerrainLogic->getGroundHeight(v[0], v[1], 0);
	out->x = v[0];
	out->y = v[1];
	out->z = z;
}
