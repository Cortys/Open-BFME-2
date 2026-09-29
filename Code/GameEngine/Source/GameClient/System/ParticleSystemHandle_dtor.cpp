// cl: /O1 /DNDEBUG /MD /EHsc
// ??1BfmeParticleSystemHandle@@QAE@XZ, retail 0x0004CBC0, 55 bytes.
// Intrusive-list unlink spelt from Open-BFME-1
// (Code/GameEngine/Source/GameClient/System/ParticleSystemHandleListClear.cpp,
// whose 111B list-clear row documents the idiom): destroying the handle unlinks
// it from the ParticleSystem handle chain. BFME2 deltas (retail-measured): no
// outer m_system guard, and the chain head lives at ParticleSystem
// +0x9C/+0xA0 (first/last). Pin pre-existed; row joins it here.

class ParticleSystem;

struct BfmeParticleSystemHandle
{
	~BfmeParticleSystemHandle();
	ParticleSystem *m_system;
	BfmeParticleSystemHandle *m_previous;
	BfmeParticleSystemHandle *m_next;
};

class ParticleSystem
{
public:
	unsigned char m_pad[0x9C];
	BfmeParticleSystemHandle *m_firstHandle;	// +0x9C
	BfmeParticleSystemHandle *m_lastHandle;		// +0xA0
};

BfmeParticleSystemHandle::~BfmeParticleSystemHandle()
{
	if (m_previous)
		m_previous->m_next = m_next;
	else
		m_system->m_firstHandle = m_next;
	if (m_next)
		m_next->m_previous = m_previous;
	else
		m_system->m_lastHandle = m_previous;
	m_previous = 0;
	m_next = 0;
}

// ?rva002115C5@Rva002115C5@@QAEXXZ, RVA 0x002115C5, 11B. Unlock lane:
// conditionally destroys the handle at +0 in place through rowed
// ??1BfmeParticleSystemHandle@@QAE@XZ at 0x0004CBC0 when its m_system is
// set; tail-position explicit dtor call with this already in ecx emits jmp,
// no reload. 40+ callers; unblocks 0x00211ED9/0x00212AD6. Owner unknown so
// honest address-derived struct (no vtable) holding the real handle first.
struct Rva002115C5 {
	BfmeParticleSystemHandle m_handle;
	void rva002115C5();
};

void Rva002115C5::rva002115C5()
{
	if (m_handle.m_system)
		m_handle.~BfmeParticleSystemHandle();
}
