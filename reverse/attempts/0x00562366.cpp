// ??0Rva00562366@@QAE@IAAUSrc00562366@@@Z
// partial score=0.93 date=2026-09-30
// ??0Rva00562366@@QAE@IAAUSrc00562366@@@Z
// partial score=0.93 date=2026-09-30
// cl: /O1 /DNDEBUG /MD /EHs /arch:SSE
// ??0Rva00562366@@QAE@IAAUSrc00562366@@@Z 0x00562366 376B
// Ctor twin of Rva005646BC: base Rva003ADFDB via rowed uint ctor plus member Rva0056224F plus vtable 0x81D31C plus s_slot plus 12 floats via getValue plus ParticleSystem 0x180/0x184 adds plus int at +0x40.
// Evidence: callees 0x0056224F plus 0x002341A1 plus 0x001FCBD7 pin plus 0x0004CBC0 all rowed/pinned; caller at 0x003ACAC1; prev xfer 0x0056234A same vtable.
class GameClientRandomVariable
{
public:
	float getValue() const;
private:
	int m_type;
	float m_low;
	float m_high;
};

class ParticleSystem;

class Rva003ADFDB
{
public:
	Rva003ADFDB(unsigned int a);
	virtual ~Rva003ADFDB();
private:
	unsigned int m_04;
};

class Rva0056224F
{
public:
	Rva0056224F();
	~Rva0056224F();
};

struct RvaSmartPtr12
{
	void *m_ptr;
	int m_04;
	int m_08;
};

class Rva0055DDB6SmartField
{
public:
	RvaSmartPtr12 get() const;
};

class BfmeParticleSystemHandle
{
public:
	~BfmeParticleSystemHandle();
	void *m_ptr;
	int m_04;
	int m_08;
};

ParticleSystem *Make001FCBD7();

extern "C" char s_slot3E4first;
extern const void *const g_00C1D31C[];

struct Src00562366
{
	char m_00[0x20];
	GameClientRandomVariable m_20;
	GameClientRandomVariable m_2C;
	GameClientRandomVariable m_38;
	GameClientRandomVariable m_44;
	GameClientRandomVariable m_50;
	GameClientRandomVariable m_5C;
	GameClientRandomVariable m_68;
	GameClientRandomVariable m_74;
	GameClientRandomVariable m_80;
	GameClientRandomVariable m_8C;
	GameClientRandomVariable m_98;
	GameClientRandomVariable m_A4;
	int m_B0;
};

class __declspec(novtable) Rva00562366 : public Rva003ADFDB
{
public:
	Rva00562366(unsigned int a, Src00562366 &src);
	~Rva00562366();
private:
	void *m_08;
	Rva0056224F m_0C;
};

// ??0Rva00562366@@QAE@IAAUSrc00562366@@@Z present-unmatched
Rva00562366::Rva00562366(unsigned int a, Src00562366 &src)
	: Rva003ADFDB(a)
{
	*(const char **)&m_0C = "HZz";
	*(const void **)this = g_00C1D31C;
	*(void **)((char *)this + 8) = (void *)&s_slot3E4first;
	RvaSmartPtr12 smart = ((Rva0055DDB6SmartField *)&src)->get();
	float v20 = src.m_20.getValue();
	*(float *)((char *)this + 0x10) = v20;
	ParticleSystem *ps = *(ParticleSystem **)&smart;
	if (!ps)
		ps = Make001FCBD7();
	float mul = *(float *)((char *)ps + 0x184);
	float v2C = src.m_2C.getValue();
	*(float *)((char *)this + 0x14) = v2C * mul;
	*(float *)((char *)this + 0x18) = src.m_38.getValue();
	*(float *)((char *)this + 0x1C) = src.m_44.getValue();
	*(float *)((char *)this + 0x20) = src.m_50.getValue();
	*(float *)((char *)this + 0x24) = src.m_5C.getValue();
	*(float *)((char *)this + 0x28) = src.m_68.getValue();
	*(float *)((char *)this + 0x2C) = src.m_74.getValue();
	*(float *)((char *)this + 0x30) = src.m_80.getValue();
	ParticleSystem *pa = *(ParticleSystem **)&smart;
	if (!pa)
		pa = Make001FCBD7();
	float add0 = *(float *)((char *)pa + 0x180);
	*(float *)((char *)this + 0x10) += add0;
	ParticleSystem *pb = *(ParticleSystem **)&smart;
	if (!pb)
		pb = Make001FCBD7();
	float add1 = *(float *)((char *)pb + 0x180);
	*(float *)((char *)this + 0x14) += add1;
	ParticleSystem *pc = *(ParticleSystem **)&smart;
	if (!pc)
		pc = Make001FCBD7();
	float add2 = *(float *)((char *)pc + 0x180);
	*(float *)((char *)this + 0x18) += add2;
	*(float *)((char *)this + 0x34) = src.m_8C.getValue();
	*(float *)((char *)this + 0x38) = src.m_98.getValue();
	*(float *)((char *)this + 0x3C) = src.m_A4.getValue();
	*(int *)((char *)this + 0x40) = src.m_B0;
	if (*(void **)&smart)
		((BfmeParticleSystemHandle *)&smart)->~BfmeParticleSystemHandle();
}

