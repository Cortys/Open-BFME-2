// ?rva0025FE30@Rva0025FE30@@QAEXMMMMHH@Z
// partial score=0.9 date=2026-10-02
// cl: /O1 /MD /EHsc /arch:SSE
// ?rva0025FE30@Rva0025FE30@@QAEXMMMMHH@Z 0x0025FE30 323B: Display draw with alpha clamp via TheDisplay plus two W3DDisplay draws with shadow offset from g_Va00BBB8D8.
// Evidence: caller 0x00260787 passes 4 floats from +0x4C-0x58 plus ints at +0x2C and 1; this+0x28 max alpha; callees rowed 0x0004263F and 0x0008EEF0; globals TheDisplay 0x009FE9D8 and g_Va00BBB8D8.
class Display;
extern Display *TheDisplay;
extern float g_Va00BBB8D8;
class Rva0004263F
{
public:
	void rva0004263F(float a, float b, float c, float d, int e);
};
class W3DDisplay
{
public:
	void rva0008EEF0(float x0, float y0, float x1, float y1, float w, int color);
};
inline const int &IntMin(const int &a, const int &b)
{
	return a < b ? a : b;
}
class Rva0025FE30
{
	char m_pad[0x28];
	int m_28;
public:
	void rva0025FE30(float a, float b, float c, float d, int col, int w);
};
// ?rva0025FE30@Rva0025FE30@@QAEXMMMMHH@Z present-unmatched
void Rva0025FE30::rva0025FE30(float a, float b, float c, float d, int col, int w)
{
	float dx = c - a;
	float dy = d - b;
	int alpha = ((unsigned)col >> 24);
	int c1 = IntMin(alpha, m_28);
	int col1 = (col & 0xffffff) | (c1 << 24);
	((Rva0004263F *)TheDisplay)->rva0004263F(a, b, dx, dy, col1);
	int c1x2 = c1 + c1;
	int c2 = IntMin(c1x2, m_28);
	float fw = (float)w;
	float w2 = (float)(w + w);
	float x1 = w2 + dx;
	float y1 = w2 + dy;
	float nx = a - fw;
	float ny = b - fw;
	int col2 = c2 << 24;
	((W3DDisplay *)TheDisplay)->rva0008EEF0(nx + g_Va00BBB8D8, ny + g_Va00BBB8D8, x1, y1, fw, col2);
	((W3DDisplay *)TheDisplay)->rva0008EEF0(nx, ny, x1, y1, fw, 0x7f7f7f7f);
}
