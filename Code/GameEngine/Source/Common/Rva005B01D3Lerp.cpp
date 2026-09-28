// cl: /O1 /MD /arch:SSE
// ?rva005B01D3@Rva005B01D3@@QAEMMMM@Z, retail 0x005B01D3, 38 bytes.
// Unlock leaf: lerp(a,b,t) with negative-t fallback to member at +0x60.
// If t < 0, t = m_60; then return a + (b - a) * t (fld/fsub/fmul/fadd).
// __thiscall proven by [ecx+0x60] read; ret 0xC = 3 float params.
// Callers 0x005B0588/0x005B05A8/0x005B05C8/0x005B05E8 pass
// ([ecx+4],[ecx+0x1C],t) etc; landing this makes those 4 ready.
// Flags /O1 (EBP frame) + /arch:SSE (xorps/comiss/movss, x87 arithmetic).

class Rva005B01D3
{
public:
	float rva005B01D3(float a, float b, float t);

private:
	char m_pad[0x60];
	float m_60;
};

float Rva005B01D3::rva005B01D3(float a, float b, float t)
{
	if (t < 0.0f)
		t = m_60;
	return a + (b - a) * t;
}
