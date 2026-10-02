// Derived destructor at retail 0x006ECFC0 (82 bytes), recovered from the
// ??1Rva006D6470Owner@@UAE@XZ recipe at 0x006D6470. Same operand-masked shape:
// the compiler stores this class's vtable, calls the EAStringC member
// destructor at +0x20 under EH state 0, then calls the base destructor under
// EH state -1 around the SEH registration. Only the vtable, the member offset
// and the member/base callees differ; the base here is the template's own
// Rva006D6470Owner, so the class is one level deeper. Evidence: retail vtable
// 0x00CECB54; member dtor 0x006D3010 is the rowed ??1EAStringC@@QAE@XZ; base
// dtor 0x006D6470 is the rowed template body.

struct Rva006D6470Owner
{
	char m_pad[8]; // +0x04..0x0B: base footprint is the vtable plus its members
	virtual ~Rva006D6470Owner();
};

class EAStringC
{
public:
	~EAStringC();
};

struct Rva006ECFC0Owner : public Rva006D6470Owner
{
	char m_pad[0x14]; // +0x0C..0x1F
	EAStringC m_member; // +0x20

	virtual ~Rva006ECFC0Owner();
};

Rva006ECFC0Owner::~Rva006ECFC0Owner()
{
}
