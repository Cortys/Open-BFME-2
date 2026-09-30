// cl: /O1 /DNDEBUG /MD /arch:SSE
// ?rva00098573@Rva00098573@@QAEPAMPAMHH@Z @ 0x00098573 95B
// Fill out vec3: init to g_Va00BBB8D8, query grid cell via rowed Rva00285D34
// at g_00DFEC68, copy this+0x20 on 1 and this+0x14 on 2, then copy to out.
extern float g_Va00BBB8D8;

class Rva00285D34
{
public:
	int rva00285D34(int x, int y);
};

extern Rva00285D34 *g_00DFEC68;

struct Rva00098573Vec
{
	float x;
	float y;
	float z;
};

class Rva00098573
{
public:
	float *rva00098573(float *out, int a, int b);
private:
	char m_pad[0x14];
};

float *Rva00098573::rva00098573(float *out, int a, int b)
{
	Rva00098573Vec tmp;
	tmp.x = g_Va00BBB8D8;
	tmp.y = g_Va00BBB8D8;
	tmp.z = g_Va00BBB8D8;
	float *f = (float *)this;
	Rva00285D34 *grid = g_00DFEC68;
	if (grid != 0) {
		int r = grid->rva00285D34(a, b);
		if (r == 1) {
			f += 8;
			tmp = *(const Rva00098573Vec *)f;
		}
		else if (r == 2) {
			f += 5;
			tmp = *(const Rva00098573Vec *)f;
		}
	}
	*(Rva00098573Vec *)out = tmp;
	return out;
}

