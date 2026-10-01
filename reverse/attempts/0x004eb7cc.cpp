// ?rva004EB7CC@Rva004EB7CC@@QAE_NPAVPlayer@@@Z
// partial score=0.9 date=2026-10-01
// cl: /O1 /G7 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc /arch:SSE
// stlport
// ?rva004EB7CC@Rva004EB7CC@@QAE_NPAVPlayer@@@Z @0x004EB7CC 310B
// Evidence: chain from Player::rva002AF614 0x002AF614 now rowed; this+8 vector of Object* outer step 4 abuts prev Rva004EB794 0x004EB794+56; local vector via rowed Vector_base BfmeE16 0x00211E58 filled by Player iterate; inner step 0xC 3-float positions; virtual at +0x34 returns pos; distSq vs float at 0x00C6292C; caller 0x004E9DFE.
#include <vector>

struct BfmeE16 { float x, y, z, w; };
struct Pos12 { float x, y, z; };
struct Vec3 { float x, y, z; };

class Player
{
public:
	void rva002AF614(void *userData);
};

class Object
{
public:
	virtual void f0();
	virtual void f1();
	virtual void f2();
	virtual void f3();
	virtual void f4();
	virtual void f5();
	virtual void f6();
	virtual void f7();
	virtual void f8();
	virtual void f9();
	virtual void f10();
	virtual void f11();
	virtual void f12();
	virtual const Vec3 *getPos(void *tmp) throw();
};

class Rva004EB7CC
{
public:
	bool rva004EB7CC(Player *player);
private:
	char m_pad[8];
	_STL::vector<Object *> m_vec;
};

extern const float g_00C6292C;

// ?rva004EB7CC@Rva004EB7CC@@QAE_NPAVPlayer@@@Z present-unmatched
bool Rva004EB7CC::rva004EB7CC(Player *player)
{
	_STL::vector<BfmeE16> tmp;
	player->rva002AF614(&tmp);
	_STL::vector<Pos12> &loc = (_STL::vector<Pos12> &)tmp;
	if (loc.begin() == loc.end())
		return false;
	if (m_vec.begin() == m_vec.end())
		return true;
	Pos12 *lend;
	Object **oend;
	oend = m_vec.end();
	lend = loc.end();
	for (Object **outer = m_vec.begin(); outer != oend; ++outer)
	{
		bool far = true;
		for (Pos12 *p = loc.begin(); p != lend; ++p)
		{
			Vec3 local;
			local.x = p->x;
			local.y = p->y;
			local.z = p->z;
			Vec3 buf;
			const Vec3 *rem = (*outer)->getPos(&buf);
			float dx = local.x - rem->x;
			float dy = local.y - rem->y;
			float dz = local.z - rem->z;
			float d2 = dx * dx + dy * dy + dz * dz;
			if (d2 < g_00C6292C)
				far = false;
		}
		if (far)
			return false;
	}
	return true;
}
