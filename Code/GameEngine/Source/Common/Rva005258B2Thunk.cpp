// cl: /Ireference/shims/bfme2_ascii /O1 /MD /EHsc
// ?rva005258B2@Rva005258B2@@QAEXPAX@Z, retail 0x005258B2 7B chain via 0x0052557E.
// Forwarder: ecx=[ecx] then tail-jmp to rowed 0x0052557E.
// Evidence: callee rowed ?rva0052557E@Rva0052557E@@QAEXPAX@Z; caller 0x002D3756 guard then jmp; prev 0x0052557E same dir.
class Rva0052557E
{
public:
	void rva0052557E(void *p);
};

class Rva005258B2
{
public:
	Rva0052557E *m_ptr;
	void rva005258B2(void *p);
};

void Rva005258B2::rva005258B2(void *p)
{
	m_ptr->rva0052557E(p);
}
