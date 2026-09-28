// cl: /O1 /DNDEBUG /MD /EHs

// ??1Rva005C18F0@@UAE@XZ, RVA 0x005C18F0, 54B. Unlock lane: virtual dtor
// storing vtable 0x008743C4, destroying the member at +8 through rowed
// ??1Rva00535776@@UAE@XZ at 0x00535776 under EH state 0, then storing the
// base vtable 0x008743B8 with no base call (trivial inline base). Member
// size is a placeholder: nothing follows it so codegen is unaffected.
// Caller is its ??_G at 0x005C18D4. Flags copy Rva005C1A36Dtor.cpp.
class Rva00535776
{
public:
	virtual ~Rva00535776();
private:
	char m_pad[4];
};

class Rva005C18F0Base
{
public:
	virtual ~Rva005C18F0Base() {}
};

class Rva005C18F0 : public Rva005C18F0Base
{
public:
	virtual ~Rva005C18F0();
private:
	char m_pad04[4];
	Rva00535776 m_08;
};

Rva005C18F0::~Rva005C18F0()
{
}
