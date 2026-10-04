// ?rva002C600A@Rva002C600A@@QAE_NPAXPAVObject@@@Z
// partial score=0.94 date=2026-10-04
// cl: /O1 /MD
//
// ?rva002C600A@Rva002C600A@@QAE_NPAXPAVObject@@@Z @0x002C600A 159B
// Evidence: unlock lane, prev 0x002C5FE8 next DispDwordFieldSetters,
// 1 caller 0x00261535, callees getControllingPlayer row plus rva002A8AB1
// pin plus rva002C6ACB pin plus getCurrentVictim row, global g_00DFEEF8,
// flags 0x120/0x10 plus 0x258 AIUpdate plus 0x74 compare. Identity:
// honest-address thiscall method returning bool with 2 stack args ret 8.
class Player
{
};

class Object
{
public:
	const Player *getControllingPlayer() const;
	char m_pad0[4];
	void *m_ptr4;
	char m_pad1[0x6C];
	int m_74;
	char m_pad2[0x1E0];
	class AIUpdateInterface *m_ai258;
};

class Rva002A8AB1Record
{
public:
	void *rva002C6ACB();
};

class Rva002A8F24
{
public:
	Rva002A8AB1Record *rva002A8AB1(void *p);
};

extern Rva002A8F24 *g_00DFEEF8;

class AIUpdateInterface
{
public:
	Object *getCurrentVictim() const;
};

struct Rva002C600AFlag
{
	char m_pad[0x120];
	unsigned char m_flag120;
};

struct Rva002C600AArg1
{
	char m_pad[0x74];
	int m_74;
};

class Rva002C600A
{
public:
	bool rva002C600A(void *a, Object *b);

private:
	char m_pad[8];
	void *m_ptr8;
};

// ?rva002C600A@Rva002C600A@@QAE_NPAXPAVObject@@@Z present-unmatched
bool Rva002C600A::rva002C600A(void *a, Object *b)
{
	Object *obj = b;
	Rva002C600AFlag *flag = (Rva002C600AFlag *)obj->m_ptr4;
	if ((flag->m_flag120 & 0x10) != 0)
		return false;
	const Player *player = obj->getControllingPlayer();
	Rva002A8AB1Record *rec1 = g_00DFEEF8->rva002A8AB1((void *)player);
	if (rec1 == 0)
		return true;
	Rva002A8AB1Record *rec2 = g_00DFEEF8->rva002A8AB1(m_ptr8);
	void *v1 = rec1->rva002C6ACB();
	if (v1 == m_ptr8)
		return true;
	void *v2 = rec2->rva002C6ACB();
	const Player *player2 = obj->getControllingPlayer();
	if ((void *)v2 == (void *)player2)
		return true;
	obj = (Object *)((char *)obj + 0x258);
	AIUpdateInterface *ai = *(AIUpdateInterface **)obj;
	if (ai == 0)
		return false;
	Object *victim = ai->getCurrentVictim();
	if (victim == 0)
		return false;
	Object *victim2 = (*(AIUpdateInterface **)obj)->getCurrentVictim();
	Rva002C600AArg1 *arg1 = (Rva002C600AArg1 *)a;
	int w1 = *(int *)((char *)victim2 + 0x74);
	int w2 = arg1->m_74;
	if (w1 == w2)
		return true;
	return false;
}
