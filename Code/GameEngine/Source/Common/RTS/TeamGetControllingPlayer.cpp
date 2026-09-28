// cl: /O1 /DNDEBUG /MD /EHsc

// ?getControllingPlayer@Team@@QBEPAVPlayer@@XZ, retail 0x0039D7CF (12 bytes).
// Team::getControllingPlayer is `return m_proto ? m_proto->m_owningPlayer :
// NULL`. Retail-measured BFME2 layout: Team::m_proto is at +0x30 here and the
// prototype owner holds m_owningPlayer at +0x08. Dedicated TU so the pin
// (Object::getControllingPlayer tail target) resolves to a row.

class Player
{
public:
	unsigned char m_pad00[ 0x5c ];
	int m_playerType;
};

struct TeamPrototypeOwner
{
	unsigned char m_pad00[ 0x08 ];
	Player *m_owningPlayer;
};

class Rva002A9BF2
{
public:
	void *rva002A9BF2();
};

class Object
{
public:
	unsigned char m_pad00[ 0x74 ];
	unsigned int m_id;
};

class Team
{
public:
	Player *getControllingPlayer() const;
	void rva0039D84A(Object *obj);

private:
	unsigned char m_pad00[ 0x30 ];
	TeamPrototypeOwner *m_proto;
	unsigned char m_pad01[ 0x114 - 0x34 ];
	unsigned int m_target;
};

Player *Team::getControllingPlayer() const
{
	if( !m_proto )
		return 0;
	return m_proto->m_owningPlayer;
}

// ?rva0039D84A@Team@@QAEXPAVObject@@@Z, retail 0x0039D84A (63 bytes).
// Team::rva0039D84A(Object*): clears Team+0x114 when arg null else stores
// Object+0x74 id only for computer players (Player+0x5c == 1) with non-zero
// difficulty via rowed Rva002A9BF2::rva002A9BF2. Shape matches the BFME1/ZH
// Team::setTeamTargetObject donor with BFME2 deltas (Team proto +0x30 vs +0x04
// target +0x114 vs +0xE8 Player type +0x5c vs +0x2c Object id +0x74 same).
// Same TU as getControllingPlayer so the second call reuses ecx as retail does.
void Team::rva0039D84A(Object *obj)
{
	if( obj == 0 )
	{
		m_target = 0;
		return;
	}
	if( getControllingPlayer()->m_playerType != 1 )
		return;
	if( ((Rva002A9BF2 *)getControllingPlayer())->rva002A9BF2() == 0 )
		return;
	m_target = obj->m_id;
}
