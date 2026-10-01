// ?rva00290496@Object@@QAEXPAVPlayer@@@Z
// partial score=0.91 date=2026-10-01
// cl: /O1 /DNDEBUG /MD
// ?rva002900E0@Object@@QAEXH@Z retail 0x002900E0 26B.
// Object status-plus-frame setter: setStatus(0x4A true) then store frame at +0x42C.
// Evidence: same-this call to rowed ?setStatus@Object@@QAEXW4ObjectStatusTypes@@_N@Z at 0x002900E7;
// neighbours ?healCompletely@Object (0x0028FF9E) and ?isAbleToAttack@Object (0x00290B73);
// callers pass Object* in ecx plus GameLogic frame in stack e.g. 0x00492BC0 mov ecx edi,
// 0x00379228 mov ecx esi push frame, 0x00492E04 mov ecx ebx; status 0x4A per Rva004AD9B0 TU.
//
// ?rva00290496@Object@@QAEXPAVPlayer@@@Z @0x00290496 70B unlock.
// Thiscall void(Player*): if player==getControllingPlayer and byte 0x121 bit
// 0x04 set then clear it with rva0028AE6D; then tail-jump via 0x250 slot 0x7c
// to slot 0xD8. Evidence: rowed getControllingPlayer 0x0028AFA9 plus pin
// rva0028AE6D plus virtuals 0x7c 0xD8, callers 0x0023CA8E 0x00377C90 0x00377D00,
// neighbours 0x002903EF 0x0029091E same TU and flags.
enum ObjectStatusTypes
{
	STATUS_04 = 4,
	STATUS_4A = 0x4A
};

class GameLogic
{
public:
	char m_pad[0x40];
	unsigned int m_frame;
};
extern GameLogic *TheGameLogic;

class Player
{
};

struct IfaceD8
{
	virtual void d000(); virtual void d001(); virtual void d002(); virtual void d003();
	virtual void d004(); virtual void d005(); virtual void d006(); virtual void d007();
	virtual void d008(); virtual void d009(); virtual void d010(); virtual void d011();
	virtual void d012(); virtual void d013(); virtual void d014(); virtual void d015();
	virtual void d016(); virtual void d017(); virtual void d018(); virtual void d019();
	virtual void d020(); virtual void d021(); virtual void d022(); virtual void d023();
	virtual void d024(); virtual void d025(); virtual void d026(); virtual void d027();
	virtual void d028(); virtual void d029(); virtual void d030(); virtual void d031();
	virtual void d032(); virtual void d033(); virtual void d034(); virtual void d035();
	virtual void d036(); virtual void d037(); virtual void d038(); virtual void d039();
	virtual void d040(); virtual void d041(); virtual void d042(); virtual void d043();
	virtual void d044(); virtual void d045(); virtual void d046(); virtual void d047();
	virtual void d048(); virtual void d049(); virtual void d050(); virtual void d051();
	virtual void d052(); virtual void d053();
	virtual void tail(Player *player);
};

struct Iface250
{
	virtual void d000(); virtual void d001(); virtual void d002(); virtual void d003();
	virtual void d004(); virtual void d005(); virtual void d006(); virtual void d007();
	virtual void d008(); virtual void d009(); virtual void d010(); virtual void d011();
	virtual void d012(); virtual void d013(); virtual void d014(); virtual void d015();
	virtual void d016(); virtual void d017(); virtual void d018(); virtual void d019();
	virtual void d020(); virtual void d021(); virtual void d022(); virtual void d023();
	virtual void d024(); virtual void d025(); virtual void d026(); virtual void d027();
	virtual void d028(); virtual void d029(); virtual void d030();
	virtual IfaceD8 *getD8();
};

class Object
{
public:
	void setStatus(ObjectStatusTypes status, bool flag);
	void rva002900E0(int frame);
	void rva002900FA(int frame);
	void rva002903C3();
	void rva002903EF();
	Player *getControllingPlayer() const;
	void rva0028AE6D();
	void rva00290496(Player *player);

private:
	char m_pad00[0x121];
	unsigned char m_121;
	char m_pad122[0x250 - 0x122];
	Iface250 *m_250;
	char m_pad254[0x42C - 0x254];
	unsigned int m_frame42C;
	unsigned int m_frame430;
};

void Object::rva002900E0(int frame)
{
	setStatus(STATUS_4A, true);
	m_frame42C = frame;
}

void Object::rva002900FA(int frame)
{
	setStatus(STATUS_04, true);
	m_frame430 = frame;
}

void Object::rva002903C3()
{
	unsigned int f = m_frame42C;
	if (f <= 0)
		return;
	if (TheGameLogic->m_frame <= f)
		return;
	setStatus(STATUS_4A, false);
	m_frame42C = 0;
}

void Object::rva002903EF()
{
	unsigned int f = m_frame430;
	if (f <= 0)
		return;
	if (TheGameLogic->m_frame <= f)
		return;
	setStatus(STATUS_04, false);
	m_frame430 = 0;
}

// ?rva00290496@Object@@QAEXPAVPlayer@@@Z present-unmatched
void Object::rva00290496(Player *player)
{
	if (player == getControllingPlayer())
	{
		if ((m_121 & 4) != 0)
		{
			m_121 &= (unsigned char)0xFB;
			rva0028AE6D();
		}
	}
	Iface250 *p = m_250;
	if (p == 0)
		return;
	IfaceD8 *q = p->getD8();
	if (q == 0)
		return;
	return q->tail(player);
}
