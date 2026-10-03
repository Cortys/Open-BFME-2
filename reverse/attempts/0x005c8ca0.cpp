// ?rva005C8CA0@Rva005C8C73@@QAEPAXPBX@Z
// partial score=0.96 date=2026-10-03
// cl: /DNDEBUG /DWIN32 /D_WINDOWS /MD /O1 /GX /arch:SSE
//
// ?rva005C8CA0@Rva005C8C73@@QAEPAXPBX@Z @0x005C8CA0 58B.
// STLport float-keyed tree lower_bound between the rowed Rva005C8C73 erase
// (0x005C8C73) and clear (0x005C8CDA).  Callers 0x005C8D07 and 0x005C8DDF.
// Node +0x08 left / +0x0C right / +0x10 float key; head +0x04 first.

struct RvaTreeFamilyNode
{
	char m_pad[8]; // +0x00..0x07
	RvaTreeFamilyNode *m_next; // +0x08
	RvaTreeFamilyNode *m_child; // +0x0C
};

struct RvaTreeFamilyHead
{
	char m_pad00[4]; // +0x00
	RvaTreeFamilyNode *m_first; // +0x04
	RvaTreeFamilyHead *m_next; // +0x08
	RvaTreeFamilyHead *m_child; // +0x0C
};

class Rva005C8C73
{
public:
	void *rva005C8CA0(const void *key);
private:
	void *m_00Head; // +0x00
	int m_04Flag; // +0x04
};

struct Rva005C8CA0Node
{
	char m_pad[8];
	Rva005C8CA0Node *m_left; // +0x08
	Rva005C8CA0Node *m_right; // +0x0C
	float m_key; // +0x10
};

void *Rva005C8C73::rva005C8CA0(const void *key)
{
	RvaTreeFamilyHead *head = (RvaTreeFamilyHead *)m_00Head;
	Rva005C8CA0Node *cur = (Rva005C8CA0Node *)head->m_first;
	const float *kf = (const float *)key;
	Rva005C8CA0Node *res = (Rva005C8CA0Node *)head;
	while (cur)
	{
		if (!(cur->m_key < *kf))
		{
			res = cur;
			cur = cur->m_left;
		}
		else
			cur = cur->m_right;
	}
	if (res == (Rva005C8CA0Node *)head || res->m_key > *kf)
		res = (Rva005C8CA0Node *)head;
	return res;
}
