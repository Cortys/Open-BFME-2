// ?unlinkChain@Rva009A36F0Owner@@QAEXPAVRva009A36F0Thing@@@Z
// partial score=0.95 date=2026-10-01
// Retail 0x007592E0 (?apply@Rva009A36F0Owner@@QAEXPAVRva009A36F0Param@@@Z).
// BFME1 donor: reference/open-bfme-1/Code/GameEngine/Source/Common/Rva009A36F0Owner.cpp
// (b1 0x009A36F0, // cl: /O2 /Ob0). The b2 body at 0x007592E0 is the same
// function: this = ebx (list-head pointer at +8, flag byte at +0xC06D),
// param = edi (virtual +0x18 void f(int), +0x1c returns a thing pointer).
// If param is null, or slot1c returns null, the function is a no-op.
// Otherwise it calls slot18(0), then links `thing` into the doubly-linked
// list rooted at this+8 when the flag is set (same back-slot/next idiom as
// the landed Rva009A3770HashChainInsert.cpp), or unlinks it and destroys it.
// callees: 0x00759220 (pinned unlinkChain), 0x00758500 (rowed CollisionData
// dtor), 0x0002FD60 (rowed operator delete).
// Adaptation vs the donor: the donor calls destroyDirect() on the thing, but
// the b2 retail call target 0x00758500 is the ledger-rowed
// ??1Rva009A45A0CollisionData@@QAE@XZ, so this TU calls that dtor directly.
// cl: /O2 /Ob1

class Rva009A36F0Thing
{
public:
	unsigned char m_pad0[4];
	int m_4;
	unsigned char m_pad8[8];
	void *m_10;
	Rva009A36F0Thing *m_14;
	unsigned char m_pad18[8];
	void *m_queueHead;
};

class Rva009A36F0Param
{
public:
	virtual void slot0();
	virtual void slot4();
	virtual void slot8();
	virtual void slotc();
	virtual void slot10();
	virtual void slot14();
	virtual void slot18(int);
	virtual Rva009A36F0Thing *slot1c();
};

class Rva009A45A0CollisionData
{
public:
	~Rva009A45A0CollisionData();
};

void __cdecl operator delete(void *block);

struct Rva009A3300Node
{
	char m_pad0[8];
	unsigned int m_key0;
	unsigned int m_key1;
	char m_pad10[0x1c];
};

class Rva009A3300HashTable
{
public:
	void remove(Rva009A3300Node *entry);
};

struct PairNode3630
{
	struct Link
	{
		Link **backlink;
		Link *next;
	};
	char pad00[8];
	unsigned key0;
	unsigned key1;
	unsigned counter;
	Link first;
	unsigned pad1c;
	Link second;
	unsigned pad28;
	PairNode3630 **backlink;
	PairNode3630 *next;
};

class Rva009A36F0Owner
{
public:
	void apply(Rva009A36F0Param *param);
	void unlinkChain(Rva009A36F0Thing *thing);

private:
	unsigned char m_pad0[8];
	Rva009A36F0Thing *m_listHead;
	unsigned char m_pad0C_AE04[0xae04 - 0xc];
	void *m_freeHead;
	unsigned char m_padAE08[4];
	void *m_cursor;
	unsigned char m_padAE10_C06D[0xc06d - 0xae10];
	unsigned char m_flag;
};

void Rva009A36F0Owner::apply(Rva009A36F0Param *param)
{
	if (param == 0)
		return;

	Rva009A36F0Thing *thing = param->slot1c();
	if (thing == 0)
		return;

	param->slot18(0);

	if (m_flag)
	{
		if (thing->m_10 == 0)
		{
			Rva009A36F0Thing **slot = (Rva009A36F0Thing **)&m_listHead;

			thing->m_10 = slot;

			Rva009A36F0Thing *head = *slot;
			thing->m_14 = head;
			if (head != 0)
				head->m_10 = &thing->m_14;

			*slot = thing;
		}

		thing->m_4 = 0;
		return;
	}

	unlinkChain(thing);
	((Rva009A45A0CollisionData *)thing)->~Rva009A45A0CollisionData();
	operator delete(thing);
}

// ?unlinkChain@Rva009A36F0Owner@@QAEXPAVRva009A36F0Thing@@@Z @ 0x00759220 (190B). Donor BFME1 collisionmanager_impl unlinkChain 0x009A3630 plus attempt 0x009A3630: queueHead+8 node first/second Link unlinks hash remove cursor freeHead; caller apply 0x007592E0; callee remove 0x00759030 rowed.
// ?unlinkChain@Rva009A36F0Owner@@QAEXPAVRva009A36F0Thing@@@Z present-unmatched
void Rva009A36F0Owner::unlinkChain(Rva009A36F0Thing *thing)
{
	while (thing->m_queueHead)
	{
		PairNode3630 *node = *(PairNode3630 **)((char *)thing->m_queueHead + 8);
		if (node->first.next)
			node->first.next->backlink = node->first.backlink;
		*node->first.backlink = node->first.next;
		PairNode3630::Link *next = node->second.next;
		node->first.backlink = 0;
		if (next)
			next->backlink = node->second.backlink;
		*node->second.backlink = node->second.next;
		Rva009A3300Node key;
		key.m_key0 = node->key0;
		node->second.backlink = 0;
		key.m_key1 = node->key1;
		((Rva009A3300HashTable *)((char *)this + 0xae10))->remove(&key);
		PairNode3630 *cursor = (PairNode3630 *)m_cursor;
		if (cursor == node)
			m_cursor = cursor->next;
		if (node->next)
			node->next->backlink = node->backlink;
		*node->backlink = node->next;
		node->backlink = 0;
		node->next = (PairNode3630 *)m_freeHead;
		m_freeHead = node;
	}
}
