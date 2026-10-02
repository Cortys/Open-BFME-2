// cl: /O1 /EHs /MD
// ??1Rva00541EB8@@UAE@XZ @0x00541EB8 74B outer dtor.
// Retail stores vtable 0x00869514 destroys two BfmeNarrowRecord0041A5D2 at
// +0x24 and +0x44 via twin 0x00541E77 then base ??1Rva0053FB33@@UAE@XZ.
// Same chain shape as rowed ??1Rva0054080A@@UAE@XZ via inner plus base.
// Evidence: vtable store plus two twin calls plus base call plus caller 0x0054218E.
struct BfmeNarrowRecord0041A5D2
{
	~BfmeNarrowRecord0041A5D2();
	unsigned char m_pad[0x20];
};

class Rva0053FB33
{
public:
	virtual ~Rva0053FB33();
private:
	unsigned char m_pad[0x24 - 4];
};

class Rva00541EB8 : public Rva0053FB33
{
public:
	virtual ~Rva00541EB8();
private:
	BfmeNarrowRecord0041A5D2 m_24;
	BfmeNarrowRecord0041A5D2 m_44;
};

Rva00541EB8::~Rva00541EB8()
{
}
