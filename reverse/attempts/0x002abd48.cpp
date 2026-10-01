// ?bfmeDetachCFF@BfmeOwnerCFF@@QAEXPAVBfmeThingCFF@@@Z
// partial score=0.91 date=2026-10-01
// cl: /O1 /DNDEBUG /MD /Oy-
// ?bfmeDetachCFF@BfmeOwnerCFF@@QAEXPAVBfmeThingCFF@@@Z, RVA 0x002ABD48, size 75.
// Evidence: LINK BONUS caller BfmeConv593 bfmeGoCFF; callee Rva002ABAC0Free rowed; list at +0x32c node next+0 prev+4 data+8; BFME1 Player removeTeamFromList donor.
// ?bfmeDetachCFF@BfmeOwnerCFF@@QAEXPAVBfmeThingCFF@@@Z present-unmatched
class BfmeThingCFF;
struct PoolNode002ABAC0
{
	PoolNode002ABAC0* m_prev;
	PoolNode002ABAC0* m_next;
};
void __stdcall Rva002ABAC0Free(void** out, PoolNode002ABAC0* n);
struct DetachNode
{
	DetachNode* m_next;
	DetachNode* m_prev;
	BfmeThingCFF* m_data;
};
class BfmeOwnerCFF
{
public:
	void bfmeDetachCFF(BfmeThingCFF* what);
private:
	unsigned char m_pad[0x32c];
	DetachNode* m_head;
};
void BfmeOwnerCFF::bfmeDetachCFF(BfmeThingCFF* what)
{
	for (DetachNode* p = m_head->m_next; p != m_head; p = p->m_next)
	{
	}
	for (DetachNode* p = m_head->m_next; p != m_head; p = p->m_next)
	{
		if (what == p->m_data)
		{
			Rva002ABAC0Free((void**)&what, (PoolNode002ABAC0*)p);
			break;
		}
	}
	for (DetachNode* p = m_head->m_next; p != m_head; p = p->m_next)
	{
	}
}
