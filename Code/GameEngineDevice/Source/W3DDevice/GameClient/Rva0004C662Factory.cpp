// cl: /O1 /G7 /arch:SSE /MD /EHsc /DNDEBUG
// ?rva0004C662@Rva004C743@@QAEPAVRva00984EF@@XZ @0x0004C662 50B
// Virtual-slot factory returning new Rva00984EF (0x1C bytes) via rowed ctor.
// Evidence: vtable slot 48 of 0x007C4738 class Rva004C743; callees operator new 0x0002FDA0 row mem_ops.cpp ctor 0x000984CE row OpaqueSingleInheritanceDtors.cpp EH_prolog; prev W3DGameClientSnowFactory.cpp same flags same new-pattern 53B; size 0x1C matches Rva00984EF layout.
class Rva0098477
{
public:
	Rva0098477();
	virtual ~Rva0098477();
};
class Rva00984EF : public Rva0098477
{
public:
	Rva00984EF();
	virtual ~Rva00984EF();
private:
	unsigned char m_pad04[0xC];
	int m_10;
	int m_14;
	int m_18;
};
class AISkirmishPlayer;
class Rva004C743
{
public:
	Rva00984EF *rva0004C662();
	AISkirmishPlayer *rva0004C6D4();
};
class AIPlayer
{
public:
	AIPlayer() throw();
protected:
	virtual ~AIPlayer() throw();
protected:
	char m_pad04[8];
	unsigned short m_flags0C;
	char m_pad0E[0xE20 - 0x0E];
};
class AISkirmishPlayer : public AIPlayer
{
public:
	AISkirmishPlayer();
	virtual ~AISkirmishPlayer();
private:
	void *m_slotE20;
	void *m_slotE24;
};
Rva00984EF *Rva004C743::rva0004C662()
{
	return new Rva00984EF;
}
AISkirmishPlayer *Rva004C743::rva0004C6D4()
{
	return new AISkirmishPlayer;
}
