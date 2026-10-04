// cl: /O1 /MD /GX /arch:SSE
// ?Rva005EE317@@YGXPAVCoord3D@@@Z @ 0x005EE317 125B
// Random XY direction in AISPecialPowerTargetAoE.cpp (__FILE__ at 0x00878708
// line 150-151): GetGameLogicRandomValueReal(-1.0f at 0x007BB9AC, 1.0f) twice
// z=0 normalize then store to out. Callees rowed: GetGameLogicRandomValueReal
// 0x00234092 and Coord3D::normalize 0x000035B6. Gap between 0x005EE30C/0x005EE394.
//
// 0x005EE816: whether the AoE picker may use a point: its special power (+0x08,
// 0x0035B2C3) must accept it, and with +0x1A set no alive object of kind 7
// may stand within 150 of it (the PartitionFilter chain; /GX for its
// temporaries).
class Coord3D
{
public:
	void normalize();
	float x;
	float y;
	float z;
};

float __cdecl GetGameLogicRandomValueReal(float lo, float hi, char *file, int line);

void __stdcall Rva005EE317(Coord3D *out)
{
	Coord3D tmp;
	tmp.x = GetGameLogicRandomValueReal(-1.0f, 1.0f, (char *)"C:\\projects\\bfme2patch103\\bfme2\\Code\\GameEngine\\Source\\GameLogic\\SkirmishAI\\AISpecialPowers\\AISPecialPowerTargetAoE.cpp", 150);
	tmp.y = GetGameLogicRandomValueReal(-1.0f, 1.0f, (char *)"C:\\projects\\bfme2patch103\\bfme2\\Code\\GameEngine\\Source\\GameLogic\\SkirmishAI\\AISpecialPowers\\AISPecialPowerTargetAoE.cpp", 151);
	tmp.z = 0.0f;
	tmp.normalize();
	out->x = tmp.x;
	out->y = tmp.y;
	out->z = tmp.z;
}

// BFME2's partition filters (the view AIStructureCreepTactic.cpp documents):
// a vptr, the +0x04 link to the next filter, then each filter's own members.
class Object;
class Rva000421C8
{
public:
	Rva000421C8() : m_next(0) {}
	virtual ~Rva000421C8() {}
	virtual bool allow(Object *obj) = 0;
	virtual int getPlayerMask();
	Rva000421C8 *link(Rva000421C8 *next);	// 0x00625790
	Rva000421C8 *m_next;
};

class BfmeFixedStorage0004543D
{
public:
	BfmeFixedStorage0004543D(const BfmeFixedStorage0004543D &other) throw();
private:
	unsigned char m_bytes[28];
};

struct Rva00045411BitSet
{
	Rva00045411BitSet(int unused, int bit);	// 0x00045411
	unsigned int m_bits[7];
};
extern unsigned char g_00DFEFA4StoragePrototype[28];

// vftable 0x00BC2908: every kind of the first mask, none of the second.
class Rva0004584D : public Rva000421C8
{
public:
	Rva0004584D(const BfmeFixedStorage0004543D &a, const BfmeFixedStorage0004543D &b);
	virtual bool allow(Object *obj);
	BfmeFixedStorage0004543D m_08;
	BfmeFixedStorage0004543D m_24;
};

// vftable 0x00BFAD10: the object is alive.
class Rva0026119DFilter : public Rva000421C8
{
public:
	virtual bool allow(Object *obj);
};

struct BfmeWideResult
{
	Object *next() throw();	// 0x00045623
	~BfmeWideResult();	// 0x0004AA28
	void *m_value;
};

class PartitionManager
{
public:
	BfmeWideResult iterateObjectsInRange(const Coord3D *pos, float radius, int distCalc,
		Rva000421C8 *filters, int order);	// 0x00625610
};
extern PartitionManager *ThePartitionManager;

class Rva0035B2C3
{
public:
	bool rva0035B2C3(void *source, int a, const Coord3D *pos, int b);
};

// The AoE special-power target picker (0x005EE8DD walks candidate points
// round the target and keeps the first this accepts).
class Rva005EE816
{
public:
	bool rva005EE816(void *source, const Coord3D *pos);
private:
	char m_pad00[8];
	Rva0035B2C3 *m_power;	// +0x08
	char m_pad0C[0x1A - 0x0C];
	bool m_1A;		// +0x1A
};

bool Rva005EE816::rva005EE816(void *source, const Coord3D *pos)
{
	if (m_power->rva0035B2C3(source, 0, pos, 0)) {
		bool check = m_1A;
		if (check) {
			BfmeWideResult hits = ThePartitionManager->iterateObjectsInRange(pos, 150.0f, 0,
			Rva0026119DFilter().link(&Rva0004584D(*(BfmeFixedStorage0004543D *)&Rva00045411BitSet(0, 7),
				*(BfmeFixedStorage0004543D *)g_00DFEFA4StoragePrototype)), 1);
			if (hits.next() != 0)
				return false;
		}
		return true;
	}
	return false;
}

// The base filter's slot 2 is the trivial virtual retail shares across 68
// vftable slots (0x0036CC7A); bind the declaration to that row.
#pragma comment(linker, "/alternatename:?getPlayerMask@Rva000421C8@@UAEHXZ=?Get_File_Handle@FileClass@@UAEPAXXZ")
