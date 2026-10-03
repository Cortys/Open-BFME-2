// cl: /O2 /DNDEBUG /MD
// ?rva006C21C0@Rva006C17B0@@QAE_NIPAX@Z 0x006C21C0 118B hash insert with resize check via rowed 0x006C1920 and alloc via +0x14; after rva006C21B0 0x006C21B0; caller 0x006C39F0
struct Rva006C17B0Node
{
	void *m_pad0;
	void *m_data;
	Rva006C17B0Node *m_next;
};

class Rva006C17B0
{
public:
	void rva006C17B0(bool flag1, bool flag2);
	void rva006C21B0();
	bool rva006C21C0(unsigned int len, void *buf);
private:
	void **m_array;
	int m_pad4;
	unsigned int m_count;
	int m_padC;
	int m_10;
	void *(__cdecl *m_alloc)(unsigned int bytes, void *allocator);
	void (__cdecl *m_callback)(void *a, void *b);
	void *m_cbArg;
};

class Rva006C1850
{
public:
	bool rva006C1920(unsigned int newSize);
};

bool Rva006C17B0::rva006C21C0(unsigned int len, void *buf)
{
	unsigned int bucketCount = m_count;
	unsigned int size = m_10;
	unsigned int newBuckets = bucketCount * 2;
	unsigned int need = size * 4 + 4;
	if (need >= newBuckets) {
		unsigned int cap = m_padC;
		unsigned int trySize = newBuckets + 1;
		if (trySize < cap)
			trySize = cap;
		if (!((Rva006C1850 *)this)->rva006C1920(trySize))
			return false;
	}
	Rva006C17B0Node *node = (Rva006C17B0Node *)m_alloc(12, m_cbArg);
	if (node) {
		unsigned int h = (len >> 3) % m_count;
		Rva006C17B0Node *head = ((Rva006C17B0Node **)m_array)[h];
		node->m_pad0 = (void *)len;
		node->m_data = buf;
		node->m_next = head;
		((Rva006C17B0Node **)m_array)[h] = node;
		++m_10;
	}
	return node != 0;
}
