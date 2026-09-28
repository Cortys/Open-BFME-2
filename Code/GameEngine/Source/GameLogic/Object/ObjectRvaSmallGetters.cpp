// cl: /O1
//
// Three small Object readers (retail 0x0028AD6C/16 + 0x0028ADE0/12 +
// 0x0028ADF7/28). /O1 selects the retail size idioms throughout: jne plus
// inc-from-known-zero for the null-or-one reader, xor-first cmp-mem-reg for
// the flag test, and hoisted xor plus inc for the bit-test's 1<<slot.

struct Rva0028AD6CSub
{
	char m_pad[0x28];				// +0x000..+0x028 unknown
	int m_value;					// +0x028
};

struct Rva0028AF76Sub
{
	char m_pad[0x44];				// +0x000..+0x044 unknown
	int m_value;					// +0x044
};

class GameLogic
{
public:
	char m_pad[0x40];
	int m_frame; // +0x40, proven by Rva002039B6Host
};

#define TheGameLogic (*(GameLogic **)0x00DFE78C)

class WeaponSet
{
public:
	bool isOutOfAmmo() const;
};

class Object
{
	char m_pad0[0xA4];				// +0x000..+0x0A4 unknown
	Rva0028AD6CSub *m_sub;			// +0x0A4
	char m_pad1[0x240 - 0xA4 - 4];	// +0x0A8..+0x240 unknown
	Rva0028AF76Sub *m_sub240;		// +0x240
	char m_pad2[0x358 - 0x244];		// +0x244..+0x358 unknown
	int m_flag358;					// +0x358
	int m_pad358;					// +0x35C unknown
	int m_mask360;					// +0x360
	char m_pad364[0x40C - 0x364];	// +0x364..+0x40C unknown
	int m_value40C;					// +0x40C
	char m_pad410[0x48C - 0x410];	// +0x410..+0x48C unknown
	unsigned char m_flag48C;		// +0x48C
	char m_pad48D[0x490 - 0x48D];	// +0x48D..+0x490 pad
	int m_frame490;					// +0x490 cached frame

public:
	int rva0028AD6C() const;
	bool rva0028ADE0() const;
	int rva0028ADF7(int slot) const;
	int rva0028AF76() const;
	int rva0028B511() const;
	void rva0028B95F();
	bool isOutOfAmmo() const;
};

// ?rva0028AD6C@Object@@QBEHXZ
int Object::rva0028AD6C() const
{
	const Rva0028AD6CSub *sub = m_sub;
	if (sub == 0)
		return 1;
	return sub->m_value;
}

// ?rva0028ADE0@Object@@QBE_NXZ
// ?rva0028ADE0@Object@@QBE_NXZ
bool Object::rva0028ADE0() const
{
	return m_flag358 != 0;
}

// ?rva0028ADF7@Object@@QBEHH@Z
// ?rva0028ADF7@Object@@QBEHH@Z
int Object::rva0028ADF7(int slot) const
{
	return (m_mask360 & (1 << slot)) != 0 ? 1 : 0;
}

int Object::rva0028AF76() const
{
	int result = 0;
	const Rva0028AF76Sub *sub = m_sub240;
	if (sub != 0)
		result = sub->m_value;
	return result;
}

int Object::rva0028B511() const
{
	if (m_flag48C != 0)
		return 1;
	return m_value40C;
}

// ?rva0028B95F@Object@@QAEXXZ, retail 0x0028B95F, 22 bytes.
// Sets the +0x48C flag and caches TheGameLogic frame at +0x490. Evidence:
// flag byte proven by rva0028B511 in this TU, frame slot +0x40 proven by
// Rva002039B6Host, callers at 0x0046E268 0x0046E297 iterate and call with
// Object this.
void Object::rva0028B95F()
{
	m_flag48C = 1;
	m_frame490 = TheGameLogic->m_frame;
}

bool Object::isOutOfAmmo() const
{
	const WeaponSet *ws = (const WeaponSet *)((const char *)this + 0x330);
	return ws->isOutOfAmmo();
}
