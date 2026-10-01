// ?rva004BE3EF@Rva004BE3EF@@QAEXXZ
// partial score=0.94 date=2026-10-01
// ?rva004BE3EF@Rva004BE3EF@@QAEXXZ
// partial score=0.94 date=2026-10-01
// cl: /O1 /DNDEBUG /MD /EHsc
// ?rva004BE3EF@Rva004BE3EF@@QAEXXZ 0x004BE3EF 142B
// Evidence: chain via rowed 0x001F5B0A; vtable slot 20 of Body classes; EH prolog with handler; loop over list at +0xC8 with ID at +4 and next at +8 via rowed findParticleSystemByID then rowed destroy then virtual slot0 with 0 plus rowed operator delete then rowed handle dtor. Honest Rva names.
enum ParticleSystemID
{
	INVALID_PARTICLE_SYSTEM_ID = 0
};

class ParticleSystem
{
public:
	void destroy();
};

struct BfmeParticleSystemHandle
{
	~BfmeParticleSystemHandle();
	ParticleSystem *m_system;
	void *m_previous;
	void *m_next;
};

class Rva004BE3EF;

class ParticleSystemManager
{
	friend class Rva004BE3EF;
	BfmeParticleSystemHandle findParticleSystemByID(ParticleSystemID id);
};

extern ParticleSystemManager *TheParticleSystemManager;

void __cdecl operator delete(void *block);

struct ListNode
{
	virtual void *slot0(unsigned int flags);
	ParticleSystemID m_id;
	ListNode *m_next;
};

class Rva004BE3EF
{
public:
	void rva004BE3EF();
private:
	char m_pad[0xC8];
	ListNode *m_list;
};
// ?rva004BE3EF@Rva004BE3EF@@QAEXXZ present-unmatched
void Rva004BE3EF::rva004BE3EF()
{
	while (m_list)
	{
		ParticleSystemID id = m_list->m_id;
		BfmeParticleSystemHandle h = TheParticleSystemManager->findParticleSystemByID(id);
		if (h.m_system)
			h.m_system->destroy();
		ListNode *next = m_list->m_next;
		void *p;
		if (m_list)
			p = m_list->slot0(0);
		else
			p = 0;
		operator delete(p);
		m_list = next;
		if (h.m_system)
			h.~BfmeParticleSystemHandle();
	}
}
