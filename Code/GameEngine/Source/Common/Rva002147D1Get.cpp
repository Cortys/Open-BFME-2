// cl: /O1 /DNDEBUG /MD
// ?rva002147D1@Rva002147D1@@QAEPAXHPAVObject@@@Z retail 0x002147D1 48B
// Guarded indexed fetch through Rva0040327B::rva004032D3: bounds-check index
// against (m_end-m_begin)-1, null-check the slot, else return 0. Evidence:
// chain from 0x004032D3; callers at 0x004038BA 0x00403D56 0x0040408F.
class Object;
class Rva0040327B
{
public:
	void *rva004032D3(Object *obj);
};
extern "C" void _ReadWriteBarrier();
#pragma intrinsic(_ReadWriteBarrier)
class Rva002147D1
{
public:
	void *rva002147D1(int index, Object *obj);
private:
	char _pad[0x0C];
	int m_begin;
	int m_end;
};
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
