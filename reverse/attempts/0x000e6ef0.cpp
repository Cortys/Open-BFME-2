// ?rva000E6EF0@Rva000E6EF0@@QAEHPBUFloatPair@@@Z
// partial score=0.96 date=2026-10-01
// ?rva000E6EF0@Rva000E6EF0@@QAEHPBUFloatPair@@@Z
// partial score=0.96 date=2026-10-01
// cl: /O1 /MD /arch:SSE
// ?rva000E6EF0@Rva000E6EF0@@QAEHPBUFloatPair@@@Z, retail 0x000E6EF0, 216 bytes.
// Clamp world XY to +0x1948/+0x194C min and +0x1950/+0x1954 max, scale each
// axis by 49.9f over its extent, floor via IAT floor and return y*50+x.
// Evidence: retail movss/comiss clamp plus fld/fsub/fdivr/fmul floor/fistp
// pair plus imul 0x32; BFME1 donor Rva001A3060::getBucket uses 49.9f for a
// 50-by-50 grid; neighbours in same Common dir.
extern "C" __declspec(dllimport) double __cdecl floor(double);

__forceinline long FloatToLong(float f)
{
	long i;
	__asm {
		fld [f]
		fistp [i]
	}
	return i;
}

struct FloatPair
{
	float x;
	float y;
};

class Rva000E6EF0
{
public:
	int rva000E6EF0(FloatPair const *p);
	unsigned char m_pad0[0x1948];
	float m_minX;
	float m_minY;
	float m_maxX;
	float m_maxY;
};

int Rva000E6EF0::rva000E6EF0(FloatPair const *p)
{
	float x = p->x;
	float y = p->y;
	if (m_minX > x)
		x = m_minX;
	if (m_minY > y)
		y = m_minY;
	if (x > m_maxX)
		x = m_maxX;
	if (y > m_maxY)
		y = m_maxY;
	int ix = FloatToLong((float)floor((double)(x / (m_maxX - m_minX) * 49.9f)));
	int iy = FloatToLong((float)floor((double)(y / (m_maxY - m_minY) * 49.9f)));
	return iy * 50 + ix;
}
