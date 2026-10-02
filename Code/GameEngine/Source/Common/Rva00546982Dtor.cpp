// cl: /Ireference/shims/bfme2_ascii /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
//
// ??1Rva00546982@@UAE@XZ, retail 0x005468E1, 59 bytes.
// Rva00546982 destructor: reinstalls vtable 0x0086A314, destroys the +0x18
// member through the rowed ??1Rva002EE9B7 (state 0), then calls the rowed
// base ??1SpecialPowerModuleData at 0x00548948 (state -1). Layout from the
// rowed ctor 0x00546982 in Rva00546982Ctor.cpp (SpecialPowerModuleData base
// 0x18, member at +0x18, bool at +0x24). Member is the opaque rowed tree/pool
// type so the call mangles to the row name and links; vtable immediate is
// DIR32.

class SpecialPowerModuleData
{
public:
	virtual ~SpecialPowerModuleData();

private:
	unsigned char m_pad04[0x18 - 4];
};

class Rva002EE9B7
{
public:
	~Rva002EE9B7();

private:
	void *m_header;
	int m_flag;
};

class Rva00546982 : public SpecialPowerModuleData
{
public:
	virtual ~Rva00546982();

private:
	Rva002EE9B7 m_18; // +0x18
	int m_pad20; // +0x20, set in the ctor TU is 12 bytes here
	bool m_24; // +0x24
};

// ??1Rva00546982@@UAE@XZ @0x005468E1
Rva00546982::~Rva00546982()
{
}
