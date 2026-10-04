// cl: /O1 /G7 /arch:SSE /MD /GX /DNDEBUG /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// The skirmish-AI object built at 0x0050542B (newed by 0x002C6144, freed by
// 0x002C5F91 / 0x002C61D5), next to the AITacticsGenerator.cpp range. No RTTI
// or donor, so it keeps an address-derived name.
//
// Target evidence for the layout:
//   +0x00 owner, kept for the AI-manager lookup in 0x0050535A
//   +0x04 a 0x18-byte Rva005A9562 built from the owner (dtor 0x000796BC)
//   +0x08 vector of owned Rva002C589B entries (non-virtual dtor 0x002C589B)
//   +0x14 a second pointer vector, cleared with the first
#include <vector>

class Rva005A9562
{
public:
	Rva005A9562(void *owner);
	~Rva005A9562();
private:
	unsigned char m_data[0x18];
};

struct Rva0050535AStore
{
	char m_pad00[0x54];
	float m_threshold;	// +0x54
};

class Rva002A8F24
{
public:
	Rva0050535AStore **rva002A8F24(void *owner);
};

extern Rva002A8F24 *g_00DFEEF8;

class Rva002C589B
{
public:
	~Rva002C589B();
	int rva0030F2C7() const;
	float rva002C5AE6();
	char m_pad00[4];
	int m_04;		// +0x04
	char m_pad08[0x18 - 8];
	bool m_18;		// +0x18
	bool m_19;		// +0x19
	char m_pad1A[0x20 - 0x1A];
	int m_limit;		// +0x20
	char m_pad24[0x38 - 0x24];
	int m_id;		// +0x38
};

struct Rva0050542BOther;

class Rva0050542B
{
public:
	Rva0050542B(void *owner);
	~Rva0050542B();
	Rva002C589B *rva00505408(int id);
	Rva002C589B *rva005053A4();
private:
	bool rva0050535A(Rva002C589B *entry);

	void *m_owner;					// +0x00
	Rva005A9562 *m_04;				// +0x04
	_STL::vector<Rva002C589B *> m_08;		// +0x08
	_STL::vector<Rva0050542BOther *> m_14;		// +0x14
};

Rva0050542B::Rva0050542B(void *owner)
	: m_owner(owner), m_04(0)
{
	m_04 = new Rva005A9562(owner);
}

Rva0050542B::~Rva0050542B()
{
	if (m_04) {
		delete m_04;
		m_04 = 0;
	}
	for (Rva002C589B **it = m_08.begin(); it != m_08.end(); ++it)
		delete *it;
	m_08.clear();
	m_14.clear();
}

Rva002C589B *Rva0050542B::rva00505408(int id)
{
	Rva002C589B **end = m_08.end();
	for (Rva002C589B **it = m_08.begin(); it != end; ++it)
		if ((*it)->m_id == id)
			return *it;
	return 0;
}

bool Rva0050542B::rva0050535A(Rva002C589B *entry)
{
	if (!entry->m_19 && !entry->m_18) {
		if (entry->m_04 == 1)
			return true;
		Rva0050535AStore *store = *g_00DFEEF8->rva002A8F24(m_owner);
		if (store->m_threshold > entry->rva002C5AE6())
			return true;
	}
	return false;
}

Rva002C589B *Rva0050542B::rva005053A4()
{
	Rva002C589B **it;
	for (it = m_08.begin(); it != m_08.end(); ++it) {
		Rva002C589B *entry = *it;
		if (rva0050535A(entry) && entry->rva0030F2C7() == 0)
			return entry;
	}
	for (it = m_08.begin(); it != m_08.end(); ++it) {
		Rva002C589B *entry = *it;
		if (rva0050535A(entry)) {
			int limit = entry->m_limit;
			if (entry->rva0030F2C7() < limit)
				return entry;
		}
	}
	return 0;
}
