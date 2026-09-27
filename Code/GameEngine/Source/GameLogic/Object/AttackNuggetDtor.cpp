// cl: /O1 /MD /EHsc /DNDEBUG
//
// ??1AttackNugget@@UAE@XZ, retail 0x001F0622, 48 bytes.
// Target evidence: the audited scalar deleting dtor 0x001F0606 (vtable
// 0x00BE0FF4 slot 0) calls this body. It destroys the two-string record at
// +0x04 (0x000B6CF1), then the inlined trivial base stores vtable 0x00BE09D0.
// No derived vptr store (novtable). AttackNugget spelling is donor-carried
// per the audited pin; the base and member types are unrecovered.

class Rva001F0622Base
{
public:
	virtual ~Rva001F0622Base();
};

inline Rva001F0622Base::~Rva001F0622Base()
{
	*(const void **)this = reinterpret_cast<const void *>(0x00BE09D0);
}

class BfmeStringRecord000B94D2
{
public:
	~BfmeStringRecord000B94D2();

private:
	void *m_strings[2];
};

class __declspec(novtable) AttackNugget : public Rva001F0622Base
{
public:
	virtual ~AttackNugget();

private:
	BfmeStringRecord000B94D2 m_record;	// +0x04
};

AttackNugget::~AttackNugget()
{
}
