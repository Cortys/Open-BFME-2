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

// Three more destructors of this 56-byte clear-then-free shape, byte-identical to
// ??1Rva0046A93E except for the clear they call (and the EH handler record): the
// rowed clears of their own lists, whose units lay the owner out the same way
// (header +0, count +4). Owners keep their address tokens.

// ??1Rva0046A915@@QAE@XZ @0x0046AAE3 56B -> Rva0046A915::rva0046A915
class Rva0046A915
{
public:
	Rva0046A93EHolder m_header;
	int m_flag;
	void rva0046A915();
	~Rva0046A915();
};

Rva0046A915::~Rva0046A915()
{
	rva0046A915();
}

// ??1Rva0046AB7D@@QAE@XZ @0x0046E2D3 56B -> Rva0046AB7D::rva0046AB7D
class Rva0046AB7D
{
public:
	Rva0046A93EHolder m_header;
	int m_flag;
	void rva0046AB7D();
	~Rva0046AB7D();
};

Rva0046AB7D::~Rva0046AB7D()
{
	rva0046AB7D();
}

// ??1Rva0021C459@@QAE@XZ @0x0021D5D5 56B -> Rva0021C459::rva0021CF03
class Rva0021C459
{
public:
	Rva0046A93EHolder m_header;
	int m_flag;
	void rva0021CF03();
	~Rva0021C459();
};

Rva0021C459::~Rva0021C459()
{
	rva0021CF03();
}
