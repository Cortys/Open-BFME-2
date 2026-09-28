// cl: /O1 /MD
//
// Opaque single-inheritance destructors tail-calling Rva0025BFE3::~
// Rva0025BFE3 at 0x0025BFE3 (row in FreeMemberDeleters.cpp: null-checked
// free of its member at +0x04). Each class below stores its own vtable and
// tail-calls the base destructor; the base itself is only declared here
// (defined once in FreeMemberDeleters.cpp), because a same-TU definition
// would capture the call locally instead of at the ledger address. Owner
// identities are unproven (opaque Rva names). One ledger row per destructor,
// landed one commit at a time.

class Rva0025BFE3
{
public:
	Rva0025BFE3();
	virtual ~Rva0025BFE3();

private:
	void *m_ptr04;
};

class Rva00596069 : public Rva0025BFE3
{
public:
	Rva00596069();
	virtual ~Rva00596069();
};

// ??0Rva00596069@@QAE@XZ, retail 0x00596057, 18 bytes. Derived default ctor
// abutting its dtor at 0x00596069: calls base Rva0025BFE3 ctor at 0x0025BFC7,
// stores derived vtable 0x00870A40, returns this. No extra members.
// Caller at 0x004E0387 constructs this.
Rva00596069::Rva00596069() : Rva0025BFE3()
{
}

Rva00596069::~Rva00596069()
{
}

class Rva00596389 : public Rva0025BFE3
{
public:
	Rva00596389(int arg);
	virtual ~Rva00596389();
	int rva00596394() const;
private:
	char m_pad08[8];
	int m_arg10;
	int m_zero14;
	int m_minusOne18;
};

// ??0Rva00596389@@QAE@H@Z, retail 0x00596366, 35 bytes. Derived ctor taking int:
// calls base, clears +0x14 to 0 via and, sets +0x18 to -1 via or (/O1 idioms),
// stores arg at +0x10, installs derived vtable 0x00870A50. Abtus its dtor.
// Caller at 0x004E03D4 passes an int.
Rva00596389::Rva00596389(int arg) : Rva0025BFE3()
{
	m_zero14 = 0;
	m_minusOne18 = -1;
	m_arg10 = arg;
}

Rva00596389::~Rva00596389()
{
}

// ?rva00596394@Rva00596389@@QBEHXZ @0x00596394 13B
// Const chase-add getter of Rva00596389: return *(int*)(*(int*)(this+0x10)+0x94)
// plus *(this+0x14). Evidence: neighbours 0x00596389 dtor / 0x005963F0 deleting
// dtor prove Rva00596389 owner (+0x10 arg ptr +0x14 zero per rowed ctor
// 0x00596366); single caller at 0x005AC092; no donor string vtable or export.
int Rva00596389::rva00596394() const
{
	int const *ptr = reinterpret_cast<int const *>(m_arg10);
	return *(int const *)((char const *)ptr + 0x94) + m_zero14;
}
