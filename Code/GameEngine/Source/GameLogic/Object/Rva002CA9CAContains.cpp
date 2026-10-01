// cl: /O1 /DNDEBUG /MD /EHsc
// ?rva002CA9CA@Rva002CA9CA@@QAE_NHPBX@Z, retail 0x002CA9CA, 143 bytes.
// Recursive contains: +0x58 id fast path, null arg guard, intrusive list at
// +0x17C (sentinel compare), rowed upgrade-mask test 0x00507558, virtual
// slot 0x1C gate, slot 0x28 id compare at +0x158, slot 0x2C child recurse.
// Evidence: unlock lane, 4 callers including self 0x002CAA39, callees rowed,
// prev Rva002CA88BParse.cpp flags.
class Rva00507823
{
public:
	unsigned char rva00507558(const void *arg);
};

struct ListNode
{
	ListNode *m_next;
	ListNode *m_prev;
	void *m_data;
};

class VirtNode
{
public:
	virtual void v00();
	virtual bool v04(const void *a, int b);
	virtual void v08();
	virtual void v0c();
	virtual void v10();
	virtual void v14();
	virtual void v18();
	virtual bool v1c();
	virtual void v20();
	virtual void v24();
	virtual void *v28();
	virtual void *v2c();
};

struct ChildId
{
	char m_pad[0x158];
	int m_id;
};

class Rva002CA9CA
{
public:
	bool rva002CA9CA(int id, const void *arg);
	bool rva002CAA59(int a1, const void *a2);
private:
	char m_pad00[0x58];
	int m_58;
	char m_pad5c[0x17c - 0x5c];
	ListNode *m_17c;
};

bool Rva002CA9CA::rva002CA9CA(int id, const void *arg)
{
	if (m_58 == id)
		return true;
	if (arg == 0)
		return false;
	ListNode *cur = m_17c->m_next;
	while (cur != m_17c)
	{
		VirtNode *obj = (VirtNode *)cur->m_data;
		if (((Rva00507823 *)obj)->rva00507558(arg))
		{
			if (obj->v1c())
			{
				void *p = obj->v28();
				if (p != 0)
				{
					if (((ChildId *)p)->m_id == id)
						return true;
				}
			}
			void *child = obj->v2c();
			if (child != 0)
			{
				if (((Rva002CA9CA *)child)->rva002CA9CA(id, arg))
					return true;
			}
		}
		cur = cur->m_next;
	}
	return false;
}

bool Rva002CA9CA::rva002CAA59(int a1, const void *a2)
{
	if (a1 == 0)
		return false;
	ListNode *cur = m_17c->m_next;
	while (cur != m_17c)
	{
		VirtNode *obj = (VirtNode *)cur->m_data;
		if (obj->v04(a2, a1))
			return true;
		cur = cur->m_next;
	}
	return false;
}
