// ?rva00214801@Rva002147D1@@QAE?AVWeaponTemplateSetHead@@H@Z
// partial score=0.94 date=2026-10-01
// ?rva00214801@Rva002147D1@@QAE?AVWeaponTemplateSetHead@@H@Z
// partial score=0.94 date=2026-10-01
// cl: /O1 /DNDEBUG /MD
//
// ?rva00214801@Rva002147D1@@QAE?AVWeaponTemplateSetHead@@H@Z @0x00214801 97B
// Guarded indexed Head fetch through Rva002147D1 +0x0c array with double
// memset 0x4c zero tmp: bounds-check index against (m_end-m_begin)-1,
// null-check slot else copy slot+0x1c Head else copy zero tmp via rowed
// copy ctor 0x00045455. Evidence: same +0x0c +0x10 layout as siblings in
// Rva002147D1Get.cpp; callees rowed ji_memset 0x006291AE and Head copy ctor;
// callers at 0x004037B2 0x00403D2E 0x00403FBF.
extern "C" void _ReadWriteBarrier();
#pragma intrinsic(_ReadWriteBarrier)
void *__cdecl ji_006291ae(void *dest, int val, unsigned int count);
#pragma comment(linker, "/alternatename:?ji_006291ae@@YAPAXPAXHI@Z=?ji_006291ae@@YAXXZ")
class WeaponTemplateSetHead
{
	char _m[0x4C];
public:
	WeaponTemplateSetHead(const WeaponTemplateSetHead &that);
};
struct Rva00214801Slot { char _pad[0x1C]; WeaponTemplateSetHead m_head; };
class Rva002147D1
{
public:
	WeaponTemplateSetHead rva00214801(int index);
private:
	char _pad[0x0C];
	int m_begin;
	int m_end;
};
// ?rva00214801@Rva002147D1@@QAE?AVWeaponTemplateSetHead@@H@Z present-unmatched
WeaponTemplateSetHead Rva002147D1::rva00214801(int index)
{
	char tmp[0x4C];
	ji_006291ae(tmp, 0, 0x4C);
	ji_006291ae(tmp, 0, 0x4C);
	if (index < 0)
		return *(WeaponTemplateSetHead *)tmp;
	if ((unsigned)index > (unsigned)((m_end - m_begin >> 2) - 1))
		return *(WeaponTemplateSetHead *)tmp;
	_ReadWriteBarrier();
	Rva00214801Slot *slot = *(Rva00214801Slot **)(m_begin + index * 4);
	if (slot == 0)
		return *(WeaponTemplateSetHead *)tmp;
	return slot->m_head;
}
