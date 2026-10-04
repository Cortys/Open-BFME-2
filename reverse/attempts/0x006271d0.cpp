// ?calculate@Gen009F5040@@QAEXPAUGen009F5040Node@@PAH11@Z
// partial score=0.94 date=2026-10-04
// ?remove@Gen009F5040@@QAEXPAUGen009F5040Node@@@Z
//
// BFME1 donor Gen009F5040Handle.cpp shape: unlink the node from the
// secondary list, then walk the counter pyramid (mask/count halving per
// level). BFME2 repair: m_mask sits at +0x11C here, not BFME1's +0xEC
// (near-miss drift at +0x37: mov esi,[ecx+0xEC] vs [ecx+0x11C]), so the pad
// runs 0xFC, not 0xCC. B1 0x009F4E40 134B -> B2 0x00627570 134B,
// immediate-only drift. Leaf (no callees, no pins). The handle() sibling is
// not carried here (its B2 twin is unidentified).
struct Gen009F5040Item;

struct Gen009F5040Node
{
	char m_pad00[4];
	Gen009F5040Item *m_item;
	char m_pad08[8];
	Gen009F5040Node **m_secondaryPreviousLink;
	Gen009F5040Node *m_secondaryNext;
	Gen009F5040Node **m_previousLink;
	Gen009F5040Node *m_next;
	volatile int m_index;
	int m_result24;
	int m_result28;
	int m_result2c;
};

struct Gen009F5040Item
{
	virtual void *getValue0();
	virtual void *getValue1();
	virtual void *getValue2();
	virtual void *getValue3();
	virtual void *getValue4();
	virtual void *getValue5();
	virtual void *getValue6();
	virtual int getIndex();
};

class BfmeRecEQR;

class BfmeHostEQR
{
public:
	void bfmeLinkEQR(BfmeRecEQR *rec);
};

class BfmeHostER
{
public:
	unsigned int bfmeIndexER(float v);
};

class BfmeHostES
{
public:
	unsigned int bfmeIndexES(float v);
};

struct CalcV0
{
	char m_pad00[16];
	float m_base;
};

struct CalcV1
{
	float m_x;
	float m_y;
};

struct Gen009F5040Counter
{
	int m_value;
	Gen009F5040Node *m_head;
};

struct Gen009F5040Bucket
{
	Gen009F5040Counter *m_counter;
	int m_pad04;
	int m_pad08;
};

class Gen009F5040
{
public:
	__declspec(noinline) void remove(Gen009F5040Node *node);
	void handle();
	void linkNode(Gen009F5040Node *node);
	void calculate(Gen009F5040Node *node, int *result28, int *result2c,
		int *result24);

	Gen009F5040Bucket m_buckets[2];
	Gen009F5040Counter *m_rangeBegin;
	Gen009F5040Counter *m_rangeEnd;
	char m_pad20[0xfc];
	unsigned int m_mask;
	Gen009F5040Node *m_node;
};

// ?remove@Gen009F5040@@QAEXPAUGen009F5040Node@@@Z
void Gen009F5040::remove(Gen009F5040Node *node)
{
	if (node->m_secondaryNext != 0)
		node->m_secondaryNext->m_secondaryPreviousLink = node->m_secondaryPreviousLink;
	*node->m_secondaryPreviousLink = node->m_secondaryNext;

	node->m_secondaryPreviousLink = 0;
	Gen009F5040Counter *counter = m_buckets[node->m_index + 2].m_counter;

	Gen009F5040Counter *rangeEnd = m_rangeEnd;
	Gen009F5040Counter *rangeBegin = m_rangeBegin;
	unsigned int mask = m_mask >> 1;
	unsigned int count = (unsigned int)(rangeEnd - rangeBegin) >> 2;
	while (count != 0) {
		if ((node->m_result24 & mask) != 0)
			return;
		--counter->m_value;
		int step = (node->m_result2c & mask) != 0 ? 2 : 0;
		step += ((node->m_result28 & mask) != 0);
		counter += step * count + 1;
		count >>= 2;
		mask >>= 1;
	}
}

void Gen009F5040::handle()
{
	Gen009F5040Node *node = m_node;
	if (node == 0)
		return;

	while (node != 0) {
		if (node->m_next != 0)
			node->m_next->m_previousLink = node->m_previousLink;
		*node->m_previousLink = node->m_next;
		node->m_previousLink = 0;

		bool shouldProcess = node->m_index != node->m_item->getIndex() + 1;
		if (!shouldProcess) {
			int result28;
			int result2c;
			int result24;
			calculate(node, &result28, &result2c, &result24);
			if (result28 != node->m_result28 || result2c != node->m_result2c ||
				result24 != node->m_result24)
				shouldProcess = true;
		}
		if (shouldProcess) {
			remove(node);
			((BfmeHostEQR *)this)->bfmeLinkEQR((BfmeRecEQR *)node);
		}

		node = m_node;
	}
}

