// cl: /O1 /EHsc /MD /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_CRTIMP= /D_BFME_RETAIL_TREE_INSERT_LAYOUT
// stlport

// ?rva004E1F97@Rva004E1F97@@QAEXPAURva004E1F97Node@@@Z, RVA 0x004E1F97, 53B.
// Unlock lane: tree erase recurse-right via [esi+0x0C] walk-left via
// [esi+0x08] clearing StringBase at node+0x10 via rowed clear 0x0048BA39
// then freeing via rowed _free 0x00030830 ret 4. Prev TreeHint family so
// same flags. Caller at 0x004E220C plus self recursion. Owner unknown so
// honest address-derived names.
template <typename T>
class StringBase
{
public:
	void clear();
private:
	void *m_data;
};
extern "C" void __cdecl free(void *p);
struct Rva004E1F97Node
{
	char m_pad00[8];
	Rva004E1F97Node *m08;
	Rva004E1F97Node *m0c;
	StringBase<char> m10;
	int m14;
};
struct Rva004E1F97
{
	void rva004E1F97(Rva004E1F97Node *node);
};

void Rva004E1F97::rva004E1F97(Rva004E1F97Node *node)
{
	if (node == 0)
		return;
	do {
		rva004E1F97(node->m0c);
		Rva004E1F97Node *left = node->m08;
		node->m10.clear();
		free(node);
		node = left;
	} while (node != 0);
}
