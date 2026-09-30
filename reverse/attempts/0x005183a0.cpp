// ?rva005183A0@Rva005183A0@@QAE_NXZ
// partial score=0.96 date=2026-09-30
// ?rva005183A0@Rva005183A0@@QAE_NXZ
// partial score=0.96 date=2026-09-30
// cl: /O1 /DNDEBUG /MD /EHsc
// ?rva005183A0@Rva005183A0@@QAE_NXZ, retail 0x005183A0, 90 bytes.
// Unlock: if +0x310 null return false else if !=5 return true else
// OptionPreferences forward via rowed ctor/forward/base-dtor returning
// forward!=0. Evidence: unlock lane, callers 0x00518413 0x005197C4.

class Rva002E4272
{
public:
	virtual ~Rva002E4272();
	char m_pad[0x20 - 4];
};

class OptionPreferences : public Rva002E4272
{
public:
	OptionPreferences();
	int Rva002E432EForward();
};

class Rva005183A0
{
public:
	bool rva005183A0();
	char m_pad[0x310];
	int m_val310;
};

// ?rva005183A0@Rva005183A0@@QAE_NXZ present-unmatched
bool Rva005183A0::rva005183A0()
{
	int v = *(int *)((char *)this + 0x310);
	if (v == 0)
		return false;
	if (v != 5)
		return true;
	OptionPreferences opt;
	int f = opt.Rva002E432EForward();
	return f != 0;
}
