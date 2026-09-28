// cl: /O1 /MD
//
// ?rva001E34FA@Rva001E34FA@@QAEHXZ, retail 0x001E34FA, 23 bytes.
// Guarded two-level field reader: eax=[this]; if null return 1;
// ecx=[eax+8]; if null return [eax+0x18] else return [ecx+0x18].
// Called at 0x001E74A5/0x001E74B7 and 0x0026A7AE/0x0026ACCC.
// Owner identity unproven, honest Rva name.

struct Rva001E34FAInner
{
	int m_pad00[6]; // +0x00..+0x17
	int m_val18; // +0x18
};

struct Rva001E34FAOuter
{
	int m_pad00[2]; // +0x00..+0x07
	Rva001E34FAInner *m_p08; // +0x08
	int m_pad0C[3]; // +0x0C..+0x17
	int m_val18; // +0x18
};

class Rva001E34FA
{
public:
	int rva001E34FA();
private:
	Rva001E34FAOuter *m_p00;
};

int Rva001E34FA::rva001E34FA()
{
	Rva001E34FAOuter *p = m_p00;
	if (!p)
		return 1;
	Rva001E34FAInner *q = p->m_p08;
	if (q)
		return q->m_val18;
	return p->m_val18;
}
