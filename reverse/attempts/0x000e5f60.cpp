// ?rva000E5F60@Rva000E5F60@@QAEPAVRva000E5EC1@@HV?$StringBase@D@@@Z
// partial score=1.0 date=2026-09-28
// ?rva000E5F60@Rva000E5F60@@QAEPAVRva000E5EC1@@HV?$StringBase@D@@@Z
// partial score=1.0 date=2026-09-28
// cl: /O1 /MD /EHs

// ?rva000E5F60@Rva000E5F60@@QAEPAVRva000E5EC1@@HV?$StringBase@D@@@Z,
// RVA 0x000E5F60, 86B. Unlock lane: all callees rowed (rva000E5EC1
// 0x000E5EC1, releaseBuffer 0x00036410, __EH_prolog). Callers at
// 0x000E5FF0 (0x000E5FB6/79B) and 0x000E605F (0x000E6005/304B).
// List-find by (id, name): sentinel-circular list at +0x18 with next at
// +0x00 and item at +0x08; matcher is Rva000E5EC1::rva000E5EC1 (id at
// +0x4C, name at +0x8C via StringBase compare). Returns the item or 0.
// StringBase model and matcher declaration are Rva000E5EC1.cpp verbatim
// so the by-value param uses the shipped EH unwind and releaseBuffer.

template <typename T> class StringBase
{
public:
	~StringBase() { releaseBuffer(); }
	int compare(const StringBase<T> &other) const;
private:
	void releaseBuffer();
	void *m_data;
};

class Rva000E5EC1
{
public:
	bool rva000E5EC1(int id, const StringBase<char> &name) const throw();
};

struct Rva000E5F60Node
{
	Rva000E5F60Node *m_next;
	Rva000E5F60Node *m_prev;
	Rva000E5EC1 *m_item;
};

class Rva000E5F60
{
public:
	Rva000E5EC1 *rva000E5F60(int id, StringBase<char> name);

private:
	char m_pad[0x18];
	Rva000E5F60Node *m_head;
};

Rva000E5EC1 *Rva000E5F60::rva000E5F60(int id, StringBase<char> name)
{
	Rva000E5F60Node *cur = m_head->m_next;
	while (cur != m_head)
	{
		if (cur->m_item->rva000E5EC1(id, name))
			return cur->m_item;
		cur = cur->m_next;
	}
	return 0;
}
