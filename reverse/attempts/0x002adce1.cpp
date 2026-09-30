// ?rva002ADCE1@Rva000427195@@QAEXPAPAX@Z
// partial score=0.9 date=2026-09-30
// ?rva002ADCE1@Rva000427195@@QAEXPAPAX@Z
// partial score=0.90 date=2026-09-30
// cl: /O1 /MD
// ?rva00223429@Rva000427195@@QAEHPBVAsciiString@@@Z @0x00223429 145B
// Erase-all by AsciiString key over the Eva bucket vector. Buckets at +4,
// count at +0x10 (proven by rowed bucketIndex 0x00223149 and inserts
// 0x001F8F2A/0x00212A5A/0x0041539F). Walks the chain with rowed StringBase
// compare 0x000069D6, unlinks via prev node, frees via rowed 0x001FD9EF
// (ignores this, called with table this like Clear 0x003A2A41), head last
// via saved byte offset. Returns removed count. Callers 0x000A810D 0x00224BB6.
class AsciiString
{
	char *m_text;
};

template <typename T>
class StringBase
{
public:
	int compare(const StringBase<T> &other) const;
};

class Rva001FD9EF
{
public:
	void rva001FD9EF(void *node);
};

class Rva000427195
{
public:
	int bucketIndex(const AsciiString *name);
	int rva00223429(const AsciiString *key);
	void rva002ADCE1(void **pp);

	void *m_unused00;
	void **m_beginBuckets;
	void **m_endBuckets;
	void **m_storageEnd;
	unsigned int m_numElements;
};

int Rva000427195::rva00223429(const AsciiString *key)
{
	int bucket = bucketIndex(key);
	void *head = m_beginBuckets[bucket];
	int removed = 0;
	if (head != 0)
	{
		void *prev = head;
		void *cur = *(void **)head;
		while (cur != 0)
		{
			if (((StringBase<char> *)((char *)cur + 4))->compare(*(const StringBase<char> *)(const void *)key) == 0)
			{
				*(void **)prev = *(void **)cur;
				((Rva001FD9EF *)this)->rva001FD9EF(cur);
				cur = *(void **)prev;
				++removed;
				--m_numElements;
			}
			else
			{
				prev = cur;
				cur = *(void **)cur;
			}
		}
		if (((StringBase<char> *)((char *)head + 4))->compare(*(const StringBase<char> *)(const void *)key) == 0)
		{
			m_beginBuckets[bucket] = *(void **)head;
			((Rva001FD9EF *)this)->rva001FD9EF(head);
			++removed;
			--m_numElements;
		}
	}
	return removed;
}

// ?rva002ADCE1@Rva000427195@@QAEXPAPAX@Z @0x002ADCE1 80B: erase-one by node pointer
// over the Eva bucket vector. Buckets at +4 count at +0x10 (same layout as
// rva00223429 above). Finds the bucket via rowed bucketIndex on the node's
// AsciiString at +4 then linear pointer search unlinks via prev node frees via
// rowed 0x001FD9EF and decs count. Evidence: ECX=this plus ret 4 plus same
// bucketIndex plus free callees as sibling; caller 0x003A37DC passes an 8-byte
// slot whose first word is the node.
// ?rva002ADCE1@Rva000427195@@QAEXPAPAX@Z present-unmatched
void Rva000427195::rva002ADCE1(void **pp)
{
	void *node = *pp;
	if (node == 0)
		return;
	const AsciiString *key = (const AsciiString *)((char *)node + 4);
	int bucket = bucketIndex(key);
	void *head = m_beginBuckets[bucket];
	void **slot = &m_beginBuckets[bucket];
	if (head == node)
	{
		*slot = *(void **)head;
		((Rva001FD9EF *)this)->rva001FD9EF(head);
	}
	else
	{
		void *cur = *(void **)head;
		void *prev = head;
		goto Test;
	Loop:
		if (cur == node)
			goto Found;
		prev = cur;
		cur = *(void **)cur;
	Test:
		if (cur != 0)
			goto Loop;
		return;
	Found:
		*(void **)prev = *(void **)cur;
		((Rva001FD9EF *)this)->rva001FD9EF(cur);
	}
	--m_numElements;
}
