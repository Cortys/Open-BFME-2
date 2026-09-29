// ?rva00262DD3@AIUpdateInterface@@QAE_NPAX@Z
// partial score=0.95 date=2026-09-29
// ?rva00262DD3@AIUpdateInterface@@QAE_NPAX@Z
// partial score=0.95 date=2026-09-29
// cl: /O1 /DNDEBUG /MD
//
// ?rva00262DD3@AIUpdateInterface@@QAE_NPAX@Z, retail 0x00262DD3, 81 bytes.
// AIUpdateInterface predicate: arg+0x74 wanted ID; machine at +0x30 with
// primary/fallback State* at +0x50/+0x04 (ID at +0x04, INVALID 0xF423F);
// proceeds only if either ID is 0x1A, then true if wanted equals +0x198 or
// +0x19C. Models follow getCurrentStateID (machine/states) and caller
// 0x00498E11 (ECX is AIUpdateInterface via Object+0x258). Static goto form
// shares the false block like retail; remaining wall is second-check branch
// direction plus true/false block order (je-then-xor-then-mov vs jne-mov-xor).
// Whole TU below (add to AIUpdateInterface_rva00262D2D.cpp which owns the
// class and // cl:, or mirror its layout in a beside-TU).

struct AIState
{
	char m_pad00[4];
	int m_id;
};

struct AIStateMachine
{
	char m_pad00[4];
	AIState *m_state04;
	char m_pad08[0x50 - 8];
	AIState *m_state50;
};

struct Rva00262DD3Arg
{
	char m_pad00[0x74];
	int m_id74;
};

class AIUpdateInterface
{
public:
	virtual void s00();
	virtual void s04();
	virtual void s08();
	virtual void s0C();
	virtual void s10();
	virtual void s14();
	virtual void s18();
	virtual void s1C();
	virtual void s20();
	virtual void s24();
	virtual void s28();
	virtual void s2C();
	virtual void s30();
	virtual void s34();
	virtual void s38();
	virtual void s3C();
	virtual void s40();
	virtual void s44();
	virtual void s48();
	virtual void s4C();
	virtual void s50();
	virtual void s54();
	virtual void s58();
	virtual void s5C();
	virtual void s60(int v);
	void destroyPath();
	void rva00262D2D();
	bool rva00262DD3(void *arg);

private:
	char m_pad04[0x30 - 4];
	AIStateMachine *m_machine;
	char m_pad34[0x198 - 0x34];
	int m_198;
	int m_19C;
};

void AIUpdateInterface::rva00262D2D()
{
	destroyPath();
	s60(2);
}

// ?rva00262DD3@AIUpdateInterface@@QAE_NPAX@Z present-unmatched
bool AIUpdateInterface::rva00262DD3(void *arg)
{
	int wanted = ((const Rva00262DD3Arg *)arg)->m_id74;
	AIStateMachine *m = m_machine;
	int id = m->m_state50 ? m->m_state50->m_id : 0xF423F;
	if (id != 0x1A)
	{
		id = m->m_state04 ? m->m_state04->m_id : 0xF423F;
		if (id != 0x1A)
			goto False;
	}
	if (m_198 == wanted)
		goto True;
	if (m_19C != wanted)
		goto False;
True:
	return true;
False:
	return false;
}
