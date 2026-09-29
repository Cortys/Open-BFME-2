// cl: /O1 /DNDEBUG /MD
// ?rva002147D1@Rva002147D1@@QAEPAXHPAVObject@@@Z retail 0x002147D1 48B
// Guarded indexed fetch through Rva0040327B::rva004032D3: bounds-check index
// against (m_end-m_begin)-1, null-check the slot, else return 0. Evidence:
// chain from 0x004032D3; callers at 0x004038BA 0x00403D56 0x0040408F.
class Object;
class Rva0040327B
{
public:
	void *rva0040327B(Object *obj);
	void *rva004032D3(Object *obj);
};
extern "C" void _ReadWriteBarrier();
#pragma intrinsic(_ReadWriteBarrier)
class Rva002147D1
{
public:
	void *rva002147A1(int index, Object *obj);
	void *rva002147D1(int index, Object *obj);
	void *rva00214983(int index);
	int rva00214713(int key);
	void *rva00214738(int index);
private:
	char _pad[0x0C];
	int m_begin;
	int m_end;
};
// ?rva002147A1@Rva002147D1@@QAEPAXHPAVObject@@@Z retail 0x002147A1 48B sibling
// of 0x002147D1 differing only by callee rva0040327B vs rva004032D3; same
// guarded fetch via barrier reload. Evidence: chain from 0x0040327B.
void *Rva002147D1::rva002147A1(int index, Object *obj)
{
	if (index < 0)
		return 0;
	if ((unsigned)index > (unsigned)((m_end - m_begin >> 2) - 1))
		return 0;
	_ReadWriteBarrier();
	Rva0040327B *slot = *(Rva0040327B **)(m_begin + index * 4);
	if (slot != 0)
		return slot->rva0040327B(obj);
	return 0;
}
void *Rva002147D1::rva002147D1(int index, Object *obj)
{
	if (index < 0)
		return 0;
	if ((unsigned)index > (unsigned)((m_end - m_begin >> 2) - 1))
		return 0;
	_ReadWriteBarrier();
	Rva0040327B *slot = *(Rva0040327B **)(m_begin + index * 4);
	if (slot != 0)
		return slot->rva004032D3(obj);
	return 0;
}
// ?rva00214983@Rva002147D1@@QAEPAXH@Z retail 0x00214983 34B plain indexed fetch
// from same +0x0c array as 0x002147D1 without barrier or slot call.
// Evidence: same +0x0c +0x10 layout; callers at 0x0040317F 0x004038DB.
void *Rva002147D1::rva00214983(int index)
{
	if (index >= 0 && (unsigned)index < (unsigned)(m_end - m_begin >> 2))
	{
		_ReadWriteBarrier();
		return *(void **)(m_begin + index * 4);
	}
	return 0;
}
struct Rva00214713Slot { char _pad[0x14]; int m_14; };
// ?rva00214713@Rva002147D1@@QAEHH@Z retail 0x00214713 37B linear search of same
// +0x0c array for slot whose +0x14 equals key else -1. Evidence: same +0x0c
// +0x10 layout; callers at 0x00403774 0x00403EAD.
int Rva002147D1::rva00214713(int key)
{
	Rva00214713Slot **base = *(Rva00214713Slot ***)&m_begin;
	Rva00214713Slot **end = *(Rva00214713Slot ***)&m_end;
	int index = 0;
	for (; base != end; ++index, ++base)
	{
		Rva00214713Slot *slot = *base;
		if (slot->m_14 == key)
			return index;
	}
	return -1;
}
struct Rva00214738Slot { char _pad[0x18]; void *m_18; };
// ?rva00214738@Rva002147D1@@QAEPAXH@Z retail 0x00214738 42B guarded fetch of
// slot +0x18 from same +0x0c array as 0x002147D1. Evidence: same +0x0c +0x10
// layout with dec/ja bound plus null slot check; callers at 0x0049410F.
void *Rva002147D1::rva00214738(int index)
{
	if (index < 0)
		return 0;
	if ((unsigned)index > (unsigned)((m_end - m_begin >> 2) - 1))
		return 0;
	_ReadWriteBarrier();
	Rva00214738Slot *slot = *(Rva00214738Slot **)(m_begin + index * 4);
	if (slot != 0)
		return slot->m_18;
	return 0;
}
