// ?rva00431BDD@Rva00431BDD@@QAE_NPAVGameMessage@@@Z
// partial score=0.93 date=2026-10-01
// cl: /O1 /MD
// ?rva00431BDD@Rva00431BDD@@QAE_NPAVGameMessage@@@Z @0x00431BDD 88B: thiscall bool method checking GameMessage+0x10 vs this+8 then pixel proximity via rowed 0x00431978 plus int arg2 minus this+0x18 unsigned < 500. Evidence: chain lane calls rowed 0x00431978 just landed; rowed getArgument 0x0030F4EA; callers 0x00432068; neighbours Rva00431B76 Rva00431C35 same layout. Retail xor al test al prove 1-byte return not int; row type H is wrong.
struct ICoord2D
{
	int m_x;
	int m_y;
};

union GameMessageArgumentType
{
	int integer;
	float real;
	int boolean;
	int objectID;
	struct Pix { int x; int y; } pixel;
};

class GameMessage
{
public:
	const GameMessageArgumentType *getArgument(int argIndex) const;
private:
	char m_pad[0x10];
	int m_10;
};

class Rva00431978
{
	char m_pad[0x0c];
	ICoord2D m_0C;
public:
	bool rva00431978(ICoord2D *p);
};

class Rva00431BDD
{
	void *m_00;
	void *m_04;
	int m_08;
	ICoord2D m_0C;
	int m_14;
	int m_18;
public:
	bool rva00431BDD(GameMessage *msg);
};

bool Rva00431BDD::rva00431BDD(GameMessage *msg)
{
	int t = *(int *)((char *)msg + 0x10);
	if (t == m_08)
		return false;
	const GameMessageArgumentType *a0 = msg->getArgument(0);
	ICoord2D tmp;
	tmp = *(const ICoord2D *)&a0->pixel;
	if (!((Rva00431978 *)this)->rva00431978(&tmp))
		return false;
	int v = msg->getArgument(2)->integer;
	v -= m_18;
	return (unsigned int)v < 0x1f4;
}
