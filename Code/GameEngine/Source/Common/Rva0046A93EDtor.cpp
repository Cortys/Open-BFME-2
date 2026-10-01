// cl: /O1 /MD /EHs
// ??1Rva0046A93E@@QAE@XZ 0x0046AB1B 56B evidence: chain from rowed clear 0x46A93E plus rowed free 0x30830 header free after clear
extern "C" void __cdecl free(void *block);
struct Rva00469C34Node;
struct Rva0046A93EHeader
{
	int m_unk0;
	Rva00469C34Node *m_head;
	Rva0046A93EHeader *m_next;
	Rva0046A93EHeader *m_prev;
};
struct Rva0046A93EHolder
{
	Rva0046A93EHeader *m_ptr;
	~Rva0046A93EHolder()
	{
		if (m_ptr != 0)
			free(m_ptr);
	}
};
class Rva0046A93E
{
public:
	Rva0046A93EHolder m_header;
	int m_flag;
	void rva0046A93E();
	~Rva0046A93E();
};
Rva0046A93E::~Rva0046A93E()
{
	rva0046A93E();
}
