// ?rva001F6201@Rva001F6201@@QAEXXZ
// partial score=0.95 date=2026-10-01
// ?rva001F6201@Rva001F6201@@QAEXXZ
// partial score=0.95 date=2026-10-01
// cl: /O1 /MD /arch:SSE /EHs
// ?rva001F6201@Rva001F6201@@QAEXXZ 0x001F6201 142B
// Evidence: chain from 0x001F5B0A findParticleSystemByID; early-out on ID 0 at +0x84; handle via operator-> with Make001FCBD7 fallback stores owner at +0x19C; RvaSmartPtr12 assign at +0x78; redundant ID assert throws via bfmeFormatText tag 5 plus _CxxThrowException.

typedef unsigned int UnsignedInt;

enum ParticleSystemID
{
	INVALID_PARTICLE_SYSTEM_ID = 0
};

class ParticleSystem;
class ParticleSystem *Make001FCBD7();
class Rva001F6201;

class RvaSmartPtr12
{
public:
	RvaSmartPtr12 &operator=(const RvaSmartPtr12 &that);
private:
	void *m_ptr;
	int m_pad04;
	int m_pad08;
};

class BfmeParticleSystemHandle
{
public:
	~BfmeParticleSystemHandle();
	ParticleSystem *operator->() const
	{
		return m_system ? m_system : Make001FCBD7();
	}
private:
	ParticleSystem *m_system;
	void *m_previous;
	void *m_next;
};

class ParticleSystem
{
public:
	unsigned char m_pad00[0xA8];
	ParticleSystemID m_id;
	unsigned char m_padAC[0x19C - 0xAC];
	void *m_owner;
};

class ParticleSystemManager
{
	friend class Rva001F6201;
	BfmeParticleSystemHandle findParticleSystemByID(ParticleSystemID id);
};

extern ParticleSystemManager *TheParticleSystemManager;

struct BfmeFormattedText
{
	char *text;
	int tag;
};

extern "C" BfmeFormattedText *__cdecl bfmeFormatText(BfmeFormattedText *result, int tag, const char *format, ...);
extern int g_guardTargetTypeThrowInfo;
struct _s__ThrowInfo;
extern "C" void __stdcall _CxxThrowException(void *pExceptionObject, const _s__ThrowInfo *pThrowInfo);

class Rva001F6201
{
public:
	void rva001F6201();
private:
	unsigned char m_pad00[0x78];
	RvaSmartPtr12 m_smart;
	ParticleSystemID m_id;
};

void Rva001F6201::rva001F6201()
{
	if (m_id == INVALID_PARTICLE_SYSTEM_ID)
		return;
	BfmeParticleSystemHandle h = TheParticleSystemManager->findParticleSystemByID(m_id);
	h->m_owner = this;
	m_smart = *(const RvaSmartPtr12 *)&h;
	if (m_id == INVALID_PARTICLE_SYSTEM_ID)
	{
		BfmeFormattedText tmp;
		bfmeFormatText(&tmp, 5, 0);
		_CxxThrowException(&tmp, (const _s__ThrowInfo *)&g_guardTargetTypeThrowInfo);
		__assume(0);
	}
}