// ?linkNode@Gen009F5040@@QAEXPAUGen009F5040Node@@@Z
//
// BFME1 donor Gen009F5040Handle.cpp linkNode_009F4D80 shape: recompute the
// node results, clamp the item index, walk the counter pyramid bumping
// counts, then link the node into the winning counter's secondary list.
// BFME2 repair: the clamp is index >= 20 (cmp eax,0x14), not BFME1's >= 16
// (near-miss drift at +0x31: 10 vs 14, plus mask member +0x11C already in
// this TU). B1 0x009F4D80 181B -> B2 0x006274B0 181B, immediate-only drift.
// Callees: calculate (pinned 0x6271D0) + virtual getIndex (slot 0x1C).
void Gen009F5040::linkNode(Gen009F5040Node *node)
{
	calculate(node, &node->m_result28, &node->m_result2c, &node->m_result24);
	int index = node->m_item->getIndex();
	if (index < -1 || index >= 20)
		index = -1;
	Gen009F5040Counter *counter = m_buckets[index + 3].m_counter;
	unsigned int mask = m_mask >> 1;
	unsigned int count = (unsigned int)(m_rangeEnd - m_rangeBegin) >> 2;
	while (count != 0) {
		if (node->m_result24 & mask)
			break;
		++counter->m_value;
		int step = ((node->m_result2c & mask) != 0 ? 2 : 0);
		step += ((node->m_result28 & mask) != 0);
		counter += step * count + 1;
		count >>= 2;
		mask >>= 1;
	}
	Gen009F5040Node **slot = &counter->m_head;
	node->m_secondaryPreviousLink = slot;
	node->m_secondaryNext = *slot;
	if (node->m_secondaryNext != 0)
		node->m_secondaryNext->m_secondaryPreviousLink = &node->m_secondaryNext;
	*slot = node;
	node->m_index = index + 1;
}

// ?calculate@Gen009F5040@@QAEXPAUGen009F5040Node@@PAH11@Z present-unmatched
//
// Retail 0x006271D0 225B: two virtual values, float differences via
// bfmeIndexER/ES, combined xor/or into result24, then clear the top bit in
// result28/result2c. Callees rowed (bfmeIndexER 0x626FB0, bfmeIndexES
// 0x627020) plus virtual slots 0/4.
void Gen009F5040::calculate(Gen009F5040Node *node, int *result28, int *result2c,
	int *result24)
{
	CalcV1 *v1;
	CalcV0 *v0;
	v0 = (CalcV0 *)node->m_item->getValue0();
	v1 = (CalcV1 *)node->m_item->getValue1();
	float base = v0->m_base;
	*result28 = (int)((BfmeHostER *)this)->bfmeIndexER(v1->m_x - base);
	*result2c = (int)((BfmeHostES *)this)->bfmeIndexES(v1->m_y - base);
	unsigned int t3 = ((BfmeHostER *)this)->bfmeIndexER(base + v1->m_x) ^ (unsigned int)*result28;
	unsigned int t4 = ((BfmeHostES *)this)->bfmeIndexES(base + v1->m_y) ^ (unsigned int)*result2c;
	unsigned int comb = t3;
	comb |= t4;
	*result24 = (int)comb;
	if (comb != 0) {
		unsigned int a = comb;
		int c = 0;
		if ((a & 0xffff0000) != 0) {
			a >>= 16;
			c |= 16;
		}
		if ((a & 0xff00) != 0) {
			a >>= 8;
			c |= 8;
		}
		if ((a & 0xf0) != 0) {
			a >>= 4;
			c |= 4;
		}
		if ((a & 0xc) != 0) {
			a >>= 2;
			c |= 2;
		}
		if ((a & 2) != 0)
			c |= 1;
		int mask = ~(1 << c);
		*result28 &= mask;
		*result2c &= mask;
	}
}

// Callers elsewhere reach bodies in this unit through other spellings; retail's
// call sites in their matched rows land on these addresses (same ABI). Bind them.
#pragma comment(linker, "/alternatename:?bfmeLinkEQR@BfmeHostEQR@@QAEXPAVBfmeRecEQR@@@Z=?linkNode@Gen009F5040@@QAEXPAUGen009F5040Node@@@Z")
