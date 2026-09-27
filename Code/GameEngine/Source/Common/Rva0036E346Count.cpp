// cl: /O1
//
// ?rva0036E346@Rva0036E346@@QAEHXZ, retail 0x0036E346, 17 bytes.
// Circular intrusive-list count: head at +0x04, first at [head], next at
// [node+0x00], counted until back to head. Callers at 0x003540D7 (AIGroup
// path via createGroup) and 0x00548A7D (SpecialPower vector sizing) both
// pass a holder whose +0x04 is the sentinel.

struct ListNode
{
	ListNode *m_next; // +0x00
};

class Rva0036E346
{
public:
	int rva0036E346();

private:
	char m_pad0[4]; // +0x00
	ListNode *m_head; // +0x04
};

int Rva0036E346::rva0036E346()
{
	ListNode *head = m_head;
	ListNode *cur = head->m_next;
	int count = 0;
	while (cur != head)
	{
		cur = cur->m_next;
		++count;
	}
	return count;
}
