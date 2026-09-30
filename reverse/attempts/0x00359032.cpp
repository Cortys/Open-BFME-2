// ?rva00359032@Rva00358E6A@@QAE?AUInsertResult00359032@@ABUValue00359032@@@Z
// partial score=0.9 date=2026-09-30
// ?rva00359032@Rva00358E6A@@QAE?AUInsertResult00359032@@ABUValue00359032@@@Z
// partial score=0.90 date=2026-09-30
// cl: /O1 /GX- /arch:SSE2
// ?rva00359032@Rva00358E6A@@QAE?AUInsertResult00359032@@ABUValue00359032@@@Z @0x00359032 151B
// insert_unique over Rva00358E6A tree: walk via AsciiString operator< 0x0005598C,
// decrement via 0x000242C0, insert via 0x00358E9F. Neighbours Rva00358E6AClear and
// Rva003592E6Clear share /O1 /GX- /arch:SSE2; header at [ebx] with root at +4 and
// leftmost at +8; node key at +0x10; ret 8 via hidden pair pointer.
class AsciiString
{
public:
	void *m_data;
};

bool __cdecl operatorLess00359032(const AsciiString &left, const AsciiString &right);
struct NodeBase00359032
{
	int m_color;
	NodeBase00359032 *m_parent;
	NodeBase00359032 *m_left;
	NodeBase00359032 *m_right;
};

struct Value00359032
{
	AsciiString m_key;
	int m_mapped;
};

struct TreeNode00359032 : public NodeBase00359032
{
	Value00359032 m_value;
};

struct TreeHeader00359032
{
	int m_color;
	TreeNode00359032 *m_parent;
	TreeHeader00359032 *m_left;
	TreeHeader00359032 *m_right;
};

struct InsertResult00359032
{
	TreeNode00359032 *m_node;
	unsigned char m_inserted;
	char m_pad[3];
};

struct Iter00359032
{
	TreeNode00359032 *m_ptr;
	Iter00359032() {}
};

class Rva00358E6A
{
public:
	InsertResult00359032 rva00359032(const Value00359032 &v);
	TreeNode00359032 *_M_decrement00359032(TreeNode00359032 *n);
	Iter00359032 _M_insert00359032(TreeNode00359032 *x, TreeNode00359032 *y, const Value00359032 &v);
private:
	TreeHeader00359032 *m_header;
	int m_count;
};

static const AsciiString &KeyOf00359032(const TreeNode00359032 *n)
{
	return n->m_value.m_key;
}

NodeBase00359032 *_Decrement00359032(NodeBase00359032 *n);
bool __cdecl Less00359032(const AsciiString &a, const AsciiString &b);

// ?rva00359032@Rva00358E6A@@QAE?AUInsertResult00359032@@ABUValue00359032@@@Z present-unmatched
InsertResult00359032 Rva00358E6A::rva00359032(const Value00359032 &v)
{
	TreeNode00359032 *y = (TreeNode00359032 *)m_header;
	TreeNode00359032 *x = m_header->m_parent;
	bool comp = true;
	while (x != 0) {
		y = x;
		comp = Less00359032(v.m_key, x->m_value.m_key);
		x = comp ? (TreeNode00359032 *)x->m_left : (TreeNode00359032 *)x->m_right;
	}
	TreeNode00359032 *j = y;
	if (comp) {
		TreeHeader00359032 *h = m_header;
		if (j == (TreeNode00359032 *)h->m_left)
			goto do_insert;
		j = (TreeNode00359032 *)_Decrement00359032(j);
	}
	if (!Less00359032(j->m_value.m_key, v.m_key)) {
		InsertResult00359032 r;
		r.m_node = j;
		r.m_inserted = 0;
		return r;
	}
do_insert:
	{
		Iter00359032 it = _M_insert00359032(x, y, v);
		InsertResult00359032 r;
		r.m_node = it.m_ptr;
		r.m_inserted = 1;
		return r;
	}
}
