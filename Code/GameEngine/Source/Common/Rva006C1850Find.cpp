// ?rva006C1850@Rva006C1850@@QAE_NIPAPAX@Z, retail 0x006C1850, 70 bytes.
// Hash-chain find: bucket = (key>>3) % bucketCount, walk next at +8,
// compare key at +0, on hit store node+4 to *out when out non-null.
// Evidence: unlock lane calls from 0x006C259D 0x006C268C 0x006C3B6D
// 0x006C4969; div plus shr 3 plus edx*4 table load; ret 8 two args.
struct Rva006C1850Node
{
	unsigned int m_key;
	void *m_value;
	Rva006C1850Node *m_next;
};
class Rva006C1850
{
public:
	bool rva006C1850(unsigned int key, void **out);
private:
	Rva006C1850Node **m_table;
	int m_pad04;
	unsigned int m_bucketCount;
};
bool Rva006C1850::rva006C1850(unsigned int key, void **out)
{
	Rva006C1850Node **table = m_table;
	Rva006C1850Node *node = 0;
	if (table) {
		unsigned int h = (key >> 3) % m_bucketCount;
		node = table[h];
		while (node && node->m_key != key)
			node = node->m_next;
		if (node) {
			if (out)
				*out = &node->m_value;
			return true;
		}
	}
	return false;
}
