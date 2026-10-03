// cl: /O1
// ??1Rva00150558@@UAE@XZ @0x00150558 54B: dtor destroying vector Rva001501CA at +4 then restoring vtable 0x007C6F24 for member at +0x10 and base. Evidence: rowed callee 0x001501CA, vtable data 0x007C6F24, callers 0x00150620 0x00150DE4.
// Retail: mov eax handler / call __EH_prolog / mov edi vtable / lea ecx [esi+4] / mov [esi+0x10] edi / call ??1Rva001501CA / mov [esi] edi / EH epilog.
// Not established: owning class identity; address-derived name.

extern const void *const g_00BC6F24[];

class Snapshot
{
public:
	virtual ~Snapshot();
};

inline Snapshot::~Snapshot()
{
	*(const void **)this = g_00BC6F24;
}

class Rva0052BF33Elem;

struct Rva001501CA
{
	Rva0052BF33Elem *m_start;
	Rva0052BF33Elem *m_finish;
	Rva0052BF33Elem *m_endOfStorage;
	~Rva001501CA();
};

class __declspec(novtable) Rva00150558 : public Snapshot
{
public:
	virtual ~Rva00150558();
private:
	Rva001501CA m_04;
	Snapshot m_10;
};

Rva00150558::~Rva00150558()
{
}
