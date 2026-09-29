// cl: /O1 /DNDEBUG /MD
// ?rva003FC7FC@Rva003FC7FC@@QAEXXZ @0x003FC7FC 48B:
// Clear particle handle at +0x1C and ID at +0x28: if handle.m_system then
// destroy by ID via TheParticleSystemManager then dtor handle and clear
// both to 0. Callees rowed handle dtor 0x0004CBC0 plus pinned destroy
// 0x001F5B79. Callers 0x002118C2 and 0x003FCD71. Owner unproven.
enum ParticleSystemID
{
	INVALID_PARTICLE_SYSTEM_ID = 0
};
class ParticleSystemManager
{
public:
	void destroyParticleSystemByID(ParticleSystemID id);
};
extern ParticleSystemManager *TheParticleSystemManager;
struct BfmeParticleSystemHandle
{
	~BfmeParticleSystemHandle();
	void *m_system;
	void *m_previous;
	void *m_next;
};
class Rva003FC7FC
{
public:
	void rva003FC7FC(void);
private:
	unsigned char m_pad[0x1C];
	BfmeParticleSystemHandle m_handle;
	ParticleSystemID m_id;
};

void Rva003FC7FC::rva003FC7FC(void)
{
	if (m_handle.m_system != 0)
	{
		TheParticleSystemManager->destroyParticleSystemByID(m_id);
		if (m_handle.m_system != 0)
		{
			m_handle.~BfmeParticleSystemHandle();
			m_handle.m_system = 0;
		}
		m_id = INVALID_PARTICLE_SYSTEM_ID;
	}
}
