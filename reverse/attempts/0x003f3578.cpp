// ?rva003F3578@ConnectionVec@@QAEPAVLivingWorldRegionConnection@@PAV2@@Z
// partial score=0.91 date=2026-10-04
// cl: /O1 /Oy- /DNDEBUG /MD
// ?rva003F3578@ConnectionVec@@QAEPAVLivingWorldRegionConnection@@PAV2@@Z @0x003F3578 56B
// Vector erase over LivingWorldRegionConnection ranges: rowed copy
// 0x003F325A with dead-slot dummy [ebp+0xb] when pos+1 != m_finish, then
// decrement m_finish and destroy last via virtual dtor, return pos.
// Same ConnectionVec layout and flags as Rva003F35B0Finish. Evidence:
// retail 4 pushes + add esp,0x10, add [esi+4],-0x18, push 0 + call [eax],
// ret 4, callees rowed.
class LivingWorldRegionConnection
{
public:
	virtual ~LivingWorldRegionConnection();
private:
	unsigned char m_pad04[0x14];
};
class Rva003F2A11;
Rva003F2A11 *Rva003F325ACopy(Rva003F2A11 *, Rva003F2A11 *, Rva003F2A11 *);
typedef Rva003F2A11 *(__cdecl *Rva003F325A4Fn)(Rva003F2A11 *, Rva003F2A11 *, Rva003F2A11 *, void *);
struct ConnectionVec
{
	LivingWorldRegionConnection *rva003F3578(LivingWorldRegionConnection *pos);
	LivingWorldRegionConnection *m_start;
	LivingWorldRegionConnection *m_finish;
	LivingWorldRegionConnection *m_end;
};
// ?rva003F3578@ConnectionVec@@QAEPAVLivingWorldRegionConnection@@PAV2@@Z present-unmatched
LivingWorldRegionConnection *ConnectionVec::rva003F3578(LivingWorldRegionConnection *pos)
{
	LivingWorldRegionConnection *finish = m_finish;
	LivingWorldRegionConnection *next = pos + 1;
	if (finish != next)
		((Rva003F325A4Fn)&Rva003F325ACopy)((Rva003F2A11 *)(void *)next, (Rva003F2A11 *)(void *)finish, (Rva003F2A11 *)(void *)pos, (char *)&pos + 3);
	m_finish -= 1;
	m_finish->~LivingWorldRegionConnection();
	return pos;
}
