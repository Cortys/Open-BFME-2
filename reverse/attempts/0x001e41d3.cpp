// ?rva001E41D3@Rva001E41D3@@QAEXPAM@Z
// partial score=0.9 date=2026-10-01
// cl: /O1 /G7 /arch:SSE /MD
//
// ?rva001E41D3@Rva001E41D3@@QAEXPAM@Z @0x001E41D3 39B
// __thiscall void(float*): copies 3 floats from this+0x68+0xc/0x1c/0x2c to out[0..2].
// Evidence: caller 0x001E7F12 in 0x001E7ECA; neighbours Rva001E4194Get / Disp32DwordFieldGetters.
struct Rva001E41D3Inner
{
	char _00[0x0c];
	float m_0c;
	char _10[0x0c];
	float m_1c;
	char _20[0x0c];
	float m_2c;
};
class Rva001E41D3
{
public:
	void rva001E41D3(float *out);
	char _00[0x68];
	Rva001E41D3Inner m_68;
};
// ?rva001E41D3@Rva001E41D3@@QAEXPAM@Z present-unmatched
void Rva001E41D3::rva001E41D3(float *out)
{
	float a = m_68.m_0c;
	float b = m_68.m_1c;
	float c = m_68.m_2c;
	out[0] = a;
	out[1] = b;
	out[2] = c;
}
