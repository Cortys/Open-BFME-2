// cl: /O1 /MD /EHsc
// ??1Rva0036783F@@UAE@XZ @0x0036783F 79B
// Dtor: vtable 0x00817548 plus delete of heap member at +0x28 via virtual
// slot 0 plus operator delete 0x0002FD60 plus base WindModuleInfo dtor
// 0x0049B47C. Evidence: caller 0x003689AB; rowed base dtor plus delete.
void __cdecl operator delete(void *p);
class Rva0036783FMember
{
public:
	virtual void *slot00(int flag);
};
class Snapshot
{
public:
	virtual ~Snapshot();
};
namespace FXParticleSystem
{
class WindModuleInfo : public Snapshot
{
public:
	virtual ~WindModuleInfo();
	virtual void v1() = 0;
};
}
class Rva0036783F : public FXParticleSystem::WindModuleInfo
{
public:
	virtual ~Rva0036783F();
private:
	char m_pad[0x28 - 4];
	Rva0036783FMember *m_28;
};
Rva0036783F::~Rva0036783F()
{
	::operator delete(m_28 ? m_28->slot00(0) : 0);
	m_28 = 0;
}
