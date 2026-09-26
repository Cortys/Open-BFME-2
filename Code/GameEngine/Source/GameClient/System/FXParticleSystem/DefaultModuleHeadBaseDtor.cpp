// cl: /O1 /MD
// ??1DefaultModuleHeadBase@@UAE@XZ, retail 0x003A57E7, 20 bytes.
// Head-base destructor for the DefaultModule family (shared three-vtable base
// in DefaultModuleBaseCopyCtors.cpp: vptr 0x00C1B590, 12-byte smart member at
// +0x04, int at +0x10). Retail stores the head vptr, then releases the smart
// member through the rowed 0x0004CBC0 unlink body only when its first dword
// (m_system/m_ptr) is non-zero, via tail-jmp; plain member-dtor codegen gives
// an unconditional 14B call, so the member is modelled trivial here and the
// release is an explicit conditional destroy through the same 12-byte
// intrusive-list layout (head at ParticleSystem +0x9C/+0xA0, cf.
// ParticleSystemHandle_dtor.cpp and SmartPtrCopyCtor.cpp). Callers: jmp from
// 0x003A5817 (??1Rva003AEEB3) and 0x003A984D; ??_G at 0x003A57FB calls here.

struct BfmeParticleSystemHandle
{
	~BfmeParticleSystemHandle();
	void *m_system;
	void *m_prev;
	void *m_next;
};

struct RvaSmartPtr12
{
	void *m_ptr;
	int m_pad04;
	int m_pad08;
};

class DefaultModuleHeadBase
{
public:
	virtual ~DefaultModuleHeadBase();
private:
	RvaSmartPtr12 m_smart;
	int m_int10;
};

DefaultModuleHeadBase::~DefaultModuleHeadBase()
{
	BfmeParticleSystemHandle *p = (BfmeParticleSystemHandle *)&m_smart;
	if (p->m_system != 0)
		p->~BfmeParticleSystemHandle();
}
