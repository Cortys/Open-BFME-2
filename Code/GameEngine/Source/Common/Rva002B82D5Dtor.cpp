// cl: /O1 /DNDEBUG /MD /EHsc
// ??1Rva002B82D5@@QAE@XZ @0x002B82D5 53B.
// Family dtor: member Rva002B57D5 at +0xC through the rowed 0x002B62A6,
// then base Rva002B57AC at +0 through the rowed 0x002B626E, with the
// __EH_prolog frame and state 0/-1 stores around the member call. Both
// subobject layouts come from the sibling dtor TUs (each 8 bytes:
// handle plus count); +8 is an untouched trivial member. Owner unknown,
// non-virtual like both callees. Callers across 0x00500xxx/0x00502xxx/
// 0x0059xxxx plus del-dtor-style jmps; unblocks 7 functions.

class Rva002B57AC
{
public:
	~Rva002B57AC();
private:
	char m_pad[8];
};

class Rva002B57D5
{
public:
	~Rva002B57D5();
private:
	char m_pad[8];
};

class Rva002B82D5 : public Rva002B57AC
{
public:
	~Rva002B82D5();
private:
	char m_pad8[4];
	Rva002B57D5 m_xC;
};

Rva002B82D5::~Rva002B82D5()
{
}
