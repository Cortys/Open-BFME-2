// ?rva0046A6C1@Rva0046A6C1@@QAE_NXZ
// partial score=0.95 date=2026-09-29
// ?rva0046A6C1@Rva0046A6C1@@QAE_NXZ
// partial score=0.95 date=2026-09-29
// cl: /O1
// ?rva0046A6C1@Rva0046A6C1@@QAE_NXZ retail 0x0046A6C1 81B.
// Chain lane: calls rowed 0x003638BA plus rowed 0x0046247D pair out-copy.
// Evidence: same this-0x11C plus list head reload plus +0x258/+0x140 chase.

struct Rva0046A6C1Node
{
	Rva0046A6C1Node *m_next0;
	char m_pad4[4];
	void *m_ptr8;
};

struct Rva0046247DPair
{
	void *first;
	Rva0046A6C1Node **second;
};

class Rva0046247D
{
public:
	void rva0046247D(Rva0046247DPair &result);
};

class Rva003638BA
{
public:
	bool rva003638BA();
};

struct Rva0046A6C1Mid
{
	char m_pad0[0x140];
	Rva003638BA *m_rva140;
};

struct Rva0046A6C1Outer
{
	char m_pad0[0x258];
	Rva0046A6C1Mid *m_mid258;
};

class Rva0046A6C1
{
public:
	bool rva0046A6C1();
};

// ?rva0046A6C1@Rva0046A6C1@@QAE_NXZ present-unmatched
bool Rva0046A6C1::rva0046A6C1()
{
	Rva0046247DPair pair;
	((Rva0046247D *)((char *)this - 0x11C))->rva0046247D(pair);
	Rva0046A6C1Node **headPtr = pair.second;
	Rva0046A6C1Node *node = *(Rva0046A6C1Node **)*headPtr;
	if (node == *headPtr)
		return false;
	do {
		void *p8 = node->m_ptr8;
		if (p8 != 0) {
			Rva0046A6C1Mid *mid = ((Rva0046A6C1Outer *)p8)->m_mid258;
			Rva003638BA *rva = mid->m_rva140;
			if (rva != 0 && rva->rva003638BA())
				return true;
		}
		node = node->m_next0;
	} while (node != *headPtr);
	return false;
}
