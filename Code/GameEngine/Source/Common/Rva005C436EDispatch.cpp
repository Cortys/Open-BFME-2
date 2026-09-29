// cl: /O1 /MD
// ?rva005C436E@Rva005C436E@@QAEXH@Z retail 0x005C436E 65B
// Evidence: callers 0x005C43BE 0x005C444D unblocks 0x005C4423 plus 0x005C43AF; rowed find 0x002B51F8 plus adds 0x002E07B9 0x002E07AC; chain [esi+4]+0x24+0x13c plus switch [esi+8]+8
class Rva002E2903Player;
class Rva002BA8F1Logic
{
public:
	Rva002E2903Player *find(int v, unsigned int *p);
};

class Rva002E07B9
{
public:
	void add(int v);
};

class Rva002E07AC
{
public:
	void add(int v);
};

struct Inner13C
{
	char m_pad[0x13C];
	int m_val;
};

struct Inner24
{
	char m_pad[0x24];
	Inner13C *m_ptr;
};

struct Outer08
{
	char m_pad[8];
	int m_val;
};

class Rva005C436E
{
public:
	void rva005C436E(int v);
private:
	char m_pad00[4];
	Inner24 *m_04;
	Outer08 *m_08;
};

void Rva005C436E::rva005C436E(int v)
{
	int idx = m_04->m_ptr->m_val;
	Rva002E2903Player *p = (*(Rva002BA8F1Logic **)0x00DFEF10)->find(idx, 0);
	if (!p)
		return;
	switch (m_08->m_val) {
	case 0:
		((Rva002E07AC *)p)->add(v);
		break;
	case 1:
		((Rva002E07B9 *)p)->add(v);
		break;
	}
}
